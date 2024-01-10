#include "../include/Queue.hpp"
#include <iostream>

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

Queue::Queue(std::string topic, char signature, int priority)
    : topic (topic), signature (signature), priority (priority) {}

Queue::~Queue() {}

void Queue::deleteFirstTicket() {
    queue.erase(queue.begin());
}