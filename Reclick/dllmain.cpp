// dllmain.cpp : Defines the entry point for the DLL application.
// Made by playingo (Discord: DEERUX#1041)
// Re-selling is illegal! Opensource-ware. NOTE: Used to be called 'reclick' but its badly searchable / many people use this name already so I called it "Auraclick"

#include "pch.h"
#include <random>

DWORD WINAPI MainThread(HMODULE hModule)
{
    bool activated = false;
    while (true)
    {
        Sleep(10);
        if (GetAsyncKeyState(VK_F7) & 0x8000) // R key seems like a bad way cuz if u chat etc (i dont know how to detect input, you can pr it), so I changed it to F7.
        {
            activated = !activated;
            Sleep(100);
        }

        
        if (activated) {


            mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL); // mouse press
            Sleep((rand() % 9) + 2);
            mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL); // mouse release after possibly 10ms

            Sleep(21 + std::rand() % 26); // generate delay
        }
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

