#include "il2cpp-appdata.h"
#include "il2cpp-init.h"
#include "il2cpp-helper.h"

// IL2CPP APIs
#define DO_API(r, n, p) r (*n) p
#include "il2cpp-functions.h"
#undef DO_API


void init_il2cpp()
{
	// Get base address of IL2CPP module
	uintptr_t baseAddress = il2cppi_get_base_address();

	HMODULE lib = il2cppi_get_module();
	if (!lib)
	{
		return;
	}

	// right here baby
	#define DO_API(r, n, p) n = (r(*) p)(GetProcAddress(lib, #n))
	#include "il2cpp-functions.h"
	#undef DO_API
}