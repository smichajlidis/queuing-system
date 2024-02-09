#ifndef _WINDOWSMANAGER_HPP_
#define _WINDOWSMANAGER_HPP_

class Window;

#include <memory>
#include <vector>

class WindowsManager {
public:
    WindowsManager() = default;

    ~WindowsManager() = default;

    void addWindow(std::shared_ptr<Window> window);
    void runAllWindows() const;

private:
    std::vector<std::shared_ptr<Window>> windows;
};

#endif