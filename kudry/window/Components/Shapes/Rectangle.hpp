#pragma once
#include "../Shape.hpp"

namespace kudry
{

// Rectangle shape. Has many useful methods.
class RectangleShape : AbstractShapeComponent
{
public:
    RectangleShape() = delete;

    RectangleShape(const FlatObj& origin, const FlatObj& size);
    
    virtual bool Contains(const FlatObj& point) override;

    FlatObj& GetOrigin();

    FlatObj& GetSize();

    const FlatObj& GetOrigin() const;

    const FlatObj& GetSize() const;

    void SetOrigin(const FlatObj& origin);

    void SetSize(const FlatObj& size);

    //virtual void Draw(engineInterface* Canvas) override;

protected:
    FlatObj origin_;
    FlatObj size_;
    // TODO: Draw ?
};

}