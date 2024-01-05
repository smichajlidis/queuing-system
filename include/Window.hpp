#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Queue.hpp"

class Window {
protected:
    sf::RenderWindow window;
    std::vector<std::shared_ptr<Queue>> relatedQueues;
public:
    virtual void addRelatedQueue(const Queue& relatedQueue);
    virtual void display() const = 0;
    Window(const sf::VideoMode& mode, const std::string& title);
    ~Window() {};
};

#endif