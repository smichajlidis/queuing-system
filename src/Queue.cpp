#include "../include/Queue.hpp"

void Queue::pickATicket() {
    queue.push(queueLength+1);
    ++queueLength;
}

Queue::Queue() {}

Queue::Queue(std::string topic)
    : topic (topic) {}

Queue::Queue(std::string topic, int priority)
    : topic (topic), priority (priority) {}

Queue::~Queue() {}