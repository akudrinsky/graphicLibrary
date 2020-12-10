#include "Instrument.hpp"
#include "../Scrollbar/Scrollbar.hpp"

namespace kudry
{

class Palette : public RectangleWindow
{
public:
    Palette(const FlatObj<int>& position, const FlatObj<int>& size);

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* engine) override;

private:
    Scrollbar R_Scrlbar;
    Scrollbar G_Scrlbar;
    Scrollbar B_Scrlbar;
    RectangleWindow resultClr;
};

class ThicknessController : public RectangleWindow
{
public:
    ThicknessController(const FlatObj<int>& position, const FlatObj<int>& size);

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* engine) override;

private:
    Scrollbar thckCntrl;
    RectangleWindow resultThck;
};

}