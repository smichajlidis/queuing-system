#ifndef _QUEUESMANAGER_HPP_
#define _QUEUESMANAGER_HPP_

#include "Queue.hpp"
#include "Window.hpp"
#include "Station.hpp"
#include "Kiosk.hpp"
#include "AllQueuesScreen.hpp"
#include "WindowsManager.hpp"

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <limits>

class QueuesManager {
public:
    QueuesManager();

    ~QueuesManager() = default;

    void addQueue(std::shared_ptr<Queue> queue);
    int systemCreator(const std::string& issue, int limit) const;
    std::shared_ptr<Queue> queuesCreator() const;
    std::shared_ptr<Station> stationsCreator();

private:
    WindowsManager windows_manager;
    std::vector<std::shared_ptr<Queue>> queues;
};

#endif