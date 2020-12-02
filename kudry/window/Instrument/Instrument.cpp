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

const Color& AbstractInstrument::GetMainColor() const
{
    return mainColor;
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
    thickness(10)
{
    button.SetColor(Color::RedColor);
    button.SetOrigin(FlatObj(10, 10));
    button.SetSize(FlatObj(100, 100));
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
            LOGS("Instrument %p has received user event\n", GetActive())
            CanvasEvent* realEvent = static_cast<CanvasEvent*>(event);
            previousDots.push_back(realEvent->pos);
            if (picture == nullptr)
                picture = realEvent->pict;

            LOGS("Saw %lu dots", previousDots.size())

            //drawLine(realEvent);

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

    if (previousDots.size() > 1)
    {
        for (int i = 0; i < (long)previousDots.size() - 1; ++i)
        {
            const FlatObj& first = previousDots[i];
            const FlatObj& second = previousDots[i + 1];
            LOGS("Points %d -> %d", i, i + 1)
            double k = std::numeric_limits<double>::max();
            if (fabs(first.x - second.x) > FlatObj::SmallDifference)
            {
                k = (first.y - second.y) / 
                    (first.x - second.x);
            }

            double b = (first.x * second.y - first.y * second.x) / (first.x - second.x);

            const Color& clr = GetMainColor();

            for (int x = first.x; x < second.x; ++x)
            {
                for (int deltaX = -thickness; deltaX < thickness; ++deltaX)
                {
                    for (int deltaY = -thickness; deltaY < thickness; ++deltaY)
                    {
                        picture->SetPixel(
                            FlatObj(
                                x + deltaX,
                                k * x + b + deltaY
                            ), 
                            clr
                        );
                    }
                }
            }
        }

        previousDots.clear();
    }
}

/*--------------------------------------------------------------------------*/

void Pencil::drawLine(CanvasEvent* event)
{
    if (previousDots.size() == 0)
    {
        // Here I state that if there is no dots, 
        // then we will draw spline basing on an assumption,
        // that first dot will we used in spline twice.
        previousDots.push_back(event->pos);
        //previousDots.push_back(event->pos);
    }
    else if (previousDots.size() == 1)
    {


    }
    else
    {
        LOGS("Unknown size of prev dots: %lu", previousDots.size())
    }
}

/*--------------------------------------------------------------------------*/

void Pencil::EmplaceWindow(AbstractWindow*)
{}

/*--------------------------------------------------------------------------*/

void Pencil::RemoveWindow(AbstractWindow*)
{}

}