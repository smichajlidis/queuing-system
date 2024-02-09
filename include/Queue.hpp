#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <queue>
#include <string>

class Queue {
public:
    Queue(const std::string &topic = "Queue", char signature = 'Q')
    : topic(topic), signature(signature), counter (0) {}

    ~Queue() = default;

    void pickATicket(); // take a new ticket
    char getSignature() const;
    size_t getSize() const;
    std::uint32_t getLastInQueue() const; // take a number of the last ticket
    std::uint32_t getFirstInQueue() const;
    void deleteFirstTicket();
    std::string getTopic() const;

private:
    std::queue<std::uint32_t> queue;
    std::string topic;
    char signature;
    std::uint32_t counter;
};

#endif