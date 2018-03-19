// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "Controller.h"

Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::setPawn(Tank& pawn)
{
    pawn_ = &pawn;
}

const Tank& Controller::getPawn() const
{
    return *pawn_;
}