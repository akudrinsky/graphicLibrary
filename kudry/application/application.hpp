#pragma once

#include "../engine/settings.hpp"
#include "../LOGS/logs.hpp"
#include "../window/AbstractWindow.hpp"
#include "SubscriptionManager/SubscriptionManager.hpp"
//#include "../window/SystemWindow/SystemWindow.hpp"

#include <stdexcept>
#include <unordered_map>

namespace kudry
{

// Singleton.
// Provides high level interface to interact with library.
template <typename Engine>
class Application;

namespace
{
// needed to destroy singleton Application
template <typename Engine>
class applicationDestroyer
{
private:
    Application<Engine>* instance;

public:
    ~applicationDestroyer();
    void initialize(Application<Engine>* app);
};   
}

template <typename Engine>
class Application : private Engine
{
public:
    // Creates application instance with a given name. Can throw std::out_of_bounds if application is to being created not for the first time.
    static Application<Engine>& GetInstance(const char* name = nullptr);

    // Adds new window to the application
    virtual void NewWindow(AbstractWindow* window) override;

    // Deletes window from application (can no longer be drawn or influence something)
    virtual void DeleteWindow(AbstractWindow* window) override;

    // Checks if application already has window inside
    virtual bool IsInside(AbstractWindow* window) override;

    // Main loop with drawings and all the events work. 
    // All preparations must be ended before this function.
    uint8_t Loop();

private:
    friend class applicationDestroyer<Engine>;

    //SystemWindow sysEventSender;

    static Application<Engine>* app;

    //[[deprecated]] std::unordered_set<AbstractWindow*> windows;

    static applicationDestroyer<Engine> destroyer;

    Application(const char* name);

    virtual ~Application();
};

}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//-------------------------------------IMPL-------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


namespace kudry
{

template <typename Engine>
Application<Engine>* Application<Engine>::app = nullptr;

template <typename Engine>
applicationDestroyer<Engine> Application<Engine>::destroyer = {};

//-------------------UNSEEN-------------------
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
}
//-----------------UNSEEN-END-----------------

template <typename Engine>
Application<Engine>::Application(const char* name)
    //:
    //sysEventSender()
{
    Engine::Init(name);
    //windows.insert(&sysEventSender);
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
    if (app == nullptr and name != nullptr) 
    {
        app = new Application(name);
        destroyer.initialize(app);
    }
    else if (app == nullptr and name == nullptr) 
    {
        throw std::out_of_range("Application instance was not initialized");
    }
    else if (app != nullptr and name != nullptr) 
    {
        throw std::out_of_range("Application instance has already been initialized");
    }

    return *app;
}

template <typename Engine>
void Application<Engine>::NewWindow(AbstractWindow* window)
{
    Engine::NewWindow(window);
}

template <typename Engine>
void Application<Engine>::DeleteWindow(AbstractWindow* window)
{
    Engine::DeleteWindow(window);
}

template <typename Engine>
bool Application<Engine>::IsInside(AbstractWindow* window) 
{
    return Engine::IsInside(window);
}

template <typename Engine>
uint8_t Application<Engine>::Loop()
{
    return Engine::Run();
}

}