#pragma once

#include "../AbstractWindow.hpp"
#include "canvasEvents.hpp"
#include "../RectangleButton/RectangleButton.hpp"
#include "../../simpleGraphics/color/color.hpp"

//#include <optional>
#include <deque>

namespace kudry
{

class ManagingButton;

// Class that describes functionality, that every instrument must have.
// Important: all instruments have an active one. It is the one that acts on canvas. 
class AbstractInstrument : public AbstractWindow
{
public:
    AbstractInstrument();

    static AbstractInstrument* GetActive();

protected:
    void SetActive();
    Canvas* canvas;

private:
    // Active instrument, that would affect the Canvas
    static AbstractInstrument* active;

    friend class ManagingButton;
};

/*--------------------------------------------------------------------------*/

// Decsribes button, that manages this instrument.
class ManagingButton : public RectangleButton
{
public:
    ManagingButton(AbstractInstrument* instr);

    virtual void OnClick() override;

    virtual void OnRelease() override;
private:
    AbstractInstrument* instr;
};

/*--------------------------------------------------------------------------*/

// For pencil
class Pencil : public AbstractInstrument
{
public: 
    Pencil();

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* engine) override;

    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) override;

    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) override;

    ManagingButton button;

protected:
    Color clr; 
    Thickness_t thickness;
    // the closer to beginning - the earlier dot was presented
    std::deque<FlatObj> previousDots;

    // Uses spline techique to draw lines
    // See: https://en.wikipedia.org/wiki/Spline_interpolation
    void drawLine(CanvasEvent* event);
};

/*--------------------------------------------------------------------------*/

// For eraser (just colors with the color of background)
class Eraser : public Pencil
{
public:
    virtual bool HandleEvent([[maybe_unused]] Event* event) override;
};

}