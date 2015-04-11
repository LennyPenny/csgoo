#include "localplayer.h"

using namespace glob;

localPlayer *localPlayer::getLocalPlayer() {
	static localPlayer lply;
	return &lply;
}

localPlayer::localPlayer() {
	plyPtr = mem::getCsgo()->readMemory<DWORD>(offsets::LocalPlayer_offset);
}

localPlayer::localPlayer(DWORD lplyPtr) {
	plyPtr = lplyPtr;
}

int localPlayer::getCrossHairID() {
	return mem::getCsgo()->readMemory<int>(getPlyPtr(), offsets::m_iCrosshairID);
}
