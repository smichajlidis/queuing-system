#include "../include/Queue.hpp"

void Queue::pickATicket() {
    queue.push(queue.size()+1);
}

char Queue::getSignature() const {
    return signature;
}

std::string Queue::getTopic() const {
    return topic;
}

void Queue::deleteFirstTicket() {
    queue.pop();
}

size_t Queue::getSize() const {
    return queue.size();
}

int Queue::getLastInQueue() const {
    return (!queue.empty() ? queue.back() : 0);
}

int Queue::getFirstInQueue() const {
    return (!queue.empty() ? queue.front() : 0);
}