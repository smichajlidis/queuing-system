#include "../include/QueuesManager.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>

QueuesManager::QueuesManager() {
    //create queues
    std::uint32_t number_of_queues {inputValidator("queues",12)};
    for (std::uint32_t i = 0; i < number_of_queues; ++i) {
        queues.push_back(createQueue());
    }
}

std::shared_ptr<Queue> QueuesManager::createQueue() const {
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

std::vector<std::shared_ptr<Queue>> QueuesManager::getQueues() const {
    return queues;
}

std::uint32_t QueuesManager::inputValidator(const std::string& issue, std::uint32_t limit) const {
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