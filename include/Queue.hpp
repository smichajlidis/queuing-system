#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_
#include <vector>
#include <string>

class Queue {
    std::vector<int> queue {};
    std::string topic {};
    char signature {};
    int queueLength {0};
    int priority = 0;
public:
    void pickATicket(); // take a new ticket
    size_t size() const;
    char getSignature() const;
    void deleteFirstTicket();
    int getATicket(int pos) const; // get a name of existing ticket
    Queue();
    Queue(std::string topic, char signature);
    Queue(std::string topic, char signature, int priority);
    ~Queue();
};

#endif