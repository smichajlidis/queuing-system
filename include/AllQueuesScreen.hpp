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
    AllQueuesScreen(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& related_queues, const std::vector<std::shared_ptr<Station>>& stations)
    : Window(mode, title, related_queues), active_stations (stations) {}

    virtual void processEvents() override;
    virtual void render() override;

private:
    std::vector<std::shared_ptr<Station>> active_stations; // vector of all active stations for display datas
};

#endif