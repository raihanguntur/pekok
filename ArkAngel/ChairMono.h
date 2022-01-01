#pragma once
#define ARKANGEL_ASSERT(v, msg) if (!v) {Console.printf("Error: %s (%s)", msg, #v); return; }
#define ARKANGEL_ASSERT(v, msg, r) if (!v) {Console.printf("Error: %s (%s)", msg, #v); return r; }

std::string getcwd();
namespace Mono
{
	//MonoMethod* onChatCommandMethod = nullptr;
	MonoThread* gfxThread = nullptr;
	MonoMethod* updateMethod = nullptr;
	MonoMethod* onConsumeBytes = nullptr;
	std::vector<MonoAssembly*> openAssemblies = {};
	void InitMono()
	{
		std::string cwd = getcwd();
		mono_set_dirs((cwd + "\\mono-shipping\\lib").c_str(), (cwd + "\\mono-shipping\\etc\\mono\\mconfig\\").c_str());

		const char* domainName = "ChairMonoDomain";
		MonoDomain* rootDomain = mono_jit_init(domainName);
		ARKANGEL_ASSERT(rootDomain, "Domain Failed To Create");
		mono_domain_set_config(rootDomain, (cwd + "\\mono-shipping\\etc\\mono\\4.5").c_str(), "machine.config");
	}
	void ReInitMono()
	{
		updateMethod = nullptr;
		onConsumeBytes = nullptr;
		onChatCommandMethod = nullptr;
		openAssemblies.clear();

		MonoDomain* domainToUnload = mono_domain_get();
		if (domainToUnload && domainToUnload != mono_get_root_domain())
		{
			mono_domain_set(mono_get_root_domain(), false);
			mono_domain_unload(domainToUnload);
		}

	}

	void ShutdownMono()
	{
		MonoDomain* domainToUnload = mono_domain_get();
		if (domainToUnload && domainToUnload != mono_get_root_domain())
		{
			mono_domain_set(mono_get_root_domain(), false);
			mono_domain_unload(domainToUnload);
		}

		MonoDomain* rootDomain = mono_get_root_domain();
		if (!rootDomain)
			return; 
		//MonoDomain* domainToUnload = mono_domain_get();
		//if (domainToUnload && domainToUnload != mono_get_root_domain())
		//{
		//	mono_domain_set(mono_get_root_domain(), false);
		//	mono_domain_unload(domainToUnload);
		//}

		

		mono_jit_cleanup(rootDomain);
	}


	void Console_AddLog_Mono(MonoString* s)
	{
		std::string s_utf8 = mono_string_to_utf8(s);
		Console.AddLog(s_utf8);
	}
	
	MonoString* getcwd_mono()
	{
		return mono_string_new(mono_domain_get(), getcwd().c_str());
	}

	void hook_mono(void* target, void* detour, void** original)
	{
		MH_CreateHook(target, detour, original);
		MH_EnableHook(target);
	}

	MonoBoolean IsInWorld_mono()
	{
		return Globals::IsInWorld;
	}

	MonoBoolean QueryMiscBool_mono(MonoString* s)
	{
		std::string s_utf8 = mono_string_to_utf8(s);
		return Globals::MiscBools[s_utf8].value;
	}

	

	void RunMonoFile(const std::string& path)
	{
		ARKANGEL_ASSERT(mono_get_root_domain(), "No Domain");
		MonoAssembly* assembly = nullptr;

		char* name = (char*)"TempAppDomain";
		MonoDomain* newDomain = mono_domain_create_appdomain(name, NULL);
		mono_domain_set(newDomain, false); 

		MonoImageOpenStatus openStatis;
		assembly = mono_assembly_open(path.c_str(), &openStatis);
		ARKANGEL_ASSERT(assembly, "Failed to Create assembly");
		 
		MonoImage* image = mono_assembly_get_image(assembly);
		ARKANGEL_ASSERT(image, "Failed to Get Assembly Image");

		MonoClass* mainClass = mono_class_from_name(image, "MainNamespace", "MainClass");
		ARKANGEL_ASSERT(mainClass, "Failed to Get Main Class from Image");

		MonoClass* importClass = mono_class_from_name(image, "Imports", "ImportClass");
		ARKANGEL_ASSERT(importClass, "Failed to Get Import Class from Image");

		mono_add_internal_call("Imports.ImportClass::getcwd", getcwd_mono);
		mono_add_internal_call("Imports.ImportClass::hook", hook_mono);
		mono_add_internal_call("Imports.ImportClass::IsInWorld", IsInWorld_mono);
		mono_add_internal_call("Imports.ImportClass::QueryMiscBool", QueryMiscBool_mono);

		MonoClass* consoleImportClass = mono_class_from_name(image, "Imports", "ArkConsole");
		ARKANGEL_ASSERT(consoleImportClass, "Failed to Get Console Import Class from Image");

		mono_add_internal_call("Imports.ArkConsole::AddLog", Console_AddLog_Mono);

		MonoMethod* mainMethod = mono_class_get_method_from_name(mainClass, "Main", 0);
		ARKANGEL_ASSERT(mainClass, "Failed to Get Main Function from Main Class");
		updateMethod = mono_class_get_method_from_name(mainClass, "Update", 0);
		onChatCommandMethod = mono_class_get_method_from_name(mainClass, "OnChatCommand", 2);
		onConsumeBytes = mono_class_get_method_from_name(mainClass, "OnConsumeBytes", 1);

		mono_runtime_invoke(mainMethod, nullptr, nullptr, nullptr);
		openAssemblies.push_back(assembly);
	}
}

std::string getcwd()
{
	// this is sexy code
	char buffer[MAX_PATH];
	GetModuleFileNameA(GetModuleHandleA("ArkAngel.dll"), buffer, MAX_PATH);
	std::string path = std::string(buffer);
	std::string::size_type pos = path.find_last_of("\\/");
	return path.substr(0, pos);
}