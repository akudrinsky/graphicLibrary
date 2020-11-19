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
    RectangleButton(
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Black
    );

    virtual void OnClick() = 0;

    virtual void OnRelease() = 0;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

protected:
    ClickableComponent clickInterface;
};

};