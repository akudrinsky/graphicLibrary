#pragma once

namespace kudry 
{

// Just 2d object
class FlatObj 
{
public:
    FlatObj(const double& x, const double& y)
        :
        x(x),
        y(y)
    {}

    double x;
    double y;

    static constexpr double SmallDifference = 1.0 / 1000.0;
};

}