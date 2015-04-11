#pragma once

#include "baseplayer.h"
class localPlayer : public basePlayer {
public:
	localPlayer();
	localPlayer(DWORD lplyPtr);

	int getCrossHairID();
};