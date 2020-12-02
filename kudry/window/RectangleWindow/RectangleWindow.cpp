#include "RectangleWindow.hpp"
#include "../../engine/engineInterface.hpp"
#include "../../LOGS/logs.hpp"

namespace kudry
{

RectangleWindow::RectangleWindow()
    :
    shape(FlatObj<int>(0, 0), FlatObj<int>(0, 0)),
    backgroundColor(kudry::Color::DarkGreyColor)
{}

/*--------------------------------------------------------------------------*/

RectangleWindow::RectangleWindow(
    const FlatObj<int>& center, 
    const FlatObj<int>& size, 
    const Color& backgroundColor
)   :
    shape(center, size),
    backgroundColor(backgroundColor)
{}

/*--------------------------------------------------------------------------*/

RectangleWindow::~RectangleWindow()
{}

/*--------------------------------------------------------------------------*/

bool RectangleWindow::HandleEvent([[maybe_unused]] Event* event)
{
    return event != nullptr;
}

/*--------------------------------------------------------------------------*/

void RectangleWindow::Draw(engineInterface* Canvas)
{
    Canvas->DrawRect(shape, backgroundColor);
    //LOGS("INFO >>> rect was drawn\n")
}

/*--------------------------------------------------------------------------*/

void RectangleWindow::SetColor(const Color& newColor)
{
    backgroundColor = newColor;
}

/*--------------------------------------------------------------------------*/

void RectangleWindow::SetOrigin(const FlatObj<int>& newOrigin)
{
    shape.SetOrigin(newOrigin);
}

/*--------------------------------------------------------------------------*/

void RectangleWindow::SetSize(const FlatObj<int>& newSize)
{
    shape.SetSize(newSize);
}

/*--------------------------------------------------------------------------*/

void RectangleWindow::EmplaceWindow([[maybe_unused]] AbstractWindow* window)
{}

/*--------------------------------------------------------------------------*/

void RectangleWindow::RemoveWindow([[maybe_unused]] AbstractWindow* window)
{}

/*--------------------------------------------------------------------------*/

const Color& RectangleWindow::GetColor() const
{
    return backgroundColor;
}

/*--------------------------------------------------------------------------*/

const FlatObj<int>& RectangleWindow::GetOrigin() const
{
    return shape.GetOrigin();
}

/*--------------------------------------------------------------------------*/

const FlatObj<int>& RectangleWindow::GetSize() const
{
    return shape.GetSize();
}

}