#include "../include/Queue.hpp"

void Queue::pickATicket() {
    queue.push(++counter);
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

std::uint32_t Queue::getLastInQueue() const {
    return (!queue.empty() ? queue.back() : 0);
}

std::uint32_t Queue::getFirstInQueue() const {
    return (!queue.empty() ? queue.front() : 0);
}