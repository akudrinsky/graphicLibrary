#pragma once
#include "../Shape.hpp"

namespace kudry
{

// Rectangle shape. Has many useful methods.
class RectangleShape : AbstractShapeComponent
{
public:
    RectangleShape() = delete;

    RectangleShape(const FlatObj<int>& origin, const FlatObj<int>& size);
    
    virtual bool Contains(const FlatObj<int>& point) const override;

    FlatObj<int>& GetOrigin();

    FlatObj<int>& GetSize();

    const FlatObj<int>& GetOrigin() const;

    const FlatObj<int>& GetSize() const;

    void SetOrigin(const FlatObj<int>& origin);

    void SetSize(const FlatObj<int>& size);

    //virtual void Draw(engineInterface* Canvas) override;

protected:
    FlatObj<int> origin_;
    FlatObj<int> size_;
    // TODO: Draw ?
};

}