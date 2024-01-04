#include "../include/WindowsManager.hpp"

void WindowsManager::addWindow(const sf::VideoMode& mode, const std::string& title) {
    windows.push_back(std::make_unique<sf::RenderWindow>(mode, title));
}