#include "glow.h"

using namespace glob;

glow::glow() {
	threadhelper::threadhelper(&logic3);
}

void glow::logic() {
	DWORD glowObjectArray = getGlowObjectArray();
	GlowObjectDefinition_t glowObjects[128];
	int count = getGlowObjectCount();
	size_t size = count * sizeof(GlowObjectDefinition_t);
	ReadProcessMemory(imem->getHandle(), ( void * ) glowObjectArray, &glowObjects, size, nullptr);
	for (int i = 0; i < count; i++) {
		basePlayer curPlayer((DWORD)glowObjects[i].pEntity);
		if (!curPlayer.isAlive())
			continue;
		glowObjects[i].a = 1.f;
		if (curPlayer.getTeam() != localPlayer::getLocalPlayer(imem)->getTeam()) {
			glowObjects[i].r = 1;
			glowObjects[i].g = 0;
			glowObjects[i].b = 0;
		} else {
			glowObjects[i].r = 0;
			glowObjects[i].g = 1;
			glowObjects[i].b = 0;
		}
		glowObjects[i].m_bRenderWhenOccluded = true;
		glowObjects[i].m_bRenderWhenUnoccluded = false;
	}
	WriteProcessMemory(imem->getHandle(), ( void * ) glowObjectArray, &glowObjects, size, nullptr);
}

DWORD glow::getGlowObjectArray() {
	return imem->readMemory<DWORD>(offsets::m_dwGlowObject);
}

uint32_t glow::getGlowObjectCount() {
	return imem->readMemory<int>(offsets::m_dwGlowObject + 0x4);
}

void logic3(mem *csgo) {
	glow::imem = csgo;
	glow::logic();
	Sleep(250);
}

mem *glow::imem = 0;