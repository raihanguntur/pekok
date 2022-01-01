#pragma once
#include "il2cpp-appdata.h"
#include <chrono>
#include <unordered_map>
#include "kiero/kiero.h"
#include "kiero/minhook/include/MinHook.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_stdlib.h"
#include "imgui/imgui_internal.h"
#include "Globals.h"
#include <string>
#include <vector>
#define istr(d) il2cpp_string_new(d)
#define cppstr(d) string_Utf16ToUtf8(d)
#define il2cpp_array_get(array, type, index) ((type*)((uintptr_t)array + 0x20))[index]
#define il2cpp_object_get_field_value(object, type, field)  *(type*)((uintptr_t)object + field->offset)
#define il2cpp_object_get_field_value_by_name(object, type, class, fieldName)  *(type*)((uintptr_t)object + il2cpp_class_get_field_from_name(class, fieldName)->offset)
#define il2cpp_object_get_field_value_static(static_fields, type, class, field)  *(type*)((uintptr_t)static_fields + field->offset)
#define il2cpp_object_get_field_value_static_by_name(static_fields, type, class, fieldName)  *(type*)((uintptr_t)static_fields + il2cpp_class_get_field_from_name(class, fieldName)->offset)
#define il2cpp_object_get_field_value_by_offset(object, type, offset) *(type*)((uintptr_t)object + offset)
#define il2cpp_list_get(list, type, index) il2cpp_array_get(*(Il2CppArray**)((uintptr_t)list + 0x10), type, index)
#define InBounds(point, bounds) (!(point.x > bounds.x - 1 || point.x < 0 || point.y > bounds.y - 1 || point.y < 0))
#define il2cpp_call_catch(function, onwrap, onexcept) try { function; } catch (Il2CppExceptionWrapper& e) { onwrap; } catch (Il2CppException& e) { onexcept; }
#define il2cpp_call_catch_console(function) try { function; } catch (Il2CppExceptionWrapper& e) { Console.printf("Il2CppException: %s", cppstr(e.ex->message).c_str()); } catch (Il2CppException& e) { Console.printf("Il2CppException: %s", cppstr(e.message).c_str()); }
#define strcnt(str, toFind) (strstr(str, toFind) != 0)
#define il2cpp_raise_exception(exc) if (ecx != nullptr) { Console.errorf("%s", cppstr(ecx->ex->message).c_str()); }
#define il2cpp_object_make(n, ctype, itype) ctype n = (ctype)il2cpp_object_new(itype); Il2CppSystem::ConstructObject((Il2CppObject*)n);
#define il2cpp_object_remake(n, ctype, itype) n = (ctype)il2cpp_object_new(itype); Il2CppSystem::ConstructObject((Il2CppObject*)n);
#define il2cpp_time_to_c(t) (((t & 0x3FFFFFFFFFFFFFFF) - 0x089f7ff5f7b58000) / 10000000)

inline void u_AllocConsole()
{
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
}
inline bool string_StartsWith(const std::string& str, const char* with)
{
	return str.find(with, 0) == 0;
}
inline bool string_EndsWidth(const std::string& str, const char* with)
{
	size_t len = strlen(with);
	if (str.length() >= len)
	{
		int rfound = str.find(with, 0);
		return rfound == (str.length() - len);
	}
	else
		return false;
}
inline std::string string_ToLowercase(const std::string& str)
{
	std::string tempString = str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			tempString[i] += 32;
	}
	return tempString;
}
inline std::string string_ToUppercase(const std::string& str)
{
	std::string tempString = str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			tempString[i] -= 32;
	}
	return tempString;
}
inline std::string string_ReplaceAll(const std::string& str, const char* from, const char* to)
{
	std::string tempString = str;
	size_t to_len = strlen(to);
	size_t from_len = strlen(from);
	if (strlen(from) == 0)
		return "";
	size_t start_pos = 0;
	while ((start_pos = tempString.find(from, start_pos)) != std::string::npos)
	{
		tempString.replace(start_pos, from_len, to);
		start_pos += to_len;
	}
	return tempString;
}
inline std::vector<std::string> string_Split(const std::string& str, const char* token)
{
	std::vector<std::string> s = {};
	char* t = strtok((char*)str.c_str(), token);
	while (t != NULL) {
		s.push_back(t);
		t = strtok(NULL, token);
	}
	return s;
}
bool strlwrcmp(const char* str, const char* str2)
{
	char* lwr1 = strdup(str); // make a copy
	char* lwr2 = strdup(str2); // make a copy

// adjust copy to lowercase
	unsigned char* tptr = (unsigned char*)lwr1;
	while (*tptr)
	{
		*tptr = tolower(*tptr);
		tptr++;
	}

	unsigned char* tptr2 = (unsigned char*)lwr2;
	while (*tptr2)
	{
		*tptr2 = tolower(*tptr2);
		tptr2++;
	}

	bool b = strcnt(lwr1, lwr2);

	// release copy
	free(lwr1);
	free(lwr2);
	return b;
}
char* frmt(size_t bufSize, const char* format, ...)
{
	char* buffer = new char[bufSize];
	va_list args;
	va_start(args, format);
	vsprintf_s(buffer, bufSize, format, args);
	va_end(args);
	return buffer;
}
std::string string_printf(const char* format, ...)
{
	va_list argsToCheckSize;
	int n;
	std::string ret;

	va_start(argsToCheckSize, format);
	// use a temporary buffer as some docs indicate we cannot pass NULL to vsnprintf
	char buf[1];
	n = vsnprintf(buf, 0, format, argsToCheckSize);
	if (n == -1)
		return NULL;

	ret.resize(n + 1, 0);
	va_end(argsToCheckSize);

	va_list argsToFormat;

	va_start(argsToFormat, format);
	n = vsnprintf(&ret[0], ret.size(), format, argsToFormat);
	va_end(argsToFormat);


	if (n == -1)
		return "";

	// The v*printf methods might put a trailing NUL character, which should not not be in a
	// std::string, so strip it out.
	if (!ret.empty() && ret[ret.size() - 1] == '\0')
		ret = ret.substr(0, ret.size() - 1);

	return ret;
}
inline char* cstring_Utf16ToUtf8(const Il2CppString* utf16String)
{
	char* buffer = new char[utf16String->length];
	for (int i = 0; i < utf16String->length; i++)
	{
		buffer[i] = (char)utf16String->chars[i];
	}
	return buffer;
}
inline unsigned int ComputeStringHash(const char* str)
{
	unsigned int num = 2166136261U;
	while (*str)
	{
		num = ((unsigned char)(*str) ^ num) * 16777619U;
		str++;
	}
	return num;
}

