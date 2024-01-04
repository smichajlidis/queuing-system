#ifndef _WINDOWSMANAGER_HPP_
#define _WINDOWSMANAGER_HPP_
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

class WindowsManager {

    std::vector<std::unique_ptr<sf::RenderWindow>> windows;

public:
    void addWindow(const sf::VideoMode& mode, const std::string& title);
    WindowsManager() {};
    ~WindowsManager() {};

};

#endif