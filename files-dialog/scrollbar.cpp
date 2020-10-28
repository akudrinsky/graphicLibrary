#include "../kudry/application/application.hpp"
#include "../kudry/window/RectangleWindow/RectangleWindow.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        printf("Need name if window\n");
        exit(1);
    }

    kudry::Application& app = kudry::Application::Init(argv[1]);

    kudry::AbstractWindow* rect = new kudry::RectangleWindow(
        kudry::FlatObj(100, 100), 
        kudry::FlatObj(100, 100),
        kudry::Red
    );

    app.NewWindow(rect);

    kudry::Event* event = nullptr;

    while ((event = app.PollEvent())->ID != kudry::Event::Close) {
        app.Display();
    }
}