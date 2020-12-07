#include "Picture.hpp"

namespace kudry
{

Picture::Picture(const FlatObj<int>& position, const FlatObj<int>& imgSize)
    :
    RectangleShape(position, imgSize),
    pixelsData(new uint8_t[sizeof(Color) * imgSize.x * imgSize.y])
{}

void Picture::SetPixel(const FlatObj<int>& where, const Color& clr)
{
    if (!Contains(where))
    {
        return;
    }
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

Color Picture::GetPixel(const FlatObj<int>& where) const
{
    int posInData = arrayPosition(where);
    return *reinterpret_cast<Color*>(pixelsData + posInData);
}

const uint8_t* Picture::GetRawData() const
{
    return pixelsData;
}

int Picture::arrayPosition(const FlatObj<int>& where) const
{
    //LOGS("Position of (%d, %d) in (%d, %d) picture with sizes (%d, %d) should be %lu", where.x, where.y, origin_.x, origin_.y, size_.x, size_.y, (where.y * GetSize().x + where.x) * sizeof(Color))
    return ((where.y - origin_.y) * GetSize().x + (where.x - origin_.x)) * sizeof(Color);
}

int Picture::pixelsNum() const
{
    return GetSize().x * GetSize().y * sizeof(Color);
}

}