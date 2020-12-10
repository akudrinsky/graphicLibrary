#include "InstrControllers.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

Palette::Palette(const FlatObj<int> &position, const FlatObj<int> &size)
    :
    RectangleWindow(position, size, Color(150, 150, 150)),
    R_Scrlbar(
        position + FlatObj<int>(size.x / 7, size.y / 3), 
        FlatObj<int>(size.x / 7, (11 * size.y) / 18), 
        Color::BlackColor, 
        Color::RedColor),
    G_Scrlbar(
        position + FlatObj<int>((3 * size.x) / 7, size.y / 3), 
        FlatObj<int>(size.x / 7, (11 * size.y) / 18), 
        Color::BlackColor, 
        Color::GreenColor),
    B_Scrlbar(
        position + FlatObj<int>((5 * size.x) / 7, size.y / 3), 
        FlatObj<int>(size.x / 7, (11 * size.y) / 18), 
        Color::BlackColor, 
        Color::BlueColor),
    resultClr(
        position + FlatObj<int>(size.x / 7, size.y / 18), 
        FlatObj<int>((5 * size.x) / 7, (2 * size.y) / 9), 
        Color::WhiteColor)
{
    SubscriptionManager::Subscribe(&R_Scrlbar, this);
    SubscriptionManager::Subscribe(&G_Scrlbar, this);
    SubscriptionManager::Subscribe(&B_Scrlbar, this);
}

/*--------------------------------------------------------------------------*/

bool Palette::HandleEvent(Event *event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            //LOGS("Start")
            R_Scrlbar.HandleEvent(event);
            G_Scrlbar.HandleEvent(event);
            B_Scrlbar.HandleEvent(event);
            //LOGS("End")
            break;
        }
        case Event::User:
        {
            //LOGS("Palette has received user event\n")
            ScrollbarEvent* realEvent = static_cast<ScrollbarEvent*>(event);

            if (realEvent->ReceivedFrom == &R_Scrlbar)
            {
                resultClr.GetColor().Red = 255 * realEvent->Position;
            }
            else if (realEvent->ReceivedFrom == &G_Scrlbar)
            {
                resultClr.GetColor().Green = 255 * realEvent->Position;
            }
            else if (realEvent->ReceivedFrom == &B_Scrlbar)
            {
                resultClr.GetColor().Blue = 255 * realEvent->Position;
            }

            AbstractInstrument::SetMainColor(resultClr.GetColor());
            
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

void Palette::Draw(engineInterface* engine)
{
    RectangleWindow::Draw(engine);
    R_Scrlbar.Draw(engine);
    G_Scrlbar.Draw(engine);
    B_Scrlbar.Draw(engine);
    resultClr.Draw(engine);
}

/*--------------------------------------------------------------------------*/

ThicknessController::ThicknessController(
    const FlatObj<int> &position, 
    const FlatObj<int> &size)
    :
    RectangleWindow(position, size, Color::DarkGreyColor),
    thckCntrl(
        position + FlatObj<int>((2 * size.x) / 3, size.y / 7), 
        FlatObj<int>(size.x / 6, (5 * size.y) / 7), 
        Color::BlackColor, 
        Color::LightGreyColor
    ),
    resultThck(
        position + FlatObj<int>(
            size.x / 4 - AbstractInstrument::GetThickness(), size.y / 2 - AbstractInstrument::GetThickness()), 
            FlatObj<int>(2 * AbstractInstrument::GetThickness(), 2 * AbstractInstrument::GetThickness()), 
        Color::LightGreyColor
    )
{
    SubscriptionManager::Subscribe(&thckCntrl, this);
}

/*--------------------------------------------------------------------------*/

bool ThicknessController::HandleEvent(Event *event)
{
    switch (event->GetEventType())
    {
        case Event::Mouse:
        {
            //LOGS("Start")
            thckCntrl.HandleEvent(event);
            //LOGS("End")
            break;
        }
        case Event::User:
        {
            //LOGS("Palette has received user event\n")
            ScrollbarEvent* realEvent = static_cast<ScrollbarEvent*>(event);

            if (realEvent->ReceivedFrom == &thckCntrl)
            {
                AbstractInstrument::SetThickness(
                    AbstractInstrument::GetMaxThickness() * realEvent->Position);

                const FlatObj<int>& size = RectangleWindow::GetSize();
                const FlatObj<int>& position = RectangleWindow::GetOrigin();

                resultThck.SetOrigin(
                    position + FlatObj<int>(
                        size.x / 4 - AbstractInstrument::GetThickness(), 
                        size.y / 2 - AbstractInstrument::GetThickness()));

                resultThck.SetSize(
                    FlatObj<int>(
                        2 * AbstractInstrument::GetThickness(), 
                        2 * AbstractInstrument::GetThickness()));
            }
            
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

void ThicknessController::Draw(engineInterface *engine)
{
    RectangleWindow::Draw(engine);
    thckCntrl.Draw(engine);
    resultThck.Draw(engine);
}

}