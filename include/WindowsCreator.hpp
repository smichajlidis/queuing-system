#ifndef _WINDOWSCREATOR_HPP_
#define _WINDOWSCREATOR_HPP_

#include "Window.hpp"
#include "Station.hpp"
#include "Kiosk.hpp"
#include "AllQueuesScreen.hpp"
#include "WindowsManager.hpp"
#include "QueuesManager.hpp"

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