// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "CrazyTanks.h"
#include "WorldTanks.h"

void CrazyTanks::beginPlay()
{
    Game::beginPlay();

    loadWorld<WorldTanks>();
}