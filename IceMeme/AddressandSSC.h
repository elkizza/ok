#pragma once
DWORD getfieldaddress = ASLR(0x743B20);
DWORD settopaddress = ASLR(0x745cb0);
DWORD pushstringaddress = ASLR(0x744EE0);
DWORD pushvalueaddress = ASLR(0x744FC0);
DWORD calladdress = ASLR(0x743520);
DWORD setfieldaddress = ASLR(0x7458E0);
DWORD pushnumberaddress = ASLR(0x744E50);
DWORD ScriptContextVFTableaddress = ASLR(0x6c1aee);
DWORD getmetatableaddress = ASLR(0x743DE0);
DWORD pcalladdress = ASLR(0x744910);
DWORD rawrjzaddress = ASLR(0x73cc47);
DWORD pushbooleanaddress = ASLR(0x7449e0);
DWORD Identityaddress = ASLR(0x173B1D0);
DWORD pushniladdress = ASLR(0x744de0);

int v41;//ScriptContext
int v49 = 1;
int luaState;

void ScanScriptContext() {
	DWORD ScriptContextVFTable = *(DWORD*)(ScriptContextVFTableaddress + 0x2);
	v41 = Memory::Scan((char*)&ScriptContextVFTable);
	//luaState
	luaState =(v41 + 56 * 1 + 164) - *(DWORD *)(v41 + 56 * 1 + 164);
	*(DWORD*)Identityaddress = 6;
}