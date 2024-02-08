#include "../include/Kiosk.hpp"

Kiosk::Kiosk(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& queues)
    :  Window(mode, title, queues) {

    window_grid.setRows(8, 40.0, 
    50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0);
    window_grid.setColumns(4, 20.0, 10.0, 10.0, 300.0);

}

void Kiosk::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

            int counter = 1;

            for (auto& queue : related_queues) {
                const sf::FloatRect buttonBounds(window_grid.getColumn(1), window_grid.getRow(counter), window_grid.getColumn(4), window_grid.getRow(1));
                if (buttonBounds.contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
                    newTicket(*queue);
                    break;
                }
                ++counter;
            }
        }
    }
}

void Kiosk::render() {
    window.clear();
    int counter {1};

    

    for (auto& queue: related_queues) {
        // if you change size, change also buttonBounds dimensions in proceesEvents() method
        sf::RectangleShape ticket_button {sf::Vector2f(window_grid.getColumn(4), window_grid.getRow(1))};
        ticket_button.setFillColor(sf::Color::Black);
        ticket_button.setPosition(window_grid.getColumn(1), window_grid.getRow(counter));
        ticket_button.setOutlineColor(sf::Color::White);
        ticket_button.setOutlineThickness(2.f);

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setString(queue->getTopic());
        text.setPosition(window_grid.getColumn(2), window_grid.getRow(counter) + 7);

        window.draw(ticket_button);
        window.draw(text);

        ++counter;
    }
    window.display();
}

void Kiosk::newTicket(Queue& queue) const {
        queue.pickATicket();
}