#include "Scrollbar.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

Scrollbar::Scrollbar(
    const FlatObj& origin, 
    const FlatObj& size, 
    const Color& endsColor,
    const Color& middleColor
)   :
    position(0.0),
    step(0.05),
    toUpper(
        origin, 
        FlatObj(size.x, size.x), 
        endsColor,
        this
    ),
    toLower(
        FlatObj(origin.x, origin.y + size.y - size.x), 
        FlatObj(size.x, size.x), 
        endsColor,
        this
    ),
    middle(
        FlatObj(origin.x, origin.y + size.x),
        FlatObj(size.x, size.y - 2 * size.x),
        middleColor,
        this
    )
{}

Scrollbar::~Scrollbar()
{}

bool Scrollbar::HandleEvent([[maybe_unused]] Event* event)
{
    SubscriptionManager::Send(this, event);
    return false;
}

void Scrollbar::SetStep(const double& newStep)
{
    step = newStep;
}

void Scrollbar::Draw(engineInterface* Canvas)
{
    toUpper.Draw(Canvas);
    toLower.Draw(Canvas);
    middle.Draw(Canvas);
}

void Scrollbar::EmplaceWindow([[maybe_unused]] AbstractWindow* window)
{}

void Scrollbar::RemoveWindow([[maybe_unused]] AbstractWindow* window)
{}

void Scrollbar::SendPosition()
{
    Event posEvent;
    posEvent.ID = Event::User;
    posEvent.Data.User.data = &position;
    SubscriptionManager::Send(this, &posEvent);
}

Scrollbar::upperButton::upperButton(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor,
    Scrollbar* scrlbar
)   :
    RectangleButton(center, size, backgroundColor),
    scrlbar(scrlbar)
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

void Scrollbar::upperButton::OnClick()
{
    scrlbar->position -= scrlbar->step;
    if (scrlbar->position < 0.0)
        scrlbar->position = 0.0;
    scrlbar->SendPosition();
    LOGS("position: %lg\n", scrlbar->position)
}

void Scrollbar::upperButton::OnRelease()
{}

Scrollbar::middleButton::middleButton(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor,
    Scrollbar* scrlbar
)   :
    RectangleButton(center, size, backgroundColor),
    scrlbar(scrlbar),
    clickData(reinterpret_cast<const FlatObj*>(0xBAD))
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

void Scrollbar::middleButton::OnClick()
{
    clickData = nullptr;
}

void Scrollbar::middleButton::OnRelease()
{
    if (shape.GetSize().y == 0.0)
        return;

    scrlbar->position = (clickData->y - shape.GetOrigin().y) / shape.GetSize().y;
    scrlbar->SendPosition();
    LOGS("position = %lg after middle button\n", scrlbar->position)
}

bool Scrollbar::middleButton::HandleEvent(Event* event)
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
            
            if (clickData != nullptr)
                return false;
            //clickInterface.OnRelease();
            clickData = &(event->Data.Click.coord);
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

Scrollbar::lowerButton::lowerButton(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor,
    Scrollbar* scrlbar
)   :
    RectangleButton(center, size, backgroundColor),
    scrlbar(scrlbar)
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

void Scrollbar::lowerButton::OnClick()
{
    scrlbar->position += scrlbar->step;
    if (scrlbar->position > 1.0)
        scrlbar->position = 1.0;
    scrlbar->SendPosition();
    LOGS("position: %lg\n", scrlbar->position)
}

void Scrollbar::lowerButton::OnRelease()
{}

}