#include "../include/QueuesManager.hpp"

QueuesManager::QueuesManager() {
    std::shared_ptr<Queue> queue = std::make_shared<Queue>("Example", 'E');
    //Queue queue {"Example", 'E'};
    queue->pickATicket();
    queue->pickATicket();
    queue->pickATicket();
    addQueue(queue);
    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(400, 600), "Station number 1");
    addWindow(station);
    station->addRelatedQueue(*queue);

    Kiosk kiosk(sf::VideoMode(400,600), "Kiosk nr 1", queues); 

    runAllWindows();

}

void QueuesManager::runAllWindows() {
    for (auto it = windows.begin(); it != windows.end();) {
        if ((*it)->isOpen()) {
            (*it)->run();
            it = windows.erase(it);
        } else {
            ++it;
        }
    }
}

void QueuesManager::addQueue(std::shared_ptr<Queue> queue) {
    queues.push_back(queue);
}

void QueuesManager::addWindow(std::shared_ptr<Window> window) {
    windows.push_back(window);
}