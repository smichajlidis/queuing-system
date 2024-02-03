#ifndef _QUEUESMANAGER_HPP_
#define _QUEUESMANAGER_HPP_

#include "Queue.hpp"

#include <memory>
#include <vector>
#include <string>

class QueuesManager {
public:
    QueuesManager();

    ~QueuesManager() = default;

    std::shared_ptr<Queue> createQueue() const;
    std::vector<std::shared_ptr<Queue>> getQueues() const;
    int inputValidator(const std::string& issue, int limit) const;

private:
    std::vector<std::shared_ptr<Queue>> queues;
};

#endif