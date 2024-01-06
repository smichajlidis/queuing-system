#ifndef _STATION_HPP_
#define _STATION_HPP_
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Station: public Window {
private:
    sf::RectangleShape nextButton;
    sf::RectangleShape confirmButton;
public:
    virtual void processEvents() override;
    virtual void render() override;
    Station(const sf::VideoMode& mode, const std::string& title);
};

#endif