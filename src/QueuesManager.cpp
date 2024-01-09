#include "../include/QueuesManager.hpp"

QueuesManager::QueuesManager() {
    std::shared_ptr<Queue> queue = std::make_shared<Queue>("Example", 'E');
    queue->pickATicket();
    queue->pickATicket();
    queue->pickATicket();
    addQueue(queue);
    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(400, 600), "Station number 1");
    addWindow(station);
    station->addRelatedQueue(*queue);

    std::shared_ptr<Kiosk> kiosk = std::make_shared<Kiosk>(sf::VideoMode(400,600), "Kiosk nr 1", queues);
    addWindow(kiosk);
    kiosk->addRelatedQueue(*queue);

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