#include "../include/Window.hpp"

Window::Window(const sf::VideoMode& mode, const std::string& title)
    : window(mode, title) {}

void Window::addRelatedQueue(const Queue& relatedQueue) {
    relatedQueues.push_back(std::make_shared<Queue>(relatedQueue));
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}