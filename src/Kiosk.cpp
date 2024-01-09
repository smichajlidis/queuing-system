#include "../include/Kiosk.hpp"

Kiosk::Kiosk(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& queues)
    :  Window(mode, title) {

        int distance {1};

        for(auto& queue: queues) {
            sf::RectangleShape ticketButton {sf::Vector2f(200, 50)};
            ticketButton.setFillColor(sf::Color::Black);
            ticketButton.setPosition(20, 20*distance);
            ticketButton.setOutlineColor(sf::Color::White);
            ticketButton.setOutlineThickness(2.f);

            std::string description {queue->getTopic()};

            topics.insert(std::make_pair(description, ticketButton));
            ++distance;
        }

}

void Kiosk::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Kiosk::render() {
    window.clear();
    int distance {1};
    for (const auto& topic : topics) {
        text.setString(topic.first);
        text.setPosition(25, 20*distance+10);
        window.draw(topic.second);
        window.draw(text);
        ++distance;   
    }
    window.display();
}
