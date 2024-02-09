#include "../include/Animator.hpp"

void Animator::notConfirmedTicketAnimation(sf::Text& ticket) {

    if ((clock.getElapsedTime()).asSeconds() >= 0.6f) {
        color = (color == sf::Color::Black) ? sf::Color::White : sf::Color::Black;
        start();
    }
    ticket.setFillColor(color);
}

void Animator::start() {
    clock.restart();
}