#include "../include/Window.hpp"

Window::Window(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& related_queues)
    : window(mode, title), related_queues(related_queues), title(title), animator() {

    if (!font.loadFromFile("../resources/fonts/Lato-Regular.ttf")) {
        // Handling exception
    }
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);    
}

void Window::addRelatedQueue(std::shared_ptr<Queue> related_queue) {
    related_queues.push_back(std::move(related_queue));
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::setText(const std::string& content, const sf::Vector2f& position) {
    text.setString(content);
    text.setPosition(position);
}

std::string Window::getTitle() const {
    return title;
}