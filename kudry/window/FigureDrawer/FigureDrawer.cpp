#include "FigureDrawer.hpp"
#include "../../engine/engineInterface.hpp"

namespace kudry
{

RectangleDrawer::RectangleDrawer(
    const FlatObj &center, 
    const FlatObj &size, 
    const Color &backgroundColor)
    :
    RectangleButton(center, size, backgroundColor),
    managingShape({0.0, 0.0}, {0.0, 0.0}),
    col(Color::DarkGreyColor),
    isActive(false),
    startingTouch(-1.0, -1.0)
{}

void RectangleDrawer::OnClick()
{}

void RectangleDrawer::OnRelease()
{
    isActive = true;
}

void RectangleDrawer::OnMove(FlatObj coords)
{
    auto& origin = managingShape.GetOrigin();
    if (origin.x <= 0.001 and origin.y <= 0.001)
        return;
    managingShape.SetSize({coords.x - origin.x, coords.y - origin.y});
}

void RectangleDrawer::OnDrawingClick(FlatObj coords)
{
    managingShape.SetOrigin(coords);
    //LOGS("Active click: coords are (%5.5lf, %5.5lf)", managingShape.GetOrigin().x,  managingShape.GetOrigin().y)
}

void RectangleDrawer::OnDrawingRelease(FlatObj)
{
    //LOGS("Active release")
    isActive = false;
    managingShape.SetOrigin({0.0, 0.0});
    managingShape.SetSize({0.0, 0.0});
}

void RectangleDrawer::Draw(engineInterface* Canvas)
{
    RectangleButton::Draw(Canvas);
    if (isActive)
    {
        Canvas->DrawRect(managingShape, col);
    }
}

bool RectangleDrawer::HandleEvent(Event *event)
{
    switch (event->ID)
    {
        case Event::MousePressed:
        {
            if (isActive)
            {
                OnDrawingClick(event->Data.Click.coord);
                return true;
            }
            //LOGS("Not active MousePressed")
            if (!shape.Contains(event->Data.Click.coord))
                return false;
            OnClick();
            return true;
            break;
        }
        case Event::MouseReleased:
        {
            if (isActive)
            {
                OnDrawingRelease(event->Data.Click.coord);
                return true;
            }
            //LOGS("Not active MouseReleased")
            if (!shape.Contains(event->Data.Click.coord))
                return false;
            OnRelease();
            return true;
            break;
        }
        case Event::MouseMoved:
        {
            if (!isActive)
                return false;

            OnMove(event->Data.Click.coord);
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


}