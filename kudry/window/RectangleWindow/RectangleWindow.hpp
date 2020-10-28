#pragma once

#include "../AbstractWindow.hpp"
#include "../../simpleGraphics/geometry/geometry.hpp"
#include "../../simpleGraphics/color/color.hpp"
#include "../../simpleGraphics/color/color.hpp"

namespace kudry
{

class RectangleWindow : public AbstractWindow
{
public:
    RectangleWindow
    (
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Black
    );

protected:
    FlatObj center;
    FlatObj size;
    Color backgroundColor;
};

};