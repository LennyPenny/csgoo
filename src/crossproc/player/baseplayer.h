#pragma once

#include "windows.h"
#include "../main.h"

class basePlayer {
public:
	basePlayer();
	basePlayer(DWORD plyPtr);

	void setMemoryInterface(mem *iface);
	
	DWORD getPlyPtr();

	Angle getEyeAngles();

	int getTeam();
	int getHealth();
	bool isAlive();
protected:
	DWORD plyPtr;
	mem *imem;
};