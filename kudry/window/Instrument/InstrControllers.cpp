#include "InstrControllers.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

Palette::Palette(const FlatObj<int> &position, const FlatObj<int> &size)
    :
    RectangleWindow(position, size, Color(150, 150, 150)),
    R_Scrlbar(position + FlatObj<int>(size.x / 7, size.y / 3), FlatObj<int>(size.x / 7, (11 * size.y) / 18), Color::BlackColor, Color::RedColor),
    G_Scrlbar(position + FlatObj<int>((3 * size.x) / 7, size.y / 3), FlatObj<int>(size.x / 7, (11 * size.y) / 18), Color::BlackColor, Color::GreenColor),
    B_Scrlbar(position + FlatObj<int>((5 * size.x) / 7, size.y / 3), FlatObj<int>(size.x / 7, (11 * size.y) / 18), Color::BlackColor, Color::BlueColor),
    resultClr(position + FlatObj<int>(size.x / 7, size.y / 18), FlatObj<int>((5 * size.x) / 7, (2 * size.y) / 9), Color::WhiteColor)
{
    SubscriptionManager::Subscribe(&R_Scrlbar, this);
    SubscriptionManager::Subscribe(&G_Scrlbar, this);
    SubscriptionManager::Subscribe(&B_Scrlbar, this);
}

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

void Palette::Draw(engineInterface* engine)
{
    RectangleWindow::Draw(engine);
    R_Scrlbar.Draw(engine);
    G_Scrlbar.Draw(engine);
    B_Scrlbar.Draw(engine);
    resultClr.Draw(engine);
}

}