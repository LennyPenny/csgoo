#pragma once

#include "../main.h"

class entlist {
public:
	static DWORD getEntPtrFromID(int id);

	entlist();
private:
	DWORD entlistPtr;
};