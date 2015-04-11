#include <Windows.h>

#include "VMT.h"
#include "VTable.h"

namespace Hook {

	VMT::VMT(void *target) {
		VTable_Old = GetVTable(target);
		VTable_Size = GetVTableSize(VTable_Old);

		VTable = new void *[VTable_Size]; //new vtable

		for (size_t i = 0; i < VTable_Size; i++) {
			VTable[i] = GetMethod(target, i);
		}

		SetVTable(target, VTable);
	}

	VMT::~VMT() {
		for (size_t i = 0; i < VTable_Size; i++) {
			VTable[i] = VTable_Old[i];
		}

		delete[] VTable_Old;
	}

	void VMT::Hook(int index, void *hook) {
		VTable[index] = hook;
	}

	void VMT::Unhook(int index) {
		VTable[index] = VTable_Old[index];
	}

	void VMT::Remove() {
		delete this;
	}

}