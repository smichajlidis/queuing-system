#ifndef _KIOSK_HPP_
#define _KIOSK_HPP_

#include "Window.hpp"
#include "Queue.hpp"

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Kiosk: public Window {
public:
    virtual void processEvents() override;
    virtual void render() override;
    void newTicket(Queue& queue) const;
    Kiosk(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& queues);    
};

#endif