#include "RectangleWindow.hpp"

namespace kudry
{

RectangleWindow::RectangleWindow(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor
)   :
    center(center),
    size(size),
    backgroundColor(backgroundColor)
{}

RectangleWindow::~RectangleWindow()
{
    center.x = 0;
    center.y = 0;

    size.x = 0;
    size.y = 0;
}

bool RectangleWindow::HandleEvent(Event* event)
{
    return event != nullptr;
}

void RectangleWindow::Draw()
{
    Engine::DrawRect(center, size, backgroundColor);
}

void RectangleWindow::EmplaceWindow(AbstractWindow* window)
{
    window = nullptr;
}

void RectangleWindow::RemoveWindow(AbstractWindow* window)
{
    window = nullptr;
}

};