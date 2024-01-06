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

Queue::Queue() {}

Queue::Queue(std::string topic, char signature)
    : topic (topic), signature (signature) {}

Queue::Queue(std::string topic, char signature, int priority)
    : topic (topic), signature (signature), priority (priority) {}

Queue::~Queue() {}