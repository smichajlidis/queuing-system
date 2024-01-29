#ifndef _STATION_HPP_
#define _STATION_HPP_

#include "Window.hpp"

#include <string>
#include <SFML/Graphics.hpp>

class Station: public Window {
public:
    Station(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& related_queues);

    virtual void processEvents() override;
    virtual void render() override;
    void drawCurrentTicket();
    std::string getCurrentTicket() const;
    void callNextPerson();
    void confirmNextPerson();
    bool getWaitingForCurrentTicket() const;
    void setWaitingForCurrentTicketAsTrue(); // it is needed to run animation of not confirmed ticket
    void notConfirmedTicketAnimation(sf::Text& ticket); // run Animator class method for not confirmed ticket

private:
    sf::RectangleShape nextButton;
    sf::RectangleShape confirmButton;
    std::string currentTicket;
    bool waitingForCurrentTicket {false}; // true when nextButton was clicked but confirmButton hasn't been clicked yet
};

#endif