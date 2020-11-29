#pragma once

#include "../AbstractWindow.hpp"
#include "../../simpleGraphics/color/color.hpp"

namespace kudry
{

// Class that describes functionality, that every instrument must have.
// Important: all instruments have an active one. It is the one that acts on canvas. 
class AbstractInstrument : public AbstractWindow
{
public:
    static AbstractInstrument* GetActive();

protected:
    void SetActive();

private:
    // Active instrument, that would affect the Canvas
    static AbstractInstrument* active;
};

/*--------------------------------------------------------------------------*/

// For pencil
class Pencil : public AbstractInstrument
{
public: 
    Pencil();

    typedef char Thickness_t;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

protected:
    Color clr; 
    Thickness_t thickness;
};

/*--------------------------------------------------------------------------*/

// For eraser (just colors with the color of background)
class Eraser : public Pencil
{
public:
    virtual bool HandleEvent([[maybe_unused]] Event* event) override;
};

}