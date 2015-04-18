#pragma once

#include <iostream>
#include <stdio.h>
#include <tchar.h>

#include "windows.h"

#include "injector/injector.h"
#include "mem/mem.h"

#define safecontinue(msToWait) csgo->closeHandle();Sleep(msToWait);continue;

namespace glob {

	namespace offsets
	{
		const DWORD LocalPlayer_offset = 0xa4b98c;
		const DWORD HandleOnGround_offset = 0x14C;
		const DWORD m_bSpotted  = 0x935;
		const DWORD GlobalVars = 0x4e53b8;
		const DWORD m_vecOrigin = 0x134;
		const DWORD EntList = 0x49ed1b4;
		const DWORD m_iCrosshairID = 0x2400;
		const DWORD m_dwEntityList = 0x49EC194;
		const DWORD m_iHealth = 0xfc;
		const DWORD m_dwGlowObject = 0x4afde04;
		const DWORD m_iTeamNum = 0xf0;
		const DWORD viewpunch = 0x13DC;
	}
}