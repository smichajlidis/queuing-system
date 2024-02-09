#ifndef _KIOSK_HPP_
#define _KIOSK_HPP_

#include "Window.hpp"

class Queue;

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Kiosk: public Window {
public:
    Kiosk(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& queues);

    void processEvents() override;
    void render() override;
    void newTicket(Queue& queue) const;    
};

#endif