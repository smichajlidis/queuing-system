#ifndef _ANIMATOR_HPP_
#define _ANIMATOR_HPP_

#include <SFML/Graphics.hpp>

class Animator {
public:
    Animator() : color(sf::Color::White) {}

    ~Animator() = default;

    void notConfirmedTicketAnimation(sf::Text& ticket);
    void start();

private:
    sf::Clock clock;
    sf::Color color; // Used to animate sf::Text when the ticket is called but not confirmed yet.

};

#endif