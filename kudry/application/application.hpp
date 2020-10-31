#pragma once

#include "../engine/settings.hpp"
#include "../window/AbstractWindow.hpp"
#include <stdexcept>
#include <unordered_map>

namespace kudry
{

class Application;

namespace
{
class applicationDestroyer
{
private:
    Application* instance;

public:
    ~applicationDestroyer();
    void initialize(Application* app);
};   
}

class Application 
{
public:
    // std::out_of_bounds
    static Application& GetInstance();

    // exception-safe
    static Application& Init(const char* name);

    void NewWindow(AbstractWindow* window);

    void DeleteWindow(AbstractWindow* window);

    bool IsInside(AbstractWindow* window);

    uint8_t Run();

private:
    friend class applicationDestroyer;

    static Application* app;

    std::unordered_set<AbstractWindow*> windows;

    static applicationDestroyer destroyer;

    Application(const char* name);

    ~Application();
};

};