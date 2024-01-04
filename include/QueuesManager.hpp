#ifndef _QUEUESMANAGER_HPP_
#define _QUEUESMANAGER_HPP_
#include <vector>
#include <queue>

class QueuesManager {

    std::vector<std::queue<int>> queues;

public:
    void addQueue(std::queue<int>&);
    void pickATicket(int queueNum);
    QueuesManager() {};
    ~QueuesManager() {};

};

#endif