#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
//#define dict_GetValue(dict, key) 
void FieldAsText(Il2CppObject* object, FieldInfo* field)
{
	bool fieldStatic = il2cpp_type_is_static(field->type);
	if (fieldStatic)
		return;

	switch (field->type->type)
	{
	case IL2CPP_TYPE_CLASS:
	{
		Il2CppObject*& o = il2cpp_object_get_field_value_by_offset(object, Il2CppObject*, field->offset);
		if (o) 
		{
			ImGui::Text("%s: ", field->name);
			ImGui::Text("{");
			ImGui::Indent(20.f);
			for (int i = 0; i < o->Il2CppClass.klass->field_count; i++)
			{
				//Il2CppObject*& a = il2cpp_object_get_field_value_by_offset(object, Il2CppObject*, field->offset);
				FieldAsText((Il2CppObject*)&o, &o->Il2CppClass.klass->fields[i]);
			}
			ImGui::Indent(-20.f);
			ImGui::Text("}");
		}
		break;
	}
	case IL2CPP_TYPE_VALUETYPE:
	{
		Il2CppClass* c = il2cpp_class_from_type(field->type);
		ImGui::Text("%s: {", field->name);
		if (std::string(c->name) == "DateTime")
		{
			const unsigned __int64 UnixEpoch = 0x089f7ff5f7b58000;
			unsigned __int64 dateData = ((il2cpp_object_get_field_value_by_offset(object, unsigned __int64, field->offset) & 0x3FFFFFFFFFFFFFFF) - UnixEpoch) / 10000000;
			time_t t = dateData;
			std::string data = "";
			data.resize(64);

			if (ImGui::GetIO().KeysDown[VK_F5])
			{
				strftime(data.data(), 64, "%m-%d-%Y %H:%M:%S", localtime(&t));
			}
			else
			{
				strftime(data.data(), 64, "%B %d, %Y %H:%M:%S", localtime(&t));
			}
			
			ImGui::SameLine();
			ImGui::Text("%s", data.c_str());
		}
		else
		{
			for (int i = 0; i < c->field_count; i++)
			{
				void*& a = il2cpp_object_get_field_value_by_offset(object, void*, field->offset);
				c->fields[i].offset -= 0x10;
				ImGui::SameLine();
				FieldAsText((Il2CppObject*)&a, &c->fields[i]);
				c->fields[i].offset += 0x10;
			}
		}
		ImGui::SameLine();
		ImGui::Text("}");
		break;
	}
	case IL2CPP_TYPE_ARRAY:
	{
		Il2CppArray* a = il2cpp_object_get_field_value_by_offset(object, Il2CppArray*, field->offset);
		if (a)
			ImGui::Text("%s: %s[%i]", field->name, a->obj.Il2CppClass.klass->name, a->max_length);
		break;
	}
	case IL2CPP_TYPE_SZARRAY:
	{
		Il2CppArray* a = il2cpp_object_get_field_value_by_offset(object, Il2CppArray*, field->offset);
		if (a)
			ImGui::Text("%s: %s[%i]", field->name, a->obj.Il2CppClass.klass->name, a->max_length);
		break;
	}
	case IL2CPP_TYPE_GENERICINST:
	{
		Il2CppList<Il2CppObject*>* ll = (Il2CppList<Il2CppObject*>*)il2cpp_object_get_field_value_by_offset(object, Il2CppObject*, field->offset);
		Il2CppObject* l = il2cpp_object_get_field_value_by_offset(object, Il2CppObject*, field->offset);
		if (l)
		{
			bool stoppedForVTYPE = false;
			const Il2CppType* t = l->Il2CppClass.klass->generic_class->context.class_inst->type_argv[0];
			int sz = Il2Cpp::Lists::il2cpp_list_get_size(l);
			std::string items = "{ ";
			if (t->type == IL2CPP_TYPE_VALUETYPE)
			{
				stoppedForVTYPE = true;
				ImGui::Text("%s: List<%s>[%i]", field->name, il2cpp_type_get_name(l->Il2CppClass.klass->generic_class->context.class_inst->type_argv[0]), Il2Cpp::Lists::il2cpp_list_get_size(l));
				ImGui::SameLine();
				ImGui::Text("{");
			}
			for (int i = 0; i < sz; i++)
			{
				switch (t->type)
				{
				//case IL2CPP_TYPE_CLASS:
				//{
				//	Il2CppObject*& o = ll->arry->vector[i];//il2cpp_object_get_field_value_by_offset(l, Il2CppObject*, i * 8);
				//	if (o)
				//	{
				//		ImGui::Text("%s: ", field->name);
				//		ImGui::Text("{");
				//		ImGui::Indent(20.f);
				//		for (int i = 0; i < o->Il2CppClass.klass->field_count; i++)
				//		{
				//			//Il2CppObject*& a = il2cpp_object_get_field_value_by_offset(object, Il2CppObject*, field->offset);
				//			FieldAsText(o, &o->Il2CppClass.klass->fields[i]);
				//		}
				//		ImGui::Indent(-20.f);
				//		ImGui::Text("}");
				//	}
				//	break;
				//}
				//case IL2CPP_TYPE_VALUETYPE:
				{
					stoppedForVTYPE = true;
					Il2CppClass* c = il2cpp_class_from_type(t);
					ImGui::SameLine();
					ImGui::Text("{");
					for (int j = 0; j < c->field_count; j++)
					{
					 	void*& a = il2cpp_list_get(l, void*, i);
						c->fields[j].offset -= 0x10;
						ImGui::SameLine();
						FieldAsText((Il2CppObject*)&a, &c->fields[j]);
						c->fields[j].offset += 0x10;
					}
					ImGui::SameLine();
					ImGui::Text("}");
					break;
				}
				case IL2CPP_TYPE_STRING:
				{
					Il2CppString* s = Il2Cpp::Lists::il2cpp_list_index<Il2CppString*>(l, i);;
					if (il2cpp_class_get_type(s->object.Il2CppClass.klass)->type == IL2CPP_TYPE_STRING)
					{
						items += string_Utf16ToUtf8(s);
					}
					break;
				}
				case IL2CPP_TYPE_BOOLEAN:
					items += (Il2Cpp::Lists::il2cpp_list_index<bool>(l, i) ? "True" : "False");
					//ImGui::Text("%s: %s", field->name, Il2Cpp::Lists::il2cpp_list_index<bool>(l, i); ? "True" : "False");
					break;
				case IL2CPP_TYPE_U1:
					//ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned char, field->offset));
					items += string_printf("%u", Il2Cpp::Lists::il2cpp_list_index<unsigned char>(l, i));
					break;
				case IL2CPP_TYPE_CHAR:
					items += string_printf("%u", Il2Cpp::Lists::il2cpp_list_index<char>(l, i));
					//ImGui::Text("%s: %c", field->name, il2cpp_object_get_field_value_by_offset(object, char, field->offset));
					break;
				case IL2CPP_TYPE_U2:
					items += string_printf("%u", Il2Cpp::Lists::il2cpp_list_index<unsigned short>(l, i));
					//ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned short, field->offset));
					break;
				case IL2CPP_TYPE_U4:
					items += string_printf("%u", Il2Cpp::Lists::il2cpp_list_index<unsigned int>(l, i));
					//ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned int, field->offset));
					break;
				case IL2CPP_TYPE_U8:
					items += string_printf("%u", Il2Cpp::Lists::il2cpp_list_index<unsigned long long>(l, i));
					//ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned long long, field->offset));
					break;
				case IL2CPP_TYPE_I1:
					items += string_printf("%i", Il2Cpp::Lists::il2cpp_list_index<char>(l, i));
					//ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, char, field->offset));
					break;
				case IL2CPP_TYPE_I2:
					items += string_printf("%i", Il2Cpp::Lists::il2cpp_list_index<short>(l, i));
					//ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, short, field->offset));
					break;
				case IL2CPP_TYPE_I4:
				{
					int r = Il2Cpp::Lists::il2cpp_list_index<int>(l, i);
					const static auto InventoryKey_IntToInventoryKey1 = reinterpret_cast<InventoryKey(*)(int/*System.Int32*/ asInt)>(Globals::Methods["PlayerData.InventoryKey Assembly-CSharp.InventoryKey.IntToInventoryKey(System.Int32,)"]->methodPointer);
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					if (ImGui::GetIO().KeysDown[VK_F5])
						items += string_printf("%i (%s)", r, Il2Cpp::Enums::EnumToString(c, InventoryKey_IntToInventoryKey1(r).blockType).c_str());
					else 
						items += string_printf("%i", r);
					//ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, int, field->offset));
					break;
				}
				case IL2CPP_TYPE_I8:
					items += string_printf("%i", Il2Cpp::Lists::il2cpp_list_index<long long>(l, i));
					//ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, long long, field->offset));
					break;
				case IL2CPP_TYPE_R4:
					items += string_printf("%f", Il2Cpp::Lists::il2cpp_list_index<float>(l, i));
					//ImGui::Text("%s: %f", field->name, il2cpp_object_get_field_value_by_offset(object, float, field->offset));
					break;
				case IL2CPP_TYPE_R8:
					items += string_printf("%f", Il2Cpp::Lists::il2cpp_list_index<double>(l, i));
					//ImGui::Text("%s: %f", field->name, il2cpp_object_get_field_value_by_offset(object, double, field->offset));
					break;
				default:
					int a = 0;
					a += 12;
					items += "unknown";
					break;
				}
				items += i + 1 < sz ? ", " : "";
			}
			items += " }";
			if (!stoppedForVTYPE)
				ImGui::Text("%s: List<%s>[%i]%s", field->name, il2cpp_type_get_name(l->Il2CppClass.klass->generic_class->context.class_inst->type_argv[0]), Il2Cpp::Lists::il2cpp_list_get_size(l), items.c_str());
			else
			{
				ImGui::SameLine();
				ImGui::Text("}");
			}
		}
		break;
	}
	case IL2CPP_TYPE_STRING:
	{
		Il2CppString* s = il2cpp_object_get_field_value_by_offset(object, Il2CppString*, field->offset);
		if (!IsBadMem(s))
		{
			if (il2cpp_class_get_type(s->object.Il2CppClass.klass)->type == IL2CPP_TYPE_STRING)
				ImGui::Text("%s: %s", field->name, string_Utf16ToUtf8(s).c_str());
		}
		break;
	}
	case IL2CPP_TYPE_BOOLEAN:
		ImGui::Text("%s: %s", field->name, il2cpp_object_get_field_value_by_offset(object, bool, field->offset) ? "True" : "False");
		break;
	case IL2CPP_TYPE_U1:
		ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned char, field->offset));
		break;
	case IL2CPP_TYPE_CHAR:
		ImGui::Text("%s: %c", field->name, il2cpp_object_get_field_value_by_offset(object, char, field->offset));
		break;
	case IL2CPP_TYPE_U2:
		ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned short, field->offset));
		break;
	case IL2CPP_TYPE_U4:
		ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned int, field->offset));
		break;
	case IL2CPP_TYPE_U8:
		ImGui::Text("%s: %u", field->name, il2cpp_object_get_field_value_by_offset(object, unsigned long long, field->offset));
		break;
	case IL2CPP_TYPE_I1:
		ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, char, field->offset));
		break;
	case IL2CPP_TYPE_I2:
		ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, short, field->offset));
		break;
	case IL2CPP_TYPE_I4:
		ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, int, field->offset));
		break;
	case IL2CPP_TYPE_I8:
		ImGui::Text("%s: %i", field->name, il2cpp_object_get_field_value_by_offset(object, long long, field->offset));
		break;
	case IL2CPP_TYPE_R4:
		ImGui::Text("%s: %f", field->name, il2cpp_object_get_field_value_by_offset(object, float, field->offset));
		break;
	case IL2CPP_TYPE_R8:
		ImGui::Text("%s: %f", field->name, il2cpp_object_get_field_value_by_offset(object, double, field->offset));
		break;
	default:
		int a = 0;
		a += 12;
		break;
	}
}


