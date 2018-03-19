// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef WINDOWS_CONSOLE_SCREEN_H
#define WINDOWS_CONSOLE_SCREEN_H

#include "Screen.h"
#include "Pixel.h"

#include <Windows.h>

class WindowsConsoleScreen : public Screen
{
public:

    WindowsConsoleScreen();

    virtual void setCursorVisible(bool visible) override;

    virtual void draw(int x, int y, const Pixel& pixel) override;

    virtual void draw(int x, int y, const char* str) override;

    virtual void clear() override;

private:

    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO cursorInfo;
    Pixel defaultPixel;
    
};

#endif // !WINDOWS_CONSOLE_SCREEN_H