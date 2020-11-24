//#include "../Instrument/Instrument.hpp"
#include "../Components/Shapes/Rectangle.hpp"
#include "../../simpleGraphics/color/color.hpp"
#include "../RectangleButton/RectangleButton.hpp"

namespace kudry
{

class RectangleDrawer : public RectangleButton // : Instrument
{
public:
    RectangleDrawer(
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Color::BlackColor
    );

    virtual void Draw(engineInterface* Canvas) override;

    virtual void OnClick() override;

    virtual void OnRelease() override;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

private:
    RectangleShape managingShape;
    Color col;
    bool isActive;
    FlatObj startingTouch;

    void OnDrawingClick(FlatObj coords);

    void OnDrawingRelease(FlatObj coords);

    void OnMove(FlatObj coords);
};

}