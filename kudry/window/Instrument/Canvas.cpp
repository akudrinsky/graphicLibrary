#include "Canvas.hpp"
#include "canvasEvents.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

Canvas::Canvas(
    const FlatObj &position, 
    const FlatObj &size, 
    const Color &color
)   :
    RectangleWindow(position, size)
{

}

bool Canvas::HandleEvent(Event *event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            MouseEvent* realEvent = static_cast<MouseEvent*>(event);
            if (!shape.Contains(realEvent->Position))
                return false;

            LOGS("Mouse event on Canvas\nCoords are (%lg, %lg)\nType is %d\n", realEvent->Position.x, realEvent->Position.y, realEvent->Action)

            CanvasEvent passingEvent {
                .pos = realEvent->Position, 
                .canvas = this, 
                .act = realEvent->Action};

            if (AbstractInstrument::GetActive() != nullptr)
            {
                SubscriptionManager::SendTo(
                    AbstractInstrument::GetActive(), 
                    &passingEvent
                );
            }

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

//void Canvas::Draw(engineInterface *engine){}

}