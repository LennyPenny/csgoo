#include "localplayer.h"

using namespace glob;

localPlayer::localPlayer() {
	plyPtr = getCsgo()->readMemory<DWORD>(offsets::LocalPlayer_offset);
}

localPlayer::localPlayer(DWORD lplyPtr) {
	plyPtr = lplyPtr;
}

int localPlayer::getCrossHairID() {
	return getCsgo()->readMemory<int>(getPlyPtr(), offsets::m_iCrosshairID);
}
