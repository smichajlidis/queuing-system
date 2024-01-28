#include "../include/QueuesManager.hpp"

#include <algorithm>

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

int QueuesManager::systemCreator(const std::string& issue, int limit) const {
    std::cout << "How many "<< issue << " do you want to create?" << std::endl;
    bool repeat {false};
    int givenNumber {};
    do {
        repeat = false;
        try {
            std::cin >> givenNumber;
            if (std::cin.fail() || givenNumber > limit || givenNumber < 1) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidAmountException(limit);
            }
        } catch (const InvalidAmountException &ex) {
            std::cerr << ex.what() << std::endl;
            repeat = true;
        }
    } while (repeat);
    return givenNumber;
}

#include <cctype>

std::shared_ptr<Queue> QueuesManager::queuesCreator() const {
    std::string topic {};
    std::string signatureTemp {};
    char signature {};
    bool repeat {false};
    std::cout << "Give a topic of the queue - no more than 20 characters: " << std::endl;
    do {
        repeat = false;
        try {
            std::cin >> topic;
            if (topic.size() > 20)
                throw TooManyCharsException();
        } catch (const TooManyCharsException &ex) {
            std::cerr << ex.what() << std::endl;
            repeat = true;
        }
    } while (repeat);

    std::cout << "Give a signature of the queue - only one character: " << std::endl;
    do {
        repeat = false;
        std::cin >> signatureTemp;
        signature = signatureTemp[0];
        try {
            if (!std::isalpha(signature))
                throw NotLetterException();
        } catch (const NotLetterException &ex) {
            std::cerr << ex.what() << std::endl;
            repeat = true;
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
    size_t choice = 0;
    std::vector<std::shared_ptr<Queue>> allQueues = queues;
    std::vector<std::shared_ptr<Queue>> relatedQueues;
    do {
        int count = 1;
        for (auto queue: allQueues) {
            std::cout << "\t" << count << ".\t" << allQueues.at(count-1)->getTopic() << std::endl;
            ++count;
        }
        if (!relatedQueues.empty())
            std::cout << "\t0.\tAll related queues have related" << std::endl; 
        std::cout << "\nWhich queues do you want to relate with?" << std::endl;
        try {
            std::cin >> choice;
            if (std::cin.fail() || choice > allQueues.size() || (choice == 0 && relatedQueues.empty())) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidAmountException(allQueues.size());
            }
            else if (choice) {
                relatedQueues.push_back(allQueues.at(choice-1));
                auto toRemove = allQueues.begin() + (choice - 1);
                allQueues.erase(toRemove);
            }
        } catch (const InvalidAmountException &ex) {
            std::cerr << ex.what() << std::endl;
        }
    } while (choice);

    std::cout << "What is the name of the station?" << std::endl;
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(400, 600), name, relatedQueues);
    addWindow(station);
    std::cout << name << " created\n" << std::endl;
    return station;
}