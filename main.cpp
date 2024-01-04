#include <SFML/Graphics.hpp>
#include <queue>
#include "include/QueuesManager.hpp"
#include "include/WindowsManager.hpp"

int main() {

    QueuesManager queues;
    WindowsManager windows;

    std::queue<int> a {};

    queues.addQueue(a);
    
    queues.pickATicket(0);
    queues.pickATicket(0);
    queues.pickATicket(0);

    windows.addWindow(sf::VideoMode(200, 200), "SFML works!");

    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     //window.draw(shape);
    //     window.display();
    // }

    return 0;
}