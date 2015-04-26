#include "threadhelper.h"

threadhelper::threadhelper(functype func) {
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&loop, func, 0, NULL);
}


DWORD WINAPI loop(functype func) {
	mem *csgo = new mem("Counter-Strike: Global Offensive");

	for (;;) {
		if (!csgo->checkForeGroundWindow()) {
			Sleep(100);
			continue;
		}

		csgo->setModule("client.dll");
		csgo->openHandle();

		func(csgo);

		csgo->closeHandle();
		Sleep(5);
	}
}