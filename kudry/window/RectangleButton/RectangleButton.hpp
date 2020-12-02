#pragma once

#include "../RectangleWindow/RectangleWindow.hpp"
#include "../Text/Text.hpp"
#include "../Components/Clickable.hpp"
#include "../Components/Clickable.hpp"

namespace kudry
{

// Class to describe button with rectangle shape
class RectangleButton : public RectangleWindow
{
public:
    RectangleButton();

    RectangleButton(
        const FlatObj<int>& origin, 
        const FlatObj<int>& size, 
        const Color& backgroundColor = Color::BlackColor
    );

    virtual void OnClick() = 0;

    virtual void OnRelease() = 0;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

protected:
    //ClickableComponent clickInterface;
};

};