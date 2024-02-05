#include "../include/WindowGrid.hpp"

#include <cstdarg>
#include <numeric>

void WindowGrid::setRows(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        double val = va_arg(args, double);
        rows.push_back(static_cast<float>(val));
    }
    va_end(args);
}

void WindowGrid::setColumns(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        double val = va_arg(args, double);
        columns.push_back(static_cast<float>(val));
    }
    va_end(args);
}

float WindowGrid::getColumn(int index) const {
    return std::accumulate(columns.begin(), columns.begin() + index, 0);
}

float WindowGrid::getRow(int index) const {
    return std::accumulate(rows.begin(), rows.begin() + index, 0);
}