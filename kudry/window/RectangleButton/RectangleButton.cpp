#include "RectangleButton.hpp"

// In process

namespace kudry
{

static void clickTest (kudry::AbstractWindow*)
{
    LOGS("button has accepted click\n")
}

static void releaseTest (kudry::AbstractWindow*)
{
    LOGS("button has accepted release\n")
}

RectangleButton::RectangleButton(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor
)   :
    RectangleWindow(center, size, backgroundColor),
    clickInterface(clickTest, releaseTest, this)
{}

bool RectangleButton::HandleEvent([[maybe_unused]] Event* event)
{
    switch (event->ID)
    {
        case Event::MousePressed:
        {
            clickInterface.OnClick();
            return true;
            break;
        }
        case Event::MouseReleased:
        {
            clickInterface.OnRelease();
            return true;
            break;
        }
        default:
        {
            break;
        }
    }
    return false;
}

}