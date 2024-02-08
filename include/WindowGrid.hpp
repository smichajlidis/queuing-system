#ifndef _WINDOWGRID_HPP_
#define _WINDOWGRID_HPP_

#include <vector>
#include <cstdint>

class WindowGrid {
public:
    WindowGrid() = default;

    ~WindowGrid() = default;

    void setRows(std::uint32_t count, ...);
    void setColumns(std::uint32_t count, ...);
    float getColumn(std::uint32_t index) const;
    float getRow(std::uint32_t index) const;

private:
    std::vector<float> rows;
    std::vector<float> columns;
};

#endif