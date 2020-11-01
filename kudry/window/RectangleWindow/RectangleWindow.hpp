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
    RectangleWindow(
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Black
    );

    virtual ~RectangleWindow() override;

    virtual bool HandleEvent(Event* event) override;

    virtual void Draw(engineInterface* Canvas) override;

    virtual void EmplaceWindow(AbstractWindow* window) override;

    virtual void RemoveWindow(AbstractWindow* window) override;

protected:
    FlatObj center;
    FlatObj size;
    Color backgroundColor;
};

};