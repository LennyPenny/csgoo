#pragma once

#include "windows.h"
#include "../main.h"

class basePlayer {
public:
	basePlayer();
	basePlayer(DWORD plyPtr);
	
	DWORD getPlyPtr();

	int getTeam();
	int getHealth();
	bool isAlive();
protected:
	DWORD plyPtr;
};