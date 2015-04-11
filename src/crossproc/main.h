#pragma once

#include <iostream>
#include <stdio.h>
#include <tchar.h>

#include "windows.h"

#include "injector/injector.h"
#include "mem/mem.h"

const DWORD LocalPlayer_offset = 0xA4A98C;
const DWORD m_iCrosshairID = 0x23F8;

namespace glob {
	mem *getCsgo();

	namespace offsets {
		const DWORD LocalPlayer_offset = 0xA4A98C;
		const DWORD HandleOnGround_offset = 0x14C;
		const DWORD m_bSpotted = 0x9353;
		const DWORD GlobalVars = 0x55A0C0;
		const DWORD m_vecOrigin = 0x134;
		const DWORD m_dwEntList = 0x4A0F0D4;
		const DWORD m_iCrosshairID = 0x23F8;
		const DWORD m_dwEntityList = 0x49EC194;
		const DWORD m_iHealth = 0xfc;
		const DWORD m_dwGlowObject = 0x4afcde4;
		const DWORD m_iTeamNum = 0xf0;
	}
}