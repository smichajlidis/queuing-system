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

    text.setString("List of printed tickets: ");
    text.setPosition(20, 20);
    window.draw(text);

    for (size_t i = 0; i < relatedQueues.size(); ++i) {
        for (size_t j = 0; j < relatedQueues.at(i)->size(); ++j) {
            sf::Text numberText(std::to_string(relatedQueues.at(i)->getATicket(j)), font, 18);
            numberText.setFillColor(sf::Color::White);
            numberText.setPosition(50, 50 + i * 30 + j * 20);
            window.draw(numberText);
        }
    }

    window.draw(nextButton);
    window.draw(confirmButton);

    window.display();
}