#include "main.h"
#include "player/baseplayer.h"
#include "player/localplayer.h"
#include "entlist/entlist.h"

#include "modules/triggerbot.h"

using namespace glob;

int main(char *argv[], int argc) {
	printf("running...\n");

	mem *csgo = mem::getCsgo();

	printf("%s\n", csgo->getWindowName());

	triggerbot trigger;

	for (;;) {}

	return 0;
}