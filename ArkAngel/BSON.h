#pragma once
#include <unordered_map>
#include <string>
#include <memory>

namespace BSON
{
	enum class ValueType
	{
		Double,
		String,
		Array,
		Binary,
		Boolean,
		UTCDateTime,
		None,
		Int32,
		Int64,
		Object
	};

	typedef struct Object Object;
	struct Value
	{
		ValueType valueType;
		double _double;
		std::string _string;
		std::vector<char> _binary;
		bool _bool;
		int int32;
		long long int64;
		Object* _object;

		Value()
		{
			_double = 0.0;
			_string = "";
			_binary = {};
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::None;
		}
		Value(float v)
		{
			_double = v;
			_string = "";
			_binary = {};
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::Double;
		}
		Value(double v)
		{
			_double = v;
			_string = "";
			_binary = {};
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::Double;
		}
		Value(char* v)
		{
			_double = 0.0;
			_binary = {};
			_string = v;
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::String;
		}
		Value(std::string v)
		{
			_double = 0.0;
			_binary = {};
			_string = v;
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::String;
		}
		Value(std::vector<char> v)
		{
			_double = 0.0;
			_binary = v;
			_string = "";
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::Binary;
		}
		Value(bool v)
		{
			_double = 0.0;
			_string = "";
			_binary = {};
			_bool = v;
			int32 = 0;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::Boolean;
		}
		Value(int v)
		{
			_double = 0.0;
			_string = "";
			_binary = {};
			_bool = false;
			int32 = v;
			int64 = 0;
			_object = nullptr;
			valueType = ValueType::Int32;
		}
		Value(long long v)
		{
			_double = 0.0;
			_string = "";
			_binary = {};
			_bool = false;
			int32 = 0;
			int64 = v;
			_object = nullptr;
			valueType = ValueType::Int64;
		}
		Value(Object& v)
		{
			_double = 0.0;
			_string = "";
			_binary = {};
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = &v;
			valueType = ValueType::Object;
		}
		Value(Object* v)
		{
			_double = 0.0;
			_string = "";
			_binary = {};
			_bool = false;
			int32 = 0;
			int64 = 0;
			_object = v;
			valueType = ValueType::Object;
		}
	};
	struct Object
	{
		std::unordered_map<std::string, Value> map = {};
		Value& operator[](const std::string& v)
		{
			if (map.count(v) != 0)
				return map[v];
		}
	};
	struct BSONEncoder
	{
		static std::string DecodeCString(std::vector<char>& v, int& pos)
		{
			std::string s = "";
			while (v[pos] != 0)
			{
				s += v[pos];
				pos++;
			}
			pos++;
			return s;
		}
		static std::string DecodeString(std::vector<char>& v, int& pos)
		{
			int len = *(int*)&v[pos];
			pos += sizeof(int);
			std::string s = "";
			for (int i = 0; i < len; i++)
			{
				s += v[pos];
				pos++;
			}
			pos++;
			return s;
		}


		static Value DecodeElement(std::vector<char>& v, int& pos, std::string& name)
		{
			char valType = v[pos];
			pos++;
			Value val = Value();
			switch (valType)
			{
			case 0x1: // float/double
				name = DecodeCString(v, pos);
				val = Value(*(float*)&v[pos]);
				pos += 4;
				break;
			case 0x2: // string
				name = DecodeCString(v, pos);
				val = Value(DecodeString(v, pos));
				break;
			case 0x3: // bson document
				name = DecodeCString(v, pos);
				{
					std::vector<char> f = {};
					int l = *(int*)&v[pos];
					f.assign(v.begin() + pos, v.begin() + pos + l);
					//Object o = ;
					Object loadedObject = Load(f, &pos);
					val = Value(new Object(loadedObject));

				}
				break;
			case 0x5: // binary
				name = DecodeCString(v, pos);
				{
					int len = *(int*)&v[pos];
					pos += 4;
					char binaryType = v[pos];
					pos++;
					std::vector<char> b = {};
					b.resize(len);
					for (int i = 0; i < len; i++)
					{
						b[i] = v[pos];
						pos++;
					}
					val = Value(b);
					//val = Value(DecodeBinary(v, pos));
					break;
				}
			case 0x8: // boolean
				name = DecodeCString(v, pos);
				val = Value(*(bool*)&v[pos]);
				pos += 1;
				break;
			case 0xA: // none
				name = DecodeCString(v, pos);
				val = Value();
				break;
			case 0x10: // int32
				name = DecodeCString(v, pos);
				val = Value(*(int*)&v[pos]);
				pos += 4;
				break;
			case 0x12: // int64
				name = DecodeCString(v, pos);
				val = Value(*(long long*)&v[pos]);
				pos += 8;
				break;
			}
			return val;
		}

		static Object Load(std::vector<char>& v, int* pos = nullptr)
		{
			int len = (*(int*)&v[0]) - 4;

			Object obj = Object();

			int i = v.size() - len;


			while (i < len - 1)
			{
				std::string name = "";
				Value val = DecodeElement(v, i, name);
				obj.map[name] = val;
			}

			if (pos)
				*pos += len;

			//nt i = (int)mBinaryReader.BaseStream.Position;
			//while (mBinaryReader.BaseStream.Position < i + length - 1)
			//{
			//	string name;
			//	BSONValue value = decodeElement(out name);
			//	obj.Add(name, value);
			//}
			return obj;
		}