struct CmdStr
{
public:
	std::string command = "";
	std::vector<std::string> args = {};
	std::string fullMessage = "";
	std::string fullArgs = "";
	bool valid = true;
	static CmdStr Parse(std::string objectToParse, const char* beginCharactar)
	{
		CmdStr o{};
		if (string_StartsWith(objectToParse, beginCharactar))
		{
			int firstSplit = objectToParse.find(" ");
			if (firstSplit > -1)
			{
				o.command = objectToParse.substr(1, firstSplit - 1);
				std::string s = objectToParse.substr(firstSplit);
				o.args = string_Split(s, " ");
			}
			else
			{
				o.command = objectToParse.substr(1);
			}
			o.fullMessage = objectToParse.substr(1);
		}
		else
		{
			o.valid = false;
		}
		return o;
	}
	static CmdStr Parse(std::string objectToParse)
	{
		CmdStr o{};
		int firstSplit = objectToParse.find(" ");
		if (firstSplit > -1)
		{
			o.fullArgs = objectToParse.substr(firstSplit+1);
			o.command = objectToParse.substr(0, firstSplit);
			std::string s = objectToParse.substr(firstSplit);
			o.args = string_Split(s, " ");
		}
		else
		{
			o.command = objectToParse.substr(0);
		}
		o.fullMessage = objectToParse;
		return o;
	}
};
bool IsBadMem(void* p)
{
	if ((uintptr_t)p < 10000)
		return true;
	MEMORY_BASIC_INFORMATION mbi = { 0 };
	if (::VirtualQuery(p, &mbi, sizeof(mbi)))
	{
		DWORD mask = (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);
		bool b = !(mbi.Protect & mask);
		// check the page is not a guard page
		if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) b = true;

		return b;
	}
	return true;
}
template<typename T> T Read(uintptr_t address)
{
	if (address <= 10000000)
	{
		return T();
	}
	return *(T*)address;
}
template<typename T> void Write(uintptr_t address, T value)
{
	if (address <= 1000000)
	{
		return;
	}
	*(T*)address = value;
}
namespace Il2Cpp
{
	namespace Helpers
	{
		Il2CppObject* ObjectFromFieldPath(Il2CppClass* staticBase, std::vector<std::string> args)
		{
			FieldInfo* startField = il2cpp_class_get_field_from_name(staticBase, args[0].c_str());
			Il2CppObject* object = il2cpp_object_get_field_value_static(staticBase->static_fields, Il2CppObject*, staticBase, startField);//GetStaticFieldValue<Il2CppObject*>(startField);
			for (int i = 1; i < args.size(); i++)
			{
				object = il2cpp_object_get_field_value_by_name(object, Il2CppObject*, object->Il2CppClass.klass, args[i].c_str());//GetFieldValue<Il2CppObject*>(il2cpp_class_get_field_from_name(il2cpp_object_get_class(object), args[i].c_str()), object);
			}
			return object;
		}
		Il2CppObject* ParseForObject(std::string input, bool* foundOnlyBase)
		{
			*foundOnlyBase = false;
			std::vector<std::string> splits = string_Split(input, ".");
			if (splits.size() < 1)
			{
				return nullptr;
			}
			Il2CppClass* base = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", splits[0].c_str());
			if (!base)
			{
				return nullptr;
			}
			if (splits.size() == 1)
			{
				*foundOnlyBase = true;
				return (Il2CppObject*)base;
			}
			Il2CppObject* current = nullptr;
			FieldInfo* staticField = il2cpp_class_get_field_from_name(base, splits[1].c_str());
			if (staticField)
			{
				il2cpp_field_static_get_value(staticField, &current);
			}
			else
			{
				*foundOnlyBase = true;
				return (Il2CppObject*)base;
			}
			if (current)
			{
				for (int i = 2; i < splits.size(); i++)
				{
					if (!current || !current->Il2CppClass.klass || IsBadMem(current->Il2CppClass.klass->fields))
						return nullptr;
					FieldInfo* field = il2cpp_class_get_field_from_name(current->Il2CppClass.klass, splits[i].c_str());
					if (field)
					{
						current = il2cpp_field_get_value_object(field, current);
					}
					else
					{
						return current;
					}
				}
			}
			else
			{
				return nullptr;
			}
			return current;
		}
		void** GenerateArgs(std::vector<void*> args)
		{
			void** data = new void* [args.size()];
			for (int i = 0; i < args.size(); i++)
			{
				data[i] = args[i];
			}
			return data;
		}
		MethodInfo* GetMethod(std::string classMethod, int argCount)
		{
			size_t indx = classMethod.find(".");
			if (indx == -1)
				return nullptr;
			return (MethodInfo*)il2cpp_class_get_method_from_name(il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", classMethod.substr(0, indx).c_str()), classMethod.substr(indx + 1).c_str(), argCount);
		}
		MethodInfo* GetMethod(std::string classMethod, char splitter, int argCount)
		{
			size_t indx = classMethod.find(splitter);
			if (indx == -1)
				return nullptr;
			return (MethodInfo*)il2cpp_class_get_method_from_name(il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", classMethod.substr(0, indx).c_str()), classMethod.substr(indx + 1).c_str(), argCount);
		}
		MethodInfo* GetMethod(std::string classMethod, char* splitter, int argCount)
		{
			size_t indx = classMethod.find(splitter[0]);
			if (indx == -1)
				return nullptr;
			return (MethodInfo*)il2cpp_class_get_method_from_name(il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", classMethod.substr(0, indx).c_str()), classMethod.substr(indx + 1).c_str(), argCount);
		}
		MethodInfo* GetMethod(std::string classMethod, std::string splitter, int argCount)
		{
			size_t indx = classMethod.find(splitter[0]);
			if (indx == -1)
				return nullptr;
			return (MethodInfo*)il2cpp_class_get_method_from_name(il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", classMethod.substr(0, indx).c_str()), classMethod.substr(indx + 1).c_str(), argCount);
		}
		MethodInfo* GetMethod(std::string classMethod, std::string splitter, std::string namespaze, int argCount)
		{
			size_t indx = classMethod.find(splitter[0]);
			if (indx == -1)
				return nullptr;
			return (MethodInfo*)il2cpp_class_get_method_from_name(il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, namespaze.c_str(), classMethod.substr(0, indx).c_str()), classMethod.substr(indx + 1).c_str(), argCount);
		}
	}
	namespace Enums
	{
		bool IsEnum(const Il2CppClass* klass)
		{
			return il2cpp_class_is_enum(klass);
		}
		int StringToEnum(const Il2CppClass* enumClass, const char* s, bool useCase = true)
		{
			if (!il2cpp_class_is_enum(enumClass))
				return -1;
			if (useCase)
			{
				for (int i = 1; i < enumClass->field_count - 1; i++)
				{
					if (strcmp(enumClass->fields[i].name, s) == 0)
					{
						return i - 1;
					}
				}
			}
			else
			{
				std::string v = string_ToLowercase(s);
				for (int i = 1; i < enumClass->field_count - 1; i++)
				{
					std::string l = string_ToLowercase(enumClass->fields[i].name);
					if (strcmp(l.c_str(), v.c_str()) == 0)
					{
						return i - 1;
					}
				}
			}
			return -1;
		}
		std::string EnumToString(const Il2CppClass* enumClass, int val)
		{
			if (!il2cpp_class_is_enum(enumClass))
				return "";
			val++;
			if (val > enumClass->field_count - 2 || val < 1)
				return "";
			return enumClass->fields[val].name;
		}
	}
	namespace Arrays
	{
		template<typename T> inline T il2cpp_array_index(Il2CppArray* arry, int index)
		{
			T* ta = (T*)((uintptr_t)arry + 0x20);
			return ta[index];
		}
		template<typename T> inline void il2cpp_array_index_set(Il2CppArray* arry, int index, T v)
		{
			//Write<T>((uintptr_t)arry + 0x20 + index * sizeof(T), v);
			T* ta = (T*)((uintptr_t)arry + 0x20);
			ta[index] = v;
		}
		template<typename T> inline void il2cpp_array_2d_index_set(Il2CppArray* arry, int index, int index2, T v)
		{
			il2cpp_array_index_set<T>(il2cpp_array_index<Il2CppArray*>(arry, index), index2, v);
		}
		template<typename T> inline T il2cpp_array_2d_index(Il2CppArray* arry, int index, int index2)
		{
			return il2cpp_array_index<T>(il2cpp_array_index<Il2CppArray*>(arry, index), index2);
		}

		template<typename T> inline T* il2cpp_array_as_vector(Il2CppArray* arry)
		{
			return (T*)((uintptr_t)arry + 0x20);
		}
	}
	namespace Lists
	{
		Il2CppArray* il2cpp_list_get_array(Il2CppObject* list)
		{
			return Read<Il2CppArray*>(uintptr_t(list) + 0x10);
		}
		int il2cpp_list_get_size(Il2CppObject* list)
		{
			return *(int*)(uintptr_t(list) + 0x18);
		}
		template<typename T> T il2cpp_list_index(Il2CppObject* list, int index)
		{
			return Read<T>((uintptr_t)il2cpp_list_get_array(list) + 0x20 + index * sizeof(T));
		}
		template<typename T> void il2cpp_list_add(Il2CppObject* list, T element)
		{
			//reinterpret_cast<void(__cdecl*)(Il2CppObject** pThis, T item)>(il2cpp_class_get_method_from_name(list->Il2CppClass.klass, "Add", 1)->methodPointer)(&list, element);
			void** args = new void* { ((void*)&element) };
			il2cpp_runtime_invoke(il2cpp_class_get_method_from_name(list->Il2CppClass.klass, "Add", 1), list, args, nullptr);
			delete args;
		}
	}
	namespace Object
	{
		template<typename T> T GetValue(Il2CppObject* object)
		{
			return *(T*)(uintptr_t(object) + 0x10);
		}
		Il2CppReflectionType* GetType(Il2CppObject* object)
		{
			const static MethodInfo* x = il2cpp_class_get_method_from_name(il2cpp_class_from_name(Globals::Assemblies["mscorlib"]->image, "System", "Object"), "GetType", 0);
			return reinterpret_cast<Il2CppReflectionType * (*)(Il2CppObject * object)>(x->methodPointer)(object);
		}
	}
}
void imgui_CheckboxAutowrap(const char* text)
{
	// bounty is sucking chairs dick rn
	ImGuiStyle& style = ImGui::GetStyle();
	float wid = ImGui::CalcTextSize(text).x + style.FramePadding.x * 2.f;
	float window_visible_x2 = ImGui::GetWindowPos().x + ImGui::GetWindowContentRegionMax().x;
	float next_button_x2 = ImGui::GetItemRectMax().x + style.ItemSpacing.x + wid + 13.f;
	if (next_button_x2 < window_visible_x2)
		ImGui::SameLine();
}
int FindExtraWindowHeight(HWND h)
{
	RECT w, c;
	GetWindowRect(h, &w);
	GetClientRect(h, &c);
	return (w.bottom - w.top) - (c.bottom - c.top);
}

// these are shitty functions, optimize them please
static bool IsInWorld_Deprecated()
{
	static FieldInfo* f = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], "kukouriCamera");
	static FieldInfo* f2 = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], "worldController");
	if (/*Il2Cpp::Helpers::GetStaticFieldValue<uintptr_t>(f)*/il2cpp_object_get_field_value_static(f->parent->static_fields, uintptr_t, f->parent, f) > 1000000 && Read<uintptr_t>(il2cpp_object_get_field_value_static(f->parent->static_fields, uintptr_t, f->parent, f) + 0x10) > 1000000)
		return true;
	return false;
}
static bool IsInWorld()
{
	static void* controllerHelper = Globals::Classes["Assembly-CSharp.ControllerHelper"]->static_fields;
	static int worldControllerOffset = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], "worldController")->offset;
	static int worldOffset = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.WorldController"], "world")->offset;
	static int worldItemsDataOffset = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.World"], "worldItemsData")->offset;

	Il2CppObject* worldController = il2cpp_object_get_field_value_by_offset(controllerHelper, Il2CppObject*, worldControllerOffset);
	if (IsBadMem(worldController))
		return false;
	Il2CppObject* world = il2cpp_object_get_field_value_by_offset(worldController, Il2CppObject*, worldOffset);
	if (IsBadMem(world))
		return false;
	Il2CppObject* worldItemsData = il2cpp_object_get_field_value_by_offset(world, Il2CppObject*, worldItemsDataOffset);
	if (IsBadMem(worldItemsData))
		return false;
	if (!IsInWorld_Deprecated())
		return false;
	return true;
}

