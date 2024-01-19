#include "../include/Station.hpp"
#include <iostream>

Station::Station(const sf::VideoMode& mode, const std::string& newTitle, const std::vector<std::shared_ptr<Queue>>& relatedQueues)
    : Window(mode, newTitle, relatedQueues), nextButton (sf::Vector2f(150, 50)),
    confirmButton (sf::Vector2f(150, 50)) {

    title = newTitle;

    nextButton.setFillColor(sf::Color::Green);
    nextButton.setPosition(25, 450);

    confirmButton.setFillColor(sf::Color::Blue);
    confirmButton.setPosition(225, 450);

}

void Station::processEvents() {
    sf::Event event;
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the mouse has clicked on a button
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::FloatRect nextButtonBounds = nextButton.getGlobalBounds();
                    sf::FloatRect confirmButtonBounds = confirmButton.getGlobalBounds();

                    if (nextButtonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)) && waitingForCurrentTicket == false) {
                        callNextPerson();
                    }
                    else if (confirmButtonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)) && waitingForCurrentTicket == true) {
                        confirmNextPerson();
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
    if (waitingForCurrentTicket)
        text.setString("Waiting for: ");
    else
        text.setString("Current ticket: ");
    text.setPosition(20, 400);
    window.draw(text);
    drawCurrentTicket();

    window.draw(nextButton);
    window.draw(confirmButton);

    window.display();
}

void Station::drawCurrentTicket() {
    if (!currentTicket.empty()) {
        sf::Text numberText(currentTicket, font, 18);
        numberText.setFillColor(sf::Color::White);
        numberText.setPosition(200, 400);
        window.draw(numberText);
    }
}

void Station::callNextPerson() {

    char previousTicketSignature = '\0';
    bool foundPreviousQueue = false;
    int lapCounter {0};

    if (!currentTicket.empty())
        previousTicketSignature = currentTicket[0];

    do {
        for (const auto& queue: relatedQueues) {
            if (foundPreviousQueue == false && (queue->getSignature() == previousTicketSignature || previousTicketSignature == '\0'))
                foundPreviousQueue = true;
            else if (foundPreviousQueue && queue->size()) {
                currentTicket = queue->getSignature() + std::to_string(queue->getATicket(0));
                setWaitingForCurrentTicketAsTrue();
                queue->deleteFirstTicket();
                return;
            }
        }
        ++lapCounter;
    } while(lapCounter<2);
}

void Station::confirmNextPerson() {
        waitingForCurrentTicket = false;

}

std::string Station::getCurrentTicket() const {
    return currentTicket;
}

bool Station::getWaitingForCurrentTicket() const {
    return waitingForCurrentTicket;
}

void Station::setWaitingForCurrentTicketAsTrue() {
    animator.start();
    waitingForCurrentTicket = true;
}

void Station::notConfirmedTicketAnimation(sf::Text& ticket) {
    animator.notConfirmedTicketAnimation(ticket);
}