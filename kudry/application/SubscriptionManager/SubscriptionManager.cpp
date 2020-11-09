#include "SubscriptionManager.hpp"
#include <stdexcept>

namespace kudry
{

std::unordered_map<
    AbstractWindow*, 
    std::unordered_set<AbstractWindow*>
> SubscriptionManager::subscriptions;

void SubscriptionManager::checkNullptr(void* ptr)
{
    if (ptr == nullptr)
    {
        throw std::invalid_argument("nullptr");
    }
}

void SubscriptionManager::Subscribe(AbstractWindow* sender, AbstractWindow* receiver)
{
    checkNullptr(sender);
    checkNullptr(receiver);

    if (sender == nullptr || receiver == nullptr)
    {

    }
    subscriptions[sender].insert(receiver);
}

void SubscriptionManager::Unsubscribe(AbstractWindow* sender, AbstractWindow* receiver)
{
    checkNullptr(sender);
    checkNullptr(receiver);

    subscriptions[sender].erase(receiver);
}

void SubscriptionManager::Send(AbstractWindow* sender, Event* event)
{
    checkNullptr(sender);
    checkNullptr(event);

    if (subscriptions.count(sender) == 0)
        return;

    for (auto& window : subscriptions[sender])
        window->HandleEvent(event);
}

void SubscriptionManager::UnsubscribeAll(AbstractWindow* sender)
{
    checkNullptr(sender);
    subscriptions[sender].clear();
}

void SubscriptionManager::UnsubscribeFromAll(AbstractWindow* receiver)
{
    checkNullptr(receiver);
    if (subscriptions.size() == 0)
        return;

    for (auto& [_, receivers] : subscriptions)
    {
        if (receivers.count(receiver) != 0)
        {
            receivers.erase(receiver);
        }
    }
}


};