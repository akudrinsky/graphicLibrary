#pragma once

#include "../Application/Event.hpp"
#include "../window/Components/Shapes/Rectangle.hpp"
#include "../window/AbstractWindow.hpp"
#include "../window/SystemWindow/SystemWindow.hpp"
#include "../window/Text/Font.hpp"
#include "../window/Text/Text.hpp"
#include "../simpleGraphics/geometry/geometry.hpp"
#include "../simpleGraphics/color/color.hpp"
#include <string_view>

namespace kudry
{

class engineInterface {
public:
    using WindowContainer = std::unordered_set<AbstractWindow*>;

    virtual void DrawRect(
        const RectangleShape rect, 
        const Color& color
    ) = 0;

    virtual void DrawText(const TextWindow* textToDraw) = 0;

    virtual void Init(const std::string_view& windowName) = 0;

    virtual void Destroy() = 0;

    virtual Event* PollEvent() = 0;

    virtual uint8_t Run(WindowContainer& windows) = 0;

private:
};

}