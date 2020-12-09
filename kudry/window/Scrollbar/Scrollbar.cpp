#include "Scrollbar.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

Scrollbar::Scrollbar(
    const FlatObj<int>& origin, 
    const FlatObj<int>& size, 
    const Color& endsColor,
    const Color& middleColor
)   :
    position(0.0),
    step(0.05),
    toUpper(
        origin, 
        FlatObj<int>(size.x, size.x), 
        endsColor,
        this
    ),
    toLower(
        FlatObj<int>(origin.x, origin.y + size.y - size.x), 
        FlatObj<int>(size.x, size.x), 
        endsColor,
        this
    ),
    middle(
        FlatObj<int>(origin.x, origin.y + size.x),
        FlatObj<int>(size.x, size.y - 2 * size.x),
        middleColor,
        this
    )
{}

/*--------------------------------------------------------------------------*/

Scrollbar::~Scrollbar()
{}

/*--------------------------------------------------------------------------*/

bool Scrollbar::HandleEvent([[maybe_unused]] Event* event)
{
    SubscriptionManager::Send(this, event);
    return false;
}

/*--------------------------------------------------------------------------*/

void Scrollbar::SetStep(const double& newStep)
{
    step = newStep;
}

/*--------------------------------------------------------------------------*/

void Scrollbar::Draw(engineInterface* Canvas)
{
    toUpper.Draw(Canvas);
    toLower.Draw(Canvas);
    middle.Draw(Canvas);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::EmplaceWindow([[maybe_unused]] AbstractWindow* window)
{}

/*--------------------------------------------------------------------------*/

void Scrollbar::RemoveWindow([[maybe_unused]] AbstractWindow* window)
{}

/*--------------------------------------------------------------------------*/

void Scrollbar::SendPosition()
{
    ScrollbarEvent posEvent(position);
    SubscriptionManager::Send(this, &posEvent);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::SetColor(const Color &newColor)
{
    middleButton.SetColor(newColor);
}

/*--------------------------------------------------------------------------*/

Scrollbar::upperButton::upperButton(
    const FlatObj<int>& center, 
    const FlatObj<int>& size, 
    const Color& backgroundColor,
    Scrollbar* scrlbar
)   :
    RectangleButton(center, size, backgroundColor),
    scrlbar(scrlbar)
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::upperButton::OnClick()
{
    scrlbar->position -= scrlbar->step;
    if (scrlbar->position < 0.0)
        scrlbar->position = 0.0;
    scrlbar->SendPosition();
    LOGS("position: %lg\n", scrlbar->position)
}

/*--------------------------------------------------------------------------*/

void Scrollbar::upperButton::OnRelease()
{}

/*--------------------------------------------------------------------------*/

Scrollbar::middleButton::middleButton(
    const FlatObj<int>& center, 
    const FlatObj<int>& size, 
    const Color& backgroundColor,
    Scrollbar* scrlbar
)   :
    RectangleButton(center, size, backgroundColor),
    scrlbar(scrlbar),
    clickData(reinterpret_cast<const FlatObj<int>*>(0xBAD))
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::middleButton::OnClick()
{
    clickData = nullptr;
}

/*--------------------------------------------------------------------------*/

void Scrollbar::middleButton::OnRelease()
{
    if (shape.GetSize().y == 0.0)
        return;

    scrlbar->position = (clickData->y - shape.GetOrigin().y) / shape.GetSize().y;
    scrlbar->SendPosition();
    LOGS("position = %lg after middle button\n", scrlbar->position)
}

/*--------------------------------------------------------------------------*/

bool Scrollbar::middleButton::HandleEvent(Event* event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            auto realEvent = static_cast<MouseEvent*>(event);
            if (!shape.Contains(realEvent->Position))
                return false;
            //clickInterface.OnClick();

            if (realEvent->Action == MouseEvent::WasPressed)
            {
                OnClick();
            }
            else if (realEvent->Action == MouseEvent::WasReleased)
            {
                if (clickData != nullptr)
                    return false;
                clickData = &realEvent->Position;
                OnRelease();
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

/*--------------------------------------------------------------------------*/

Scrollbar::lowerButton::lowerButton(
    const FlatObj<int>& center, 
    const FlatObj<int>& size, 
    const Color& backgroundColor,
    Scrollbar* scrlbar
)   :
    RectangleButton(center, size, backgroundColor),
    scrlbar(scrlbar)
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::lowerButton::OnClick()
{
    scrlbar->position += scrlbar->step;
    if (scrlbar->position > 1.0)
        scrlbar->position = 1.0;
    scrlbar->SendPosition();
    LOGS("position: %lg\n", scrlbar->position)
}

/*--------------------------------------------------------------------------*/

void Scrollbar::lowerButton::OnRelease()
{}

/*--------------------------------------------------------------------------*/

ScrollbarEvent::ScrollbarEvent(double position, Scrollbar* receivedFrom)
    :
    Position(position),
    ReceivedFrom(receivedFrom)
{}

}