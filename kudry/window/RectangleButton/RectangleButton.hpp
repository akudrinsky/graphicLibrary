#pragma once

#include "../RectangleWindow/RectangleWindow.hpp"
#include "../Text/Text.hpp"
#include "../Comonents/Clickable.hpp"

namespace kudry
{

class RectangleButton : public RectangleWindow
{
public:
    RectangleButton(
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Black
    );



    TextWindow Text;

protected:

};

};