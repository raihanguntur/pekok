#pragma once
#include "il2cpp-appdata.h"
#define il2cpp_class_get_type_object(klass) il2cpp_type_get_object(il2cpp_class_get_type((Il2CppClass*)klass))

namespace Il2CppSystem
{
	extern const Il2CppAssembly* mscorlib;
	extern Il2CppClass* SystemType_Byte;
	extern Il2CppClass* SystemType_Int32;
	extern Il2CppClass* SystemType_Int64;
	extern Il2CppClass* SystemType_String;
	extern Il2CppClass* SystemType_Type;
	extern Il2CppClass* SystemType_Dictionary_2;
	extern MethodInfo* Type_MakeGeneric;

	inline MethodInfo* FindMethodByToken(Il2CppClass* klass, int token)
	{
		void* iter = nullptr;
		MethodInfo* mi = nullptr;
		while (true)
		{
			mi = (MethodInfo*)il2cpp_class_get_methods(klass, &iter);
			if (mi == nullptr)
				break;
			if (il2cpp_method_get_token(mi) == token)
			{
				return mi;
				break;
			}
		}
	}

	// hacking :)))))))))))
	inline void Init()
	{

		size_t asmCount = 0;
		const Il2CppAssembly** assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &asmCount);
		for (int i = 0; i < asmCount; i++)
		{
			if (std::string(assemblies[i]->aname.name) == "mscorlib")
			{
				mscorlib = assemblies[i];
				break;
			}
		}


		SystemType_Byte = il2cpp_class_from_name(mscorlib->image, "System", "Byte");
		SystemType_Int32 =  il2cpp_class_from_name(mscorlib->image, "System", "Int32");
		SystemType_Int64 =  il2cpp_class_from_name(mscorlib->image, "System", "Int64");
		SystemType_String = il2cpp_class_from_name(mscorlib->image, "System", "String");
		SystemType_Type =   il2cpp_class_from_name(mscorlib->image, "System", "Type");
		SystemType_Dictionary_2 = il2cpp_class_from_name(mscorlib->image, "System.Collections.Generic", "Dictionary`2");
		Type_MakeGeneric = FindMethodByToken(SystemType_Type, 100666373);
	}
	inline static Il2CppClass* CreateGenericClass(Il2CppClass* nonGeneric, std::vector<Il2CppClass*> types)
	{
		const MethodInfo* makeGeneric = il2cpp_object_get_virtual_method(il2cpp_class_get_type_object(nonGeneric), Type_MakeGeneric);
		Il2CppArrayT<Il2CppObject*>* ts = (Il2CppArrayT<Il2CppObject*>*)il2cpp_array_new(SystemType_Type, types.size());
		for (int i = 0; i < ts->max_length; i++)
		{
			ts->vector[i] = il2cpp_class_get_type_object(types[i]);
		}
		return il2cpp_class_from_system_type((Il2CppReflectionType*)il2cpp_runtime_invoke(makeGeneric, il2cpp_class_get_type_object(nonGeneric), (void**)&ts, nullptr));
	}
	static void ConstructObject(Il2CppObject* object)
	{
		il2cpp_runtime_invoke(object->Il2CppClass.klass->methods[0], object, nullptr, nullptr);
	}
}