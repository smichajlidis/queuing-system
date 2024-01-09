#ifndef _KIOSK_HPP_
#define _KIOSK_HPP_
#include "Window.hpp"
#include <SFML/Graphics.hpp>
#include "Queue.hpp"
#include <unordered_map>
#include <vector>
#include <memory>

class Kiosk: public Window {
private:
    std::unordered_map<std::string, sf::RectangleShape> topics;
public:
    virtual void processEvents() override;
    virtual void render() override;
    Kiosk(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& queues);    
};

#endif