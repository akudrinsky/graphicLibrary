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
        middleColor
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
    scrlbar(scrlbar)
{
    SubscriptionManager::Subscribe(scrlbar, this);
}

void Scrollbar::middleButton::OnClick()
{
    scrlbar->position -= scrlbar->step;
    if (scrlbar->position < 0.0)
        scrlbar->position = 0.0;
    LOGS("position: %lg\n", scrlbar->position)
}

void Scrollbar::middleButton::OnRelease()
{}

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
    LOGS("position: %lg\n", scrlbar->position)
}

void Scrollbar::lowerButton::OnRelease()
{}

}