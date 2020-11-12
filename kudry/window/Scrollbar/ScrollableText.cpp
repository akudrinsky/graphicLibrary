#include "ScrollableText.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

ScrollableText::ScrollableText(
    const TextWindow& fulltext, 
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor
)   :
    RectangleWindow(center, size, backgroundColor), 
    fulltext(fulltext),
    position(0.0)
{}

ScrollableText::~ScrollableText()
{}

bool ScrollableText::HandleEvent([[maybe_unused]] Event* event)
{
    switch (event->ID)
    {
        case Event::User:
        {
            position = *static_cast<double*>(event->Data.User.data);
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

void ScrollableText::Draw([[maybe_unused]] engineInterface* Canvas)
{
    //...
}

void ScrollableText::Attach(Scrollbar* manager)
{
    SubscriptionManager::Subscribe(manager, this);
}

}