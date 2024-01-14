#ifndef _ANIMATOR_HPP_
#define _ANIMATOR_HPP_
#include <SFML/Graphics.hpp>

class Animator {
private:
    sf::Clock clock;
    sf::Color color; // using to animate sf::Text when ticket is calling but it's not confirmed yet;
public:
    void notConfirmedTicketAnimation(sf::Text& ticket);
    void start();
    Animator();
    ~Animator() {};

};

#endif