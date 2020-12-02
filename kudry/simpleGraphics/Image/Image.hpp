#pragma once

#include "../color/color.hpp"
#include "../geometry/geometry.hpp"
#include <cstdlib>
#include <cstring>

namespace kudry
{

class Image
{
public:
    Image(const FlatObj& imgSize);

    void SetPixel(const FlatObj& where, const Color& clr);

    Color GetPixel(const FlatObj& where) const;

    FlatObj GetSize() const;

    const uint8_t* GetRawData() const;

private:
    FlatObj imgSize;
    uint8_t* pixelsData;

    int arrayPosition(const FlatObj& where) const;
};

}