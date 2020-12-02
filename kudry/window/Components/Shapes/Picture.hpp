#pragma once

#include "Rectangle.hpp"
#include <cstdlib>
#include <cstring>

namespace kudry
{

class Picture : public RectangleShape
{
public:
    Picture(const FlatObj& position, const FlatObj& imgSize);

    void SetPixel(const FlatObj& where, const Color& clr);

    void Fill(const Color& clr);

    Color GetPixel(const FlatObj& where) const;

    const uint8_t* GetRawData() const;

private:
    uint8_t* pixelsData;
    
    int arrayPosition(const FlatObj& where) const;

    int pixelsNum() const;
};

}