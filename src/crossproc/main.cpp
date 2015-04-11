#include "main.h"
#include "player/baseplayer.h"
#include "player/localplayer.h"
#include "entlist/entlist.h"

#define safecontinue(msToWait) getCsgo()->closeHandle();Sleep(msToWait);continue;

using namespace glob;

mem *glob::getCsgo() {
	static mem csgo("Counter-Strike: Global Offensive");
	return &csgo;
}

localPlayer *getLocalPlayer() {
	static localPlayer lply;
	return &lply;
}

int main(char *argv[], int argc) {
	printf("running...\n");

	printf("%s\n", getCsgo()->getWindowName());

	while (true) {
		if (!getCsgo()->checkForeGroundWindow()) {
			Sleep(100); 
			continue;
		}
		getCsgo()->setModule("client.dll");

	
		getCsgo()->openHandle();

		localPlayer *lply = getLocalPlayer();
		if (!lply->isAlive()) { safecontinue(100); }
		int idAtCrosshair = lply->getCrossHairID();
		if (idAtCrosshair == 0) { safecontinue(10); }
		

		//basePlayer atCrosshair(entlist::getEntPtrFromID(idAtCrosshair));
		//if (atCrosshair.getTeam() == lply->getTeam()) { safecontinue(10); }

		POINT point;
		GetCursorPos(&point);
		SendMessage(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(point.x, point.y));
		Sleep(10);
		SendMessage(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(point.x, point.y));

		getCsgo()->closeHandle();
		Sleep(10);
	}

	return 0;
}