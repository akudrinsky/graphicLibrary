//#include "../Instrument/Instrument.hpp"
#include "../Components/Shapes/Rectangle.hpp"
#include "../../simpleGraphics/color/color.hpp"
#include "../RectangleButton/RectangleButton.hpp"

namespace kudry
{

class RectangleDrawer : RectangleButton// : Instrument
{
public:
    RectangleDrawer(
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Color::BlackColor
    );


private:
    RectangleShape shape;
    Color col;
    bool isActive;
};

}