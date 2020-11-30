#include "RectangleButton.hpp"

// In process

namespace kudry
{

RectangleButton::RectangleButton()
{}

/*--------------------------------------------------------------------------*/

RectangleButton::RectangleButton(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor
)   :
    RectangleWindow(center, size, backgroundColor)
    //,clickInterface(nullptr, nullptr, this)
{}

/*--------------------------------------------------------------------------*/

bool RectangleButton::HandleEvent([[maybe_unused]] Event* event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            MouseEvent* realEvent = static_cast<MouseEvent*>(event);
            if (!shape.Contains(realEvent->Position))
                return false;
            //clickInterface.OnClick();
            if (realEvent->Action == MouseEvent::WasPressed)
                OnClick();
            else if (realEvent->Action == MouseEvent::WasReleased)
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