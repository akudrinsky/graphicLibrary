#include "../kudry/Application/Application.hpp"
#include "../kudry/engine/SFML/engineSFML.hpp"
#include "../kudry/window/Scrollbar/Scrollbar.hpp"
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

    kudry::Scrollbar scrlbar(
        kudry::FlatObj(100, 200),
        kudry::FlatObj(70, 700),
        kudry::Blue,
        kudry::Red
    );

    app.NewWindow(&scrlbar);

    LOGS("loop\n")

    return app.Loop();
}