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
    if (!ContainsLocal(where))
    {
        //LOGS("Does not contain")
        return;
    }
    unsigned long posInData = arrayPosition(where);
    //LOGS("Pixel was %d\n", *(int*)(pixelsData + posInData));
    memcpy(pixelsData + posInData, &clr, sizeof(clr));
    //LOGS("Pixel is %d\n", *(int*)(pixelsData + posInData));
}

void Picture::Fill(const Color& clr)
{
    int nPixels = pixelsNum();
    for (int i = 0; i < nPixels; ++i)
    {
        memcpy(pixelsData + i, &clr, sizeof(clr));
    }
}

bool Picture::ContainsLocal(const FlatObj<int> &point) const
{
    if (point.x < 0 || point.x > size_.x)
        return false;
    
    if (point.y < 0 || point.y > size_.y)
        return false;
    
    return true;
}

Color Picture::GetPixel(const FlatObj<int>& where) const
{
    if (!ContainsLocal(where))
    {
        return Color::BlackColor;
    }
    int posInData = arrayPosition(where);
    return *reinterpret_cast<Color*>(pixelsData + posInData);
}

const uint8_t* Picture::GetRawData() const
{
    return pixelsData;
}

unsigned long Picture::arrayPosition(const FlatObj<int>& where) const
{
    /*
    LOGS(
        "Position of (%d, %d) in (%d, %d) picture with sizes (%d, %d) should be %lu / %lu", 
        where.x, 
        where.y, 
        origin_.x, 
        origin_.y, 
        size_.x, 
        size_.y, 
        ((where.y - origin_.y) * GetSize().x + (where.x - origin_.x)) * sizeof(Color), 
        pixelsNum())
    */
    return ((where.y) * GetSize().x + (where.x)) * sizeof(Color);
}

unsigned long Picture::pixelsNum() const
{
    return GetSize().x * GetSize().y * sizeof(Color);
}

}