#include "baseplayer.h"

using namespace glob;

basePlayer::basePlayer() {	
}

basePlayer::basePlayer(DWORD plPtr) {
	plyPtr = plPtr;
}

void basePlayer::setMemoryInterface(mem *iface) {
	imem = iface;
}

DWORD basePlayer::getPlyPtr() {
	return plyPtr;
}

int basePlayer::getTeam() {
	return imem->readMemory<int>(getPlyPtr(), offsets::m_iTeamNum);
}

int basePlayer::getHealth() {
	return imem->readMemory<int>(getPlyPtr(), offsets::m_iHealth);
}

bool basePlayer::isAlive() {
	return getHealth() >= 1;
}

Angle basePlayer::getEyeAngles() {
	return imem->readMemory<Angle>(getPlyPtr(), offsets::m_angEyeAngles);
}