#pragma once

#include "../application/Event.hpp"
#include "../window/AbstractWindow.hpp"
#include "../simpleGraphics/geometry/geometry.hpp"
#include "../simpleGraphics/color/color.hpp"

namespace kudry
{

class engineInterface {
public:
    using WindowContainer = std::unordered_set<AbstractWindow*>;

    virtual void DrawRect
    (
        const FlatObj& coords, 
        const FlatObj& size, 
        const Color& color
    ) = 0;

    virtual void Init(const char* windowName) = 0;

    virtual void Destroy() = 0;

    virtual Event* PollEvent() = 0;

    virtual uint8_t Run(WindowContainer& windows) = 0;

private:
};

}