#pragma once
#include <string>
#include <vector>
inline std::string string_Utf16ToUtf8(const Il2CppString* utf16String)
{
	if (!utf16String)
		return "";
	std::string s = "";
	s.resize(utf16String->length);


	for (int i = 0; i < utf16String->length; i++)
	{
		// wow cast to char so hard :)))))))))))
		s[i] = (char)utf16String->chars[i];
	}


	if (!s.empty() && s[s.size() - 1] == '\0')
		s = s.substr(0, s.size() - 1);

	return s;
}
inline Il2CppString* cstring_Utf8ToUtf16(const char* utf8String)
{
	return il2cpp_string_new(utf8String);
}
inline Il2CppString* string_Utf8ToUtf16(const std::string& utf8String)
{
	return il2cpp_string_new(utf8String.c_str());
}
typedef struct Il2CppGenericList
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int GetTCount()
	{
		return il2cpp_class_get_type(this->klass)->data.generic_class->context.class_inst->type_argc;
	}
	const Il2CppClass* GetT(int index)
	{
		const Il2CppType* t1 = il2cpp_class_get_type(this->klass)->data.generic_class->context.class_inst->type_argv[index];
		return il2cpp_class_from_il2cpp_type(t1);
	}
} Il2CppGenericList;
template<typename T>
struct Il2CppArrayT
{
	//Il2CppObject obj;
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppArrayBounds* bounds;
	size_t max_length;
	T vector[32];
	T& Index(int index)
	{
		return vector[index];//il2cpp_array_get(this, T, index);
	}
	T* IndexP(int index)
	{
		T& t = vector[index];//il2cpp_array_get(this, T, index);
		return &t;
	}
	T& operator[](int index)
	{
		return vector[index];
	}
};
template<typename T>
struct Il2CppList
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppArrayT<T>* arry;
	int size;
	int version;
	Il2CppObject* syncRoot;
	const Il2CppClass* GetT()
	{
		const Il2CppType* t1 = il2cpp_class_get_type(this->klass)->data.generic_class->context.class_inst->type_argv[0];
		return il2cpp_class_from_il2cpp_type(t1);
	}
	void Add(T item)
	{
		T* pItem = &item;
		il2cpp_runtime_invoke(il2cpp_class_get_method_from_name(this->klass, "Add", 1), this, (void**)&pItem, nullptr);
		for (int i = 0; i < arry->klass->method_count; i++)
		{
			const MethodInfo* m = arry->klass->methods[i];
			//Console.AddLog(m->name);
			std::string s = m->name;
		}
	}
	bool Contains(T item)
	{
		T* pItem = &item;
		return *(bool*)il2cpp_object_unbox(il2cpp_runtime_invoke(il2cpp_class_get_method_from_name(this->klass, "Contains", 1), this, (void**)&pItem, nullptr));
	}
	void RemoveIndex(int index)
	{
		int* pIndex = &index;
		il2cpp_runtime_invoke(il2cpp_class_get_method_from_name(this->klass, "RemoveAt", 1), this, (void**)&pIndex, nullptr);
	}
	void RemoveRange(int index, int amount)
	{
		void** v = new void* [2];
		int* pIndex = &index;
		int* pAmount = &amount;
		v[0] = pIndex;
		v[1] = pAmount;
		il2cpp_runtime_invoke(il2cpp_class_get_method_from_name(this->klass, "RemoveRange", 2), this, v, nullptr);
	}
	int IndexOf(T item)
	{
		T* pItem = &item;
		return *(int*)il2cpp_object_unbox(il2cpp_runtime_invoke(il2cpp_class_get_method_from_name(this->klass, "IndexOf", 1), this, (void**)&pItem, nullptr));

	}
	void Clear()
	{
		il2cpp_runtime_invoke(il2cpp_class_get_method_from_name(this->klass, "Clear", 0), this, nullptr, nullptr);
	}
	T& Index(int index)
	{
		return il2cpp_array_get(arry, T, index);
	}
	T* IndexP(int index)
	{
		T& t = il2cpp_array_get(arry, T, index);
		return &t;
	}
	T& operator[](int index)
	{
		return il2cpp_array_get(arry, T, index);
	}
};
typedef struct Il2CppDictionary
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppArray* buckets;
	int count;
	int version;
	int freeList;
	int freeCount;
	Il2CppObject* comparer;
	Il2CppGenericList* keys;
	Il2CppGenericList* values;
	Il2CppObject* _syncRoot;
	const Il2CppClass* GetTKey()
	{
		const Il2CppType* t1 = il2cpp_class_get_type(this->klass)->data.generic_class->context.class_inst->type_argv[0];
		return il2cpp_class_from_il2cpp_type(t1);
	}
	const Il2CppClass* GetTValue()
	{
		const Il2CppType* t1 = il2cpp_class_get_type(this->klass)->data.generic_class->context.class_inst->type_argv[1];
		return il2cpp_class_from_il2cpp_type(t1);
	}

	Il2CppArray* GetKeys()
	{
		const Il2CppClass* TKey = this->GetTKey();//il2cpp_class_from_il2cpp_type(t1);
		Il2CppArray* toCopyTo = il2cpp_array_new((Il2CppClass*)TKey, reinterpret_cast<int(*)(Il2CppObject * pThis)>(il2cpp_class_get_property_from_name(this->klass, "Count")->get->methodPointer)((Il2CppObject*)this));
		Il2CppObject* keys = il2cpp_runtime_invoke(il2cpp_class_get_property_from_name(this->klass, "Keys")->get, this, nullptr, nullptr);
		reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppArray * arr, int index)>(il2cpp_class_get_method_from_name(keys->Il2CppClass.klass, "CopyTo", 2)->methodPointer)(keys, toCopyTo, 0);
		return toCopyTo;
	}
	template<typename TKey> Il2CppObject* GetValue(TKey key)
	{
		const PropertyInfo* get_Item = il2cpp_class_get_property_from_name(this->klass, "Item");
		Il2CppObject* item = il2cpp_runtime_invoke(get_Item->get, this, (void**)&key, nullptr);
		return item;
	}
	std::vector<std::string> GetKeysStringConverted()
	{
		Il2CppArray* a = this->GetKeys();
		std::vector<std::string> v = {};
		v.resize(a->max_length);
		for (int i = 0; i < a->max_length; i++)
		{
			v[i] = string_Utf16ToUtf8(((Il2CppString**)((uintptr_t)a + 0x20))[i]);
		}
		return v;
	}
} Il2CppDictionary;
template<typename TKey, typename TValue>
struct Il2CppDictionaryT
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppArray* buckets;
	int count;
	int version;
	int freeList;
	int freeCount;
	Il2CppObject* comparer;
	Il2CppGenericList* keys;
	Il2CppGenericList* values;
	Il2CppObject* _syncRoot;
	const Il2CppClass* GetTKey()
	{
		const Il2CppType* t1 = il2cpp_class_get_type(this->klass)->data.generic_class->context.class_inst->type_argv[0];
		return il2cpp_class_from_il2cpp_type(t1);
	}
	const Il2CppClass* GetTValue()
	{
		const Il2CppType* t1 = il2cpp_class_get_type(this->klass)->data.generic_class->context.class_inst->type_argv[1];
		return il2cpp_class_from_il2cpp_type(t1);
	}

	Il2CppArrayT<TKey>* GetKeys()
	{
		const Il2CppClass* keyt = this->GetTKey();
		int count = reinterpret_cast<int(*)(Il2CppObject * pThis)>(il2cpp_class_get_property_from_name(this->klass, "Count")->get->methodPointer)((Il2CppObject*)this);
		Il2CppArrayT<TKey>* toCopyTo = (Il2CppArrayT<TKey>*)il2cpp_array_new((Il2CppClass*)keyt, count);
		Il2CppObject* keys = il2cpp_runtime_invoke(il2cpp_class_get_property_from_name(this->klass, "Keys")->get, this, nullptr, nullptr);
		if (!IsBadMem(keys) && !IsBadMem(toCopyTo))
		{
			void* addr = il2cpp_class_get_method_from_name(keys->Il2CppClass.klass, "CopyTo", 2)->methodPointer;
			reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppArrayT<TKey>*arr, int index)>(addr)(keys, toCopyTo, 0);
			if (!addr)
			{
				il2cpp_domain_get();
			}
		}
		return toCopyTo;
	}
	Il2CppArrayT<TValue>* GetValues()
	{
		const Il2CppClass* valuet = this->GetTValue();
		int count = reinterpret_cast<int(*)(Il2CppObject * pThis)>(il2cpp_class_get_property_from_name(this->klass, "Count")->get->methodPointer)((Il2CppObject*)this);
		Il2CppArrayT<TValue>* toCopyTo = (Il2CppArrayT<TValue>*)il2cpp_array_new((Il2CppClass*)valuet, count);
		Il2CppObject* keys = il2cpp_runtime_invoke(il2cpp_class_get_property_from_name(this->klass, "Values")->get, this, nullptr, nullptr);
		if (!IsBadMem(keys) && !IsBadMem(toCopyTo))
		{
			void* addr = il2cpp_class_get_method_from_name(keys->Il2CppClass.klass, "CopyTo", 2)->methodPointer;
			reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppArrayT<TValue>*arr, int index)>(addr)(keys, toCopyTo, 0);
			if (!addr)
			{
				il2cpp_domain_get();
			}
		}
		return toCopyTo;
	}
	TValue GetValue(TKey key)
	{
		const PropertyInfo* get_Item = il2cpp_class_get_property_from_name(this->klass, "Item");
		TValue item = (TValue)il2cpp_runtime_invoke(get_Item->get, this, (void**)&key, nullptr);
		return item;
	}
	void SetValue(TKey key, TValue value)
	{
		const PropertyInfo* get_Item = il2cpp_class_get_property_from_name(this->klass, "Item");
		std::vector<void*> data = {key, value};
		il2cpp_runtime_invoke(get_Item->set, this, data.data(), nullptr);
	}
	void Add(TKey key, TValue value)
	{
		const MethodInfo* AddItem = il2cpp_class_get_method_from_name(this->klass, "Add", 2);
		std::vector<void*> data = { key, value };
		il2cpp_runtime_invoke(AddItem, this, data.data(), nullptr);
	}
	//Il2CppArray* GetKeys()
	//{
	//	const Il2CppClass* TKey = this->GetTKey();//il2cpp_class_from_il2cpp_type(t1);
	//	Il2CppArray* toCopyTo = il2cpp_array_new((Il2CppClass*)TKey, reinterpret_cast<int(*)(Il2CppObject * pThis)>(il2cpp_class_get_property_from_name(this->klass, "Count")->get->methodPointer)((Il2CppObject*)this));
	//	Il2CppObject* keys = il2cpp_runtime_invoke(il2cpp_class_get_property_from_name(this->klass, "Keys")->get, this, nullptr, nullptr);
	//	reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppArray * arr, int index)>(il2cpp_class_get_method_from_name(keys->Il2CppClass.klass, "CopyTo", 2)->methodPointer)(keys, toCopyTo, 0);
	//	return toCopyTo;
	//}
	//template<typename TKey> Il2CppObject* GetValue(TKey key)
	//{
	//	const PropertyInfo* get_Item = il2cpp_class_get_property_from_name(this->klass, "Item");
	//	Il2CppObject* item = il2cpp_runtime_invoke(get_Item->get, this, (void**)&key, nullptr);
	//	return item;
	//}
	//std::vector<std::string> GetKeysStringConverted()
	//{
	//	Il2CppArray* a = this->GetKeys();
	//	std::vector<std::string> v = {};
	//	v.resize(a->max_length);
	//	for (int i = 0; i < a->max_length; i++)
	//	{
	//		v[i] = string_Utf16ToUtf8(((Il2CppString**)((uintptr_t)a + 0x20))[i]);
	//	}
	//	return v;
	//}
};

struct Il2CppDictUtil
{
	template<typename TKey, typename TValue> static std::vector<std::string>  GetKeysStringConverted(Il2CppDictionaryT<TKey, TValue>* dict)
	{
		Il2CppArrayT<TKey>* a = dict->GetKeys();
		std::vector<std::string> v = {};
		v.resize(a->max_length);
		for (int i = 0; i < a->max_length; i++)
		{
			v[i] = string_Utf16ToUtf8(((Il2CppString**)((uintptr_t)a + 0x20))[i]);
		}
		return v;
	}
};