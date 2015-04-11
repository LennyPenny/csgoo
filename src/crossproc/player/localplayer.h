#pragma once

#include "baseplayer.h"
class localPlayer : public basePlayer {
public:
	static localPlayer *getLocalPlayer();

	localPlayer();
	localPlayer(DWORD lplyPtr);

	int getCrossHairID();
};