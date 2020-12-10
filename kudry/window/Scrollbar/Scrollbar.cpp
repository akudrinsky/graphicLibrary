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
    toUpper.HandleEvent(event);
    toLower.HandleEvent(event);
    middle.HandleEvent(event);
    //SubscriptionManager::Send(this, event);
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
    ScrollbarEvent posEvent(position, this);
    SubscriptionManager::Send(this, &posEvent);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::SetColor(const Color &newColor)
{
    middle.SetColor(newColor);
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
    clickData(-2, -2)
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::middleButton::OnClick()
{
    clickData = FlatObj<int>(-1, -1);
}

/*--------------------------------------------------------------------------*/

void Scrollbar::middleButton::OnRelease()
{
    if (shape.GetSize().y == 0.0)
        return;

    scrlbar->position = ((double)clickData.y - (double)shape.GetOrigin().y) / (double)shape.GetSize().y;
    scrlbar->SendPosition();
    LOGS("position = %lg after middle button in %p\n", scrlbar->position, this)
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
                if (clickData.x != -1 || clickData.y != -1)
                    return false;
                clickData = realEvent->Position;
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