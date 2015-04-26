#include "entlist.h"

using namespace glob;

entlist::entlist() {
	entlistPtr = mem::getCsgo()->readMemory<DWORD>(offsets::m_dwEntityList);
}

DWORD entlist::getEntPtrFromID(int id) {
	return mem::getCsgo()->readMemory<DWORD>(offsets::m_dwEntityList + (( id - 1 ) * 0x10));
}