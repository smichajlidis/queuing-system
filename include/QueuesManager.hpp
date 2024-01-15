#ifndef _QUEUESMANAGER_HPP_
#define _QUEUESMANAGER_HPP_
#include "exceptions/InvalidNumberOfStationsException.hpp"
#include "Queue.hpp"
#include "Window.hpp"
#include "Station.hpp"
#include "Kiosk.hpp"
#include "AllQueuesScreen.hpp"
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <limits>

class QueuesManager {
private:
    std::vector<std::shared_ptr<Window>> windows;
    std::vector<std::shared_ptr<Queue>> queues;
public:
    void addWindow(std::shared_ptr<Window> window);
    void runAllWindows();
    void addQueue(std::shared_ptr<Queue> queue);
    QueuesManager();
    ~QueuesManager() {};
};

#endif