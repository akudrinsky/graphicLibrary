#include "Image.hpp"

namespace kudry
{

Image::Image(const FlatObj& imgSize)
    :
    imgSize(imgSize),
    pixelsData(new uint8_t[imgSize.x * imgSize.y * sizeof(Color)])
{}

void Image::SetPixel(const FlatObj& where, const Color& clr)
{
    int posInData = arrayPosition(where);
    memcpy(pixelsData + posInData, &clr, sizeof(clr));
}

Color Image::GetPixel(const FlatObj& where) const
{
    int posInData = arrayPosition(where);
    return *reinterpret_cast<Color*>(pixelsData + posInData);
}

FlatObj Image::GetSize() const
{
    return imgSize;
}

const uint8_t* Image::GetRawData() const
{
    return pixelsData;
}

int Image::arrayPosition(const FlatObj& where) const
{
    return (where.y * imgSize.x + where.x) * sizeof(Color);
}

}