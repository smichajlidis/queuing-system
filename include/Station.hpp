#ifndef _STATION_HPP_
#define _STATION_HPP_
#include <SFML/Graphics.hpp>
#include <string>
#include "Window.hpp"

class Station: public Window {
private:
    sf::RectangleShape nextButton;
    sf::RectangleShape confirmButton;
    std::string currentTicket;
    bool waitingForCurrentTicket {false}; // true when nextButton was clicked but confirmButton hasn't been clicked yet
public:
    virtual void processEvents() override;
    virtual void render() override;
    void getCurrentTicket();
    std::string getCurrentTicketName() const;
    void callNextPerson();
    void confirmNextPerson();
    bool getWaitingForCurrentTicket() const;
    void setWaitingForCurrentTicketAsTrue(); // it is needed to run animation of not confirmed ticket
    void notConfirmedTicketAnimation(sf::Text& ticket); // run Animator class method for not confirmed ticket
    Station(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& relatedQueues);
};

#endif