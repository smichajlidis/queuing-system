#include "../include/AllQueuesScreen.hpp"
#include <iostream>

void AllQueuesScreen::processEvents() {
    sf::Event event;
    if (window.pollEvent(event) && event.type == sf::Event::Closed) {
            window.close();
    }
}

void AllQueuesScreen::render() {
    window.clear();

    text.setString("List of waiting tickets: ");
    text.setPosition(text_parameters.getStartingPosition(), text_parameters.getStartingPosition());
    window.draw(text);
    
    int column = 1;

    for (auto &queue: related_queues) {
        size_t size = queue->getSize();
        int last = queue->getLastInQueue();
        for (size_t j = 0; j < size; ++j) {
            sf::Text number_text(queue->getSignature() + std::to_string(last), font, 18);
            number_text.setFillColor(sf::Color::White);
            number_text.setPosition(text_parameters.getSpaceBetweenColumns()*column, text_parameters.getSpaceBetweenLines() + j * 20);
            window.draw(number_text);
            --last;
        }
        ++column;
    }

    text.setString("List of stations: ");
    text.setPosition(text_parameters.getStartingPosition(), 250);
    window.draw(text);

    column = 1;
    int count = 0;

    for (size_t i = 0; i < active_stations.size(); ++i) {
        sf::Text station_topic(active_stations.at(i)->getTitle(), font, 18);
        station_topic.setFillColor(sf::Color::White);
        station_topic.setPosition(text_parameters.getSpaceBetweenColumns() * column + 30, 300 + count * 30);
        window.draw(station_topic);

        sf::Text actual_ticket(active_stations.at(i)->getCurrentTicket(), font, 18);
        actual_ticket.setPosition(text_parameters.getSpaceBetweenColumns() * column + 120, 300 + count * 30);
        // animate if the ticket is not confirmed yet
        if (active_stations.at(i)->getWaitingForCurrentTicket()) {
            active_stations.at(i)->notConfirmedTicketAnimation(actual_ticket);
        }
        window.draw(actual_ticket);
        
        ++count;
        if ((i + 1) % 3 == 0) {
            column += 4;
            count = 0;
        }
    }

    window.display();
}