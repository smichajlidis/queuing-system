#include "../include/AllQueuesScreen.hpp"
#include <iostream>

AllQueuesScreen::AllQueuesScreen(const sf::VideoMode& mode, const std::string& newTitle, const std::vector<std::shared_ptr<Queue>>& relatedQueues, const std::vector<std::shared_ptr<Station>>& stations)
    : Window(mode, newTitle, relatedQueues), activeStations(stations) {
}

void AllQueuesScreen::processEvents() {
    sf::Event event;
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void AllQueuesScreen::render() {
    window.clear();

    text.setString("List of waiting tickets: ");
    text.setPosition(20, 20);
    window.draw(text);
    
    int column = 1;

    for (size_t i = 0; i < relatedQueues.size(); ++i) {
        for (size_t j = 0; j < relatedQueues.at(i)->size(); ++j) {
            sf::Text numberText(relatedQueues.at(i)->getSignature()+std::to_string(relatedQueues.at(i)->getATicket(j)), font, 18);
            numberText.setFillColor(sf::Color::White);
            numberText.setPosition(50*column, 50 + 30 + j * 20);
            window.draw(numberText);
        }
        ++column;
    }

    text.setString("List of stations: ");
    text.setPosition(20, 250);
    window.draw(text);

    column = 1;
    int count = 0;

    for (size_t i = 0; i < activeStations.size(); ++i) {
        sf::Text stationTopic(activeStations.at(i)->getTitle(), font, 18);
        stationTopic.setFillColor(sf::Color::White);
        stationTopic.setPosition(50*column + 30, 300 + count * 30);
        window.draw(stationTopic);

        sf::Text actualTicket(activeStations.at(i)->getCurrentTicketName(), font, 18);
        actualTicket.setPosition(50*column + 120, 300 + count * 30);
        // animate if the ticket is not confirmed yet
        if (activeStations.at(i)->getWaitingForCurrentTicket())
            activeStations.at(i)->notConfirmedTicketAnimation(actualTicket);
        
        window.draw(actualTicket);
        
        ++count;
        if ((i+1)%3==0) {
            column+=4;
            count = 0;
        }
    }

    window.display();
}