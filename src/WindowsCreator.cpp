#include "../include/WindowsCreator.hpp"

#include <iostream>
#include <limits>

WindowsCreator::WindowsCreator() {
    std::uint32_t numberOfStations {inputValidator("stations",9)};
    std::vector<std::shared_ptr<Station>> stations {};

    for (std::uint32_t i = 0; i < numberOfStations; ++i) {
        std::cout << "\t::STATION CREATOR::\n" << std::endl;
        std::shared_ptr<Station> new_station = createStation();
        windows_manager.addWindow(new_station);
        stations.push_back(new_station);
    }

    windows_manager.addWindow(createKiosk());
    windows_manager.addWindow(createAllQueuesScreen(stations));

    windows_manager.runAllWindows();
}

std::shared_ptr<Window> WindowsCreator::createKiosk() {
    return std::make_shared<Kiosk>(sf::VideoMode(400,600), "Kiosk nr 1", queues_manager.getQueues());
}

std::shared_ptr<Window> WindowsCreator::createAllQueuesScreen(const std::vector<std::shared_ptr<Station>> &stations) {
    return std::make_shared<AllQueuesScreen>(sf::VideoMode(600,400), "All Queues Screen", queues_manager.getQueues(), stations);
}

std::shared_ptr<Station> WindowsCreator::createStation() {
    size_t choice {0};
    std::vector<std::shared_ptr<Queue>> allQueues {queues_manager.getQueues()};
    std::vector<std::shared_ptr<Queue>> related_queues;

    do {
        std::uint32_t count {1};
        for (auto &queue: allQueues) {
            std::cout << "\t" << count << ".\t" << queue->getTopic() << std::endl;
            ++count;
        }

        if (!related_queues.empty()) {
            std::cout << "\t0.\tAll related queues have related" << std::endl;
        }
        std::cout << "\nWhich queues do you want to relate with?" << std::endl;
        std::cin >> choice;
        if (std::cin.fail() || choice > allQueues.size() || (choice == 0 && related_queues.empty())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Please give a number from 1 to " << count << std::endl;
        }
        else if (choice) {
            related_queues.push_back(allQueues.at(choice - 1));
            auto toRemove = allQueues.begin() + (choice - 1);
            allQueues.erase(toRemove);
        }
    } while (choice);

    std::cout << "What is the name of the station?" << std::endl;
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::shared_ptr<Station> station = std::make_shared<Station>(sf::VideoMode(400, 600), name, related_queues);
    std::cout << name << " created\n" << std::endl;

    return station;
}

std::uint32_t WindowsCreator::inputValidator(const std::string& issue, std::uint32_t limit) const {
    std::cout << "How many "<< issue << " do you want to create?" << std::endl;

    bool repeat {false};
    std::uint32_t givenNumber {};

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