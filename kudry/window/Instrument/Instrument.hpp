#pragma once

#include "../AbstractWindow.hpp"
#include "canvasEvents.hpp"
#include "../RectangleButton/RectangleButton.hpp"
#include "../../simpleGraphics/color/color.hpp"
#include <limits>
#include <cmath>

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

    static void SetMainColor(const Color& clr);

    static const Color& GetMainColor();

protected:
    void SetActive();
    Picture* picture;

private:
    // Active instrument, that would affect the Canvas
    static AbstractInstrument* active;
    
    // Main color, that is defined by managing buttons
    static Color mainColor;

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

    void SetThickness(const Thickness_t& newThickness);

    ManagingButton button;

protected:
    Thickness_t thickness;
    // the closer to beginning - the earlier dot was presented
    std::deque<FlatObj<int>> previousDots;

    bool isActive;

    // Uses spline techique to draw lines
    // See: https://en.wikipedia.org/wiki/Spline_interpolation
    void drawLine(const Color& clr);
};

/*--------------------------------------------------------------------------*/

// For eraser (just colors with the color of background)
class Eraser : public Pencil
{
public:
    virtual void Draw(engineInterface* engine) override;
};

}