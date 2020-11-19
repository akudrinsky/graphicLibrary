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
};

}