static int cameraZoom = 4;
static Vector2 cameraOrigin = 4;
Vector2i WorldToScreen(Vector2 worldPoint)
{
	float worldScaling = 100.f * cameraZoom;
	return Vector2i
	{
		((int)(worldPoint.x * worldScaling) - (int)(cameraOrigin.x * worldScaling)),
		((int)(cameraOrigin.y * worldScaling) - (int)(worldPoint.y * worldScaling))
	};
}
Vector2 ScreenToWorld(Vector2i screenPoint)
{
	RECT winRect;
	GetWindowRect(Globals::hWnd, &winRect);
	POINT lpPoint = POINT{ winRect.left, winRect.top };
	ScreenToClient(Globals::hWnd, &lpPoint);
	
	float worldScaling = 100.f * cameraZoom;
	float x = cameraOrigin.x + (screenPoint.x / worldScaling);
	float y = (cameraOrigin.y + (((lpPoint.y + FindExtraWindowHeight(Globals::hWnd)) - screenPoint.y) / worldScaling)) - 0.04;
	return Vector2{ x, y };
}
Vector2i ScaleToScreen(Vector2 point)
{
	float worldScaling = 100.f * cameraZoom;
	
	return Vector2i{ int(point.x * worldScaling), int(point.y * worldScaling) };
}
float ScaleToScreen(float point)
{
	float worldScaling = 100.f * cameraZoom;

	return point * worldScaling;
}
Vector2 ConvertMapPointToWorldPoint(Vector2i mapPoint)
{
	return Vector2{ (float)mapPoint.x * Globals::tileSize.x, (float)mapPoint.y * Globals::tileSize.y };
}
Vector2 ConvertMapPointToWorldPoint(Vector2 mapPoint)
{
	return Vector2{ mapPoint.x * Globals::tileSize.x, mapPoint.y * Globals::tileSize.y };
}
Vector2 ConvertMapPointToWorldPoint(float x, float y)
{
	return Vector2{ x * Globals::tileSize.x, y * Globals::tileSize.y };
}
Vector2i ConvertWorldPointToMapPoint(Vector2 worldPoint)
{
	return Vector2i{ (int)roundf(worldPoint.x / Globals::tileSize.x), int((worldPoint.y + (Globals::tileSize.y / 2.f)) / Globals::tileSize.y) };
}
Vector2i CursorPosition_get()
{
	POINT mp;
	if (GetCursorPos(&mp))
	{
		if (ScreenToClient(Globals::hWnd, &mp))
		{
			return Vector2i{ mp.x, mp.y };
		}
		else
			return Vector2i{ 0,0 };
	}
	else
		return Vector2i{ 0,0 };
}
float reflectAngleRad(float angle, Vector2 normal)
{
	return atan2(cos(angle), sin(angle)) + ((abs(normal.x) * -1.57) + (abs(normal.y) * 1.57));
}
struct LayerBlock 
{
	int32_t blockType;
	int32_t hitsRequired;
	int32_t hitBuffer;
	int64_t lastHitTime;
	bool isWaitingForBlock;
	int32_t waitingBlockIndex;
	bool isWaitingBlockTree;
};
struct RaycastData
{
	bool hit;
	float distTraveled;
	Vector2i hitMapPoint;
	Vector2 hitPosition;
	Vector2 hitNormal;
	LayerBlock hitBlock;
};
//struct Raycast
//{
//	static RaycastData CastRay(Vector2 startPosition, float angleRad, float maxDist, Il2CppArray* worldBlocks, Il2CppArray* worldItemBase)
//	{
//		if (!Globals::IsInWorld)
//			return { false };
//		RaycastData data = { false, 0.f, {}, {} };
//		Vector2i worldSize = Vector2i{ (int)worldBlocks->max_length, (int)il2cpp_array_get(worldBlocks, Il2CppArray*, 0)->max_length };
//		float distTraveled = 0.f;
//		Vector2 position = startPosition;
//		if (maxDist == -1.f) maxDist = INFINITY;
//		Vector2 unitDirection = { sin(angleRad), cos(angleRad) };
//		while (distTraveled < maxDist)
//		{
//			position.x += unitDirection.x / 200;
//			position.y += unitDirection.y / 200;
//			distTraveled = startPosition.Distance(position);
//			Vector2i mapPoint = ConvertWorldPointToMapPoint(position);
//			if (!InBounds(mapPoint, worldSize))
//			{
//				return { false };
//			}
//			LayerBlock block = il2cpp_array_get(il2cpp_array_get(worldBlocks, Il2CppArray*, mapPoint.x), LayerBlock, mapPoint.y);
//			if (DoesBlockTypeHaveCollider(block.blockType))
//			{
//				data.hit = true;
//				data.hitMapPoint = mapPoint;
//				data.hitPosition = position;
//				data.hitBlock = block;
//				data.distTraveled = distTraveled;
//				Vector2 centerPoint = ConvertMapPointToWorldPoint(mapPoint);
//				float dx = position.x - centerPoint.x;
//				float dy = position.y - centerPoint.y;
//				if (abs(dx) > abs(dy))
//				{
//					// in x dir
//					if (unitDirection.x < 0)
//					{
//						data.hitNormal = { 1, 0 };
//					}
//					else
//					{
//						data.hitNormal = { -1, 0 };
//
//					}
//				}
//				else
//				{
//					// in y dir
//					if (unitDirection.y < 0)
//					{
//						data.hitNormal = { 0, 1 };
//					}
//					else
//					{
//						data.hitNormal = { 0, -1 };
//
//					}
//				}
//				break;
//			}
//			
//		}
//		return data;
//	}
//	static RaycastData CastRay(Vector2 startPosition, float angleRad, Il2CppArray* worldBlocks, Il2CppArray* worldItemBase)
//	{
//		return CastRay(startPosition, angleRad, -1.0f, worldBlocks, worldItemBase);
//	}
//};
struct __declspec(align(8)) CollectableData 
{
	Il2CppClass* klass;
	MonitorData* Monitor;
	int32_t id;
	int32_t blockType;
	uint8_t inventoryItemType;
	struct InventoryItemBase* inventoryData;
	float posX;
	float posY;
	struct Vector2i mapPoint;
	int16_t amount;
	bool isGem;
	int32_t gemType;
};

