#include "../include/Kiosk.hpp"

void Kiosk::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Kiosk::render() {
    window.clear();

    window.display();
}
    
Kiosk::Kiosk(const sf::VideoMode& mode, const std::string& title, const std::vector<std::shared_ptr<Queue>>& queues)
    :  Window(mode, title) {

}