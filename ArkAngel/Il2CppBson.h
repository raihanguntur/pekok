#pragma once
struct BSONValue
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
		Object,
	};
	Il2CppClass* klass;
	MonitorData* monitor;
	ValueType mValueType;
	double _double;
	Il2CppString* _string;
	Il2CppArrayT<unsigned char>* _binary;
	bool _bool;
	DateTime _dateTime;
	int int32;
	long long int64;
};
struct BSONObject
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* mMap;
};