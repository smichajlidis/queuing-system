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
public:
    virtual void processEvents() override;
    virtual void render() override;
    void getCurrentTicket();
    Station(const sf::VideoMode& mode, const std::string& title);
};

#endif