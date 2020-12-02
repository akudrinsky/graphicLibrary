#include "../kudry/Application/Application.hpp"
#include "../kudry/engine/SFML/engineSFML.hpp"
#include "../kudry/window/FigureDrawer/FigureDrawer.hpp"
#include "../kudry/window/Instrument/Instrument.hpp"
#include "../kudry/window/Instrument/Canvas.hpp"
#include "../kudry/LOGS/logs.hpp"

#include <fstream>
#include <string>
#include <streambuf>
#include <sstream>

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Need name if window\n");
        exit(1);
    }

    LOGS("Starting application %s", argv[1])

    auto& app = 
        kudry::Application<kudry::engineSFML>::GetInstance(argv[1]);
    
    kudry::Canvas canvas(
        kudry::FlatObj(200, 100),
        kudry::FlatObj(500, 800),
        kudry::Color::LightGreyColor
    );

    kudry::Pencil pencil;
    pencil.button.SetSize(kudry::FlatObj(50, 50));
    pencil.button.SetOrigin(kudry::FlatObj(50, 50));
    pencil.button.SetColor(kudry::Color::DarkGreyColor);
    
    app.NewWindow(&canvas);
    app.NewWindow(&pencil);

    LOGS("loop\n")

    return app.Loop();
}