#include "Canvas.hpp"
#include "canvasEvents.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

bool Canvas::HandleEvent(Event *event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            MouseEvent* realEvent = static_cast<MouseEvent*>(event);
            if (!shape.Contains(realEvent->Position))
                return false;

            CanvasEvent passingEvent {
                .pos = realEvent->Position, 
                .canvas = this, 
                .act = realEvent->Action};

            SubscriptionManager::SendTo(
                AbstractInstrument::GetActive(), 
                &passingEvent);

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