Il2CppObject* dict_GetValue(Il2CppObject* dict, std::string key)
{
	const PropertyInfo* get_Item = il2cpp_class_get_property_from_name(dict->Il2CppClass.klass, "Item");
	Il2CppString* s = il2cpp_string_new(key.c_str());
	Il2CppObject* item = il2cpp_runtime_invoke(get_Item->get, dict, (void**)&s, nullptr);
	return item;
}
std::vector<std::string> dict_GetKeys(Il2CppObject* dict)
{
	if (dict)
	{
		const Il2CppType* t1 = il2cpp_class_get_type(dict->Il2CppClass.klass)->data.generic_class->context.class_inst->type_argv[0];
		const Il2CppClass* c1 = il2cpp_class_from_il2cpp_type(t1);
		Il2CppArray* toCopyTo = il2cpp_array_new((Il2CppClass*)c1, reinterpret_cast<int(*)(Il2CppObject * pThis)>(il2cpp_class_get_property_from_name(dict->Il2CppClass.klass, "Count")->get->methodPointer)(dict));
		Il2CppObject* keys = il2cpp_runtime_invoke(il2cpp_class_get_property_from_name(dict->Il2CppClass.klass, "Keys")->get, dict, nullptr, nullptr);
		reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppArray * arr, int index)>(il2cpp_class_get_method_from_name(keys->Il2CppClass.klass, "CopyTo", 2)->methodPointer)(keys, toCopyTo, 0);
		std::vector<std::string> v = {};
		for (int i = 0; i < toCopyTo->max_length; i++)
		{
			v.push_back(string_Utf16ToUtf8(il2cpp_array_get(toCopyTo, Il2CppString*, i)));
		}
		return v;
	}
	return {};
}