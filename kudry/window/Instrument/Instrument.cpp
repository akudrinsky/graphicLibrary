#include "Instrument.hpp"
#include "canvasEvents.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"
#include "../../engine/engineInterface.hpp"
#include <utility>

namespace kudry
{

/*--------------------------------------------------------------------------*/

AbstractInstrument* AbstractInstrument::active = nullptr;

Color AbstractInstrument::mainColor = Color::RedColor;

Thickness_t AbstractInstrument::thickness = 10;

const Thickness_t AbstractInstrument::maxThickness = 20;

/*--------------------------------------------------------------------------*/

AbstractInstrument::AbstractInstrument()
    :
    picture(nullptr)
{}

/*--------------------------------------------------------------------------*/

void AbstractInstrument::SetActive()
{
    active = this;
}

/*--------------------------------------------------------------------------*/

AbstractInstrument* AbstractInstrument::GetActive()
{
    return active;
}

/*--------------------------------------------------------------------------*/

void AbstractInstrument::SetMainColor(const Color& clr)
{
    mainColor = clr;
}

/*--------------------------------------------------------------------------*/

const Color& AbstractInstrument::GetMainColor()
{
    return mainColor;
}

/*--------------------------------------------------------------------------*/

void AbstractInstrument::SetThickness(const Thickness_t& thck)
{
    thickness = thck;
}

/*--------------------------------------------------------------------------*/

const Thickness_t& AbstractInstrument::GetThickness()
{
    return thickness;
}

/*--------------------------------------------------------------------------*/

const Thickness_t& AbstractInstrument::GetMaxThickness()
{
    return maxThickness;
}

/*--------------------------------------------------------------------------*/

ManagingButton::ManagingButton(AbstractInstrument* instr)
    :
    instr(instr)
{}

/*--------------------------------------------------------------------------*/

void ManagingButton::OnClick()
{
    instr->SetActive();
    LOGS("Active instrument is now %p\n", instr->GetActive())
}

/*--------------------------------------------------------------------------*/

void ManagingButton::OnRelease()
{
    //SetActive();
}

/*--------------------------------------------------------------------------*/

Pencil::Pencil()
    :
    button(this),
    isActive(false)
{
    button.SetColor(Color::RedColor);
    button.SetOrigin(FlatObj<int>(10, 10));
    button.SetSize(FlatObj<int>(100, 100));
}

/*--------------------------------------------------------------------------*/

bool Pencil::HandleEvent(Event *event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            button.HandleEvent(event);
            break;
        }
        case Event::User:
        {
            //LOGS("Instrument %p has received user event\n", GetActive())
            CanvasEvent* realEvent = static_cast<CanvasEvent*>(event);

            if (realEvent->act == MouseEvent::WasPressed)
                isActive = true;

            if (isActive)
                previousDots.push_back(realEvent->pos);

            if (picture == nullptr)
                picture = realEvent->pict;

            //LOGS("Saw %lu dots", previousDots.size())
            
            if (realEvent->act == MouseEvent::WasReleased)
            {
                isActive = false;
                previousDots.clear();
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

void Pencil::Draw(engineInterface* engine)
{
    button.Draw(engine);
    
    drawLine(GetMainColor());
}

/*--------------------------------------------------------------------------*/

void Pencil::drawLine(const Color& clr)
{
    for (int i = 0; i < (long)previousDots.size() - 1; ++i)
    {
        const FlatObj<int>& firstDot = previousDots[i];
        const FlatObj<int>& secondDot = previousDots[i + 1];

        int FlatObj<int>::* primaryAxis = nullptr;
        int FlatObj<int>::* secondaryAxis = nullptr;

        int xDotDiff = abs(previousDots[i].x - previousDots[i + 1].x);
        int yDotDiff = abs(previousDots[i].y - previousDots[i + 1].y);

        if (xDotDiff > yDotDiff)
        {
            primaryAxis = &FlatObj<int>::x;
            secondaryAxis = &FlatObj<int>::y;
        }
        else
        {
            primaryAxis = &FlatObj<int>::y;
            secondaryAxis = &FlatObj<int>::x;
        }
        if (
            fabs(firstDot.*primaryAxis - secondDot.*primaryAxis) < 
            FlatObj<double>::SmallDifference)
        {
            continue;
        }

        double k = (firstDot.*secondaryAxis - secondDot.*secondaryAxis) / 
            (firstDot.*primaryAxis - secondDot.*primaryAxis);
        double b = (
            firstDot.*primaryAxis * secondDot.*secondaryAxis - 
            firstDot.*secondaryAxis * secondDot.*primaryAxis
            ) / 
            (firstDot.*primaryAxis - secondDot.*primaryAxis);

        Thickness_t thickness = GetThickness();
        for (
            int x = std::min(firstDot.*primaryAxis, secondDot.*primaryAxis); 
            x < std::max(firstDot.*primaryAxis, secondDot.*primaryAxis); 
            ++x)
        {
            for (int deltaX = -thickness; deltaX < thickness; ++deltaX)
            {
                for (int deltaY = -thickness; deltaY < thickness; ++deltaY)
                {
                    if (xDotDiff > yDotDiff)
                    {
                        picture->SetPixel(
                        FlatObj<int>(
                            x + deltaX,
                            k * x + b + deltaY), 
                            clr);
                    }
                    else
                    {
                        picture->SetPixel(
                        FlatObj<int>(
                            k * x + b + deltaY,
                            x + deltaX), 
                        clr);
                    }
                }
            }
        }
    }
    
    if (previousDots.size() >= 2)
        previousDots.clear();
}

/*--------------------------------------------------------------------------*/

void Pencil::EmplaceWindow(AbstractWindow*)
{}

/*--------------------------------------------------------------------------*/

void Pencil::RemoveWindow(AbstractWindow*)
{}

/*--------------------------------------------------------------------------*/

void Eraser::Draw(engineInterface *engine)
{
    button.Draw(engine);
    
    drawLine(Color::WhiteColor);
}

}