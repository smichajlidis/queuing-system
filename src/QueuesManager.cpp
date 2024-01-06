#include "../include/QueuesManager.hpp"

QueuesManager::QueuesManager() {
    Queue queue;
    queue.pickATicket();
    queue.pickATicket();
    queue.pickATicket();
    addQueue(queue);
    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(300, 300), "title");
    addWindow(station);
    station->addRelatedQueue(queue); 

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

void QueuesManager::addQueue(Queue& queue) {
    queues.push_back(queue);
}

void QueuesManager::addWindow(std::shared_ptr<Window> window) {
    windows.push_back(window);
}