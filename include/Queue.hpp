#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <queue>
#include <string>

class Queue {
public:
    Queue(std::string topic = "Queue", char signature = 'Q')
    : topic (topic), signature (signature) {}

    ~Queue() = default;

    void pickATicket(); // take a new ticket
    char getSignature() const;
    size_t getSize() const;
    int getLastInQueue() const; // take a number of the last ticket
    int getFirstInQueue() const;
    void deleteFirstTicket();
    std::string getTopic() const;

private:
    std::queue<int> queue;
    std::string topic;
    char signature;
};

#endif