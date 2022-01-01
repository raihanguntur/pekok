#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <codecvt>
#include "il2cpp-typedefs.h"

inline uintptr_t il2cppi_get_base_address()
{
	return (uintptr_t)GetModuleHandleW(L"GameAssembly.dll");
}

inline HMODULE il2cppi_get_module()
{
	return GetModuleHandleW(L"GameAssembly.dll");
}
