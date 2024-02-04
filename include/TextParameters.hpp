#ifndef _TEXTPARAMETERS_HPP_
#define _TEXTPARAMETERS_HPP_

class TextParameters {
public:
    TextParameters() :
        font_size {18},
        space_between_columns {50},
        space_between_lines {80},
        starting_position {20} {}

    ~TextParameters() = default;

    int getFontSize() const;
    int getSpaceBetweenColumns() const;
    int getSpaceBetweenLines() const;
    int getStartingPosition() const;

private:
    int font_size;
    int space_between_columns;
    int space_between_lines;
    int starting_position;
};

#endif