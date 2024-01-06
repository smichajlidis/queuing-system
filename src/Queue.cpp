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

Queue::Queue() {}

Queue::Queue(std::string topic)
    : topic (topic) {}

Queue::Queue(std::string topic, int priority)
    : topic (topic), priority (priority) {}

Queue::~Queue() {}