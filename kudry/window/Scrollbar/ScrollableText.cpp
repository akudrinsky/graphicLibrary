#include "ScrollableText.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"
#include "../../engine/engineInterface.hpp"

namespace kudry
{

ScrollableText::ScrollableText(
    const TextWindow& fulltext, 
    const FlatObj<int>& center, 
    const FlatObj<int>& size, 
    const Color& backgroundColor
)   :
    RectangleWindow(center, size, backgroundColor), 
    fulltext(fulltext),
    position(0.0)
{}

/*--------------------------------------------------------------------------*/

ScrollableText::~ScrollableText()
{}

/*--------------------------------------------------------------------------*/

bool ScrollableText::HandleEvent([[maybe_unused]] Event* event)
{
    switch (event->GetEventType())
    {
        case Event::User:
        {
            auto realEvent = static_cast<ScrollbarEvent*>(event);
            position = realEvent->Position;
            LOGS("Scrollbar position was received: %lg", position)
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

/*--------------------------------------------------------------------------*/

void ScrollableText::Draw([[maybe_unused]] engineInterface* Canvas)
{
    LOGS("position %lf", position)
    Canvas->DrawText(&fulltext, &shape, &backgroundColor, position);
}

/*--------------------------------------------------------------------------*/

void ScrollableText::Attach(Scrollbar* manager)
{
    SubscriptionManager::Subscribe(manager, this);
}

}