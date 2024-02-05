#ifndef _WINDOWGRID_HPP_
#define _WINDOWGRID_HPP_

#include <vector>

class WindowGrid {
public:
    WindowGrid() = default;

    ~WindowGrid() = default;

    void setRows(int count, ...);
    void setColumns(int count, ...);
    float getColumn(int index) const;
    float getRow(int index) const;

private:
    std::vector<float> rows;
    std::vector<float> columns;
};

#endif