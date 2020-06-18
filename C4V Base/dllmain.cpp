// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

DWORD WINAPI ControlThread(LPVOID lpParam)
{
	Hooking::Start((HMODULE)lpParam);
	while (g_running) {
		std::this_thread::sleep_for(std::chrono::milliseconds(90));
		std::this_thread::yield();
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	Hooking::Cleanup();
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread, hModule, NULL, NULL);
		break;
	case DLL_THREAD_ATTACH: //kane inject me extreme injector kai tha s pw ok
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		Hooking::Cleanup();
		break;
	}
	return TRUE;
}


