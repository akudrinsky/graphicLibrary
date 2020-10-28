#pragma once

#include "../simpleGraphics/geometry/geometry.hpp"
#include "../simpleGraphics/color/color.hpp"

namespace kudry
{

class engineInterface {
public:
    static void DrawRect
    (
        const FlatObj& coords, 
        const FlatObj& size, 
        const Color& color
    );

    static void DrawText
    (
        const FlatObj& coords, 
        const Color& color
    );

    static void Init(const char* windowName);

    static void Destroy();

    
private:
    ~engineInterface() = delete;
};

}