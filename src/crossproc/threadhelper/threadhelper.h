#pragma once
#include "../main.h"

typedef void(*functype)( mem *csgo );

DWORD WINAPI loop(functype);

class threadhelper{
public:
	threadhelper(functype);
};