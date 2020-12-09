#pragma once

namespace kudry 
{

// Just 2d object
template<typename Measure>
class FlatObj 
{
public:
    FlatObj(const Measure& x, const Measure& y)
        :
        x(x),
        y(y)
    {}

    template<typename AnotherMeasure>
    FlatObj(const FlatObj<AnotherMeasure>& other)
        :
        x(other.x),
        y(other.y)
    {}

    FlatObj<Measure> operator+(const FlatObj<Measure>& other)
    {
        return FlatObj<Measure>(this->x + other.x, this->y + other.y);
    }

    Measure x;
    Measure y;

    static constexpr double SmallDifference = 1.0 / 1000.0;
};

}