		static void EncodeCString(std::vector<char>& v, std::string value)
		{
			for (int i = 0; i < value.length(); i++)
			{
				v.push_back(value[i]);
			}
			v.push_back(0x00);
		}
		static void EncodeString(std::vector<char>& v, std::string value)
		{
			int l = value.length();
			char* c = (char*)&l;
			for (int i = 0; i < 4; i++)
				v.push_back(c[i]);
			for (int i = 0; i < value.length(); i++)
			{
				v.push_back(value[i]);
			}
			v.push_back(0x00);
		}
		static void EncodeDouble(std::vector<char>& v, float value)
		{
			char* c = (char*)&value;
			for (int i = 0; i < 4; i++)
				v.push_back(c[i]);
		}
		static void EncodeBinary(std::vector<char>& v, std::vector<char>& value)
		{
			int l = value.size();
			char* c = (char*)&l;
			for (int i = 0; i < 4; i++)
				v.push_back(c[i]);
			v.push_back(0);
			for (int i = 0; i < value.size(); i++)
			{
				v.push_back(value[i]);
			}
		}
		static void EncodeBool(std::vector<char>& v, bool value)
		{
			v.push_back(value);
		}
		static void EncodeInt32(std::vector<char>& v, int value)
		{
			char* c = (char*)&value;
			for (int i = 0; i < 4; i++)
				v.push_back(c[i]);
		}
		static void EncodeInt64(std::vector<char>& v, long long value)
		{
			char* c = (char*)&value;
			for (int i = 0; i < 8; i++)
				v.push_back(c[i]);
		}

		static void EncodeElement(std::vector<char>& v, std::string name, Value value)
		{
			switch (value.valueType)
			{
			case ValueType::Double:
				v.push_back(0x01);
				EncodeCString(v, name);
				EncodeDouble(v, value._double);
				return;
			case ValueType::String:
				v.push_back(0x02);
				EncodeCString(v, name);
				EncodeString(v, value._string);
				return;
			case ValueType::Object:
				v.push_back(0x03);
				EncodeCString(v, name);
				{
					std::vector<char> bsonArray = Dump(*value._object);
					v.insert(v.end(), bsonArray.begin(), bsonArray.end());
				}
				return;
				//case ValueType::Array:
				//	v.push_back(0x04);
				//	EncodeCString(ms, name);
				//	encodeArray(ms, v as BSONArray);
				//	return;
			case ValueType::Binary:
				v.push_back(0x05);
				EncodeCString(v, name);
				EncodeBinary(v, value._binary);
				return;
			case ValueType::Boolean:
				v.push_back(0x08);
				EncodeCString(v, name);
				EncodeBool(v, value._bool);
				return;
				//case ValueType::UTCDateTime:
				//	v.push_back(0x09);
				//	EncodeCString(v, name);
				//	encodeUTCDateTime(v, v.dateTimeValue);
				//	return;
			case ValueType::None:
				v.push_back(0x0A);
				EncodeCString(v, name);
				return;
			case ValueType::Int32:
				v.push_back(0x10);
				EncodeCString(v, name);
				EncodeInt32(v, value.int32);
				return;
			case ValueType::Int64:
				v.push_back(0x12);
				EncodeCString(v, name);
				EncodeInt64(v, value.int64);
				return;
			};
		}
		static std::vector<char> Dump(Object& obj)
		{
			std::vector<char> v = {};
			for (auto& [key, value] : obj.map)
			{
				EncodeElement(v, key, value);
			}

			std::vector<char> v2 = {};
			v2.resize(v.size() + 4 + 1);
			int len = v.size() + 4 + 1;
			char* c = (char*)&len;
			for (int i = 0; i < 4; i++)
				v2[i] = c[i];

			for (int i = 0; i < v.size(); i++)
			{
				v2[i + 4] = v[i];
			}
			v2[len - 1] = 0;
			return v2;
		}
	};
}

std::string cbson_format(BSON::Object obj, std::string indent_s = "")
{
	int i = 0;
	std::string s = "{\n\t";
	for (auto& [key, value] : obj.map)
	{
		s += indent_s + key + ": ";

		switch (value.valueType)
		{
		case BSON::ValueType::Int32:
			s += std::to_string(value.int32);
			break;
		case BSON::ValueType::Int64:
			s += std::to_string(value.int64);
			break;
		case BSON::ValueType::String:
			s += value._string;
			break;
		case BSON::ValueType::Double:
			s += std::to_string(value._double);
			break;
		case BSON::ValueType::Boolean:
			s += value._bool ? "true" : false;
			break;
		case BSON::ValueType::Object:
			indent_s += "\t";
			s += cbson_format(*value._object, indent_s);
			indent_s.pop_back();
			break;
		case BSON::ValueType::Binary:
		{
			s += "[\n\t\t";
			for (int j = 0; j < value._binary.size(); j++)
			{
				s += std::to_string(value._binary[j]);
				if (j + 1 < value._binary.size())
					s += "\n\t\t";
			}
			s += "\n\t]";
			break;
		}
		}

		if (i + 1 < obj.map.size())
			s += ",\n\t";
		i++;
	}

	s += "\n" + indent_s + "}";
	return s;
}

