#include "Rectangle.hpp"

namespace kudry
{

RectangleShape::RectangleShape(FlatObj origin, FlatObj size)
    :
    origin_(origin),
    size_(size)
{}

bool RectangleShape::Contains(const FlatObj& point)
{
    //LOGS("check x\n")
    // check x axis
    if (point.x < origin_.x or point.x > origin_.x + size_.x)
        return false;

    //LOGS("check y\n")
    // check y axis
    if (point.y < origin_.y or point.y > origin_.y + size_.y)
        return false;
    
    //LOGS("hooray\n")

    return true;
}

FlatObj& RectangleShape::GetOrigin()
{
    return origin_;
}

FlatObj& RectangleShape::GetSize()
{
    return size_;
}

const FlatObj& RectangleShape::GetOrigin() const
{
    return origin_;
}

const FlatObj& RectangleShape::GetSize() const
{
    return size_;
}

}