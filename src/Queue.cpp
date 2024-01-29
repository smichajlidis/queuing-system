#include "../include/Queue.hpp"

void Queue::pickATicket() {
    queue.push_back(queueLength+1);
    ++queueLength;
}

size_t Queue::size() const {
    return queue.size();
}

int Queue::getATicket(int pos) const {
    return queue.at(pos);
}

char Queue::getSignature() const {
    return signature;
}

std::string Queue::getTopic() const {
    return topic;
}

void Queue::deleteFirstTicket() {
    queue.erase(queue.begin());
}