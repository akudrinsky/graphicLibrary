#include "../kudry/Application/Application.hpp"
#include "../kudry/engine/SFML/engineSFML.hpp"
#include "../kudry/window/Instrument/Instrument.hpp"
#include "../kudry/window/Instrument/Canvas.hpp"
#include "../kudry/window/Instrument/InstrControllers.hpp"
#include "../kudry/LOGS/logs.hpp"
#include <iostream>

#include <fstream>
#include <string>
#include <streambuf>
#include <sstream>

int main(int argc, char* argv[]) 
{
    std::cerr << (Format("% is equal to %\n"), 10, "tratata");

    if (argc != 2) 
    {
        printf("Need name if window\n");
        exit(1);
    }

    LOGS("Starting application %s", argv[1])

    auto& app = 
        kudry::Application<kudry::engineSFML>::GetInstance(argv[1]);
    
    kudry::Canvas canvas(
        kudry::FlatObj<int>(400, 100),
        kudry::FlatObj<int>(1200, 1000));

    kudry::Pencil pencil;
    pencil.button.SetSize(kudry::FlatObj<int>(50, 50));
    pencil.button.SetOrigin(kudry::FlatObj<int>(50, 50));
    pencil.button.SetColor(kudry::Color::DarkGreyColor);

    kudry::Eraser eraser;
    eraser.button.SetSize(kudry::FlatObj<int>(50, 50));
    eraser.button.SetOrigin(kudry::FlatObj<int>(50, 150));
    eraser.button.SetColor(kudry::Color::DarkGreyColor);

    kudry::Pencil::SetMainColor(kudry::Color::GreenColor);

    kudry::Palette palette(
        kudry::FlatObj<int>(1700, 800),
        kudry::FlatObj<int>(400, 400));
    
    kudry::ThicknessController thckCntrl(
        kudry::FlatObj<int>(1700, 300),
        kudry::FlatObj<int>(400, 400));
    
    app.NewWindow(&canvas);
    app.NewWindow(&pencil);
    app.NewWindow(&eraser);
    app.NewWindow(&palette);
    app.NewWindow(&thckCntrl);

    LOGS("Loop\n")

    return app.Loop();
}