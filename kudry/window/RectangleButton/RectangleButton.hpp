#pragma once

#include "../RectangleWindow/RectangleWindow.hpp"
#include "../Text/Text.hpp"
#include "../Components/Clickable.hpp"

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

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

protected:
    ClickableComponent clickInterface;
};

};