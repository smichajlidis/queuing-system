#ifndef _STATION_HPP_
#define _STATION_HPP_

#include "Window.hpp"

#include <string>
#include <SFML/Graphics.hpp>

class Station: public Window {
public:
    Station(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& related_queues);

    void processEvents() override;
    void render() override;
    void drawCurrentTicket();
    std::string getCurrentTicket() const;
    void callNextPerson();
    void confirmNextPerson();
    bool getWaitingForCurrentTicket() const;
    void setWaitingForCurrentTicketAsTrue(); // it is needed to run animation of not confirmed ticket
    void notConfirmedTicketAnimation(sf::Text& ticket); // run Animator class method for not confirmed ticket

private:
    sf::RectangleShape next_button;
    sf::RectangleShape confirm_button;
    std::string current_ticket;
    bool waiting_for_current_ticket {false}; // true when nextButton was clicked but confirmButton hasn't been clicked yet
};

#endif