std::string bson_format(Il2CppDictionaryT<Il2CppString*, BSONValue*>* map, std::string indent_s = "");
std::string format_element(BSONValue* value)
{
	std::string temps = "";
	switch (value->mValueType)
	{
	case BSONValue::ValueType::Int32:
		temps += std::to_string(value->int32);
		break;
	case BSONValue::ValueType::Int64:
		temps += std::to_string(value->int64);
		break;
	case BSONValue::ValueType::UTCDateTime:
	{
		const unsigned __int64 UnixEpoch = 0x089f7ff5f7b58000;
		unsigned __int64 dateData = ((value->_dateTime.dateData & 0x3FFFFFFFFFFFFFFF) - UnixEpoch) / 10000000;
		time_t t = dateData;
		std::string data = "";
		data.resize(64);

		size_t size = 0;
		if (ImGui::GetIO().KeysDown[VK_F5])
		{
			size = strftime(data.data(), 64, "%m-%d-%Y %H:%M:%S", localtime(&t));
		}
		else
		{
			size = strftime(data.data(), 64, "%B %d, %Y %H:%M:%S", localtime(&t));
		}
		if (data[size] == '\0')
			data = data.substr(0, size);
		temps += data;
		break;
	}
	case BSONValue::ValueType::String:
	{
		std::string sb = string_Utf16ToUtf8(value->_string);
		temps += sb;
		break;
	}
	case BSONValue::ValueType::Double:
		temps += std::to_string(value->_double);
		break;
	case BSONValue::ValueType::Boolean:
		temps += value->_bool ? "true" : "false";
		break;
	case BSONValue::ValueType::Object:
	{
		FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
		Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(value, void*, field->offset);
		temps += bson_format(l);
		break;
	}
	case BSONValue::ValueType::Binary:
	{
		temps += "[\n\t\t";
		for (int j = 0; j < value->_binary->max_length; j++)
		{
			temps += std::to_string(value->_binary->vector[j]);
			if (j + 1 < value->_binary->max_length)
				temps += "\n\t\t";
		}
		temps += "\n\t]";
		break;
	}
	case BSONValue::ValueType::Array:
	{
		FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
		Il2CppList<BSONValue*>* l = il2cpp_object_get_field_value_by_offset(value, Il2CppList<BSONValue*>*, field->offset);

		temps += "[\n\t\t";
		for (int j = 0; j < l->size; j++)
		{
			temps += format_element(l->arry->vector[j]);
			if (j + 1 < value->_binary->max_length)
				temps += "\n\t\t";
		}
		temps += "\n\t]";

		break;
	}
	}

	return temps;
}
std::string packet_format(Il2CppDictionaryT<Il2CppString*, BSONValue*>* map, std::string indent_s = "")
{
	std::string s = "{\n\t";
	Il2CppArrayT<Il2CppString*>* keys = map->GetKeys();
	std::vector<std::string> keys_c = Il2CppDictUtil::GetKeysStringConverted(map);
	for (int i = 0; i < keys_c.size(); i++)
	{
		bool deez = false;
		std::string temps = "";
		temps += indent_s + keys_c[i] + ": ";
		BSONValue* value = map->GetValue(keys->vector[i]);

		switch (value->mValueType)
		{
		case BSONValue::ValueType::Int32:
			if (keys_c[i] == "mc")
				deez = true;
			temps += std::to_string(value->int32);
			break;
		case BSONValue::ValueType::Int64:
			temps += std::to_string(value->int64);
			break;
		case BSONValue::ValueType::UTCDateTime:
		{
			const unsigned __int64 UnixEpoch = 0x089f7ff5f7b58000;
			unsigned __int64 dateData = ((value->_dateTime.dateData & 0x3FFFFFFFFFFFFFFF) - UnixEpoch) / 10000000;
			time_t t = dateData;
			std::string data = "";
			data.resize(64);

			size_t size = 0;
			if (ImGui::GetIO().KeysDown[VK_F5])
			{
				size = strftime(data.data(), 64, "%m-%d-%Y %H:%M:%S", localtime(&t));
			}
			else
			{
				size = strftime(data.data(), 64, "%B %d, %Y %H:%M:%S", localtime(&t));
			}
			if (data[size] == '\0')
				data = data.substr(0, size);
			temps += data;
			break;
		}
		case BSONValue::ValueType::String:
		{
			std::string sb = string_Utf16ToUtf8(value->_string);
			if (keys_c[i] == "ID" && (sb == "mP" || sb == "p"/* || sb == "ST" || sb == "WCM" || sb == "PSicU" || sb == "PPA" || sb == "HB" || sb == "HBB"*/))
			{
				return "";
			}

			temps += sb;
			break;
		}
		case BSONValue::ValueType::Double:
			temps += std::to_string(value->_double);
			break;
		case BSONValue::ValueType::Boolean:
			temps += value->_bool ? "true" : "false";
			break;
		case BSONValue::ValueType::Object:
		{
			indent_s += "\t";
			FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
			Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(value, void*, field->offset);

			std::string ss = packet_format(l, indent_s);
			if (!ss.empty())
			{
				temps += ss;
			}
			else
			{
				deez = true;
			}
			indent_s.pop_back();
			break;
		}
		case BSONValue::ValueType::Binary:
		{
			temps += "[\n\t\t";
			for (int j = 0; j < value->_binary->max_length; j++)
			{
				temps += std::to_string(value->_binary->vector[j]);
				if (j + 1 < value->_binary->max_length)
					temps += ",\n\t\t";
			}
			temps += "\n\t]";
			break;
		}
		case BSONValue::ValueType::Array:
		{
			FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
			Il2CppList<BSONValue*>* l = il2cpp_object_get_field_value_by_offset(value, Il2CppList<BSONValue*>*, field->offset);

			temps += "[\n\t\t";
			for (int j = 0; j < l->size; j++)
			{
				if (string_Utf16ToUtf8(l->arry->vector[j]->_string).empty())
				{
					break;
				}
				temps += format_element(l->arry->vector[j]);
				if (j + 1 < l->size && !string_Utf16ToUtf8(l->arry->vector[j+1]->_string).empty())
					temps += ",\n\t\t";
			}
			temps += "\n\t]";

			break;
		}
		}

		if (i + 1 < keys_c.size())
			temps += ",\n\t";
		if (!deez)
			s += temps;
	}

	s += "\n" + indent_s + "}";


	if (s == "{\n\t\n}")
		return "";
	return s;
}
std::string bson_format(Il2CppDictionaryT<Il2CppString*, BSONValue*>* map, std::string indent_s)
{
	int i = 0;
	std::string s = "{\n\t";
	Il2CppArrayT<Il2CppString*>* keys = map->GetKeys();
	std::vector<std::string> keys_c = Il2CppDictUtil::GetKeysStringConverted(map);
	for (int i = 0; i < keys_c.size(); i++)
	{
		s += indent_s + keys_c[i] + ": ";
		BSONValue* value = map->GetValue(keys->vector[i]);

		switch (value->mValueType)
		{
		case BSONValue::ValueType::Int32:
			s += std::to_string(value->int32);
			break;
		case BSONValue::ValueType::Int64:
			s += std::to_string(value->int64);
			break;
		case BSONValue::ValueType::UTCDateTime:
		{
			const unsigned __int64 UnixEpoch = 0x089f7ff5f7b58000;
			unsigned __int64 dateData = ((value->_dateTime.dateData & 0x3FFFFFFFFFFFFFFF) - UnixEpoch) / 10000000;
			time_t t = dateData;
			std::string data = "";
			data.resize(64);

			size_t size = 0;
			if (ImGui::GetIO().KeysDown[VK_F5])
			{
				size = strftime(data.data(), 64, "%m-%d-%Y %H:%M:%S", localtime(&t));
			}
			else
			{
				size = strftime(data.data(), 64, "%B %d, %Y %H:%M:%S", localtime(&t));
			}
			if (data[size] == '\0')
				data = data.substr(0, size);
			s += data;
			break;
		}
		case BSONValue::ValueType::String:
			s += string_Utf16ToUtf8(value->_string);
			break;
		case BSONValue::ValueType::Double:
			s += std::to_string(value->_double);
			break;
		case BSONValue::ValueType::Boolean:
			s += value->_bool ? "true" : "false";
			break;
		case BSONValue::ValueType::Object:
		{
			indent_s += "\t";
			FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
			Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(value, void*, field->offset);

			s += bson_format(l, indent_s);
			indent_s.pop_back();
			break;
		}
		case BSONValue::ValueType::Binary:
		{
			s += "[\n\t\t";
			for (int j = 0; j < value->_binary->max_length; j++)
			{
				s += std::to_string(value->_binary->vector[j]);
				if (j + 1 < value->_binary->max_length)
					s += "\n\t\t";
			}
			s += "\n\t]";
			break;
		}
		case BSONValue::ValueType::Array:
		{
			FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
			Il2CppList<BSONValue*>* l = il2cpp_object_get_field_value_by_offset(value, Il2CppList<BSONValue*>*, field->offset);

			s += "[\n\t\t";
			for (int j = 0; j < l->size; j++)
			{
				if (string_Utf16ToUtf8(l->arry->vector[j]->_string).empty())
				{
					break;
				}
				s += format_element(l->arry->vector[j]);
				if (j + 1 < l->size && !string_Utf16ToUtf8(l->arry->vector[j + 1]->_string).empty())
					s += ",\n\t\t";
			}
			s += "\n\t]";
			break;
		}
		}

		if (i + 1 < keys_c.size())
			s += ",\n\t";
	}
	
	s += "\n" + indent_s + "}";

	return s;
} 
namespace ImGui
{
	bool SelectableFormatted(const char* format, ...)
	{
		va_list argsToCheckSize;
		int n;
		std::string ret;

		va_start(argsToCheckSize, format);
		// use a temporary buffer as some docs indicate we cannot pass NULL to vsnprintf
		char buf[1];
		n = vsnprintf(buf, 0, format, argsToCheckSize);
		if (n == -1)
			return NULL;

		ret.resize(n + 1, 0);
		va_end(argsToCheckSize);

		va_list argsToFormat;

		va_start(argsToFormat, format);
		n = vsnprintf(&ret[0], ret.size(), format, argsToFormat);
		va_end(argsToFormat);


		if (n == -1)
			return "";

		// The v*printf methods might put a trailing NUL character, which should not not be in a
		// std::string, so strip it out.
		if (!ret.empty() && ret[ret.size() - 1] == '\0')
			ret = ret.substr(0, ret.size() - 1);

		return ImGui::Selectable(ret.c_str());
	}
}

