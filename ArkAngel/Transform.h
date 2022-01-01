#pragma once

static void* transform_get_position;
static void* transform_set_position;

static void* transform_get_eulerAngles;
static void* transform_set_eulerAngles;

static void* transform_get_localScale;
static void* transform_set_localScale;


struct Transform
{
	Il2CppClass* klass;
	MonitorData* monitor;

	Vector3 GetPosition()
	{
		return reinterpret_cast<Vector3(*)(Transform * pThis)>(transform_get_position)(this);
	}
	void SetPosition(Vector3 position)
	{
		reinterpret_cast<void(*)(Transform * pThis, Vector3 value)>(transform_set_position)(this, position);
	}

	Vector3 GetEulerAngles()
	{
		return reinterpret_cast<Vector3(*)(Transform * pThis)>(transform_get_eulerAngles)(this);
	}
	void SetEulerAngles(Vector3 euler)
	{
		reinterpret_cast<void(*)(Transform * pThis, Vector3 value)>(transform_set_eulerAngles)(this, euler);
	}

	Vector3 GetScale()
	{
		return reinterpret_cast<Vector3(*)(Transform * pThis)>(transform_get_localScale)(this);
	}
	void SetScale(Vector3 scale)
	{
		reinterpret_cast<void(*)(Transform * pThis, Vector3 value)>(transform_set_localScale)(this, scale);
	}
};
inline void SetupTransform()
{
	const Il2CppAssembly* UnityEngine_CoreModule = nullptr;
	size_t asmCount = 0;
	const Il2CppAssembly** assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &asmCount);
	for (int i = 0; i < asmCount; i++)
	{
		if (std::string(assemblies[i]->aname.name) == "UnityEngine.CoreModule")
		{
			UnityEngine_CoreModule = assemblies[i];
			break;
		}
	}
	Il2CppClass* Transform_class = il2cpp_class_from_name(UnityEngine_CoreModule->image, "UnityEngine", "Transform");
	const PropertyInfo* position = il2cpp_class_get_property_from_name(Transform_class, "position");
	const PropertyInfo* eulerAngles = il2cpp_class_get_property_from_name(Transform_class, "eulerAngles");
	const PropertyInfo* localScale = il2cpp_class_get_property_from_name(Transform_class, "localScale");

	transform_get_position = position->get->methodPointer;
	transform_set_position = position->set->methodPointer;

	transform_get_eulerAngles = eulerAngles->get->methodPointer;
	transform_set_eulerAngles = eulerAngles->set->methodPointer;

	transform_get_localScale = localScale->get->methodPointer;
	transform_set_localScale = localScale->set->methodPointer;
}