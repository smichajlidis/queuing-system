#ifndef _QUEUESMANAGER_HPP_
#define _QUEUESMANAGER_HPP_

#include "exceptions/InvalidAmountException.hpp"
#include "exceptions/NotLetterException.hpp"
#include "exceptions/TooManyCharsException.hpp"
#include "Queue.hpp"
#include "Window.hpp"
#include "Station.hpp"
#include "Kiosk.hpp"
#include "AllQueuesScreen.hpp"

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <limits>

class QueuesManager {
private:
    std::vector<std::shared_ptr<Window>> windows;
    std::vector<std::shared_ptr<Queue>> queues;
    std::vector<std::shared_ptr<Station>> stations;
public:
    void addWindow(std::shared_ptr<Window> window);
    void runAllWindows();
    void addQueue(std::shared_ptr<Queue> queue);
    void addStation(std::shared_ptr<Station> station);
    int systemCreator(const std::string& issue, int limit) const;
    std::shared_ptr<Queue> queuesCreator() const;
    std::shared_ptr<Station> stationsCreator();
    QueuesManager();
    ~QueuesManager() {};
};

#endif