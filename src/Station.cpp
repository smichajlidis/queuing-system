#include "../include/Station.hpp"

Station::Station(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& related_queues)
    : Window(mode, title, related_queues), next_button (sf::Vector2f(150, 50)), confirm_button (sf::Vector2f(150, 50)) {

    next_button.setFillColor(sf::Color::Green);
    next_button.setPosition(25, 450);

    confirm_button.setFillColor(sf::Color::Blue);
    confirm_button.setPosition(225, 450);
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
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                sf::FloatRect next_button_bounds = next_button.getGlobalBounds();
                sf::FloatRect confirm_button_bounds = confirm_button.getGlobalBounds();

                if (next_button_bounds.contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y)) && waiting_for_current_ticket == false) {
                    callNextPerson();
                }
                else if (confirm_button_bounds.contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y)) && waiting_for_current_ticket == true) {
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

    for (auto &queue: related_queues) {
        size_t size = queue->getSize();
        int last = queue->getLastInQueue();
        for (size_t j = 0; j < size; ++j) {
            sf::Text number_text(queue->getSignature()+std::to_string(last), font, 18);
            number_text.setFillColor(sf::Color::White);
            number_text.setPosition(50*column, 50 + 30 + j * 20);
            window.draw(number_text);
            --last;
        }
        ++column;
    }
    text.setString(waiting_for_current_ticket ? "Waiting for: " : "Current ticket: ");
    text.setPosition(20, 400);
    window.draw(text);
    drawCurrentTicket();

    window.draw(next_button);
    window.draw(confirm_button);

    window.display();
}

void Station::drawCurrentTicket() {
    if (!current_ticket.empty()) {
        sf::Text number_text(current_ticket, font, 18);
        number_text.setFillColor(sf::Color::White);
        number_text.setPosition(200, 400);
        window.draw(number_text);
    }
}

void Station::callNextPerson() {
    char previous_ticket_signature = '\0';
    bool found_previous_queue = false;
    int lap_counter {0};

    if (!current_ticket.empty()) {
        previous_ticket_signature = current_ticket[0];
    }
    do {
        for (const auto& queue: related_queues) {
            if (found_previous_queue == false && (queue->getSignature() == previous_ticket_signature || previous_ticket_signature == '\0')) {
                found_previous_queue = true;
            }
            else if (found_previous_queue && queue->getSize()) {
                current_ticket = queue->getSignature() + std::to_string(queue->getFirstInQueue());
                setWaitingForCurrentTicketAsTrue();
                queue->deleteFirstTicket();
                return;
            }
        }
        ++lap_counter;
    } while(lap_counter<2);
}

void Station::confirmNextPerson() {
    waiting_for_current_ticket = false;
}

std::string Station::getCurrentTicket() const {
    return current_ticket;
}

bool Station::getWaitingForCurrentTicket() const {
    return waiting_for_current_ticket;
}

void Station::setWaitingForCurrentTicketAsTrue() {
    animator.start();
    waiting_for_current_ticket = true;
}

void Station::notConfirmedTicketAnimation(sf::Text& ticket) {
    animator.notConfirmedTicketAnimation(ticket);
}