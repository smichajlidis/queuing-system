#ifndef _WINDOWSCREATOR_HPP_
#define _WINDOWSCREATOR_HPP_

#include "WindowsManager.hpp"
#include "QueuesManager.hpp"

class Window;
class Station;

#include <string>
#include <memory>

class WindowsCreator {
public:
    WindowsCreator();

    ~WindowsCreator() = default;

    std::shared_ptr<Window> createKiosk();
    std::shared_ptr<Window> createAllQueuesScreen(const std::vector<std::shared_ptr<Station>>& stations);
    std::shared_ptr<Station> createStation();
    std::uint32_t inputValidator(const std::string& issue, std::uint32_t limit) const;

private:
    WindowsManager windows_manager;
    QueuesManager queues_manager;
};

#endif