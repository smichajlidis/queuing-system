#include "../include/TextParameters.hpp"

int TextParameters::getFontSize() const {
    return font_size;
}

int TextParameters::getSpaceBetweenColumns() const {
    return space_between_columns;
}

int TextParameters::getSpaceBetweenLines() const {
    return space_between_lines;
}

int TextParameters::getStartingPosition() const {
    return starting_position;
}