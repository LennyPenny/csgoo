#include "triggerbot.h"

triggerbot::triggerbot() {
	threadhelper::threadhelper(&logic);
}


void logic(mem *csgo) {
	localPlayer *lply = localPlayer::getLocalPlayer();
	if (!lply->isAlive()) { return; }
	int idAtCrosshair = lply->getCrossHairID();
	if (idAtCrosshair == 0) { return; }

	//DWORD ply;
	//ReadProcessMemory(csgo->getHandle(), csgo->getModuleOffset() + glob::offsets::m_dwEntityList + ( ( idAtCrosshair - 1 ) * 0x10 ), &ply, sizeof(DWORD), nullptr);

	basePlayer atCrosshair(entlist::getEntPtrFromID(idAtCrosshair));
	printf("%d\n", atCrosshair.getTeam());
	if (atCrosshair.getTeam() == lply->getTeam()) { return; }

	POINT point;
	GetCursorPos(&point);
	SendMessage(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(point.x, point.y));
	Sleep(10);
	SendMessage(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(point.x, point.y));
}