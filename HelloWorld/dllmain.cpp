// dllmain.cpp : DllMain�� ������ ���Դϴ�.

#include "stdafx.h"
#include "resource.h"
#include "HelloWorld_i.h"
#include "dllmain.h"

CHelloWorldModule _AtlModule;

// DLL �������Դϴ�.
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hInstance);
	}
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
