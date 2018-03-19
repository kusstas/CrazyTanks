// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef SCREEN_H
#define SCREEN_H

class Pixel;

class Screen 
{
public:

    virtual void setCursorVisible(bool visible) = 0;
    virtual void draw(int x, int y, const Pixel& pixel) = 0;
    virtual void draw(int x, int y, const char* str) = 0;
    virtual void clear() = 0;

};

#endif // !SCREEN_H