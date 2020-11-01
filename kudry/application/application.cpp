#include "application.hpp"
#include "../LOGS/logs.hpp"

namespace kudry
{

template <typename Engine>
Application<Engine>* Application<Engine>::app = nullptr;

template <typename Engine>
applicationDestroyer<Engine> Application<Engine>::destroyer = {};

namespace
{
template <typename Engine>
applicationDestroyer<Engine>::~applicationDestroyer() 
{
    delete instance;
}

template <typename Engine>
void applicationDestroyer<Engine>::initialize(Application<Engine>* app)
{
    instance = app;
}
};

template <typename Engine>
Application<Engine>::Application(const char* name)
{
    Engine::Init(name);
    LOGS("INFO >>> application was created\n")
}

template <typename Engine>
Application<Engine>::~Application()
{
    Engine::Destroy();
}

template <typename Engine>
Application<Engine>& Application<Engine>::GetInstance(const char* name) 
{
    if (app == nullptr and name != nullptr) {
        app = new Application(name);
        destroyer.initialize(app);
    }
    else if (app == nullptr and name == nullptr) {
        throw std::out_of_range("Application instance was not initialized");
    }
    else if (app != nullptr and name != nullptr) {
        throw std::out_of_range("Application instance has already been initialized");
    }

    return *app;
}

template <typename Engine>
void Application<Engine>::NewWindow(AbstractWindow* window)
{
    windows.emplace(window);
}

template <typename Engine>
void Application<Engine>::DeleteWindow(AbstractWindow* window)
{
    windows.erase(window);
}

template <typename Engine>
bool Application<Engine>::IsInside(AbstractWindow* window) 
{
    return windows.find(window) != windows.end();
}

template <typename Engine>
uint8_t Application<Engine>::Loop()
{
    return Engine::Run(windows);
}

};