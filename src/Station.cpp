#include "../include/Station.hpp"

Station::Station(const sf::VideoMode& mode, const std::string& newTitle)
    : Window(mode, newTitle), nextButton (sf::Vector2f(150, 50)),
    confirmButton (sf::Vector2f(150, 50)) {

    title = newTitle;

    nextButton.setFillColor(sf::Color::Green);
    nextButton.setPosition(25, 450);

    confirmButton.setFillColor(sf::Color::Blue);
    confirmButton.setPosition(225, 450);

}

void Station::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Station::render() {
    window.clear();

    window.draw(nextButton);
    window.draw(confirmButton);

    window.display();
}