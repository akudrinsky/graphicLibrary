#pragma once

#include "../AbstractWindow.hpp"
#include "../Components/Shapes/Rectangle.hpp"
#include "../../simpleGraphics/geometry/geometry.hpp"
#include "../../simpleGraphics/color/color.hpp"

namespace kudry
{

// Class to describe something, that has rectangle shape
class RectangleWindow : public AbstractWindow
{
public:
    RectangleWindow();

    RectangleWindow(
        const FlatObj<int>& center, 
        const FlatObj<int>& size, 
        const Color& backgroundColor = Color::BlackColor
    );

    virtual ~RectangleWindow() override;

    void SetColor(const Color& newColor);

    void SetOrigin(const FlatObj<int>& newOrigin);

    void SetSize(const FlatObj<int>& newSize);

    const Color& GetColor() const;

    Color& GetColor();

    const FlatObj<int>& GetOrigin() const;

    const FlatObj<int>& GetSize() const;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* Canvas) override;

    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) override;

    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) override;

protected:
    RectangleShape shape;
    Color backgroundColor;
};

}