#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <vector>
#include <string>

class Queue {
public:
    Queue(std::string topic = "Queue", char signature = 'Q', int priority = 1)
    : topic (topic), signature (signature), priority (priority) {}

    ~Queue() = default;

    void pickATicket(); // take a new ticket
    size_t size() const;
    char getSignature() const;
    void deleteFirstTicket();
    int getATicket(int pos) const; // get a name of existing ticket
    std::string getTopic() const;

private:
    std::vector<int> queue;
    std::string topic;
    char signature;
    int queueLength {0};
    int priority;
};

#endif