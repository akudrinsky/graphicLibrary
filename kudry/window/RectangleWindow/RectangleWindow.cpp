#include "RectangleWindow.hpp"

namespace kudry
{

RectangleWindow::RectangleWindow
(
    const FlatObj& center, 
    const FlatObj& size, 
    const Color& backgroundColor
)   :
    center(center),
    size(size),
    backgroundColor(backgroundColor)
{}

};