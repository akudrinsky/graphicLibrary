#pragma once

#include "Rectangle.hpp"
#include "../../../simpleGraphics/color/color.hpp"
#include <cstdlib>
#include <cstring>

namespace kudry
{

class Picture : public RectangleShape
{
public:
    Picture(const FlatObj<int>& position, const FlatObj<int>& imgSize);

    void SetPixel(const FlatObj<int>& where, const Color& clr);

    void Fill(const Color& clr);

    Color GetPixel(const FlatObj<int>& where) const;

    const uint8_t* GetRawData() const;

private:
    uint8_t* pixelsData;
    
    unsigned long arrayPosition(const FlatObj<int>& where) const;

    unsigned long pixelsNum() const;
};

}