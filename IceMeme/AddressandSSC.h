#pragma once
DWORD getfieldaddress = ASLR(0x74BE20); // updated
DWORD settopaddress = ASLR(0x74DFD0);  // updated
DWORD pushstringaddress = ASLR(0x74D1F0);  // updated
DWORD pushvalueaddress = ASLR(0x74D2B0);  // updated
DWORD calladdress = ASLR(0x74b820);  // updated
DWORD setfieldaddress = ASLR(0x74DBF0);  // updated
DWORD pushnumberaddress = ASLR(0x74d160); // updated
DWORD ScriptContextVFTableaddress = ASLR(0x6c26de); // updated
DWORD getmetatableaddress = ASLR(0x74C0F0); // updated
DWORD pcalladdress = ASLR(0x74cc10); // updated
DWORD rawrjzaddress = ASLR(0x744f57); // updated
DWORD pushbooleanaddress = ASLR(0x74cce0); // updated
DWORD Identityaddress = ASLR(0x17AA254); // updated
DWORD pushniladdress = ASLR(0x74d0f0); // updated

int v41;//ScriptContext
int v49 = 1;
int luaState;

void ScanScriptContext() {
	DWORD ScriptContextVFTable = *(DWORD*)(ScriptContextVFTableaddress + 0x2);
	v41 = Memory::Scan((char*)&ScriptContextVFTable);
	//luaState
	luaState =*(DWORD *)(v41 + 56 * 1 + 164) - (v41 + 56 * 1 + 164);
	*(DWORD*)Identityaddress = 6;
}
