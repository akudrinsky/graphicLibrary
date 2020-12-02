#include "Instrument.hpp"
#include "canvasEvents.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"
#include "../../engine/engineInterface.hpp"
#include <utility>

namespace kudry
{

/*--------------------------------------------------------------------------*/

AbstractInstrument::AbstractInstrument()
    :
    canvas(nullptr)
{}

/*--------------------------------------------------------------------------*/

AbstractInstrument* AbstractInstrument::active = nullptr;

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
    clr(Color::RedColor),
    thickness(10)
{
    button.SetColor(clr);
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
            if (canvas == nullptr)
                canvas = realEvent->canvas;

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
        engine->DrawCurve(
            clr,
            thickness,
            previousDots,
            canvas
        );

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