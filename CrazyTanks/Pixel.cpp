// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "Pixel.h"

Pixel::Pixel()
{
    symbol_ = ' ';
    colorSymbol_ = COLOR_WHITE;
    colorBackground_ = COLOR_BLACK;
}

Pixel::Pixel(char symbol) : Pixel()
{
    symbol_ = symbol;
}

Pixel::Pixel(char symbol, Color colorSymbol, Color colorBackground)
{
    symbol_ = symbol;
    colorSymbol_ = colorSymbol;
    colorBackground_ = colorBackground;
}

char Pixel::getSymbol() const
{
    return symbol_;
}

Color Pixel::getColorSymbol() const
{
    return colorSymbol_;
}

Color Pixel::getColorBackground() const
{
    return colorBackground_;
}

void Pixel::setSymbol(char symbol)
{
    symbol_ = symbol;
}

void Pixel::setColorSymbol(Color colorSymbol)
{
    colorSymbol_ = colorSymbol;
}

void Pixel::setColorBackground(Color colorBackground)
{
    colorBackground_ = colorBackground;
}