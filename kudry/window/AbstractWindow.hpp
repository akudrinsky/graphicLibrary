#pragma once

#include "../Application/Event.hpp"
#include "../LOGS/logs.hpp"
#include "../engine/settings.hpp"
#include <unordered_set>

namespace kudry
{

/// \brief Basic block for graphical system
class AbstractWindow
{
public:
    virtual ~AbstractWindow() = 0;

    /// \brief Handles event and does some actions, that are unique for each object type
    virtual bool HandleEvent([[maybe_unused]] Event* event) = 0;

    /// \brief Needed for drawing this window and all its subwindows
    virtual void Draw(engineInterface* Canvas) = 0;

    /// \brief For container windows adds window 
    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) = 0;

    /// \brief For container windows deletes window 
    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) = 0;

protected:
    std::unordered_set<AbstractWindow*> subwindows;
    //std::unordered_set<AbstractComponent*> components;
};

class AbstractComponent
{};

}