#include "Picture.hpp"

namespace kudry
{

Picture::Picture(const FlatObj& position, const FlatObj& imgSize)
    :
    RectangleShape(position, imgSize),
    pixelsData(new uint8_t[sizeof(Color) * pixelsNum()])
{}

void Picture::SetPixel(const FlatObj& where, const Color& clr)
{
    int posInData = arrayPosition(where);
    memcpy(pixelsData + posInData, &clr, sizeof(clr));
}

void Picture::Fill(const Color& clr)
{
    int nPixels = pixelsNum();
    for (int i = 0; i < nPixels; ++i)
    {
        memcpy(pixelsData + i, &clr, sizeof(clr));
    }
}

Color Picture::GetPixel(const FlatObj& where) const
{
    int posInData = arrayPosition(where);
    return *reinterpret_cast<Color*>(pixelsData + posInData);
}

const uint8_t* Picture::GetRawData() const
{
    return pixelsData;
}

int Picture::arrayPosition(const FlatObj& where) const
{
    return (where.y * GetSize().x + where.x) * sizeof(Color);
}

int Picture::pixelsNum() const
{
    return GetSize().x * GetSize().y;
}

}