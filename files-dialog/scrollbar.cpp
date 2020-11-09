#include "../kudry/application/application.hpp"
#include "../kudry/engine/SFML/engineSFML.hpp"
#include "../kudry/window/RectangleButton/RectangleButton.hpp"
#include "../kudry/LOGS/logs.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Need name if window\n");
        exit(1);
    }

    auto& app = 
        kudry::Application<kudry::engineSFML>::GetInstance(argv[1]);

    kudry::AbstractWindow* rect = new kudry::RectangleButton(
        kudry::FlatObj(100, 100), 
        kudry::FlatObj(100, 100),
        kudry::Red
    );

    LOGS("font\n")

    kudry::Font font("data/Madina.ttf");

    LOGS("font %s created\n", font.getPathToFont().data())

    auto* text = new kudry::TextWindow(
        &font, 
        "ex",
        20
    );

    LOGS("text created\n")

    text->SetCoords(kudry::FlatObj(500, 500));

    LOGS("coords set\n")

    //app.NewWindow(text);
    app.NewWindow(rect);

    LOGS("loop\n")

    return app.Loop();
}