void PickupMapPoint(Il2CppList<CollectableData*>* collectableList, Vector2i mapPoint)
{
	const static MethodInfo* SendCollectCollectableMessage = Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendCollectCollectableMessage(System.Int32,)"];
	std::vector<int> collectableIds = {};
	for (int i = 0; i < collectableList->size; i++)
	{
		if (collectableList->arry->vector[i]->mapPoint == mapPoint)
			collectableIds.push_back(collectableList->arry->vector[i]->id);
	}

	for (int i = 0; i < collectableIds.size(); i++)
	{
		reinterpret_cast<void(*)(int id)>(SendCollectCollectableMessage->methodPointer)(collectableIds[i]);
	}
}
bool BringPlayerToMapPoint(Vector2i mapPoint, Player* player, bool& movex, bool& movey, Vector2 boxSize)
{
	Vector2i playerMapPoint = player->currentPlayerMapPoint;
	Vector2 pos = player->myTransform->GetPosition();
	pos.y += boxSize.y / 2.3f;
	Vector2 mapPointCenter = ConvertMapPointToWorldPoint(mapPoint);

	//Vector3 a = { bruh.x, bruh.y, 0 };
	//a.y -= boxSize.y / 2.4f;
	float dist = pos.Distance(mapPointCenter);
	if (dist < 0.1)
		return true;
	dist = std::min(dist * 5.f, 1.0f);
	Vector2& v = il2cpp_object_get_field_value_by_name(player, Vector2, player->klass, "velocity");
	if (pos.x > mapPointCenter.x)
	{
		v.x = -2.0f * dist;
		movex = true;
	}
	if (pos.x < mapPointCenter.x)
	{ 
		v.x = 2.0f * dist;
		movex = true;
	}
	if (pos.y > mapPointCenter.y)
	{ 
		v.y = -2.0f * dist;
		movey = true;
	}
	if (pos.y < mapPointCenter.y)
	{ 
		v.y = 2.0f * dist;
		movey = true;
	}
	return false;
}
bool IsGemBlock(int blockType)
{
	switch (blockType)
	{
	case 3995/*MiningGemStoneDiamond*/:
		return true;
	case 3996/*MiningGemStoneEmerald*/:
		return true;
	case 3997/*MiningGemStoneMoonStone*/:
		return true;
	case 3998/*MiningGemStoneOpal*/:
		return true;
	case 3999/*MiningGemStoneRuby*/:
		return true;
	case 4000/*MiningGemStoneSapphire*/:
		return true;
	case 4001/*MiningGemStoneSunStone*/:
		return true;
	case 4002/*MiningGemStoneTopaz*/:
		return true;
	case 4003/*MiningGemStoneZircon*/:
		return true;
	case 4012/*MiningGemDiamondTiny*/:
		return true;
	case 4013/*MiningGemDiamondSmall*/:
		return true;
	case 4014/*MiningGemDiamondMedium*/:
		return true;
	case 4015/*MiningGemDiamondLarge*/:
		return true;
	case 4016/*MiningGemDiamondHuge*/:
		return true;
	case 4017/*MiningGemEmeraldTiny*/:
		return true;
	case 4018/*MiningGemEmeraldSmall*/:
		return true;
	case 4019/*MiningGemEmeraldMedium*/:
		return true;
	case 4020/*MiningGemEmeraldLarge*/:
		return true;
	case 4021/*MiningGemEmeraldHuge*/:
		return true;
	case 4022/*MiningGemMoonStoneTiny*/:
		return true;
	case 4023/*MiningGemMoonStoneSmall*/:
		return true;
	case 4024/*MiningGemMoonStoneMedium*/:
		return true;
	case 4025/*MiningGemMoonStoneLarge*/:
		return true;
	case 4026/*MiningGemMoonStoneHuge*/:
		return true;
	case 4027/*MiningGemOpalTiny*/:
		return true;
	case 4028/*MiningGemOpalSmall*/:
		return true;
	case 4029/*MiningGemOpalMedium*/:
		return true;
	case 4030/*MiningGemOpalLarge*/:
		return true;
	case 4031/*MiningGemOpalHuge*/:
		return true;
	case 4032/*MiningGemRubyTiny*/:
		return true;
	case 4033/*MiningGemRubySmall*/:
		return true;
	case 4034/*MiningGemRubyMedium*/:
		return true;
	case 4035/*MiningGemRubyLarge*/:
		return true;
	case 4036/*MiningGemRubyHuge*/:
		return true;
	case 4037/*MiningGemSapphireTiny*/:
		return true;
	case 4038/*MiningGemSapphireSmall*/:
		return true;
	case 4039/*MiningGemSapphireMedium*/:
		return true;
	case 4040/*MiningGemSapphireLarge*/:
		return true;
	case 4041/*MiningGemSapphireHuge*/:
		return true;
	case 4042/*MiningGemSunStoneTiny*/:
		return true;
	case 4043/*MiningGemSunStoneSmall*/:
		return true;
	case 4044/*MiningGemSunStoneMedium*/:
		return true;
	case 4045/*MiningGemSunStoneLarge*/:
		return true;
	case 4046/*MiningGemSunStoneHuge*/:
		return true;
	case 4047/*MiningGemTopazTiny*/:
		return true;
	case 4048/*MiningGemTopazSmall*/:
		return true;
	case 4049/*MiningGemTopazMedium*/:
		return true;
	case 4050/*MiningGemTopazLarge*/:
		return true;
	case 4051/*MiningGemTopazHuge*/:
		return true;
	case 4052/*MiningGemZirconTiny*/:
		return true;
	case 4053/*MiningGemZirconSmall*/:
		return true;
	case 4054/*MiningGemZirconMedium*/:
		return true;
	case 4055/*MiningGemZirconLarge*/:
		return true;
	case 4056/*MiningGemZirconHuge*/:
		return true;
	default:
		return false;
	}
}

