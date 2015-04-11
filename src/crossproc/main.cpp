#include "main.h"
#include "player/baseplayer.h"
#include "player/localplayer.h"
#include "entlist/entlist.h"

#define safecontinue(msToWait) csgo->closeHandle();Sleep(msToWait);continue;

using namespace glob;

int main(char *argv[], int argc) {
	printf("running...\n");

	mem *csgo = mem::getCsgo();

	printf("%s\n", csgo->getWindowName());

	for (;;) {
		if (!csgo->checkForeGroundWindow()) {
			Sleep(100); 
			continue;
		}
		csgo->setModule("client.dll");

	
		csgo->openHandle();

		localPlayer *lply = localPlayer::getLocalPlayer();
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

		csgo->closeHandle();
		Sleep(10);
	}

	return 0;
}