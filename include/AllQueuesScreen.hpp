#ifndef _ALLQUEUESSCREEN_HPP_
#define _ALLQUEUESSCREEN_HPP_

#include "Window.hpp"
#include "Station.hpp"
#include "Queue.hpp"

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class AllQueuesScreen: public Window {
public:
    AllQueuesScreen(const sf::VideoMode& mode, const std::string& newTitle, const std::vector<std::shared_ptr<Queue>>& relatedQueues, const std::vector<std::shared_ptr<Station>>& stations)
    : Window(mode, newTitle, relatedQueues), activeStations(stations) {}

    virtual void processEvents() override;
    virtual void render() override;
    
private:
    std::vector<std::shared_ptr<Station>> activeStations; // vector of all active stations for display datas
};

#endif