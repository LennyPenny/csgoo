#include "baseplayer.h"

using namespace glob;

basePlayer::basePlayer() {	
}

basePlayer::basePlayer(DWORD plPtr) {
	plyPtr = plPtr;
}

DWORD basePlayer::getPlyPtr() {
	return plyPtr;
}

int basePlayer::getTeam() {
	return getCsgo()->readMemory<int>(getPlyPtr(), offsets::m_iTeamNum);
}

int basePlayer::getHealth() {
	return getCsgo()->readMemory<int>(getPlyPtr(), offsets::m_iHealth);
}

bool basePlayer::isAlive() {
	return getHealth() >= 1;
}