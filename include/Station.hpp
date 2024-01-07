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
    bool waitingForCurrentTicket {false}; // true when nextButton was clicked but confirmButton hasn't been clicked yet.
public:
    virtual void processEvents() override;
    virtual void render() override;
    void getCurrentTicket();
    void callNextPerson();
    void confirmNextPerson();
    Station(const sf::VideoMode& mode, const std::string& title);
};

#endif