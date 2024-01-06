#ifndef _STATION_HPP_
#define _STATION_HPP_
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Station: public Window {

public:
    virtual void display() const override;
    virtual void processEvents() override;
    virtual void update() override;
    virtual void render() override;
    Station(const sf::VideoMode& mode, const std::string& title);
};

#endif