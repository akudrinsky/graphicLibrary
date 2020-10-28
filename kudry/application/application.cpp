#include "application.hpp"


namespace kudry
{

Application* Application::app = nullptr;

applicationDestroyer Application::destroyer = {};

applicationDestroyer::~applicationDestroyer() 
{
    delete instance;
}

void applicationDestroyer::initialize(Application* app)
{
    instance = app;
}

Application& Application::GetInstance() 
{
    if (app == nullptr) {
        throw std::out_of_range("Application instance was not initialized");
    }
    return *app;
}

Application::Application(const char* name)
{
    Engine::Init(name);
}

Application& Application::Init(const char* name) {
    if (app == nullptr) {
        app = new Application(name);
        destroyer.initialize(app);
    }
    return *app;
}

void Application::NewWindow(AbstractWindow* window)
{
    windows.emplace(window);
}

void Application::DeleteWindow(AbstractWindow* window)
{
    windows.erase(window);
}

bool Application::IsInside(AbstractWindow* window) 
{
    return windows.find(window) != windows.end();
}

};