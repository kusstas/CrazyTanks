// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "PlayerController.h"
#include "Tank.h"

#include <conio.h>

void PlayerController::tick(float deltaTime)
{
    if (_kbhit())
    {
        int ch = _getch();
        if (ch == 0 || ch == 0xE0)
        {
            ch = _getch();
            switch (ch)
            {
            case 72:
                pawn_->startMove(ROTATION_Z_UP);
                break;
            case 75:
                pawn_->startMove(ROTATION_Z_LEFT);
                break;
            case 77:
                pawn_->startMove(ROTATION_Z_RIGHT);
                break;
            case 80:
                pawn_->startMove(ROTATION_Z_DOWN);
                break;
            default:
                pawn_->stopMove();
                break;
            }
        }
        else
        {
            switch (ch)
            {
            case ' ':
                pawn_->fire();
                break;
            }
        }
    }
    else
    {
        pawn_->stopMove();
    }
}