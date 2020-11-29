#include "RectangleWindow.hpp"
#include "../../engine/engineInterface.hpp"
#include "../../LOGS/logs.hpp"

namespace kudry
{

RectangleWindow::RectangleWindow(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor
)   :
    shape(center, size),
    backgroundColor(backgroundColor)
{}

RectangleWindow::~RectangleWindow()
{}

bool RectangleWindow::HandleEvent([[maybe_unused]] Event* event)
{
    return event != nullptr;
}

void RectangleWindow::Draw(engineInterface* Canvas)
{
    Canvas->DrawRect(shape, backgroundColor);
    //LOGS("INFO >>> rect was drawn\n")
}

void RectangleWindow::SetColor(const const Color& newColor)
{
    backgroundColor = newColor;
}

void RectangleWindow::SetOrigin(const FlatObj& newOrigin)
{
    shape.SetOrigin(newOrigin);
}

void RectangleWindow::SetSize(const FlatObj& newSize)
{
    shape.SetSize(newSize);
}

void RectangleWindow::EmplaceWindow([[maybe_unused]] AbstractWindow* window)
{}

void RectangleWindow::RemoveWindow([[maybe_unused]] AbstractWindow* window)
{}

}