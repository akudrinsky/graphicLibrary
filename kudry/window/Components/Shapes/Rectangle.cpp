#include "Rectangle.hpp"

namespace kudry
{

RectangleShape::RectangleShape(const FlatObj<int>& origin, const FlatObj<int>& size)
    :
    origin_(origin),
    size_(size)
{}

bool RectangleShape::Contains(const FlatObj<int>& point) const
{
    //LOGS("check x : %d in [%d, %d]\n", point.x, origin_.x, origin_.x + size_.x)
    // check x axis
    if (point.x < origin_.x or point.x > origin_.x + size_.x)
        return false;

    //LOGS("check y : %d in [%d, %d]\n", point.y, origin_.y, origin_.y + size_.y)
    // check y axis
    if (point.y < origin_.y or point.y > origin_.y + size_.y)
        return false;
    
    //LOGS("hooray\n")

    return true;
}

FlatObj<int>& RectangleShape::GetOrigin()
{
    return origin_;
}

FlatObj<int>& RectangleShape::GetSize()
{
    return size_;
}

const FlatObj<int>& RectangleShape::GetOrigin() const
{
    return origin_;
}

const FlatObj<int>& RectangleShape::GetSize() const
{
    return size_;
}

void RectangleShape::SetOrigin(const FlatObj<int>& origin)
{
    origin_ = origin;
}

void RectangleShape::SetSize(const FlatObj<int>& size)
{
    size_ = size;
}

}