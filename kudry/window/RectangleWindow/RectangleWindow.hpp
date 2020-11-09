#pragma once

#include "../AbstractWindow.hpp"
#include "../Components/Shapes/Rectangle.hpp"
#include "../../simpleGraphics/geometry/geometry.hpp"
#include "../../simpleGraphics/color/color.hpp"

namespace kudry
{

class RectangleWindow : public AbstractWindow
{
public:
    RectangleWindow(
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Black
    );

    virtual ~RectangleWindow() override;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* Canvas) override;

    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) override;

    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) override;

protected:
    RectangleShape shape;
    Color backgroundColor;
};

}