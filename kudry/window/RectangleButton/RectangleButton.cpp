#include "RectangleButton.hpp"

// In process

namespace kudry
{

RectangleButton::RectangleButton(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor
)   :
    RectangleWindow(center, size, backgroundColor),
    clickInterface(nullptr, nullptr, this)
{}

bool RectangleButton::HandleEvent([[maybe_unused]] Event* event)
{
    switch (event->ID)
    {
        case Event::MousePressed:
        {
            if (!shape.Contains(event->Data.Click.coord))
                return false;
            //clickInterface.OnClick();
            OnClick();
            return true;
            break;
        }
        case Event::MouseReleased:
        {
            if (!shape.Contains(event->Data.Click.coord))
                return false;
            //clickInterface.OnRelease();
            OnRelease();
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