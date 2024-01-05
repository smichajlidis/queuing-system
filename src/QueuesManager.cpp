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

}

void QueuesManager::addQueue(Queue& queue) {
    queues.push_back(queue);
}

void QueuesManager::addWindow(std::shared_ptr<Window> window) {
    windows.push_back(window);
}