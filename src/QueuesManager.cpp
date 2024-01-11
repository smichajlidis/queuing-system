#include "../include/QueuesManager.hpp"

QueuesManager::QueuesManager() {
    std::shared_ptr<Queue> queue = std::make_shared<Queue>("Example", 'E');
    std::shared_ptr<Queue> queue2 = std::make_shared<Queue>();
    queue->pickATicket();
    queue->pickATicket();
    queue->pickATicket();
    addQueue(queue);
    addQueue(queue2);
    
    std::vector<std::shared_ptr<Queue>> relatedQueues;
    relatedQueues.push_back(queue);
    relatedQueues.push_back(queue2);

    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(400, 600), "Station number 1", relatedQueues);
    addWindow(station);

    // station->addRelatedQueue(queue);
    // station->addRelatedQueue(queue2);

    std::shared_ptr<Kiosk> kiosk = std::make_shared<Kiosk>(sf::VideoMode(400,600), "Kiosk nr 1", queues);
    addWindow(kiosk);

    runAllWindows();

}

void QueuesManager::runAllWindows() {
    while (std::any_of(windows.begin(), windows.end(), [](const auto& window) { return window->isOpen(); })) {
        for(auto it: windows) {
            it->run();
        }
    }
}

void QueuesManager::addQueue(std::shared_ptr<Queue> queue) {
    queues.push_back(queue);
}

void QueuesManager::addWindow(std::shared_ptr<Window> window) {
    windows.push_back(window);
}