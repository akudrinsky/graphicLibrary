#include "../kudry/Application/Application.hpp"
#include "../kudry/engine/SFML/engineSFML.hpp"
#include "../kudry/window/FigureDrawer/FigureDrawer.hpp"
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

    auto& app = 
        kudry::Application<kudry::engineSFML>::GetInstance(argv[1]);

    kudry::RectangleDrawer rectdrw(
        {100, 100}, 
        {100, 100}, 
        kudry::Color::LightGreyColor);
    
    app.NewWindow(&rectdrw);

    LOGS("loop\n")

    return app.Loop();
}