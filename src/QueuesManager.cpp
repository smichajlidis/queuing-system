#include "../include/QueuesManager.hpp"

void QueuesManager::addQueue(std::queue<int>& queue) {
    queues.push_back(queue);
}

void QueuesManager::pickATicket(int queueNum) {
    queues.at(queueNum).push(queues.at(queueNum).size()+1);
}