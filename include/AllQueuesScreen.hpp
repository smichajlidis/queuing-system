#ifndef _ALLQUEUESSCREEN_HPP_
#define _ALLQUEUESSCREEN_HPP_
#include "Window.hpp"
#include "Station.hpp"
#include <SFML/Graphics.hpp>
#include "Queue.hpp"
#include <vector>
#include <memory>

class AllQueuesScreen: public Window {
private:
    std::vector<std::shared_ptr<Station>> activeStations; // vector of all active stations for display datas
public:
    virtual void processEvents() override;
    virtual void render() override;
    AllQueuesScreen(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& relatedQueues, const std::vector<std::shared_ptr<Station>>& stations);    
};

#endif