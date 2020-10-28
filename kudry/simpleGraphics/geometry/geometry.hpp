#pragma once

namespace kudry 
{

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