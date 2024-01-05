#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_
#include <queue>
#include <string>

class Queue {
    std::queue<int> queue {};
    std::string topic {};
    int queueLength {0};
    int priority = 0;
public:
    void pickATicket();
    Queue();
    Queue(std::string topic);
    Queue(std::string topic, int priority);
    ~Queue();
};

#endif