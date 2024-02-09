#ifndef _QUEUESMANAGER_HPP_
#define _QUEUESMANAGER_HPP_

class Queue;

#include <memory>
#include <vector>
#include <string>

class QueuesManager {
public:
    QueuesManager();

    ~QueuesManager() = default;

    std::shared_ptr<Queue> createQueue() const;
    std::vector<std::shared_ptr<Queue>> getQueues() const;
    std::uint32_t inputValidator(const std::string& issue, std::uint32_t limit) const;

private:
    std::vector<std::shared_ptr<Queue>> queues;
};

#endif