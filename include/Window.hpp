#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_
#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Queue.hpp"

class Window {
protected:
    sf::RenderWindow window;
    std::vector<std::shared_ptr<Queue>> relatedQueues;
    std::string title;
    sf::Font font;
    sf::Text text;
public:
    virtual void setText(const std::string& content, const sf::Vector2f& position);
    
    virtual void addRelatedQueue(std::shared_ptr<Queue> relatedQueue);
    virtual bool isOpen() const;
    virtual void run();
    virtual void processEvents() = 0;
    virtual void render() = 0;
    Window(const sf::VideoMode& mode, const std::string& title);
    ~Window() {};
};

#endif