#pragma once
DWORD getfieldaddress = ASLR(0x74BE20);
DWORD settopaddress = ASLR(0x74DFD0);
DWORD pushstringaddress = ASLR(0x74D1F0);
DWORD pushvalueaddress = ASLR(0x74D2B0);
DWORD calladdress = ASLR(0x74b820);
DWORD setfieldaddress = ASLR(0x74DBF0);
DWORD pushnumberaddress = ASLR(0x74d160);
DWORD ScriptContextVFTableaddress = ASLR(0x6c26de);
DWORD getmetatableaddress = ASLR(0x74C0F0);
DWORD pcalladdress = ASLR(0x74cc10);
DWORD rawrjzaddress = ASLR(0x744f57);
DWORD pushbooleanaddress = ASLR(0x74cce0);
DWORD Identityaddress = ASLR(0x17AA254);
DWORD pushniladdress = ASLR(0x74d0f0);

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
