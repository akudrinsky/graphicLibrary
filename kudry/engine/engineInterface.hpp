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

// Interface for connecting high-level Application interface with low-level drawing library
class engineInterface {
public:
    // Contains pointers to AbstractWindow's
    using WindowContainer = std::unordered_set<AbstractWindow*>;

    // Draws rectangle with given characteristics
    virtual void DrawRect(
        const RectangleShape rect, 
        const Color& color
    ) = 0;

    // Draws text with given characteristics
    virtual void DrawText(
        const TextWindow* textToDraw, 
        const RectangleShape* canvas = nullptr,
        const Color* backgroundColor = nullptr,
        double offset = 0.0
    ) = 0;

    // Inits the low-level library
    virtual void Init(const std::string_view& windowName) = 0;

    // Frees all resources of a low-level library
    virtual void Destroy() = 0;

    [[deprecated]]
    virtual Event* PollEvent() = 0;

    // Main loop
    // @param windows - set of windows, that are needed ot be drawn
    virtual uint8_t Run(WindowContainer& windows) = 0;

private:
};

}