Vector2 findClosestPointOnRect(Vector2 point, Vector2 pos, Vector2 bounds)
{
	float x_min = pos.x;
	float y_min = pos.y;
	float x_max = pos.x + bounds.x;
	float y_max = pos.y + bounds.y;
	float point_x = 0;
	float point_y = 0;

	if (point.x < x_min) point_x = x_min;
	else if (point.x > x_max) point_x = x_max;
	else point_x = point.x;

	if (point.y < y_min) point_y = y_min;
	else if (point.y > y_max) point_y = y_max;
	else point_y = point.y;

	return Vector2{point_x, point_y};
}

Vector2 line_intersect(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, bool* hit) 
{
	float ua, ub, denom = (p4.y - p3.y) * (p2.x - p1.x) - (p4.x - p3.x) * (p2.y - p1.y);
	if (denom == 0)
	{
		*hit = false;
		return {};
	}
	ua = ((p4.x - p3.x) * (p1.y - p3.y) - (p4.y - p3.y) * (p1.x - p3.x)) / denom;
	ub = ((p2.x - p1.x) * (p1.y - p3.y) - (p2.y - p1.y) * (p1.x - p3.x)) / denom;
	*hit = (ua >= 0 && ua <= 1) && (ub >= 0 && ub <= 1);
	return { p1.x + ua * (p2.x - p1.x), p1.y + ua * (p2.y - p1.y) };
}
InventoryKey IntToIK(int ik)
{
	union ikp
	{
		int iki;
		short iks[2];
		char ikc[4];
	};
	ikp p;
	p.iki = ik;
	InventoryKey sik;
	sik.blockType = p.iks[0];
	sik.itemType = p.ikc[3];
	return sik;
}