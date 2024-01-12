#include "../include/QueuesManager.hpp"

QueuesManager::QueuesManager() {
    // create examples queues
    std::shared_ptr<Queue> queue = std::make_shared<Queue>("Example", 'E');
    std::shared_ptr<Queue> queue2 = std::make_shared<Queue>();
    std::shared_ptr<Queue> queue3 = std::make_shared<Queue>("New example", 'N');
    std::shared_ptr<Queue> queue4 = std::make_shared<Queue>("Another example", 'A');

    queue->pickATicket();
    queue->pickATicket();
    queue->pickATicket();
    // add queues to vectors of all queues
    addQueue(queue);
    addQueue(queue2);
    addQueue(queue3);
    addQueue(queue4);
    // create vector of relatedQueues for a station
    std::vector<std::shared_ptr<Queue>> relatedQueues;
    relatedQueues.push_back(queue);
    relatedQueues.push_back(queue4);
    std::vector<std::shared_ptr<Queue>> relatedQueues2;
    relatedQueues2.push_back(queue);
    std::vector<std::shared_ptr<Queue>> relatedQueues3;
    relatedQueues3.push_back(queue2);
    relatedQueues3.push_back(queue3);
    relatedQueues3.push_back(queue4);
    std::vector<std::shared_ptr<Queue>> relatedQueues4;
    relatedQueues4.push_back(queue2);
    std::vector<std::shared_ptr<Queue>> relatedQueues5;
    relatedQueues5.push_back(queue);
    relatedQueues5.push_back(queue2);
    relatedQueues5.push_back(queue3);
    relatedQueues5.push_back(queue4);
    // create some stations for testing and add it to the vector
    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(400, 600), "Station 1", relatedQueues);
    addWindow(station);
    std::shared_ptr<Station> station2 = std::make_shared<Station>(sf::VideoMode(400, 600), "Station 2", relatedQueues2);
    addWindow(station2);
    std::shared_ptr<Station> station3 = std::make_shared<Station>(sf::VideoMode(400, 600), "Station 3", relatedQueues3);
    addWindow(station3);
    std::shared_ptr<Station> station4 = std::make_shared<Station>(sf::VideoMode(400, 600), "Station 4", relatedQueues4);
    addWindow(station4);
    std::shared_ptr<Station> station5 = std::make_shared<Station>(sf::VideoMode(400, 600), "Station 5", relatedQueues5);
    addWindow(station5);
    // create vector of existing stations for allQueuesScreen
    std::vector<std::shared_ptr<Window>> stations;
    stations.push_back(station);
    stations.push_back(station2);
    stations.push_back(station3);
    stations.push_back(station4);
    stations.push_back(station5);

    std::shared_ptr<Kiosk> kiosk = std::make_shared<Kiosk>(sf::VideoMode(400,600), "Kiosk nr 1", queues);
    addWindow(kiosk);

    std::shared_ptr<AllQueuesScreen> allQueuesScreen = std::make_shared<AllQueuesScreen>(sf::VideoMode(600,400), "All queues screen", queues, stations);
    addWindow(allQueuesScreen);

    runAllWindows();

}

void QueuesManager::runAllWindows() {
    while (std::any_of(windows.begin(), windows.end(), [](const auto& window) { return window->isOpen(); })) {
        for (auto& window : windows) {
            window->run();
            if (!window->isOpen()) {
                return;
            }
        }
    }
}

void QueuesManager::addQueue(std::shared_ptr<Queue> queue) {
    queues.push_back(queue);
}

void QueuesManager::addWindow(std::shared_ptr<Window> window) {
    windows.push_back(window);
}