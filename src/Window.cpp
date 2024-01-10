#include "../include/Window.hpp"

Window::Window(const sf::VideoMode& mode, const std::string& title)
    : window(mode, title) {

    if (!font.loadFromFile("../resources/fonts/Lato-Regular.ttf")) {
        // Handling exception
    }
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);    
    }

void Window::addRelatedQueue(std::shared_ptr<Queue> relatedQueue) {
    relatedQueues.push_back(relatedQueue);
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::run() {
    if (window.isOpen()) {
        processEvents();
        render();
    }
}

void Window::setText(const std::string& content, const sf::Vector2f& position) {

    text.setString(content);
    text.setPosition(position);
}