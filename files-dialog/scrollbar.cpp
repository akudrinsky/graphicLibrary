#include "../kudry/application/application.hpp"
#include "../kudry/engine/SFML/engineSFML.hpp"
#include "../kudry/window/RectangleWindow/RectangleWindow.hpp"
#include "../kudry/LOGS/logs.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        printf("Need name if window\n");
        exit(1);
    }

    kudry::Application<kudry::engineSFML>& app = kudry::Application<kudry::engineSFML>::GetInstance(argv[1]);

    kudry::AbstractWindow* rect = new kudry::RectangleWindow(
        kudry::FlatObj(100, 100), 
        kudry::FlatObj(100, 100),
        kudry::Red
    );

    app.NewWindow(rect);

    return app.Loop();
}