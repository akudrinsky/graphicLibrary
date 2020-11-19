#pragma once

#include "../AbstractWindow.hpp"
#include "../../simpleGraphics/geometry/geometry.hpp"

namespace kudry
{

// Shape interface
class AbstractShapeComponent
{
public:
    virtual bool Contains(const FlatObj& point) = 0;

    // TODO: Draw ?
};

}