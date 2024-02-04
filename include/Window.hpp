#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include "Queue.hpp"
#include "Animator.hpp"

#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>


class Window {
public:
    Window(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& related_queues = {});
    
    ~Window() = default;

    virtual void setText(const std::string& content, const sf::Vector2f& position);
    virtual void addRelatedQueue(std::shared_ptr<Queue> related_queue);
    virtual bool isOpen() const;
    virtual std::string getTitle() const;
    virtual void processEvents() = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow window;
    std::vector<std::shared_ptr<Queue>> related_queues;
    std::string title;
    sf::Font font;
    sf::Text text;
    Animator animator;
};

#endif