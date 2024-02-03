#include "../include/QueuesManager.hpp"

#include <algorithm>
#include <cctype>

QueuesManager::QueuesManager() {
    //create queues
    int numberOfQueues {systemCreator("queues",12)};
    for (int i = 0; i < numberOfQueues; ++i)
        addQueue(queuesCreator());
    //create stations
    int numberOfStations {systemCreator("stations",9)};
    for (int i = 0; i < numberOfStations; ++i) {
        std::cout << "\t<<STATION CREATOR>>\n" << std::endl;
        addStation(stationsCreator());
    }

    std::shared_ptr<Kiosk> kiosk = std::make_shared<Kiosk>(sf::VideoMode(400,600), "Kiosk nr 1", queues);
    windows_manager.addWindow(kiosk);

    std::shared_ptr<AllQueuesScreen> allQueuesScreen = std::make_shared<AllQueuesScreen>(sf::VideoMode(600,400), "All queues screen", queues, stations);
    windows_manager.addWindow(allQueuesScreen);

    windows_manager.runAllWindows();
}

void QueuesManager::addQueue(std::shared_ptr<Queue> queue) {
    queues.push_back(queue);
}

int QueuesManager::systemCreator(const std::string& issue, int limit) const {
    std::cout << "How many "<< issue << " do you want to create?" << std::endl;

    bool repeat {false};
    int givenNumber {};

    do {
        repeat = false;
        std::cin >> givenNumber;
        if (std::cin.fail() || givenNumber > limit || givenNumber < 1) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            repeat = true;
            std::cerr << "Please give a number from 1 to " << limit << std::endl;
        }
    } while (repeat);

    return givenNumber;
}

std::shared_ptr<Queue> QueuesManager::queuesCreator() const {
    std::string topic {};
    std::string signatureTemp {};
    char signature {};
    bool repeat {false};

    std::cout << "Give a topic of the queue - no more than 20 characters: " << std::endl;
    do {
        repeat = false;
        std::cin >> topic;
        if (topic.size() > 20) {
            repeat = true;
            std::cerr << "Given too many chars" << std::endl;
        }
    } while (repeat);

    std::cout << "Give a signature of the queue - only one character: " << std::endl;
    do {
        repeat = false;
        std::cin >> signatureTemp;
        signature = signatureTemp[0];
        if (!std::isalpha(signature)) {
            repeat = true;
            std::cerr << "You have to give a letter" << std::endl;
        }
    } while (repeat);

    if (std::islower(signature))
        signature = std::toupper(signature);
    return std::make_shared<Queue>(topic, signature);
    
}

void QueuesManager::addStation(std::shared_ptr<Station> station) {
    stations.push_back(station);
}

std::shared_ptr<Station> QueuesManager::stationsCreator() {
    size_t choice {0};
    std::vector<std::shared_ptr<Queue>> allQueues = queues;
    std::vector<std::shared_ptr<Queue>> relatedQueues;

    do {
        int count {1};
        for (auto &queue: allQueues) {
            std::cout << "\t" << count << ".\t" << queue->getTopic() << std::endl;
            ++count;
        }

        if (!relatedQueues.empty()) {
            std::cout << "\t0.\tAll related queues have related" << std::endl;
        }
        std::cout << "\nWhich queues do you want to relate with?" << std::endl;
        std::cin >> choice;
        if (std::cin.fail() || choice > allQueues.size() || (choice == 0 && relatedQueues.empty())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Please give a number from 1 to " << count << std::endl;
        }
        else if (choice) {
            relatedQueues.push_back(allQueues.at(choice - 1));
            auto toRemove = allQueues.begin() + (choice - 1);
            allQueues.erase(toRemove);
        }
    } while (choice);

    std::cout << "What is the name of the station?" << std::endl;
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(400, 600), name, relatedQueues);
    windows_manager.addWindow(station);
    std::cout << name << " created\n" << std::endl;

    return station;
}