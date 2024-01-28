#include "../include/Animator.hpp"

void Animator::notConfirmedTicketAnimation(sf::Text& ticket) {

    if ((clock.getElapsedTime()).asSeconds() >= 0.6f) {
        if (color == sf::Color::Black)
            color = sf::Color::White;
        else
            color = sf::Color::Black;
        start();
    }
    ticket.setFillColor(color);
}

void Animator::start() {
    clock.restart();
}