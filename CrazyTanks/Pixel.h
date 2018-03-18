// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef PIXEL_H
#define PIXEL_H

// Colors for console
enum Color
{
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GRAY = 7,
    COLOR_DARK_GRAY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_YELLOW = 14,
    COLOR_WHITE = 15
};

class Pixel
{
public:

    Pixel();
    Pixel(char symbol);
    Pixel(char symbol, Color colorSymbol, Color colorBackground);

    char getSymbol() const;
    Color getColorSymbol() const;
    Color getColorBackground() const;

    void setSymbol(char symbol);
    void setColorSymbol(Color colorSymbol);
    void setColorBackground(Color colorBackground);

private:

    char symbol_;
    Color colorSymbol_;
    Color colorBackground_;

};

#endif // !PIXEL_H