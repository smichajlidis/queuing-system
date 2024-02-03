#include "../include/WindowsManager.hpp"

void WindowsManager::addWindow(std::shared_ptr<Window> window) {
    windows.push_back(window);
}

void WindowsManager::runAllWindows() const {
    while (std::any_of(windows.begin(), windows.end(), [](const auto& window) { return window->isOpen(); })) {
        for (auto& window : windows) {
            window->run();
            if (!window->isOpen()) {
                return;
            }
        }
    }
}