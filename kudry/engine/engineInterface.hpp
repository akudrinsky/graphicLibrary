#pragma once

#include "../Application/Event.hpp"
#include "../window/Components/Shapes/Rectangle.hpp"
#include "../window/AbstractWindow.hpp"
#include "../window/Instrument/Canvas.hpp"
#include "../window/SystemWindow/SystemWindow.hpp"
#include "../window/Text/Font.hpp"
#include "../window/Text/Text.hpp"
#include "../simpleGraphics/geometry/geometry.hpp"
#include "../simpleGraphics/color/color.hpp"
#include <string_view>
#include <deque>

namespace kudry
{

// Interface for connecting high-level Application interface with low-level drawing library
class engineInterface {
public:
    // Contains pointers to AbstractWindow's
    using WindowContainer = std::unordered_set<AbstractWindow*>;

    // Adds window to set of attached windows
    virtual void NewWindow(AbstractWindow* window) = 0;

    // Deletes window from set of attached windows
    virtual void DeleteWindow(AbstractWindow* window) = 0;

    // Check if window is attached
    virtual bool IsInside(AbstractWindow* window) = 0;

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

    // Draws line between points
    virtual void DrawLine(
        const Color& clr,
        Thickness_t thickness,
        const FlatObj& from,
        const FlatObj& to,
        const Canvas* canvas = nullptr
    ) = 0;

    // Draws curve between points
    virtual void DrawCurve(
        const Color& clr,
        Thickness_t thickness,
        const std::deque<FlatObj>& points,
        const Canvas* canvas = nullptr
    ) = 0;

    // Draws canvas
    virtual void DrawCanvas(const Canvas* canvas) = 0;

    // Inits the low-level library
    virtual void Init(const std::string_view& windowName) = 0;

    // Frees all resources of a low-level library
    virtual void Destroy() = 0;

    // Main loop
    virtual uint8_t Run() = 0;

private:
};

}