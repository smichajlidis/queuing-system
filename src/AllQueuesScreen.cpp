#include "../include/AllQueuesScreen.hpp"
#include <iostream>

AllQueuesScreen::AllQueuesScreen(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& related_queues, const std::vector<std::shared_ptr<Station>>& stations)
    : Window(mode, title, related_queues), active_stations (stations) {

    window_grid.setRows(18, 
    20.0, 30.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
    30.0, 30.0, 20.0, 20.0, 20.0, 20.0, 20.0);
    window_grid.setColumns(10, 20.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0);

}

void AllQueuesScreen::processEvents() {
    sf::Event event;
    if (window.pollEvent(event) && event.type == sf::Event::Closed) {
            window.close();
    }
}

void AllQueuesScreen::render() {
    window.clear();

    text.setString("List of waiting tickets: ");
    text.setPosition(window_grid.getColumn(1), window_grid.getColumn(1));
    window.draw(text);

    int column {1};

    for (auto &queue: related_queues) {
        size_t size = queue->getSize();
        int last = queue->getLastInQueue();
        for (size_t i = 1; i <= size; ++i) {
            sf::Text number_text(queue->getSignature() + std::to_string(last), font, 18);
            number_text.setFillColor(sf::Color::White);
            number_text.setPosition(window_grid.getColumn(column), window_grid.getRow(i+1));
            window.draw(number_text);
            --last;
        }
        ++column;
    }

    text.setString("List of stations: ");
    text.setPosition(window_grid.getColumn(1), window_grid.getRow(12));
    window.draw(text);

    column = 1;
    int line {1};

    for (size_t i = 1; i <= active_stations.size(); ++i) {
        sf::Text station_topic(active_stations.at(i-1)->getTitle(), font, 18);
        station_topic.setFillColor(sf::Color::White);
        station_topic.setPosition(window_grid.getColumn(column), window_grid.getRow(12+line));
        window.draw(station_topic);

        sf::Text actual_ticket(active_stations.at(i-1)->getCurrentTicket(), font, 18);
        actual_ticket.setPosition(window_grid.getColumn(column+3), window_grid.getRow(12+line));
        // animate if the ticket is not confirmed yet
        if (active_stations.at(i-1)->getWaitingForCurrentTicket()) {
            active_stations.at(i-1)->notConfirmedTicketAnimation(actual_ticket);
        }
        window.draw(actual_ticket);
        
        ++line;
        if (i % 4 == 0) {
            column += 4;
            line = 1;
        }
    }

    window.display();
}