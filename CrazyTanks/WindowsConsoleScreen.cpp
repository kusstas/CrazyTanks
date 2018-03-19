// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "WindowsConsoleScreen.h"

#include <conio.h>
#include <iostream>

WindowsConsoleScreen::WindowsConsoleScreen()
{
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(hConsoleOutput, &cursorInfo);
}

void WindowsConsoleScreen::setCursorVisible(bool visible)
{
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(hConsoleOutput, &cursorInfo);
}

void WindowsConsoleScreen::draw(int x, int y, const Pixel& pixel)
{
    // Set colors
    Color bg = pixel.getColorBackground();
    Color ch = pixel.getColorSymbol();
    WORD textArr = static_cast<WORD>(((bg << 4) | ch));

    SetConsoleTextAttribute(hConsoleOutput, textArr);

    // Set cursor
    COORD point;
    point.X = static_cast<SHORT>(x);
    point.Y = static_cast<SHORT>(y);

    SetConsoleCursorPosition(hConsoleOutput, point);
    // print
    _putch(pixel.getSymbol());

    // Set to default colors
    bg = defaultPixel.getColorBackground();
    ch = defaultPixel.getColorSymbol();
    textArr = static_cast<WORD>(((bg << 4) | ch));

    SetConsoleTextAttribute(hConsoleOutput, textArr);
}

void WindowsConsoleScreen::draw(int x, int y, const char* str)
{
    // Set cursor
    COORD point;
    point.X = static_cast<SHORT>(x);
    point.Y = static_cast<SHORT>(y);

    SetConsoleCursorPosition(hConsoleOutput, point);

    std::cout << str;
}

void WindowsConsoleScreen::clear()
{
    system("cls");
}