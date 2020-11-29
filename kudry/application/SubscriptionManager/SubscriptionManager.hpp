#include "../Event.hpp"
#include "../../window/AbstractWindow.hpp"
#include <unordered_map>
#include <unordered_set>

namespace kudry
{

// Interface to manage events between windows.
class SubscriptionManager
{
public:
    // Allows receiver see all events sent from sender
    static void Subscribe(AbstractWindow* sender, AbstractWindow* receiver);

    // After this func, receiver can not longer get events from sender
    static void Unsubscribe(AbstractWindow* sender, AbstractWindow* receiver);

    // This function sends an event to all subsribed windows
    static void Send(AbstractWindow* sender, Event* event);

    // This function sends an event to exact window
    static void SendTo(AbstractWindow* receiver, Event* event);

    // Unsubscribes all windows from this one (useful when window is destroyed)
    static void UnsubscribeAll(AbstractWindow* sender);

    // VERY ineffective function
    // Unsubscribes window from all windows (useful when window is destroyed)
    static void UnsubscribeFromAll(AbstractWindow* receiver);

private:
    static std::unordered_map<
        AbstractWindow*, 
        std::unordered_set<AbstractWindow*>
    > subscriptions;

    static void checkNullptr(void* ptr);
};

};