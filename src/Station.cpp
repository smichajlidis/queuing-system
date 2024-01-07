#include "../include/Station.hpp"
#include <iostream>

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
        else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the mouse has clicked on a button
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::FloatRect nextButtonBounds = nextButton.getGlobalBounds();
                    sf::FloatRect confirmButtonBounds = confirmButton.getGlobalBounds();

                    if (nextButtonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                        // Next button event
                        std::cout << "Next button clicked!" << std::endl;
                    }
                    else if (confirmButtonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                        // Confirm button event
                        std::cout << "Confirm button clicked!" << std::endl;
                    }
                }
        } 
    }
}

void Station::render() {
    window.clear();

    text.setString("List of waiting tickets: ");
    text.setPosition(20, 20);
    window.draw(text);

    for (size_t i = 0; i < relatedQueues.size(); ++i) {
        for (size_t j = 0; j < relatedQueues.at(i)->size(); ++j) {
            sf::Text numberText(relatedQueues.at(i)->getSignature()+std::to_string(relatedQueues.at(i)->getATicket(j)), font, 18);
            numberText.setFillColor(sf::Color::White);
            numberText.setPosition(50, 50 + i * 30 + j * 20);
            window.draw(numberText);
        }
    }
    
    text.setString("Current ticket: ");
    text.setPosition(20, 400);
    window.draw(text);
    getCurrentTicket();

    window.draw(nextButton);
    window.draw(confirmButton);

    window.display();
}

void Station::getCurrentTicket() {
    if (!currentTicket.empty()) {
        sf::Text numberText(currentTicket, font, 18);
        numberText.setFillColor(sf::Color::White);
        numberText.setPosition(200, 400);
        window.draw(numberText);
    }
}