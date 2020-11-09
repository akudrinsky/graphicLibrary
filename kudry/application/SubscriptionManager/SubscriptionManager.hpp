#include "../Event.hpp"
#include "../../window/AbstractWindow.hpp"
#include <unordered_map>
#include <unordered_set>

namespace kudry
{

class SubscriptionManager
{
public:
    static void Subscribe(AbstractWindow* sender, AbstractWindow* receiver);

    static void Unsubscribe(AbstractWindow* sender, AbstractWindow* receiver);

    static void Send(AbstractWindow* sender, Event* event);

    static void UnsubscribeAll(AbstractWindow* sender);

    static void UnsubscribeFromAll(AbstractWindow* receiver);

private:
    static std::unordered_map<
        AbstractWindow*, 
        std::unordered_set<AbstractWindow*>
    > subscriptions;

    static void checkNullptr(void* ptr);
};

};