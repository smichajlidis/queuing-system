#include "../include/Kiosk.hpp"

void Kiosk::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            int distance = 1;

            for (auto& queue : related_queues) {
                const sf::FloatRect buttonBounds(20, 60 * distance, 200, 50);
                if (buttonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                    newTicket(*queue);
                    break;
                }
                ++distance;
            }
        }
    }
}

void Kiosk::render() {
    window.clear();
    int distance {1};

    

    for (auto& queue: related_queues) {
        // if you change size, change also buttonBounds dimensions in proceesEvents() method
        sf::RectangleShape ticketButton {sf::Vector2f(200, 50)};
        ticketButton.setFillColor(sf::Color::Black);
        ticketButton.setPosition(20, 60 * distance);
        ticketButton.setOutlineColor(sf::Color::White);
        ticketButton.setOutlineThickness(2.f);

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setString(queue->getTopic());
        text.setPosition(25, 60 * distance + 10);

        window.draw(ticketButton);
        window.draw(text);

        ++distance;
    }
    window.display();
}

void Kiosk::newTicket(Queue& queue) const {
        queue.pickATicket();
}