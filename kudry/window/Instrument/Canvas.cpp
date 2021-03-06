#include "Canvas.hpp"
#include "canvasEvents.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"
#include "../../engine/engineInterface.hpp"

namespace kudry
{

Canvas::Canvas(
    const FlatObj<int> &position, 
    const FlatObj<int> &size, 
    const Color &color
)   :
    picture(position, size)
{
    picture.Fill(color);
}

/*--------------------------------------------------------------------------*/

bool Canvas::HandleEvent(Event *event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            MouseEvent* realEvent = static_cast<MouseEvent*>(event);
                        
            if (!picture.Contains(realEvent->Position))
                return false;
            
            /*
            LOGS(
                "Mouse event on Canvas\n"
                "Coords are (%d, %d)\n"
                "Type is %d\n",
                realEvent->Position.x, 
                realEvent->Position.y, 
                realEvent->Action)
            */

            CanvasEvent passingEvent{
                .pos = FlatObj<int>(
                    realEvent->Position.x - picture.GetOrigin().x,
                    realEvent->Position.y - picture.GetOrigin().y),
                .pict = &picture, 
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
        case Event::Close:
        {

            break;
        }
        default:
        {
            break;
        }
    }
    return false;
}

/*--------------------------------------------------------------------------*/

void Canvas::LoadFromFile(const char* filename)
{

}

/*--------------------------------------------------------------------------*/

void Canvas::SaveToFile(const char* filename) const
{
    
}

/*--------------------------------------------------------------------------*/

void Canvas::Draw(engineInterface* engine)
{
    engine->DrawPicture(&picture);
}

/*--------------------------------------------------------------------------*/

void Canvas::EmplaceWindow(AbstractWindow*)
{}

/*--------------------------------------------------------------------------*/

void Canvas::RemoveWindow(AbstractWindow*)
{}

/*--------------------------------------------------------------------------*/

const Picture& Canvas::GetPicture() const
{
    return picture;
}

/*--------------------------------------------------------------------------*/

void Canvas::SetOrigin(const FlatObj<int>& origin)
{
    picture.SetOrigin(origin);
}

/*--------------------------------------------------------------------------*/

void Canvas::SetSize(const FlatObj<int>& size)
{
    picture.SetSize(size);
}

/*--------------------------------------------------------------------------*/

void Canvas::SetColor(const Color& clr)
{
    picture.Fill(clr);
}

}