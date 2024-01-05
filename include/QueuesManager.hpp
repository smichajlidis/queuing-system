#ifndef _QUEUESMANAGER_HPP_
#define _QUEUESMANAGER_HPP_
#include "Queue.hpp"
#include "Window.hpp"
#include "Station.hpp"
#include <memory>
#include <vector>
#include <string>

class QueuesManager {
private:
    std::vector<std::shared_ptr<Window>> windows;
    std::vector<Queue> queues;
public:
    void addWindow(std::shared_ptr<Window> window);
    void addQueue(Queue& queue);
    QueuesManager();
    ~QueuesManager() {};
};

#endif