#pragma once

#include "Windows.h"
#include "TlHelp32.h"
#include <stdio.h>
#include <string.h>

class mem {
public:
	mem(const char *windowName);
	~mem();

	bool checkForeGroundWindow();

	const char *getWindowName();

	bool openHandle();
	bool closeHandle();

	DWORD getProcID();
	HANDLE getHandle();

	bool setModule(const char *moduleName);
	const char *getModuleOffset();

	template <class retType>
	retType readMemory(DWORD address, bool useModuleOffset = true) {
		retType toReturn;
		ReadProcessMemory(getHandle(), ( LPVOID ) ((useModuleOffset ? getModuleOffset() : 0) + address), &toReturn, sizeof(retType), nullptr);
		return toReturn;
	}
	template <class retType>
	retType readMemory(DWORD address, DWORD offset, bool useModuleOffset = false) {
		if (useModuleOffset)
			address = readMemory<DWORD>(address);

		return readMemory<retType>(address + offset, false);
	}

	private:
	const char *windowName;
	DWORD procId = -1; //let's hope these default values work
	HANDLE handle = 0;
	const char *moduleOffset = 0;
	const char *moduleName = "";

};