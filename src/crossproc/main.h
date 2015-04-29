#pragma once

#include <iostream>
#include <stdio.h>
#include <tchar.h>

#include "windows.h"

#include "injector/injector.h"
#include "mem/mem.h"

#define safecontinue(msToWait) csgo->closeHandle();Sleep(msToWait);continue;

struct Vector {
	float x, y, z;
};
struct Angle {
	float x, y, z;
};

namespace glob {

	namespace offsets
	{
		const static DWORD LocalPlayer_offset = 0xa4ca5c;
		const static DWORD HandleOnGround_offset = 0x14C;
		const static DWORD m_bSpotted = 0x935;
		const static DWORD GlobalVars = 0x4e53b8;
		const static DWORD m_vecOrigin = 0x134;
		const static DWORD m_iCrosshairID = 0x2400;
		const static DWORD m_dwEntityList = 0x049ee2e4;
		const static DWORD m_iHealth = 0xfc;
		const static DWORD m_dwGlowObject = 0x04afef74;
		const static DWORD m_iTeamNum = 0xf0;
		const static DWORD m_flFlashMaxAlpha = 0x1da4;
		const static DWORD m_flFlashDuration = 0x1da8;
		const static DWORD m_vecPunch = 0x13e8;
		const static DWORD m_angEyeAngles = 0x23a4;
		const static DWORD m_dwClientState = 0x005c71b4;
		const static DWORD m_dwViewAngles = 0x4ce0;
		const static DWORD m_dwInput = 0x4a36b50;
		const static DWORD m_dwInGame = 0xe8;
	}
}