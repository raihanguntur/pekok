#include <stdint.h>
#pragma once
// IL2CPP APIs


typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppType Il2CppType;
typedef struct EventInfo EventInfo;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppArray Il2CppArray;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppProfiler Il2CppProfiler;
typedef struct Il2CppObject Il2CppObject;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppReflectionType Il2CppReflectionType;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppThread Il2CppThread;
typedef struct Il2CppAsyncResult Il2CppAsyncResult;
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef struct Il2CppCustomAttrInfo Il2CppCustomAttrInfo;
typedef enum
{
    IL2CPP_PROFILE_NONE = 0,
    IL2CPP_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
    IL2CPP_PROFILE_ASSEMBLY_EVENTS = 1 << 1,
    IL2CPP_PROFILE_MODULE_EVENTS = 1 << 2,
    IL2CPP_PROFILE_CLASS_EVENTS = 1 << 3,
    IL2CPP_PROFILE_JIT_COMPILATION = 1 << 4,
    IL2CPP_PROFILE_INLINING = 1 << 5,
    IL2CPP_PROFILE_EXCEPTIONS = 1 << 6,
    IL2CPP_PROFILE_ALLOCATIONS = 1 << 7,
    IL2CPP_PROFILE_GC = 1 << 8,
    IL2CPP_PROFILE_THREADS = 1 << 9,
    IL2CPP_PROFILE_REMOTING = 1 << 10,
    IL2CPP_PROFILE_TRANSITIONS = 1 << 11,
    IL2CPP_PROFILE_ENTER_LEAVE = 1 << 12,
    IL2CPP_PROFILE_COVERAGE = 1 << 13,
    IL2CPP_PROFILE_INS_COVERAGE = 1 << 14,
    IL2CPP_PROFILE_STATISTICAL = 1 << 15,
    IL2CPP_PROFILE_METHOD_EVENTS = 1 << 16,
    IL2CPP_PROFILE_MONITOR_EVENTS = 1 << 17,
    IL2CPP_PROFILE_IOMAP_EVENTS = 1 << 18,
    IL2CPP_PROFILE_GC_MOVES = 1 << 19,
    IL2CPP_PROFILE_FILEIO = 1 << 20
} Il2CppProfileFlags;
typedef enum
{
    IL2CPP_PROFILE_FILEIO_WRITE = 0,
    IL2CPP_PROFILE_FILEIO_READ
} Il2CppProfileFileIOKind;
typedef enum
{
    IL2CPP_GC_EVENT_START,
    IL2CPP_GC_EVENT_MARK_START,
    IL2CPP_GC_EVENT_MARK_END,
    IL2CPP_GC_EVENT_RECLAIM_START,
    IL2CPP_GC_EVENT_RECLAIM_END,
    IL2CPP_GC_EVENT_END,
    IL2CPP_GC_EVENT_PRE_STOP_WORLD,
    IL2CPP_GC_EVENT_POST_STOP_WORLD,
    IL2CPP_GC_EVENT_PRE_START_WORLD,
    IL2CPP_GC_EVENT_POST_START_WORLD
} Il2CppGCEvent;
typedef enum
{
    IL2CPP_STAT_NEW_OBJECT_COUNT,
    IL2CPP_STAT_INITIALIZED_CLASS_COUNT,
    IL2CPP_STAT_METHOD_COUNT,
    IL2CPP_STAT_CLASS_STATIC_DATA_SIZE,
    IL2CPP_STAT_GENERIC_INSTANCE_COUNT,
    IL2CPP_STAT_GENERIC_CLASS_COUNT,
    IL2CPP_STAT_INFLATED_METHOD_COUNT,
    IL2CPP_STAT_INFLATED_TYPE_COUNT,
} Il2CppStat;
typedef enum
{
    IL2CPP_UNHANDLED_POLICY_LEGACY,
    IL2CPP_UNHANDLED_POLICY_CURRENT
} Il2CppRuntimeUnhandledExceptionPolicy;
typedef struct Il2CppStackFrameInfo
{
    const MethodInfo* method;
} Il2CppStackFrameInfo;
typedef void(*Il2CppMethodPointer)();
typedef struct Il2CppMethodDebugInfo
{
    Il2CppMethodPointer methodPointer;
    int32_t code_size;
    const char* file;
} Il2CppMethodDebugInfo;
typedef struct
{
    void* (*malloc_func)(size_t size);
    void* (*aligned_malloc_func)(size_t size, size_t alignment);
    void (*free_func)(void* ptr);
    void (*aligned_free_func)(void* ptr);
    void* (*calloc_func)(size_t nmemb, size_t size);
    void* (*realloc_func)(void* ptr, size_t size);
    void* (*aligned_realloc_func)(void* ptr, size_t size, size_t alignment);
} Il2CppMemoryCallbacks;
typedef struct
{
    const char* name;
    void(*connect)(const char* address);
    int(*wait_for_attach)(void);
    void(*close1)(void);
    void(*close2)(void);
    int(*send)(void* buf, int len);
    int(*recv)(void* buf, int len);
} Il2CppDebuggerTransport;
typedef uint16_t Il2CppChar;
typedef char Il2CppNativeChar;
typedef void (*il2cpp_register_object_callback)(Il2CppObject** arr, int size, void* userdata);
typedef void (*il2cpp_WorldChangedCallback)();
typedef void (*Il2CppFrameWalkFunc) (const Il2CppStackFrameInfo* info, void* user_data);
typedef void (*Il2CppProfileFunc) (Il2CppProfiler* prof);
typedef void (*Il2CppProfileMethodFunc) (Il2CppProfiler* prof, const MethodInfo* method);
typedef void (*Il2CppProfileAllocFunc) (Il2CppProfiler* prof, Il2CppObject* obj, Il2CppClass* klass);
typedef void (*Il2CppProfileGCFunc) (Il2CppProfiler* prof, Il2CppGCEvent event, int generation);
typedef void (*Il2CppProfileGCResizeFunc) (Il2CppProfiler* prof, int64_t new_size);
typedef void (*Il2CppProfileFileIOFunc) (Il2CppProfiler* prof, Il2CppProfileFileIOKind kind, int count);
typedef void (*Il2CppProfileThreadFunc) (Il2CppProfiler* prof, unsigned long tid);
typedef const Il2CppNativeChar* (*Il2CppSetFindPlugInCallback)(const Il2CppNativeChar*);
typedef void (*Il2CppLogCallback)(const char*);
typedef size_t(*Il2CppBacktraceFunc) (Il2CppMethodPointer* buffer, size_t maxSize);
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef uintptr_t il2cpp_array_size_t;
typedef void (*SynchronizationContextCallback)(intptr_t arg);
typedef uint32_t Il2CppMethodSlot;
static const uint32_t kInvalidIl2CppMethodSlot = 65535;
static const int ipv6AddressSize = 16;
typedef int32_t il2cpp_hresult_t;
typedef struct Il2CppMetadataField
{
    uint32_t offset;
    uint32_t typeIndex;
    const char* name;
    uint8_t isStatic;
} Il2CppMetadataField;
typedef enum Il2CppMetadataTypeFlags
{
    kNone = 0,
    kValueType = 1 << 0,
    kArray = 1 << 1,
    kArrayRankMask = 0xFFFF0000
} Il2CppMetadataTypeFlags;
typedef struct Il2CppMetadataType
{
    Il2CppMetadataTypeFlags flags;
    Il2CppMetadataField* fields;
    uint32_t fieldCount;
    uint32_t staticsSize;
    uint8_t* statics;
    uint32_t baseOrElementTypeIndex;
    char* name;
    const char* assemblyName;
    uint64_t typeInfoAddress;
    uint32_t size;
} Il2CppMetadataType;
typedef struct Il2CppMetadataSnapshot
{
    uint32_t typeCount;
    Il2CppMetadataType* types;
} Il2CppMetadataSnapshot;
typedef struct Il2CppManagedMemorySection
{
    uint64_t sectionStartAddress;
    uint32_t sectionSize;
    uint8_t* sectionBytes;
} Il2CppManagedMemorySection;
typedef struct Il2CppManagedHeap
{
    uint32_t sectionCount;
    Il2CppManagedMemorySection* sections;
} Il2CppManagedHeap;
typedef struct Il2CppStacks
{
    uint32_t stackCount;
    Il2CppManagedMemorySection* stacks;
} Il2CppStacks;
typedef struct NativeObject
{
    uint32_t gcHandleIndex;
    uint32_t size;
    uint32_t instanceId;
    uint32_t classId;
    uint32_t referencedNativeObjectIndicesCount;
    uint32_t* referencedNativeObjectIndices;
} NativeObject;
typedef struct Il2CppGCHandles
{
    uint32_t trackedObjectCount;
    uint64_t* pointersToObjects;
} Il2CppGCHandles;
typedef struct Il2CppRuntimeInformation
{
    uint32_t pointerSize;
    uint32_t objectHeaderSize;
    uint32_t arrayHeaderSize;
    uint32_t arrayBoundsOffsetInHeader;
    uint32_t arraySizeOffsetInHeader;
    uint32_t allocationGranularity;
} Il2CppRuntimeInformation;
typedef struct Il2CppManagedMemorySnapshot
{
    Il2CppManagedHeap heap;
    Il2CppStacks stacks;
    Il2CppMetadataSnapshot metadata;
    Il2CppGCHandles gcHandles;
    Il2CppRuntimeInformation runtimeInformation;
    void* additionalUserInformation;
} Il2CppManagedMemorySnapshot;
typedef enum Il2CppTypeEnum
{
    IL2CPP_TYPE_END = 0x00,
    IL2CPP_TYPE_VOID = 0x01,
    IL2CPP_TYPE_BOOLEAN = 0x02,
    IL2CPP_TYPE_CHAR = 0x03,
    IL2CPP_TYPE_I1 = 0x04,
    IL2CPP_TYPE_U1 = 0x05,
    IL2CPP_TYPE_I2 = 0x06,
    IL2CPP_TYPE_U2 = 0x07,
    IL2CPP_TYPE_I4 = 0x08,
    IL2CPP_TYPE_U4 = 0x09,
    IL2CPP_TYPE_I8 = 0x0a,
    IL2CPP_TYPE_U8 = 0x0b,
    IL2CPP_TYPE_R4 = 0x0c,
    IL2CPP_TYPE_R8 = 0x0d,
    IL2CPP_TYPE_STRING = 0x0e,
    IL2CPP_TYPE_PTR = 0x0f,
    IL2CPP_TYPE_BYREF = 0x10,
    IL2CPP_TYPE_VALUETYPE = 0x11,
    IL2CPP_TYPE_CLASS = 0x12,
    IL2CPP_TYPE_VAR = 0x13,
    IL2CPP_TYPE_ARRAY = 0x14,
    IL2CPP_TYPE_GENERICINST = 0x15,
    IL2CPP_TYPE_TYPEDBYREF = 0x16,
    IL2CPP_TYPE_I = 0x18,
    IL2CPP_TYPE_U = 0x19,
    IL2CPP_TYPE_FNPTR = 0x1b,
    IL2CPP_TYPE_OBJECT = 0x1c,
    IL2CPP_TYPE_SZARRAY = 0x1d,
    IL2CPP_TYPE_MVAR = 0x1e,
    IL2CPP_TYPE_CMOD_REQD = 0x1f,
    IL2CPP_TYPE_CMOD_OPT = 0x20,
    IL2CPP_TYPE_INTERNAL = 0x21,
    IL2CPP_TYPE_MODIFIER = 0x40,
    IL2CPP_TYPE_SENTINEL = 0x41,
    IL2CPP_TYPE_PINNED = 0x45,
    IL2CPP_TYPE_ENUM = 0x55
} Il2CppTypeEnum;
typedef enum
{
    IL2CPP_TOKEN_MODULE = 0x00000000,
    IL2CPP_TOKEN_TYPE_REF = 0x01000000,
    IL2CPP_TOKEN_TYPE_DEF = 0x02000000,
    IL2CPP_TOKEN_FIELD_DEF = 0x04000000,
    IL2CPP_TOKEN_METHOD_DEF = 0x06000000,
    IL2CPP_TOKEN_PARAM_DEF = 0x08000000,
    IL2CPP_TOKEN_INTERFACE_IMPL = 0x09000000,
    IL2CPP_TOKEN_MEMBER_REF = 0x0a000000,
    IL2CPP_TOKEN_CUSTOM_ATTRIBUTE = 0x0c000000,
    IL2CPP_TOKEN_PERMISSION = 0x0e000000,
    IL2CPP_TOKEN_SIGNATURE = 0x11000000,
    IL2CPP_TOKEN_EVENT = 0x14000000,
    IL2CPP_TOKEN_PROPERTY = 0x17000000,
    IL2CPP_TOKEN_MODULE_REF = 0x1a000000,
    IL2CPP_TOKEN_TYPE_SPEC = 0x1b000000,
    IL2CPP_TOKEN_ASSEMBLY = 0x20000000,
    IL2CPP_TOKEN_ASSEMBLY_REF = 0x23000000,
    IL2CPP_TOKEN_FILE = 0x26000000,
    IL2CPP_TOKEN_EXPORTED_TYPE = 0x27000000,
    IL2CPP_TOKEN_MANIFEST_RESOURCE = 0x28000000,
    IL2CPP_TOKEN_GENERIC_PARAM = 0x2a000000,
    IL2CPP_TOKEN_METHOD_SPEC = 0x2b000000,
} Il2CppTokenType;
typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t InteropDataIndex;
static const TypeIndex kTypeIndexInvalid = -1;
static const TypeDefinitionIndex kTypeDefinitionIndexInvalid = -1;
static const DefaultValueDataIndex kDefaultValueIndexNull = -1;
static const CustomAttributeIndex kCustomAttributeIndexInvalid = -1;
static const EventIndex kEventIndexInvalid = -1;
static const FieldIndex kFieldIndexInvalid = -1;
static const MethodIndex kMethodIndexInvalid = -1;
static const PropertyIndex kPropertyIndexInvalid = -1;
static const GenericContainerIndex kGenericContainerIndexInvalid = -1;
static const GenericParameterIndex kGenericParameterIndexInvalid = -1;
static const RGCTXIndex kRGCTXIndexInvalid = -1;
static const StringLiteralIndex kStringLiteralIndexInvalid = -1;
static const InteropDataIndex kInteropDataIndexInvalid = -1;
typedef uint32_t EncodedMethodIndex;
typedef enum Il2CppMetadataUsage
{
    kIl2CppMetadataUsageInvalid,
    kIl2CppMetadataUsageTypeInfo,
    kIl2CppMetadataUsageIl2CppType,
    kIl2CppMetadataUsageMethodDef,
    kIl2CppMetadataUsageFieldInfo,
    kIl2CppMetadataUsageStringLiteral,
    kIl2CppMetadataUsageMethodRef,
} Il2CppMetadataUsage;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppTypeDefinitionMetadata Il2CppTypeDefinitionMetadata;
typedef union Il2CppRGCTXDefinitionData
{
    int32_t rgctxDataDummy;
    MethodIndex methodIndex;
    TypeIndex typeIndex;
} Il2CppRGCTXDefinitionData;
typedef enum Il2CppRGCTXDataType
{
    IL2CPP_RGCTX_DATA_INVALID,
    IL2CPP_RGCTX_DATA_TYPE,
    IL2CPP_RGCTX_DATA_CLASS,
    IL2CPP_RGCTX_DATA_METHOD,
    IL2CPP_RGCTX_DATA_ARRAY,
} Il2CppRGCTXDataType;
typedef struct Il2CppRGCTXDefinition
{
    Il2CppRGCTXDataType type;
    Il2CppRGCTXDefinitionData data;
} Il2CppRGCTXDefinition;
typedef struct Il2CppInterfaceOffsetPair
{
    TypeIndex interfaceTypeIndex;
    int32_t offset;
} Il2CppInterfaceOffsetPair;
typedef struct Il2CppTypeDefinition
{
    StringIndex nameIndex;
    StringIndex namespaceIndex;
    TypeIndex byvalTypeIndex;
    TypeIndex byrefTypeIndex;
    TypeIndex declaringTypeIndex;
    TypeIndex parentIndex;
    TypeIndex elementTypeIndex;
    GenericContainerIndex genericContainerIndex;
    uint32_t flags;
    FieldIndex fieldStart;
    MethodIndex methodStart;
    EventIndex eventStart;
    PropertyIndex propertyStart;
    NestedTypeIndex nestedTypesStart;
    InterfacesIndex interfacesStart;
    VTableIndex vtableStart;
    InterfacesIndex interfaceOffsetsStart;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint32_t bitfield;
    uint32_t token;
} Il2CppTypeDefinition;
typedef struct Il2CppFieldDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    uint32_t token;
} Il2CppFieldDefinition;
typedef struct Il2CppFieldDefaultValue
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppFieldDefaultValue;
typedef struct Il2CppFieldMarshaledSize
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    int32_t size;
} Il2CppFieldMarshaledSize;
typedef struct Il2CppFieldRef
{
    TypeIndex typeIndex;
    FieldIndex fieldIndex;
} Il2CppFieldRef;
typedef struct Il2CppParameterDefinition
{
    StringIndex nameIndex;
    uint32_t token;
    TypeIndex typeIndex;
} Il2CppParameterDefinition;
typedef struct Il2CppParameterDefaultValue
{
    ParameterIndex parameterIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppParameterDefaultValue;
typedef struct Il2CppMethodDefinition
{
    StringIndex nameIndex;
    TypeDefinitionIndex declaringType;
    TypeIndex returnType;
    ParameterIndex parameterStart;
    GenericContainerIndex genericContainerIndex;
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint16_t parameterCount;
} Il2CppMethodDefinition;
typedef struct Il2CppEventDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    MethodIndex add;
    MethodIndex remove;
    MethodIndex raise;
    uint32_t token;
} Il2CppEventDefinition;
typedef struct Il2CppPropertyDefinition
{
    StringIndex nameIndex;
    MethodIndex get;
    MethodIndex set;
    uint32_t attrs;
    uint32_t token;
} Il2CppPropertyDefinition;
typedef struct Il2CppMethodSpec
{
    MethodIndex methodDefinitionIndex;
    GenericInstIndex classIndexIndex;
    GenericInstIndex methodIndexIndex;
} Il2CppMethodSpec;
typedef struct Il2CppStringLiteral
{
    uint32_t length;
    StringLiteralIndex dataIndex;
} Il2CppStringLiteral;
typedef struct
{
    MethodIndex methodIndex;
    MethodIndex invokerIndex;
} Il2CppGenericMethodIndices;
typedef struct Il2CppGenericMethodFunctionsDefinitions
{
    GenericMethodIndex genericMethodIndex;
    Il2CppGenericMethodIndices indices;
} Il2CppGenericMethodFunctionsDefinitions;
static const int kPublicKeyByteLength = 8;
typedef struct Il2CppAssemblyNameDefinition
{
    StringIndex nameIndex;
    StringIndex cultureIndex;
    StringIndex publicKeyIndex;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[8];
} Il2CppAssemblyNameDefinition;
typedef struct Il2CppImageDefinition
{
    StringIndex nameIndex;
    AssemblyIndex assemblyIndex;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    MethodIndex entryPointIndex;
    uint32_t token;
    CustomAttributeIndex customAttributeStart;
    uint32_t customAttributeCount;
} Il2CppImageDefinition;
typedef struct Il2CppAssemblyDefinition
{
    ImageIndex imageIndex;
    uint32_t token;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    Il2CppAssemblyNameDefinition aname;
} Il2CppAssemblyDefinition;
typedef struct Il2CppMetadataUsageList
{
    uint32_t start;
    uint32_t count;
} Il2CppMetadataUsageList;
typedef struct Il2CppMetadataUsagePair
{
    uint32_t destinationIndex;
    uint32_t encodedSourceIndex;
} Il2CppMetadataUsagePair;
typedef struct Il2CppCustomAttributeTypeRange
{
    uint32_t token;
    int32_t start;
    int32_t count;
} Il2CppCustomAttributeTypeRange;
typedef struct Il2CppRange
{
    int32_t start;
    int32_t length;
} Il2CppRange;
typedef struct Il2CppWindowsRuntimeTypeNamePair
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
} Il2CppWindowsRuntimeTypeNamePair;
#pragma pack(push, p1,4)
typedef struct Il2CppGlobalMetadataHeader
{
    int32_t sanity;
    int32_t version;
    int32_t stringLiteralOffset;
    int32_t stringLiteralCount;
    int32_t stringLiteralDataOffset;
    int32_t stringLiteralDataCount;
    int32_t stringOffset;
    int32_t stringCount;
    int32_t eventsOffset;
    int32_t eventsCount;
    int32_t propertiesOffset;
    int32_t propertiesCount;
    int32_t methodsOffset;
    int32_t methodsCount;
    int32_t parameterDefaultValuesOffset;
    int32_t parameterDefaultValuesCount;
    int32_t fieldDefaultValuesOffset;
    int32_t fieldDefaultValuesCount;
    int32_t fieldAndParameterDefaultValueDataOffset;
    int32_t fieldAndParameterDefaultValueDataCount;
    int32_t fieldMarshaledSizesOffset;
    int32_t fieldMarshaledSizesCount;
    int32_t parametersOffset;
    int32_t parametersCount;
    int32_t fieldsOffset;
    int32_t fieldsCount;
    int32_t genericParametersOffset;
    int32_t genericParametersCount;
    int32_t genericParameterConstraintsOffset;
    int32_t genericParameterConstraintsCount;
    int32_t genericContainersOffset;
    int32_t genericContainersCount;
    int32_t nestedTypesOffset;
    int32_t nestedTypesCount;
    int32_t interfacesOffset;
    int32_t interfacesCount;
    int32_t vtableMethodsOffset;
    int32_t vtableMethodsCount;
    int32_t interfaceOffsetsOffset;
    int32_t interfaceOffsetsCount;
    int32_t typeDefinitionsOffset;
    int32_t typeDefinitionsCount;
    int32_t imagesOffset;
    int32_t imagesCount;
    int32_t assembliesOffset;
    int32_t assembliesCount;
    int32_t metadataUsageListsOffset;
    int32_t metadataUsageListsCount;
    int32_t metadataUsagePairsOffset;
    int32_t metadataUsagePairsCount;
    int32_t fieldRefsOffset;
    int32_t fieldRefsCount;
    int32_t referencedAssembliesOffset;
    int32_t referencedAssembliesCount;
    int32_t attributesInfoOffset;
    int32_t attributesInfoCount;
    int32_t attributeTypesOffset;
    int32_t attributeTypesCount;
    int32_t unresolvedVirtualCallParameterTypesOffset;
    int32_t unresolvedVirtualCallParameterTypesCount;
    int32_t unresolvedVirtualCallParameterRangesOffset;
    int32_t unresolvedVirtualCallParameterRangesCount;
    int32_t windowsRuntimeTypeNamesOffset;
    int32_t windowsRuntimeTypeNamesSize;
    int32_t exportedTypeDefinitionsOffset;
    int32_t exportedTypeDefinitionsCount;
} Il2CppGlobalMetadataHeader;
#pragma pack(pop, p1)
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppArrayType
{
    const Il2CppType* etype;
    uint8_t rank;
    uint8_t numsizes;
    uint8_t numlobounds;
    int* sizes;
    int* lobounds;
} Il2CppArrayType;
typedef struct Il2CppGenericInst
{
    uint32_t type_argc;
    const Il2CppType** type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
    const Il2CppGenericInst* class_inst;
    const Il2CppGenericInst* method_inst;
} Il2CppGenericContext;
typedef struct Il2CppGenericParameter
{
    GenericContainerIndex ownerIndex;
    StringIndex nameIndex;
    GenericParameterConstraintIndex constraintsStart;
    int16_t constraintsCount;
    uint16_t num;
    uint16_t flags;
} Il2CppGenericParameter;
typedef struct Il2CppGenericContainer
{
    int32_t ownerIndex;
    int32_t type_argc;
    int32_t is_method;
    GenericParameterIndex genericParameterStart;
} Il2CppGenericContainer;
typedef struct Il2CppGenericClass
{
    TypeDefinitionIndex typeDefinitionIndex;
    Il2CppGenericContext context;
    Il2CppClass* cached_class;
} Il2CppGenericClass;
typedef struct Il2CppGenericMethod
{
    const MethodInfo* methodDefinition;
    Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct Il2CppType
{
    union
    {
        void* dummy;
        TypeDefinitionIndex klassIndex;
        const Il2CppType* type;
        Il2CppArrayType* array;
        GenericParameterIndex genericParameterIndex;
        Il2CppGenericClass* generic_class;
    } data;
    unsigned int attrs : 16;
    Il2CppTypeEnum type : 8;
    unsigned int num_mods : 6;
    unsigned int byref : 1;
    unsigned int pinned : 1;
} Il2CppType;
typedef enum Il2CppCallConvention
{
    IL2CPP_CALL_DEFAULT,
    IL2CPP_CALL_C,
    IL2CPP_CALL_STDCALL,
    IL2CPP_CALL_THISCALL,
    IL2CPP_CALL_FASTCALL,
    IL2CPP_CALL_VARARG
} Il2CppCallConvention;
typedef enum Il2CppCharSet
{
    CHARSET_ANSI,
    CHARSET_UNICODE,
    CHARSET_NOT_SPECIFIED
} Il2CppCharSet;
typedef struct Il2CppHString__
{
    int unused;
} Il2CppHString__;
typedef Il2CppHString__* Il2CppHString;
typedef struct Il2CppHStringHeader
{
    union
    {
        void* Reserved1;
        char Reserved2[24];
    } Reserved;
} Il2CppHStringHeader;
typedef struct Il2CppGuid
{
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[8];
} Il2CppGuid;
typedef struct Il2CppSafeArrayBound
{
    uint32_t element_count;
    int32_t lower_bound;
} Il2CppSafeArrayBound;
typedef struct Il2CppSafeArray
{
    uint16_t dimension_count;
    uint16_t features;
    uint32_t element_size;
    uint32_t lock_count;
    void* data;
    Il2CppSafeArrayBound bounds[1];
} Il2CppSafeArray;
typedef struct Il2CppWin32Decimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } s;
        uint16_t signscale;
    } u;
    uint32_t hi32;
    union
    {
        struct
        {
            uint32_t lo32;
            uint32_t mid32;
        } s2;
        uint64_t lo64;
    } u2;
} Il2CppWin32Decimal;
typedef int16_t IL2CPP_VARIANT_BOOL;
typedef enum Il2CppVarType
{
    IL2CPP_VT_EMPTY = 0,
    IL2CPP_VT_NULL = 1,
    IL2CPP_VT_I2 = 2,
    IL2CPP_VT_I4 = 3,
    IL2CPP_VT_R4 = 4,
    IL2CPP_VT_R8 = 5,
    IL2CPP_VT_CY = 6,
    IL2CPP_VT_DATE = 7,
    IL2CPP_VT_BSTR = 8,
    IL2CPP_VT_DISPATCH = 9,
    IL2CPP_VT_ERROR = 10,
    IL2CPP_VT_BOOL = 11,
    IL2CPP_VT_VARIANT = 12,
    IL2CPP_VT_UNKNOWN = 13,
    IL2CPP_VT_DECIMAL = 14,
    IL2CPP_VT_I1 = 16,
    IL2CPP_VT_UI1 = 17,
    IL2CPP_VT_UI2 = 18,
    IL2CPP_VT_UI4 = 19,
    IL2CPP_VT_I8 = 20,
    IL2CPP_VT_UI8 = 21,
    IL2CPP_VT_INT = 22,
    IL2CPP_VT_UINT = 23,
    IL2CPP_VT_VOID = 24,
    IL2CPP_VT_HRESULT = 25,
    IL2CPP_VT_PTR = 26,
    IL2CPP_VT_SAFEARRAY = 27,
    IL2CPP_VT_CARRAY = 28,
    IL2CPP_VT_USERDEFINED = 29,
    IL2CPP_VT_LPSTR = 30,
    IL2CPP_VT_LPWSTR = 31,
    IL2CPP_VT_RECORD = 36,
    IL2CPP_VT_INT_PTR = 37,
    IL2CPP_VT_UINT_PTR = 38,
    IL2CPP_VT_FILETIME = 64,
    IL2CPP_VT_BLOB = 65,
    IL2CPP_VT_STREAM = 66,
    IL2CPP_VT_STORAGE = 67,
    IL2CPP_VT_STREAMED_OBJECT = 68,
    IL2CPP_VT_STORED_OBJECT = 69,
    IL2CPP_VT_BLOB_OBJECT = 70,
    IL2CPP_VT_CF = 71,
    IL2CPP_VT_CLSID = 72,
    IL2CPP_VT_VERSIONED_STREAM = 73,
    IL2CPP_VT_BSTR_BLOB = 0xfff,
    IL2CPP_VT_VECTOR = 0x1000,
    IL2CPP_VT_ARRAY = 0x2000,
    IL2CPP_VT_BYREF = 0x4000,
    IL2CPP_VT_RESERVED = 0x8000,
    IL2CPP_VT_ILLEGAL = 0xffff,
    IL2CPP_VT_ILLEGALMASKED = 0xfff,
    IL2CPP_VT_TYPEMASK = 0xfff,
} Il2CppVarType;
typedef struct Il2CppVariant Il2CppVariant;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppVariant
{
    union
    {
        struct __tagVARIANT
        {
            uint16_t type;
            uint16_t reserved1;
            uint16_t reserved2;
            uint16_t reserved3;
            union
            {
                int64_t llVal;
                int32_t lVal;
                uint8_t bVal;
                int16_t iVal;
                float fltVal;
                double dblVal;
                IL2CPP_VARIANT_BOOL boolVal;
                int32_t scode;
                int64_t cyVal;
                double date;
                Il2CppChar* bstrVal;
                Il2CppIUnknown* punkVal;
                void* pdispVal;
                Il2CppSafeArray* parray;
                uint8_t* pbVal;
                int16_t* piVal;
                int32_t* plVal;
                int64_t* pllVal;
                float* pfltVal;
                double* pdblVal;
                IL2CPP_VARIANT_BOOL* pboolVal;
                int32_t* pscode;
                int64_t* pcyVal;
                double* pdate;
                Il2CppChar* pbstrVal;
                Il2CppIUnknown** ppunkVal;
                void** ppdispVal;
                Il2CppSafeArray** pparray;
                struct Il2CppVariant* pvarVal;
                void* byref;
                char cVal;
                uint16_t uiVal;
                uint32_t ulVal;
                uint64_t ullVal;
                int intVal;
                unsigned int uintVal;
                Il2CppWin32Decimal* pdecVal;
                char* pcVal;
                uint16_t* puiVal;
                uint32_t* pulVal;
                uint64_t* pullVal;
                int* pintVal;
                unsigned int* puintVal;
                struct __tagBRECORD
                {
                    void* pvRecord;
                    void* pRecInfo;
                } n4;
            } n3;
        } n2;
        Il2CppWin32Decimal decVal;
    } n1;
} Il2CppVariant;
typedef struct Il2CppFileTime
{
    uint32_t low;
    uint32_t high;
} Il2CppFileTime;
typedef struct Il2CppStatStg
{
    Il2CppChar* name;
    uint32_t type;
    uint64_t size;
    Il2CppFileTime mtime;
    Il2CppFileTime ctime;
    Il2CppFileTime atime;
    uint32_t mode;
    uint32_t locks;
    Il2CppGuid clsid;
    uint32_t state;
    uint32_t reserved;
} Il2CppStatStg;
typedef enum Il2CppWindowsRuntimeTypeKind
{
    kTypeKindPrimitive = 0,
    kTypeKindMetadata,
    kTypeKindCustom
} Il2CppWindowsRuntimeTypeKind;
typedef struct Il2CppWindowsRuntimeTypeName
{
    Il2CppHString typeName;
    enum Il2CppWindowsRuntimeTypeKind typeKind;
} Il2CppWindowsRuntimeTypeName;
typedef void (*PInvokeMarshalToNativeFunc)(void* managedStructure, void* marshaledStructure);
typedef void (*PInvokeMarshalFromNativeFunc)(void* marshaledStructure, void* managedStructure);
typedef void (*PInvokeMarshalCleanupFunc)(void* marshaledStructure);
typedef struct Il2CppIUnknown* (*CreateCCWFunc)(Il2CppObject* obj);
typedef struct Il2CppInteropData
{
    Il2CppMethodPointer delegatePInvokeWrapperFunction;
    PInvokeMarshalToNativeFunc pinvokeMarshalToNativeFunction;
    PInvokeMarshalFromNativeFunc pinvokeMarshalFromNativeFunction;
    PInvokeMarshalCleanupFunc pinvokeMarshalCleanupFunction;
    CreateCCWFunc createCCWFunction;
    const Il2CppGuid* guid;
    const Il2CppType* type;
} Il2CppInteropData;
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppGuid Il2CppGuid;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppAppDomain Il2CppAppDomain;
typedef struct Il2CppAppDomainSetup Il2CppAppDomainSetup;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppAppContext Il2CppAppContext;
typedef struct Il2CppNameToTypeDefinitionIndexHashTable Il2CppNameToTypeDefinitionIndexHashTable;
typedef struct Il2CppCodeGenModule Il2CppCodeGenModule;
typedef struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
} VirtualInvokeData;
typedef enum Il2CppTypeNameFormat
{
    IL2CPP_TYPE_NAME_FORMAT_IL,
    IL2CPP_TYPE_NAME_FORMAT_REFLECTION,
    IL2CPP_TYPE_NAME_FORMAT_FULL_NAME,
    IL2CPP_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED
} Il2CppTypeNameFormat;
typedef struct Il2CppDefaults
{
    Il2CppImage* corlib;
    Il2CppClass* object_class;
    Il2CppClass* byte_class;
    Il2CppClass* void_class;
    Il2CppClass* boolean_class;
    Il2CppClass* sbyte_class;
    Il2CppClass* int16_class;
    Il2CppClass* uint16_class;
    Il2CppClass* int32_class;
    Il2CppClass* uint32_class;
    Il2CppClass* int_class;
    Il2CppClass* uint_class;
    Il2CppClass* int64_class;
    Il2CppClass* uint64_class;
    Il2CppClass* single_class;
    Il2CppClass* double_class;
    Il2CppClass* char_class;
    Il2CppClass* string_class;
    Il2CppClass* enum_class;
    Il2CppClass* array_class;
    Il2CppClass* delegate_class;
    Il2CppClass* multicastdelegate_class;
    Il2CppClass* asyncresult_class;
    Il2CppClass* manualresetevent_class;
    Il2CppClass* typehandle_class;
    Il2CppClass* fieldhandle_class;
    Il2CppClass* methodhandle_class;
    Il2CppClass* systemtype_class;
    Il2CppClass* monotype_class;
    Il2CppClass* exception_class;
    Il2CppClass* threadabortexception_class;
    Il2CppClass* thread_class;
    Il2CppClass* internal_thread_class;
    Il2CppClass* appdomain_class;
    Il2CppClass* appdomain_setup_class;
    Il2CppClass* field_info_class;
    Il2CppClass* method_info_class;
    Il2CppClass* property_info_class;
    Il2CppClass* event_info_class;
    Il2CppClass* mono_event_info_class;
    Il2CppClass* stringbuilder_class;
    Il2CppClass* stack_frame_class;
    Il2CppClass* stack_trace_class;
    Il2CppClass* marshal_class;
    Il2CppClass* typed_reference_class;
    Il2CppClass* marshalbyrefobject_class;
    Il2CppClass* generic_ilist_class;
    Il2CppClass* generic_icollection_class;
    Il2CppClass* generic_ienumerable_class;
    Il2CppClass* generic_ireadonlylist_class;
    Il2CppClass* generic_ireadonlycollection_class;
    Il2CppClass* runtimetype_class;
    Il2CppClass* generic_nullable_class;
    Il2CppClass* il2cpp_com_object_class;
    Il2CppClass* attribute_class;
    Il2CppClass* customattribute_data_class;
    Il2CppClass* version;
    Il2CppClass* culture_info;
    Il2CppClass* async_call_class;
    Il2CppClass* assembly_class;
    Il2CppClass* mono_assembly_class;
    Il2CppClass* assembly_name_class;
    Il2CppClass* mono_field_class;
    Il2CppClass* mono_method_class;
    Il2CppClass* mono_method_info_class;
    Il2CppClass* mono_property_info_class;
    Il2CppClass* parameter_info_class;
    Il2CppClass* mono_parameter_info_class;
    Il2CppClass* module_class;
    Il2CppClass* pointer_class;
    Il2CppClass* system_exception_class;
    Il2CppClass* argument_exception_class;
    Il2CppClass* wait_handle_class;
    Il2CppClass* safe_handle_class;
    Il2CppClass* sort_key_class;
    Il2CppClass* dbnull_class;
    Il2CppClass* error_wrapper_class;
    Il2CppClass* missing_class;
    Il2CppClass* value_type_class;
    Il2CppClass* threadpool_wait_callback_class;
    MethodInfo* threadpool_perform_wait_callback_method;
    Il2CppClass* mono_method_message_class;
    Il2CppClass* ireference_class;
    Il2CppClass* ireferencearray_class;
    Il2CppClass* ikey_value_pair_class;
    Il2CppClass* key_value_pair_class;
    Il2CppClass* windows_foundation_uri_class;
    Il2CppClass* windows_foundation_iuri_runtime_class_class;
    Il2CppClass* system_uri_class;
    Il2CppClass* system_guid_class;
    Il2CppClass* sbyte_shared_enum;
    Il2CppClass* int16_shared_enum;
    Il2CppClass* int32_shared_enum;
    Il2CppClass* int64_shared_enum;
    Il2CppClass* byte_shared_enum;
    Il2CppClass* uint16_shared_enum;
    Il2CppClass* uint32_shared_enum;
    Il2CppClass* uint64_shared_enum;
} Il2CppDefaults;
extern Il2CppDefaults il2cpp_defaults;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct Il2CppObject Il2CppObject;
typedef struct MemberInfo MemberInfo;
typedef struct CustomAttributesCache
{
    int count;
    Il2CppObject** attributes;
} CustomAttributesCache;
typedef void (*CustomAttributesCacheGenerator)(CustomAttributesCache*);
typedef struct FieldInfo
{
    const char* name;
    const Il2CppType* type;
    Il2CppClass* parent;
    int32_t offset;
    uint32_t token;
} FieldInfo;
typedef struct PropertyInfo
{
    Il2CppClass* parent;
    const char* name;
    const MethodInfo* get;
    const MethodInfo* set;
    uint32_t attrs;
    uint32_t token;
} PropertyInfo;
typedef struct EventInfo
{
    const char* name;
    const Il2CppType* eventType;
    Il2CppClass* parent;
    const MethodInfo* add;
    const MethodInfo* remove;
    const MethodInfo* raise;
    uint32_t token;
} EventInfo;
typedef struct ParameterInfo
{
    const char* name;
    int32_t position;
    uint32_t token;
    const Il2CppType* parameter_type;
} ParameterInfo;
typedef void* (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**);
typedef enum MethodVariableKind
{
    kMethodVariableKind_This,
    kMethodVariableKind_Parameter,
    kMethodVariableKind_LocalVariable
} MethodVariableKind;
typedef enum SequencePointKind
{
    kSequencePointKind_Normal,
    kSequencePointKind_StepOut
} SequencePointKind;
typedef struct Il2CppMethodExecutionContextInfo
{
    TypeIndex typeIndex;
    int32_t nameIndex;
    int32_t scopeIndex;
} Il2CppMethodExecutionContextInfo;
typedef struct Il2CppMethodExecutionContextInfoIndex
{
    int32_t startIndex;
    int32_t count;
} Il2CppMethodExecutionContextInfoIndex;
typedef struct Il2CppMethodScope
{
    int32_t startOffset;
    int32_t endOffset;
} Il2CppMethodScope;
typedef struct Il2CppMethodHeaderInfo
{
    int32_t code_size;
    int32_t startScope;
    int32_t numScopes;
} Il2CppMethodHeaderInfo;
typedef struct Il2CppSequencePointSourceFile
{
    const char* file;
    uint8_t hash[16];
} Il2CppSequencePointSourceFile;
typedef struct Il2CppTypeSourceFilePair
{
    TypeDefinitionIndex klassIndex;
    int32_t sourceFileIndex;
} Il2CppTypeSourceFilePair;
typedef struct Il2CppSequencePoint
{
    MethodIndex methodDefinitionIndex;
    int32_t sourceFileIndex;
    int32_t lineStart, lineEnd;
    int32_t columnStart, columnEnd;
    int32_t ilOffset;
    SequencePointKind kind;
    int32_t isActive;
    int32_t id;
} Il2CppSequencePoint;
typedef struct Il2CppCatchPoint
{
    MethodIndex methodDefinitionIndex;
    TypeIndex catchTypeIndex;
    int32_t ilOffset;
    int32_t tryId;
    int32_t parentTryId;
} Il2CppCatchPoint;
typedef struct Il2CppDebuggerMetadataRegistration
{
    Il2CppMethodExecutionContextInfo* methodExecutionContextInfos;
    Il2CppMethodExecutionContextInfoIndex* methodExecutionContextInfoIndexes;
    Il2CppMethodScope* methodScopes;
    Il2CppMethodHeaderInfo* methodHeaderInfos;
    Il2CppSequencePointSourceFile* sequencePointSourceFiles;
    int32_t numSequencePoints;
    Il2CppSequencePoint* sequencePoints;
    int32_t numCatchPoints;
    Il2CppCatchPoint* catchPoints;
    int32_t numTypeSourceFileEntries;
    Il2CppTypeSourceFilePair* typeSourceFiles;
    const char** methodExecutionContextInfoStrings;
} Il2CppDebuggerMetadataRegistration;
typedef union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
} Il2CppRGCTXData;
typedef struct MethodInfo
{
    Il2CppMethodPointer methodPointer;
    InvokerMethod invoker_method;
    const char* name;
    Il2CppClass* klass;
    const Il2CppType* return_type;
    const ParameterInfo* parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const Il2CppMethodDefinition* methodDefinition;
    } Il2CppVariant;
    union
    {
        const Il2CppGenericMethod* genericMethod;
        const Il2CppGenericContainer* genericContainer;
    };
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint8_t parameters_count;
    uint8_t is_generic : 1;
    uint8_t is_inflated : 1;
    uint8_t wrapper_type : 1;
    uint8_t is_marshaled_from_native : 1;
} MethodInfo;
typedef struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
} Il2CppRuntimeInterfaceOffsetPair;
typedef struct Il2CppClass
{
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass* generic_class;
    const Il2CppTypeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    Il2CppClass* klass;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct Il2CppClass** typeHierarchy;
    void* unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    __declspec(align(8)) size_t cctor_thread;
    GenericContainerIndex genericContainerIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t initialized_and_no_error : 1;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
    uint8_t has_initialization_error : 1;
    VirtualInvokeData vtable[32];
} Il2CppClass;

typedef struct Il2CppClass_0 {
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass* generic_class;
    const Il2CppTypeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    Il2CppClass* klass;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
} Il2CppClass_0;

typedef struct Il2CppClass_1 {
    struct Il2CppClass** typeHierarchy;
    void* unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
#ifdef IS_32BIT
    uint32_t cctor_thread;
#else
    __declspec(align(8)) size_t cctor_thread;
#endif
    GenericContainerIndex genericContainerIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t initialized_and_no_error : 1;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
    uint8_t has_initialization_error : 1;
} Il2CppClass_1;

typedef struct __declspec(align(8)) Il2CppClass_Merged {
    struct Il2CppClass_0 _0;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct Il2CppClass_1 _1;
    VirtualInvokeData vtable[32];
} Il2CppClass_Merged;

typedef struct Il2CppTypeDefinitionSizes
{
    uint32_t instance_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
} Il2CppTypeDefinitionSizes;
typedef struct Il2CppDomain
{
    Il2CppAppDomain* domain;
    Il2CppAppDomainSetup* setup;
    Il2CppAppContext* default_context;
    const char* friendly_name;
    uint32_t domain_id;
    volatile int threadpool_jobs;
    void* agent_info;
} Il2CppDomain;
typedef struct Il2CppAssemblyName
{
    const char* name;
    const char* culture;
    const uint8_t* public_key;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[8];
} Il2CppAssemblyName;
typedef struct Il2CppImage
{
    const char* name;
    const char* nameNoExt;
    Il2CppAssembly* assembly;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    CustomAttributeIndex customAttributeStart;
    uint32_t customAttributeCount;
    MethodIndex entryPointIndex;
    Il2CppNameToTypeDefinitionIndexHashTable* nameToClassHashTable;
    const Il2CppCodeGenModule* codeGenModule;
    uint32_t token;
    uint8_t dynamic;
} Il2CppImage;
typedef struct Il2CppAssembly
{
    Il2CppImage* image;
    uint32_t token;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    Il2CppAssemblyName aname;
} Il2CppAssembly;
typedef struct Il2CppCodeGenOptions
{
    uint8_t enablePrimitiveValueTypeGenericSharing;
    int maximumRuntimeGenericDepth;
} Il2CppCodeGenOptions;
typedef struct Il2CppTokenIndexPair
{
    uint32_t token;
    int32_t index;
} Il2CppTokenIndexPair;
typedef struct Il2CppTokenRangePair
{
    uint32_t token;
    Il2CppRange range;
} Il2CppTokenRangePair;
typedef struct Il2CppTokenIndexMethodTuple
{
    uint32_t token;
    int32_t index;
    void** method;
    uint32_t genericMethodIndex;
} Il2CppTokenIndexMethodTuple;
typedef struct Il2CppWindowsRuntimeFactoryTableEntry
{
    const Il2CppType* type;
    Il2CppMethodPointer createFactoryFunction;
} Il2CppWindowsRuntimeFactoryTableEntry;
typedef struct Il2CppCodeGenModule
{
    const char* moduleName;
    const uint32_t methodPointerCount;
    const Il2CppMethodPointer* methodPointers;
    const int32_t* invokerIndices;
    const uint32_t reversePInvokeWrapperCount;
    const Il2CppTokenIndexMethodTuple* reversePInvokeWrapperIndices;
    const uint32_t rgctxRangesCount;
    const Il2CppTokenRangePair* rgctxRanges;
    const uint32_t rgctxsCount;
    const Il2CppRGCTXDefinition* rgctxs;
    const Il2CppDebuggerMetadataRegistration* debuggerMetadata;
} Il2CppCodeGenModule;
typedef struct Il2CppCodeRegistration
{
    uint32_t reversePInvokeWrapperCount;
    const Il2CppMethodPointer* reversePInvokeWrappers;
    uint32_t genericMethodPointersCount;
    const Il2CppMethodPointer* genericMethodPointers;
    uint32_t invokerPointersCount;
    const InvokerMethod* invokerPointers;
    CustomAttributeIndex customAttributeCount;
    const CustomAttributesCacheGenerator* customAttributeGenerators;
    uint32_t unresolvedVirtualCallCount;
    const Il2CppMethodPointer* unresolvedVirtualCallPointers;
    uint32_t interopDataCount;
    Il2CppInteropData* interopData;
    uint32_t windowsRuntimeFactoryCount;
    Il2CppWindowsRuntimeFactoryTableEntry* windowsRuntimeFactoryTable;
    uint32_t codeGenModulesCount;
    const Il2CppCodeGenModule** codeGenModules;
} Il2CppCodeRegistration;
typedef struct Il2CppMetadataRegistration
{
    int32_t genericClassesCount;
    Il2CppGenericClass* const* genericClasses;
    int32_t genericInstsCount;
    const Il2CppGenericInst* const* genericInsts;
    int32_t genericMethodTableCount;
    const Il2CppGenericMethodFunctionsDefinitions* genericMethodTable;
    int32_t typesCount;
    const Il2CppType* const* types;
    int32_t methodSpecsCount;
    const Il2CppMethodSpec* methodSpecs;
    FieldIndex fieldOffsetsCount;
    const int32_t** fieldOffsets;
    TypeDefinitionIndex typeDefinitionsSizesCount;
    const Il2CppTypeDefinitionSizes** typeDefinitionsSizes;
    const size_t metadataUsagesCount;
    void** const* metadataUsages;
} Il2CppMetadataRegistration;
typedef struct Il2CppPerfCounters
{
    uint32_t jit_methods;
    uint32_t jit_bytes;
    uint32_t jit_time;
    uint32_t jit_failures;
    uint32_t exceptions_thrown;
    uint32_t exceptions_filters;
    uint32_t exceptions_finallys;
    uint32_t exceptions_depth;
    uint32_t aspnet_requests_queued;
    uint32_t aspnet_requests;
    uint32_t gc_collections0;
    uint32_t gc_collections1;
    uint32_t gc_collections2;
    uint32_t gc_promotions0;
    uint32_t gc_promotions1;
    uint32_t gc_promotion_finalizers;
    uint32_t gc_gen0size;
    uint32_t gc_gen1size;
    uint32_t gc_gen2size;
    uint32_t gc_lossize;
    uint32_t gc_fin_survivors;
    uint32_t gc_num_handles;
    uint32_t gc_allocated;
    uint32_t gc_induced;
    uint32_t gc_time;
    uint32_t gc_total_bytes;
    uint32_t gc_committed_bytes;
    uint32_t gc_reserved_bytes;
    uint32_t gc_num_pinned;
    uint32_t gc_sync_blocks;
    uint32_t remoting_calls;
    uint32_t remoting_channels;
    uint32_t remoting_proxies;
    uint32_t remoting_classes;
    uint32_t remoting_objects;
    uint32_t remoting_contexts;
    uint32_t loader_classes;
    uint32_t loader_total_classes;
    uint32_t loader_appdomains;
    uint32_t loader_total_appdomains;
    uint32_t loader_assemblies;
    uint32_t loader_total_assemblies;
    uint32_t loader_failures;
    uint32_t loader_bytes;
    uint32_t loader_appdomains_uloaded;
    uint32_t thread_contentions;
    uint32_t thread_queue_len;
    uint32_t thread_queue_max;
    uint32_t thread_num_logical;
    uint32_t thread_num_physical;
    uint32_t thread_cur_recognized;
    uint32_t thread_num_recognized;
    uint32_t interop_num_ccw;
    uint32_t interop_num_stubs;
    uint32_t interop_num_marshals;
    uint32_t security_num_checks;
    uint32_t security_num_link_checks;
    uint32_t security_time;
    uint32_t security_depth;
    uint32_t unused;
    uint64_t threadpool_workitems;
    uint64_t threadpool_ioworkitems;
    unsigned int threadpool_threads;
    unsigned int threadpool_iothreads;
} Il2CppPerfCounters;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct FieldInfo FieldInfo;
typedef struct EventInfo EventInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppAsyncCall Il2CppAsyncCall;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppWaitHandle Il2CppWaitHandle;
typedef struct MonitorData MonitorData;
typedef struct Il2CppReflectionAssembly Il2CppReflectionAssembly;
typedef Il2CppClass Il2CppVTable;
typedef struct Il2CppObject
{
    union
    {
        Il2CppClass* klass;
        Il2CppVTable* vtable;
    } Il2CppClass;
    MonitorData* monitor;
} Il2CppObject;
typedef int32_t il2cpp_array_lower_bound_t;
typedef struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
} Il2CppArrayBounds;
typedef struct Il2CppArray
{
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
} Il2CppArray;
typedef struct Il2CppArraySize
{
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    __declspec(align(8)) void* vector[32];
} Il2CppArraySize;
typedef struct Il2CppString
{
    Il2CppObject object;
    int32_t length;
    Il2CppChar chars[32];
} Il2CppString;
typedef struct Il2CppReflectionType
{
    Il2CppObject object;
    const Il2CppType* type;
} Il2CppReflectionType;
typedef struct Il2CppReflectionRuntimeType
{
    Il2CppReflectionType type;
    Il2CppObject* type_info;
    Il2CppObject* genericCache;
    Il2CppObject* serializationCtor;
} Il2CppReflectionRuntimeType;
typedef struct Il2CppReflectionMonoType
{
    Il2CppReflectionRuntimeType type;
} Il2CppReflectionMonoType;
typedef struct Il2CppReflectionEvent
{
    Il2CppObject object;
    Il2CppObject* cached_add_event;
} Il2CppReflectionEvent;
typedef struct Il2CppReflectionMonoEvent
{
    Il2CppReflectionEvent event;
    Il2CppReflectionType* reflectedType;
    const EventInfo* eventInfo;
} Il2CppReflectionMonoEvent;
typedef struct Il2CppReflectionMonoEventInfo
{
    Il2CppReflectionType* declaringType;
    Il2CppReflectionType* reflectedType;
    Il2CppString* name;
    Il2CppReflectionMethod* addMethod;
    Il2CppReflectionMethod* removeMethod;
    Il2CppReflectionMethod* raiseMethod;
    uint32_t eventAttributes;
    Il2CppArray* otherMethods;
} Il2CppReflectionMonoEventInfo;
typedef struct Il2CppReflectionField
{
    Il2CppObject object;
    Il2CppClass* klass;
    FieldInfo* field;
    Il2CppString* name;
    Il2CppReflectionType* type;
    uint32_t attrs;
} Il2CppReflectionField;
typedef struct Il2CppReflectionProperty
{
    Il2CppObject object;
    Il2CppClass* klass;
    const PropertyInfo* property;
} Il2CppReflectionProperty;
typedef struct Il2CppReflectionMethod
{
    Il2CppObject object;
    const MethodInfo* method;
    Il2CppString* name;
    Il2CppReflectionType* reftype;
} Il2CppReflectionMethod;
typedef struct Il2CppReflectionGenericMethod
{
    Il2CppReflectionMethod base;
} Il2CppReflectionGenericMethod;
typedef struct Il2CppMethodInfo
{
    Il2CppReflectionType* parent;
    Il2CppReflectionType* ret;
    uint32_t attrs;
    uint32_t implattrs;
    uint32_t callconv;
} Il2CppMethodInfo;
typedef struct Il2CppPropertyInfo
{
    Il2CppReflectionType* parent;
    Il2CppReflectionType* declaringType;
    Il2CppString* name;
    Il2CppReflectionMethod* get;
    Il2CppReflectionMethod* set;
    uint32_t attrs;
} Il2CppPropertyInfo;
typedef struct Il2CppReflectionParameter
{
    Il2CppObject object;
    Il2CppReflectionType* ClassImpl;
    Il2CppObject* DefaultValueImpl;
    Il2CppObject* MemberImpl;
    Il2CppString* NameImpl;
    int32_t PositionImpl;
    uint32_t AttrsImpl;
    Il2CppObject* MarshalAsImpl;
} Il2CppReflectionParameter;
typedef struct Il2CppReflectionModule
{
    Il2CppObject obj;
    const Il2CppImage* image;
    Il2CppReflectionAssembly* assembly;
    Il2CppString* fqname;
    Il2CppString* name;
    Il2CppString* scopename;
    uint8_t is_resource;
    uint32_t token;
} Il2CppReflectionModule;
typedef struct Il2CppReflectionAssemblyName
{
    Il2CppObject obj;
    Il2CppString* name;
    Il2CppString* codebase;
    int32_t major, minor, build, revision;
    Il2CppObject* cultureInfo;
    uint32_t flags;
    uint32_t hashalg;
    Il2CppObject* keypair;
    Il2CppArray* publicKey;
    Il2CppArray* keyToken;
    uint32_t versioncompat;
    Il2CppObject* version;
    uint32_t processor_architecture;
    uint32_t contentType;
} Il2CppReflectionAssemblyName;
typedef struct Il2CppReflectionAssembly
{
    Il2CppObject object;
    const Il2CppAssembly* assembly;
    Il2CppObject* resolve_event_holder;
    Il2CppObject* evidence;
    Il2CppObject* minimum;
    Il2CppObject* optional;
    Il2CppObject* refuse;
    Il2CppObject* granted;
    Il2CppObject* denied;
    uint8_t from_byte_array;
    Il2CppString* name;
} Il2CppReflectionAssembly;
typedef struct Il2CppReflectionMarshal
{
    Il2CppObject object;
    int32_t count;
    int32_t type;
    int32_t eltype;
    Il2CppString* guid;
    Il2CppString* mcookie;
    Il2CppString* marshaltype;
    Il2CppObject* marshaltyperef;
    int32_t param_num;
    uint8_t has_size;
} Il2CppReflectionMarshal;
typedef struct Il2CppReflectionPointer
{
    Il2CppObject object;
    void* data;
    Il2CppReflectionType* type;
} Il2CppReflectionPointer;
typedef struct Il2CppInternalThread
{
    Il2CppObject obj;
    int lock_thread_id;
    void* handle;
    void* native_handle;
    Il2CppArray* cached_culture_info;
    Il2CppChar* name;
    int name_len;
    uint32_t state;
    Il2CppObject* abort_exc;
    int abort_state_handle;
    uint64_t tid;
    intptr_t debugger_thread;
    void** static_data;
    void* runtime_thread_info;
    Il2CppObject* current_appcontext;
    Il2CppObject* root_domain_thread;
    Il2CppArray* _serialized_principal;
    int _serialized_principal_version;
    void* appdomain_refs;
    int32_t interruption_requested;
    void* synch_cs;
    uint8_t threadpool_thread;
    uint8_t thread_interrupt_requested;
    int stack_size;
    uint8_t apartment_state;
    int critical_region_level;
    int managed_id;
    uint32_t small_id;
    void* manage_callback;
    void* interrupt_on_stop;
    intptr_t flags;
    void* thread_pinning_ref;
    void* abort_protected_block_count;
    int32_t priority;
    void* owned_mutexes;
    void* suspended;
    int32_t self_suspended;
    size_t thread_state;
    size_t unused2;
    void* last;
} Il2CppInternalThread;
typedef struct Il2CppIOSelectorJob
{
    Il2CppObject object;
    int32_t operation;
    Il2CppObject* callback;
    Il2CppObject* state;
} Il2CppIOSelectorJob;
typedef enum
{
    Il2Cpp_CallType_Sync = 0,
    Il2Cpp_CallType_BeginInvoke = 1,
    Il2Cpp_CallType_EndInvoke = 2,
    Il2Cpp_CallType_OneWay = 3
} Il2CppCallType;
typedef struct Il2CppMethodMessage
{
    Il2CppObject obj;
    Il2CppReflectionMethod* method;
    Il2CppArray* args;
    Il2CppArray* names;
    Il2CppArray* arg_types;
    Il2CppObject* ctx;
    Il2CppObject* rval;
    Il2CppObject* exc;
    Il2CppAsyncResult* async_result;
    uint32_t call_type;
} Il2CppMethodMessage;
typedef struct Il2CppAppDomainSetup
{
    Il2CppObject object;
    Il2CppString* application_base;
    Il2CppString* application_name;
    Il2CppString* cache_path;
    Il2CppString* configuration_file;
    Il2CppString* dynamic_base;
    Il2CppString* license_file;
    Il2CppString* private_bin_path;
    Il2CppString* private_bin_path_probe;
    Il2CppString* shadow_copy_directories;
    Il2CppString* shadow_copy_files;
    uint8_t publisher_policy;
    uint8_t path_changed;
    int loader_optimization;
    uint8_t disallow_binding_redirects;
    uint8_t disallow_code_downloads;
    Il2CppObject* activation_arguments;
    Il2CppObject* domain_initializer;
    Il2CppObject* application_trust;
    Il2CppArray* domain_initializer_args;
    uint8_t disallow_appbase_probe;
    Il2CppArray* configuration_bytes;
    Il2CppArray* serialized_non_primitives;
} Il2CppAppDomainSetup;
typedef struct Il2CppThread
{
    Il2CppObject obj;
    Il2CppInternalThread* internal_thread;
    Il2CppObject* start_obj;
    Il2CppException* pending_exception;
    Il2CppObject* principal;
    int32_t principal_version;
    Il2CppDelegate* delegate;
    Il2CppObject* executionContext;
    uint8_t executionContextBelongsToOuterScope;
} Il2CppThread;
typedef struct Il2CppException
{
    Il2CppObject object;
    Il2CppString* className;
    Il2CppString* message;
    Il2CppObject* _data;
    Il2CppException* inner_ex;
    Il2CppString* _helpURL;
    Il2CppArray* trace_ips;
    Il2CppString* stack_trace;
    Il2CppString* remote_stack_trace;
    int remote_stack_index;
    Il2CppObject* _dynamicMethods;
    il2cpp_hresult_t hresult;
    Il2CppString* source;
    Il2CppObject* safeSerializationManager;
    Il2CppArray* captured_traces;
    Il2CppArray* native_trace_ips;
} Il2CppException;
typedef struct Il2CppSystemException
{
    Il2CppException base;
} Il2CppSystemException;
typedef struct Il2CppArgumentException
{
    Il2CppException base;
    Il2CppString* argName;
} Il2CppArgumentException;
typedef struct Il2CppTypedRef
{
    const Il2CppType* type;
    void* value;
    Il2CppClass* klass;
} Il2CppTypedRef;
typedef struct Il2CppDelegate
{
    Il2CppObject object;
    Il2CppMethodPointer method_ptr;
    InvokerMethod invoke_impl;
    Il2CppObject* target;
    const MethodInfo* method;
    void* delegate_trampoline;
    intptr_t extraArg;
    uint8_t** method_code;
    Il2CppReflectionMethod* method_info;
    Il2CppReflectionMethod* original_method_info;
    Il2CppObject* data;
    uint8_t method_is_virtual;
} Il2CppDelegate;
typedef struct Il2CppMulticastDelegate
{
    Il2CppDelegate delegate;
    Il2CppArray* delegates;
} Il2CppMulticastDelegate;
typedef struct Il2CppMarshalByRefObject
{
    Il2CppObject obj;
    Il2CppObject* identity;
} Il2CppMarshalByRefObject;
typedef struct Il2CppAppDomain
{
    Il2CppMarshalByRefObject mbr;
    Il2CppDomain* data;
} Il2CppAppDomain;
typedef struct Il2CppStackFrame
{
    Il2CppObject obj;
    int32_t il_offset;
    int32_t native_offset;
    uint64_t methodAddress;
    uint32_t methodIndex;
    Il2CppReflectionMethod* method;
    Il2CppString* filename;
    int32_t line;
    int32_t column;
    Il2CppString* internal_method_name;
} Il2CppStackFrame;
typedef struct Il2CppDateTimeFormatInfo
{
    Il2CppObject obj;
    Il2CppObject* CultureData;
    Il2CppString* Name;
    Il2CppString* LangName;
    Il2CppObject* CompareInfo;
    Il2CppObject* CultureInfo;
    Il2CppString* AMDesignator;
    Il2CppString* PMDesignator;
    Il2CppString* DateSeparator;
    Il2CppString* GeneralShortTimePattern;
    Il2CppString* GeneralLongTimePattern;
    Il2CppString* TimeSeparator;
    Il2CppString* MonthDayPattern;
    Il2CppString* DateTimeOffsetPattern;
    Il2CppObject* Calendar;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
    Il2CppString* FullDateTimePattern;
    Il2CppArray* AbbreviatedDayNames;
    Il2CppArray* ShortDayNames;
    Il2CppArray* DayNames;
    Il2CppArray* AbbreviatedMonthNames;
    Il2CppArray* MonthNames;
    Il2CppArray* GenitiveMonthNames;
    Il2CppArray* GenitiveAbbreviatedMonthNames;
    Il2CppArray* LeapYearMonthNames;
    Il2CppString* LongDatePattern;
    Il2CppString* ShortDatePattern;
    Il2CppString* YearMonthPattern;
    Il2CppString* LongTimePattern;
    Il2CppString* ShortTimePattern;
    Il2CppArray* YearMonthPatterns;
    Il2CppArray* ShortDatePatterns;
    Il2CppArray* LongDatePatterns;
    Il2CppArray* ShortTimePatterns;
    Il2CppArray* LongTimePatterns;
    Il2CppArray* EraNames;
    Il2CppArray* AbbrevEraNames;
    Il2CppArray* AbbrevEnglishEraNames;
    Il2CppArray* OptionalCalendars;
    uint8_t readOnly;
    int32_t FormatFlags;
    int32_t CultureID;
    uint8_t UseUserOverride;
    uint8_t UseCalendarInfo;
    int32_t DataItem;
    uint8_t IsDefaultCalendar;
    Il2CppArray* DateWords;
    Il2CppString* FullTimeSpanPositivePattern;
    Il2CppString* FullTimeSpanNegativePattern;
    Il2CppArray* dtfiTokenHash;
} Il2CppDateTimeFormatInfo;
typedef struct Il2CppNumberFormatInfo
{
    Il2CppObject obj;
    Il2CppArray* numberGroupSizes;
    Il2CppArray* currencyGroupSizes;
    Il2CppArray* percentGroupSizes;
    Il2CppString* positiveSign;
    Il2CppString* negativeSign;
    Il2CppString* numberDecimalSeparator;
    Il2CppString* numberGroupSeparator;
    Il2CppString* currencyGroupSeparator;
    Il2CppString* currencyDecimalSeparator;
    Il2CppString* currencySymbol;
    Il2CppString* ansiCurrencySymbol;
    Il2CppString* naNSymbol;
    Il2CppString* positiveInfinitySymbol;
    Il2CppString* negativeInfinitySymbol;
    Il2CppString* percentDecimalSeparator;
    Il2CppString* percentGroupSeparator;
    Il2CppString* percentSymbol;
    Il2CppString* perMilleSymbol;
    Il2CppArray* nativeDigits;
    int dataItem;
    int numberDecimalDigits;
    int currencyDecimalDigits;
    int currencyPositivePattern;
    int currencyNegativePattern;
    int numberNegativePattern;
    int percentPositivePattern;
    int percentNegativePattern;
    int percentDecimalDigits;
    int digitSubstitution;
    uint8_t readOnly;
    uint8_t useUserOverride;
    uint8_t isInvariant;
    uint8_t validForParseAsNumber;
    uint8_t validForParseAsCurrency;
} Il2CppNumberFormatInfo;
typedef struct Il2CppCultureData
{
    Il2CppObject obj;
    Il2CppString* AMDesignator;
    Il2CppString* PMDesignator;
    Il2CppString* TimeSeparator;
    Il2CppArray* LongTimePatterns;
    Il2CppArray* ShortTimePatterns;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
} Il2CppCultureData;
typedef struct Il2CppCalendarData
{
    Il2CppObject obj;
    Il2CppString* NativeName;
    Il2CppArray* ShortDatePatterns;
    Il2CppArray* YearMonthPatterns;
    Il2CppArray* LongDatePatterns;
    Il2CppString* MonthDayPattern;
    Il2CppArray* EraNames;
    Il2CppArray* AbbreviatedEraNames;
    Il2CppArray* AbbreviatedEnglishEraNames;
    Il2CppArray* DayNames;
    Il2CppArray* AbbreviatedDayNames;
    Il2CppArray* SuperShortDayNames;
    Il2CppArray* MonthNames;
    Il2CppArray* AbbreviatedMonthNames;
    Il2CppArray* GenitiveMonthNames;
    Il2CppArray* GenitiveAbbreviatedMonthNames;
} Il2CppCalendarData;
typedef struct Il2CppCultureInfo
{
    Il2CppObject obj;
    uint8_t is_read_only;
    int32_t lcid;
    int32_t parent_lcid;
    int32_t datetime_index;
    int32_t number_index;
    int32_t default_calendar_type;
    uint8_t use_user_override;
    Il2CppNumberFormatInfo* number_format;
    Il2CppDateTimeFormatInfo* datetime_format;
    Il2CppObject* textinfo;
    Il2CppString* name;
    Il2CppString* englishname;
    Il2CppString* nativename;
    Il2CppString* iso3lang;
    Il2CppString* iso2lang;
    Il2CppString* win3lang;
    Il2CppString* territory;
    Il2CppArray* native_calendar_names;
    Il2CppString* compareinfo;
    const void* text_info_data;
    int dataItem;
    Il2CppObject* calendar;
    Il2CppObject* parent_culture;
    uint8_t constructed;
    Il2CppArray* cached_serialized_form;
    Il2CppObject* cultureData;
    uint8_t isInherited;
} Il2CppCultureInfo;
typedef struct Il2CppRegionInfo
{
    Il2CppObject obj;
    int32_t geo_id;
    Il2CppString* iso2name;
    Il2CppString* iso3name;
    Il2CppString* win3name;
    Il2CppString* english_name;
    Il2CppString* native_name;
    Il2CppString* currency_symbol;
    Il2CppString* iso_currency_symbol;
    Il2CppString* currency_english_name;
    Il2CppString* currency_native_name;
} Il2CppRegionInfo;
typedef struct Il2CppSafeHandle
{
    Il2CppObject base;
    void* handle;
    int state;
    uint8_t owns_handle;
    uint8_t fullyInitialized;
} Il2CppSafeHandle;
typedef struct Il2CppStringBuilder Il2CppStringBuilder;
typedef struct Il2CppStringBuilder
{
    Il2CppObject object;
    Il2CppArray* chunkChars;
    Il2CppStringBuilder* chunkPrevious;
    int chunkLength;
    int chunkOffset;
    int maxCapacity;
} Il2CppStringBuilder;
typedef struct Il2CppSocketAddress
{
    Il2CppObject base;
    int m_Size;
    Il2CppArray* data;
    uint8_t m_changed;
    int m_hash;
} Il2CppSocketAddress;
typedef struct Il2CppSortKey
{
    Il2CppObject base;
    Il2CppString* str;
    Il2CppArray* key;
    int32_t options;
    int32_t lcid;
} Il2CppSortKey;
typedef struct Il2CppErrorWrapper
{
    Il2CppObject base;
    int32_t errorCode;
} Il2CppErrorWrapper;
typedef struct Il2CppAsyncResult
{
    Il2CppObject base;
    Il2CppObject* async_state;
    Il2CppWaitHandle* handle;
    Il2CppDelegate* async_delegate;
    void* data;
    Il2CppAsyncCall* object_data;
    uint8_t sync_completed;
    uint8_t completed;
    uint8_t endinvoke_called;
    Il2CppObject* async_callback;
    Il2CppObject* execution_context;
    Il2CppObject* original_context;
} Il2CppAsyncResult;
typedef struct Il2CppAsyncCall
{
    Il2CppObject base;
    Il2CppMethodMessage* msg;
    MethodInfo* cb_method;
    Il2CppDelegate* cb_target;
    Il2CppObject* state;
    Il2CppObject* res;
    Il2CppArray* out_args;
} Il2CppAsyncCall;
typedef struct Il2CppExceptionWrapper Il2CppExceptionWrapper;
typedef struct Il2CppExceptionWrapper
{
    Il2CppException* ex;
} Il2CppExceptionWrapper;
typedef struct Il2CppIOAsyncResult
{
    Il2CppObject base;
    Il2CppDelegate* callback;
    Il2CppObject* state;
    Il2CppWaitHandle* wait_handle;
    uint8_t completed_synchronously;
    uint8_t completed;
} Il2CppIOAsyncResult;
typedef struct Il2CppSocketAsyncResult
{
    Il2CppIOAsyncResult base;
    Il2CppObject* socket;
    int32_t operation;
    Il2CppException* delayedException;
    Il2CppObject* endPoint;
    Il2CppArray* buffer;
    int32_t offset;
    int32_t size;
    int32_t socket_flags;
    Il2CppObject* acceptSocket;
    Il2CppArray* addresses;
    int32_t port;
    Il2CppObject* buffers;
    uint8_t reuseSocket;
    int32_t currentAddress;
    Il2CppObject* acceptedSocket;
    int32_t total;
    int32_t error;
    int32_t endCalled;
} Il2CppSocketAsyncResult;
typedef enum Il2CppResourceLocation
{
    IL2CPP_RESOURCE_LOCATION_EMBEDDED = 1,
    IL2CPP_RESOURCE_LOCATION_ANOTHER_ASSEMBLY = 2,
    IL2CPP_RESOURCE_LOCATION_IN_MANIFEST = 4
} Il2CppResourceLocation;
typedef struct Il2CppManifestResourceInfo
{
    Il2CppObject object;
    Il2CppReflectionAssembly* assembly;
    Il2CppString* filename;
    uint32_t location;
} Il2CppManifestResourceInfo;
typedef struct Il2CppAppContext
{
    Il2CppObject obj;
    int32_t domain_id;
    int32_t context_id;
    void* static_data;
} Il2CppAppContext;
typedef struct Il2CppDecimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } u;
        uint16_t signscale;
    } u;
    uint32_t Hi32;
    union
    {
        struct
        {
            uint32_t Lo32;
            uint32_t Mid32;
        } v;
        uint64_t Lo64;
    } v;
} Il2CppDecimal;
typedef struct Il2CppDouble
{
    uint32_t mantLo : 32;
    uint32_t mantHi : 20;
    uint32_t exp : 11;
    uint32_t sign : 1;
} Il2CppDouble;
typedef union Il2CppDouble_double
{
    Il2CppDouble s;
    double d;
} Il2CppDouble_double;
typedef enum Il2CppDecimalCompareResult
{
    IL2CPP_DECIMAL_CMP_LT = -1,
    IL2CPP_DECIMAL_CMP_EQ,
    IL2CPP_DECIMAL_CMP_GT
} Il2CppDecimalCompareResult;
typedef struct Il2CppSingle
{
    uint32_t mant : 23;
    uint32_t exp : 8;
    uint32_t sign : 1;
} Il2CppSingle;
typedef union Il2CppSingle_float
{
    Il2CppSingle s;
    float f;
} Il2CppSingle_float;

enum class World_BlockType__Enum : int32_t {
    None = 0x00000000,
    SoilBlock = 0x00000001,
    CaveWall = 0x00000002,
    Bedrock = 0x00000003,
    Granite = 0x00000004,
    Sand = 0x00000005,
    SandStone = 0x00000006,
    Lava = 0x00000007,
    Marble = 0x00000008,
    Obsidian = 0x00000009,
    Grass = 0x0000000a,
    Rose = 0x0000000b,
    Sunflower = 0x0000000c,
    Lily = 0x0000000d,
    Blueberry = 0x0000000e,
    MetalPlate = 0x0000000f,
    WoodenPlatform = 0x00000010,
    Ice = 0x00000011,
    Water = 0x00000012,
    GreyBrick = 0x00000013,
    RedBrick = 0x00000014,
    YellowBrick = 0x00000015,
    WhiteBrick = 0x00000016,
    BlackBrick = 0x00000017,
    WoodWall = 0x00000018,
    WoodBlock = 0x00000019,
    WoodenBackground = 0x0000001a,
    JungleGrass = 0x0000001b,
    MetalPlatform = 0x0000001c,
    Microwave = 0x0000001d,
    WoodenTable = 0x0000001e,
    Brazier = 0x0000001f,
    WindowFrame = 0x00000020,
    GreenJello = 0x00000021,
    YellowJello = 0x00000022,
    BlueJello = 0x00000023,
    RedJello = 0x00000024,
    Tree = 0x00000025,
    BasicFace = 0x00000026,
    BasicEyebrows = 0x00000027,
    BasicEyeballs = 0x00000028,
    BasicPupil = 0x00000029,
    BasicMouth = 0x0000002a,
    BasicLegs = 0x0000002b,
    BasicTorso = 0x0000002c,
    BasicTopArm = 0x0000002d,
    BasicBottomArm = 0x0000002e,
    BasicEyelashes = 0x0000002f,
    PantsBatman = 0x00000030,
    ShoesBatman = 0x00000031,
    WeaponClaymore = 0x00000032,
    WeaponExecutionerAxe = 0x00000033,
    WeaponKatana = 0x00000034,
    WeaponPickAxe = 0x00000035,
    WeaponPitchFork = 0x00000036,
    WeaponShortSword = 0x00000037,
    WeaponSpartanSword = 0x00000038,
    WeaponWalkingCane = 0x00000039,
    WeaponGunBeretta = 0x0000003a,
    SandyCaveWall = 0x0000003b,
    LunarSoil = 0x0000003c,
    MoonRock = 0x0000003d,
    MoonBackground = 0x0000003e,
    MartianSoil = 0x0000003f,
    MartianRock = 0x00000040,
    MartianBackground = 0x00000041,
    MagicStuff = 0x00000042,
    QuickSand = 0x00000043,
    RedWallpaper = 0x00000044,
    RedBlock = 0x00000045,
    YellowBlock = 0x00000046,
    BlueBlock = 0x00000047,
    WhiteBlock = 0x00000048,
    BlackBlock = 0x00000049,
    Sign = 0x0000004a,
    Mushroom = 0x0000004b,
    Door = 0x0000004c,
    StoneBackground = 0x0000004d,
    WoodPanel = 0x0000004e,
    LavaLamp = 0x0000004f,
    SmallChest = 0x00000050,
    GreenBlock = 0x00000051,
    PurpleBlock = 0x00000052,
    OrangeBlock = 0x00000053,
    LightBlueBlock = 0x00000054,
    GreyBlock = 0x00000055,
    PinkBlock = 0x00000056,
    FlowerWallpaper = 0x00000057,
    WoodenChair = 0x00000058,
    Pineapple = 0x00000059,
    Corn = 0x0000005a,
    Lantern = 0x0000005b,
    ClassicPainting = 0x0000005c,
    RubberDuck = 0x0000005d,
    IronBlock = 0x0000005e,
    ClearJello = 0x0000005f,
    Fireplace = 0x00000060,
    ClayPot = 0x00000061,
    Armchair = 0x00000062,
    GlassDoor = 0x00000063,
    FloorLamp = 0x00000064,
    FruitTray = 0x00000065,
    BrownBlock = 0x00000066,
    Strawberry = 0x00000067,
    Shoji = 0x00000068,
    GardenGnome = 0x00000069,
    Oven = 0x0000006a,
    Cabinet = 0x0000006b,
    OldTV = 0x0000006c,
    SpikeTrap = 0x0000006d,
    EntrancePortal = 0x0000006e,
    FireTrap = 0x0000006f,
    LEDSign = 0x00000070,
    DungeonWall = 0x00000071,
    DungeonDoor = 0x00000072,
    RedBrickWallpaper = 0x00000073,
    BrownBrickWallpaper = 0x00000074,
    YellowBrickWallpaper = 0x00000075,
    ClownWallpaper = 0x00000076,
    IllusorySoilBlock = 0x00000077,
    HugeMetalFan = 0x00000078,
    Shrubbery = 0x00000079,
    Tapestry = 0x0000007a,
    CastleWallpaper = 0x0000007b,
    CastleWall = 0x0000007c,
    CastleDoor = 0x0000007d,
    IronChandelier = 0x0000007e,
    Throne = 0x0000007f,
    GreekColumn = 0x00000080,
    Fountain = 0x00000081,
    Torch = 0x00000082,
    TileWhite = 0x00000083,
    Stereos = 0x00000084,
    ExtraSpeaker = 0x00000085,
    HotTub = 0x00000086,
    Safe = 0x00000087,
    ATM = 0x00000088,
    CubistPainting = 0x00000089,
    ModernPainting = 0x0000008a,
    ImperialWallpaper = 0x0000008b,
    GoldenToilet = 0x0000008c,
    ModernSculpture = 0x0000008d,
    GoldBlock = 0x0000008e,
    BlackLeatherChair = 0x0000008f,
    SellOMat = 0x00000090,
    LightBlueWallpaper = 0x00000091,
    Hummer = 0x00000092,
    Sandbag = 0x00000093,
    ArmyTent = 0x00000094,
    PlywoodWallpaper = 0x00000095,
    BarbedWire = 0x00000096,
    Tracktor = 0x00000097,
    Wheat = 0x00000098,
    Scarecrow = 0x00000099,
    BarnWall = 0x0000009a,
    BarnDoor = 0x0000009b,
    PicketFence = 0x0000009c,
    Hayblock = 0x0000009d,
    ShirtBatman = 0x0000009e,
    MaskBatman = 0x0000009f,
    CapeBatman = 0x000000a0,
    PantsSweat = 0x000000a1,
    ShoesBrown = 0x000000a2,
    ShoesRubberBootsYellow = 0x000000a3,
    GlassesBasic = 0x000000a4,
    GlassesNerdy = 0x000000a5,
    GlassesRed = 0x000000a6,
    GlassesWhite = 0x000000a7,
    GlassesSunBasic = 0x000000a8,
    BeardBasic = 0x000000a9,
    BeardGoatee = 0x000000aa,
    BeardLong = 0x000000ab,
    BeardBlack = 0x000000ac,
    HatAcademic = 0x000000ad,
    HatCapBlue = 0x000000ae,
    HatCapGreen = 0x000000af,
    HatCapPink = 0x000000b0,
    HatCapRed = 0x000000b1,
    HatCapWhite = 0x000000b2,
    MaskExecutioner = 0x000000b3,
    HatFireFighter = 0x000000b4,
    HatGolfBeret = 0x000000b5,
    MaskMedievalKnight = 0x000000b6,
    HatNavy = 0x000000b7,
    HatNurse = 0x000000b8,
    MaskPaperBagBrown = 0x000000b9,
    HatPolice = 0x000000ba,
    MaskSkimask = 0x000000bb,
    HatSombrero = 0x000000bc,
    HatStetson = 0x000000bd,
    HatStrawHat = 0x000000be,
    HatTennisHeadband = 0x000000bf,
    HatTopHat = 0x000000c0,
    HatWoolcapGreen = 0x000000c1,
    HairBeadedBlack = 0x000000c2,
    HairBradedBlack = 0x000000c3,
    HairLongBlonde = 0x000000c4,
    HairLongBrown = 0x000000c5,
    HairLongGolden = 0x000000c6,
    HairLongPink = 0x000000c7,
    HairLongCurlyBrown = 0x000000c8,
    HairPigtailRed = 0x000000c9,
    HairPunkBlue = 0x000000ca,
    HairAfroDark = 0x000000cb,
    HairArchyGrey = 0x000000cc,
    HairBuzzCutBrown = 0x000000cd,
    HairCasualBrown = 0x000000ce,
    HairClownRed = 0x000000cf,
    HairPonytailBrown = 0x000000d0,
    HairSideyBlack = 0x000000d1,
    HairSpikyBlack = 0x000000d2,
    HairSpikyBrown = 0x000000d3,
    ShirtTBlack = 0x000000d4,
    ShirtTSkullRed = 0x000000d5,
    CapeSparta = 0x000000d6,
    WingsDemon = 0x000000d7,
    WeaponGunRevolver = 0x000000d8,
    WeaponGunAK47 = 0x000000d9,
    Chicken = 0x000000da,
    Cow = 0x000000db,
    Sheep = 0x000000dc,
    ScifiPanel1 = 0x000000dd,
    ScifiPanel2 = 0x000000de,
    ScifiPanel3 = 0x000000df,
    ScifiBackground1 = 0x000000e0,
    ScifiBackground2 = 0x000000e1,
    ScifiLights = 0x000000e2,
    ScifiDoor = 0x000000e3,
    ScifiGenerator = 0x000000e4,
    ScifiCrate = 0x000000e5,
    ScifiTable = 0x000000e6,
    HauntedMirror = 0x000000e7,
    Chains = 0x000000e8,
    CandleStand = 0x000000e9,
    Gravestone = 0x000000ea,
    SlimeBackground = 0x000000eb,
    Diploma = 0x000000ec,
    WireFence = 0x000000ed,
    WoodenBarrel = 0x000000ee,
    MetalBarrel = 0x000000ef,
    WindowFrameWooden = 0x000000f0,
    YardLamp = 0x000000f1,
    Bookshelf = 0x000000f2,
    GreyBrickWallpaper = 0x000000f3,
    RustyPlate = 0x000000f4,
    JunkBackground = 0x000000f5,
    FireBarrel = 0x000000f6,
    JunkBlock = 0x000000f7,
    WastelandWall = 0x000000f8,
    BulletRiddledWall = 0x000000f9,
    RustyBackground = 0x000000fa,
    DeadTree = 0x000000fb,
    RadioactiveBarrel = 0x000000fc,
    UraniumBlock = 0x000000fd,
    WindowFrameBroken = 0x000000fe,
    DottedPinkBlock = 0x000000ff,
    SheetMetalBlack = 0x00000100,
    SheetMetalDirty = 0x00000101,
    FishBowl = 0x00000102,
    PurpleJello = 0x00000103,
    CircuitBoard = 0x00000104,
    StarryWallpaper = 0x00000105,
    ManekiNekoR = 0x00000106,
    Bed = 0x00000107,
    BookPodium = 0x00000108,
    Gargoyle = 0x00000109,
    Fridge = 0x0000010a,
    Coffin = 0x0000010b,
    WindowFrameTinted = 0x0000010c,
    WallpaperTorn = 0x0000010d,
    WoodenBackgroundLight = 0x0000010e,
    NoteBoard = 0x0000010f,
    GlassDoorTinted = 0x00000110,
    Dice = 0x00000111,
    Gramophone = 0x00000112,
    GlassCabinet = 0x00000113,
    BarStool = 0x00000114,
    HelloBot = 0x00000115,
    WatermelonBlock = 0x00000116,
    ArrowSign = 0x00000117,
    StopSign = 0x00000118,
    PlayNoteA = 0x00000119,
    PlayNoteASharp = 0x0000011a,
    PlayNoteB = 0x0000011b,
    PlayNoteC = 0x0000011c,
    PlayNoteCSharp = 0x0000011d,
    PlayNoteD = 0x0000011e,
    PlayNoteDSharp = 0x0000011f,
    PlayNoteE = 0x00000120,
    PlayNoteF = 0x00000121,
    PlayNoteFSharp = 0x00000122,
    PlayNoteG = 0x00000123,
    PlayNoteGSharp = 0x00000124,
    RatingBoard = 0x00000125,
    MagicCauldron = 0x00000126,
    VortexPortal = 0x00000127,
    GlassBlock = 0x00000128,
    Fishtank = 0x00000129,
    FlatScreenTV = 0x0000012a,
    WaterBed = 0x0000012b,
    IronFence = 0x0000012c,
    CactusBlock = 0x0000012d,
    PottedPlant = 0x0000012e,
    SkullBlock = 0x0000012f,
    DiscoBall = 0x00000130,
    AmateurRadio = 0x00000131,
    DeskTopPC = 0x00000132,
    MetalChairYellow = 0x00000133,
    MetalChairBlue = 0x00000134,
    MetalChairRed = 0x00000135,
    MetalChairPink = 0x00000136,
    MetalChairGreen = 0x00000137,
    TVChair = 0x00000138,
    Sargophagus = 0x00000139,
    TrashCan = 0x0000013a,
    HeartDecoration = 0x0000013b,
    OpenSign = 0x0000013c,
    DecorativeSword = 0x0000013d,
    MarbleFireplace = 0x0000013e,
    Bat = 0x0000013f,
    Bathtub = 0x00000140,
    ParrotCage = 0x00000141,
    StainedGlassWindow = 0x00000142,
    Mailbox = 0x00000143,
    FireHydrant = 0x00000144,
    SwingChair = 0x00000145,
    MirrorWardrobe = 0x00000146,
    SuitOfArmor = 0x00000147,
    SteelBlock = 0x00000148,
    Portal = 0x00000149,
    CeilingLampWhite = 0x0000014a,
    Fungi = 0x0000014b,
    CatDecoration = 0x0000014c,
    WallpaperWhiteStriped = 0x0000014d,
    CoatRack = 0x0000014e,
    DiscoBlock = 0x0000014f,
    Whiteboard = 0x00000150,
    MammothIceBlock = 0x00000151,
    PosterHeavyMetal = 0x00000152,
    MakeupTable = 0x00000153,
    MetalTableRound = 0x00000154,
    Wardrobe = 0x00000155,
    CoatRackSheriff = 0x00000156,
    EndLavaRock = 0x00000157,
    EndLava = 0x00000158,
    TightsRed = 0x00000159,
    TailTiger = 0x0000015a,
    ShirtFlash = 0x0000015b,
    ShirtHeart = 0x0000015c,
    PantsCamo = 0x0000015d,
    HatWolf = 0x0000015e,
    DressPink = 0x0000015f,
    ShoesLightBlue = 0x00000160,
    ShoesLoafers = 0x00000161,
    CoatLong = 0x00000162,
    PantsSaggy = 0x00000163,
    ShoesUggBoots = 0x00000164,
    DressWhite = 0x00000165,
    ShirtSweaterWhite = 0x00000166,
    JacketBlack = 0x00000167,
    ShoesGroxsYellow = 0x00000168,
    ShirtJerseyPurple = 0x00000169,
    ShoesFootwraps = 0x0000016a,
    HatFedoraGreen = 0x0000016b,
    PantsLeatherBlack = 0x0000016c,
    PantsShortsJean = 0x0000016d,
    PantsJeansGreen = 0x0000016e,
    GlovesWhite = 0x0000016f,
    HatFedoraRed = 0x00000170,
    CoatRain = 0x00000171,
    SuitOnepiece = 0x00000172,
    HatHardHat = 0x00000173,
    ShirtSoccer = 0x00000174,
    ShirtAdventurer = 0x00000175,
    PantsAdventurer = 0x00000176,
    ShoesAdventurer = 0x00000177,
    PantsSoccer = 0x00000178,
    NoseClown = 0x00000179,
    PantsCargo = 0x0000017a,
    PantsJeansRed = 0x0000017b,
    ShoesOnepiece = 0x0000017c,
    ShoesSneakersRed = 0x0000017d,
    EarPointy = 0x0000017e,
    HeadphonesBlack = 0x0000017f,
    HairBlue = 0x00000180,
    HairLongBlack = 0x00000181,
    HatAdventurer = 0x00000182,
    BeardMoustache = 0x00000183,
    MaskCarneval = 0x00000184,
    MaskDevil = 0x00000185,
    GlassesMirrorShades = 0x00000186,
    GlassesSkiGogglesWhite = 0x00000187,
    SuitToga = 0x00000188,
    HatFedoraBlack = 0x00000189,
    HatHeadScarfLightBlueHead = 0x0000018a,
    MaskMime = 0x0000018b,
    HatGlassHelmet = 0x0000018c,
    GloveMittensPink = 0x0000018d,
    SuitScifi = 0x0000018e,
    ShirtJerseyGreen = 0x0000018f,
    ShirtTSkullBlack = 0x00000190,
    HairPunkGreen = 0x00000191,
    DressLongBlue = 0x00000192,
    TightsWhite = 0x00000193,
    SuitClown = 0x00000194,
    ShirtDressWhite = 0x00000195,
    ShirtBlouseRed = 0x00000196,
    ShoesBallerinaWhite = 0x00000197,
    SkirtGreen = 0x00000198,
    SkirtRed = 0x00000199,
    LockSmall = 0x0000019a,
    LockMedium = 0x0000019b,
    LockLarge = 0x0000019c,
    LockWorld = 0x0000019d,
    LockGold = 0x0000019e,
    LockDiamond = 0x0000019f,
    LockClan = 0x000001a0,
    HatCapWoolWhite = 0x000001a1,
    WorldKey = 0x000001a2,
    CheckPoint = 0x000001a3,
    BonusBox1 = 0x000001a4,
    BonusBox2 = 0x000001a5,
    BonusBox3 = 0x000001a6,
    BonusBoxVIP1 = 0x000001a7,
    PennantBlack = 0x000001a8,
    SnowBlock = 0x000001a9,
    IceBackground = 0x000001aa,
    ShoesBallerinaRed = 0x000001ab,
    ShoesBallerinaBlack = 0x000001ac,
    JacketSuede = 0x000001ad,
    DressSkaterYellow = 0x000001ae,
    PantsJeansGanstaBaggy = 0x000001af,
    ShoesBasketballGansta = 0x000001b0,
    ShirtJerseyGanstaRed = 0x000001b1,
    NeckChainGanstaGold = 0x000001b2,
    SkirtFarmDenim = 0x000001b3,
    SuitFarmOveralls = 0x000001b4,
    ShirtFarmPlaidRed = 0x000001b5,
    WeaponSickleFarm = 0x000001b6,
    WeaponMicrophoneGansta = 0x000001b7,
    GlovesRingGanstaBlin = 0x000001b8,
    PantsLeatherMedievalBrown = 0x000001b9,
    TunicMedievalExecutioners = 0x000001ba,
    TunicMedievalLords = 0x000001bb,
    ShirtMedievalPeasantRags = 0x000001bc,
    ShirtMedievalRingMail = 0x000001bd,
    CapeMedievalLords = 0x000001be,
    GlovesMittensWoolWhite = 0x000001bf,
    ShirtWoolWhite = 0x000001c0,
    GloveClown = 0x000001c1,
    ShoesClown = 0x000001c2,
    PantsMedievalLords = 0x000001c3,
    BonusArrowSign = 0x000001c4,
    Buzzsaw = 0x000001c5,
    BonusBlackBackground = 0x000001c6,
    BonusBlackBlock = 0x000001c7,
    BonusBlackBlockHole = 0x000001c8,
    BonusBlackPillar = 0x000001c9,
    BonusBoxVIP2 = 0x000001ca,
    BonusBoxVIP3 = 0x000001cb,
    BonusConcreteBackground = 0x000001cc,
    BonusConcreteGrey = 0x000001cd,
    BonusCushionBackground1 = 0x000001ce,
    BonusCushionBackground2 = 0x000001cf,
    BonusDarksBackground = 0x000001d0,
    BonusFenceLeft = 0x000001d1,
    BonusFenceMiddle = 0x000001d2,
    BonusFenceRight = 0x000001d3,
    BonusGrandPrize = 0x000001d4,
    BonusLightbarsBackground = 0x000001d5,
    BonusLightCeiling = 0x000001d6,
    BonusLightWall = 0x000001d7,
    BonusNumber1 = 0x000001d8,
    BonusNumber2 = 0x000001d9,
    BonusNumber3 = 0x000001da,
    BonusNumber4 = 0x000001db,
    BonusNumber5 = 0x000001dc,
    BonusRailing = 0x000001dd,
    BonusRedBackground1 = 0x000001de,
    BonusRedBackground2 = 0x000001df,
    BonusShinyBlock = 0x000001e0,
    BonusSign = 0x000001e1,
    BonusStarsBackground = 0x000001e2,
    BonusVioletBlock = 0x000001e3,
    BonusBlueBackground1 = 0x000001e4,
    BonusBlueBackground2 = 0x000001e5,
    BonusVioletBackground1 = 0x000001e6,
    BonusVioletBackground2 = 0x000001e7,
    BonusOrangeBackground1 = 0x000001e8,
    BonusOrangeBackground2 = 0x000001e9,
    BonusBlueDotBlock = 0x000001ea,
    BonusVioletDotBlock = 0x000001eb,
    BonusPlatform = 0x000001ec,
    Egg = 0x000001ed,
    Milk = 0x000001ee,
    TileRed = 0x000001ef,
    TileOrange = 0x000001f0,
    TileYellow = 0x000001f1,
    TilePink = 0x000001f2,
    TileBlue = 0x000001f3,
    TileGreen = 0x000001f4,
    TileGlass = 0x000001f5,
    ArmChairLeopard = 0x000001f6,
    CountryBlockBrazil = 0x000001f7,
    CountryBlockDenmark = 0x000001f8,
    CountryBlockFinland = 0x000001f9,
    CountryBlockFrance = 0x000001fa,
    CountryBlockGermany = 0x000001fb,
    CountryBlockItaly = 0x000001fc,
    CountryBlockNorway = 0x000001fd,
    CountryBlockRussia = 0x000001fe,
    CountryBlockSpain = 0x000001ff,
    CountryBlockSweden = 0x00000200,
    CountryBlockUK = 0x00000201,
    ClassicSculpture = 0x00000202,
    JumpsuitMale = 0x00000203,
    CastleWallBackground = 0x00000204,
    Underwear = 0x00000205,
    FarmFence = 0x00000206,
    OrbDesertBackground = 0x00000207,
    OrbForestBackground = 0x00000208,
    OrbIceBackground = 0x00000209,
    OrbNightBackground = 0x0000020a,
    OrbSpaceBackground = 0x0000020b,
    OrbStarBackground = 0x0000020c,
    TutorialBot = 0x0000020d,
    JumpsuitFemale = 0x0000020e,
    HatJumpsuitMale = 0x0000020f,
    HatJumpsuitFemale = 0x00000210,
    BonusBigSign001 = 0x00000211,
    BonusBigSign002 = 0x00000212,
    BonusBigSign003 = 0x00000213,
    BonusBigSign004 = 0x00000214,
    BonusBigSign005 = 0x00000215,
    BonusBigSign006 = 0x00000216,
    BonusBigSign007 = 0x00000217,
    BonusGrandPrizeLowerLeft = 0x00000218,
    BonusGrandPrizeLowerRight = 0x00000219,
    BonusGrandPrizeUpperLeft = 0x0000021a,
    BonusGrandPrizeUpperRight = 0x0000021b,
    HatSanta = 0x0000021c,
    HairSanta = 0x0000021d,
    ShoesSanta = 0x0000021e,
    PantsSanta = 0x0000021f,
    ShirtSanta = 0x00000220,
    BeardSanta = 0x00000221,
    MaskAlien1 = 0x00000222,
    MaskAlien2 = 0x00000223,
    SuitAlien1 = 0x00000224,
    SuitAlien2 = 0x00000225,
    ShirtHospitalGown = 0x00000226,
    ShoesSneakersPink = 0x00000227,
    ShoesSneakersGreen = 0x00000228,
    ShirtTanktopGreen = 0x00000229,
    ShirtTanktopBlack = 0x0000022a,
    TightsBlack = 0x0000022b,
    HatHeadScarfBlack = 0x0000022c,
    HatHeadScarfRed = 0x0000022d,
    ShirtBlouseOrange = 0x0000022e,
    ShoesSuitAlien1 = 0x0000022f,
    ShoesSuitAlien2 = 0x00000230,
    SkirtMaxiYellow = 0x00000231,
    DressMaxiLightGreen = 0x00000232,
    DressDecoMaxiLightGreen = 0x00000233,
    DressDecoLongBlue = 0x00000234,
    HatSlouchyBeanieGrey = 0x00000235,
    HeadphonesRed = 0x00000236,
    HeadphonesBlue = 0x00000237,
    PinkJello = 0x00000238,
    LightBlueJello = 0x00000239,
    GlowingContainer = 0x0000023a,
    GlassesNerdyPurple = 0x0000023b,
    EarringsGold = 0x0000023c,
    CapeGreen = 0x0000023d,
    DressDecoSkaterYellow = 0x0000023e,
    GloveSuitAlien1 = 0x0000023f,
    GloveSuitAlien2 = 0x00000240,
    WeaponGlowStickRed = 0x00000241,
    WeaponGlowStickBlue = 0x00000242,
    WeaponGlowStickGreen = 0x00000243,
    HairBuzzCutWhite = 0x00000244,
    HairLongOrange = 0x00000245,
    HairBlondeSpiky = 0x00000246,
    HairPonytailBlonde = 0x00000247,
    GloveLeather = 0x00000248,
    DressDecoWhite = 0x00000249,
    WingsPixie = 0x0000024a,
    MiniatureSpaceship = 0x0000024b,
    ScifiCratePile = 0x0000024c,
    ScifiComputer = 0x0000024d,
    BonusDoorVIP = 0x0000024e,
    HairAdminJaakko = 0x0000024f,
    JacketAdminJaakko = 0x00000250,
    PantsJeansAdminJaakko = 0x00000251,
    ShoesSneakersAdminJaakko = 0x00000252,
    WeaponKatanaAdminJaakko = 0x00000253,
    BackKatanaNoHiltAdminJaakko = 0x00000254,
    GlassesAdminJaakko = 0x00000255,
    WeaponSantaCane = 0x00000256,
    HeadphonesAdminJaakko = 0x00000257,
    DaHoodSign = 0x00000258,
    PileOfMoney = 0x00000259,
    DollarsBackground = 0x0000025a,
    MoneyBackground = 0x0000025b,
    RedVelvetBackground = 0x0000025c,
    BlingBlingBlock = 0x0000025d,
    BackKatanaHiltAdminJaakko = 0x0000025e,
    ShoesRubberBootsRed = 0x0000025f,
    WingsDarkPixie = 0x00000260,
    ContactLensesRed = 0x00000261,
    GlassesScifi = 0x00000262,
    StrawberryBlock = 0x00000263,
    PineappleBlock = 0x00000264,
    KiwiBlock = 0x00000265,
    ShoesAdminCommander = 0x00000266,
    GlovesAdminCommander = 0x00000267,
    SuitAdminCommander = 0x00000268,
    HatHelmetVisorUpAdminCommander = 0x00000269,
    HatHelmetVisorDownAdminCommander = 0x0000026a,
    GloveMittensRed = 0x0000026b,
    GloveMittensGreen = 0x0000026c,
    PantsElf = 0x0000026d,
    ShoesElf = 0x0000026e,
    HatElf = 0x0000026f,
    CoatElf = 0x00000270,
    CandyCaneBlock = 0x00000271,
    GingerbreadBlock = 0x00000272,
    HollyWreath = 0x00000273,
    Snowman = 0x00000274,
    ChristmasRibbonGreen = 0x00000275,
    ChristmasRibbonRed = 0x00000276,
    ChristmasTree = 0x00000277,
    WinterBells = 0x00000278,
    ChristmasWallpaperRed = 0x00000279,
    ChristmasWallpaperBlue = 0x0000027a,
    PantsKrampus = 0x0000027b,
    ShoesKrampus = 0x0000027c,
    HairKrampus = 0x0000027d,
    HatHornsKrampus = 0x0000027e,
    ReindeerLights = 0x0000027f,
    ChristmasLights = 0x00000280,
    CoatKrampus = 0x00000281,
    ScarfRed = 0x00000282,
    ScarfGreen = 0x00000283,
    EarMuffsRed = 0x00000284,
    Icicles = 0x00000285,
    WeaponCandyCane = 0x00000286,
    CapeFrost = 0x00000287,
    HatchWooden = 0x00000288,
    HatchMetal = 0x00000289,
    Skulls = 0x0000028a,
    Spider = 0x0000028b,
    AlienEye = 0x0000028c,
    StitchedSkinBlock = 0x0000028d,
    GhostBackground = 0x0000028e,
    GutsBackground = 0x0000028f,
    CloudPlatform = 0x00000290,
    ShirtHoodieGrey = 0x00000291,
    DressSkaterLightBlue = 0x00000292,
    GlassesEyepatch = 0x00000293,
    CapeTowel = 0x00000294,
    GlassesScifiRed = 0x00000295,
    GlassesScifiGreenVIP = 0x00000296,
    GlassesMonocle = 0x00000297,
    WeaponShortSwordGolden = 0x00000298,
    WeaponFlameSword = 0x00000299,
    WeaponSwordAdminMidnightWalker = 0x0000029a,
    SuitAdminMidnightWalker = 0x0000029b,
    CandyBlockGreen = 0x0000029c,
    CandyBlockRed = 0x0000029d,
    CandyBlockPink = 0x0000029e,
    CandyBlockBlue = 0x0000029f,
    CandyBlockCyan = 0x000002a0,
    CandyBlockYellow = 0x000002a1,
    CandyWatermelonBlock = 0x000002a2,
    CandySpiralBlock = 0x000002a3,
    MilkChocolateBlock = 0x000002a4,
    DarkChocolateBlock = 0x000002a5,
    CandyLaceBackground = 0x000002a6,
    ChocolateBackground = 0x000002a7,
    Cake = 0x000002a8,
    LiquorishBlock = 0x000002a9,
    CandyBackground = 0x000002aa,
    DarkChocolateDecoratedBlock = 0x000002ab,
    MaskRobbers = 0x000002ac,
    ShirtPonchoLightGreen = 0x000002ad,
    SuitJumpPrison = 0x000002ae,
    HatCandyKing = 0x000002af,
    HatWinterPurple = 0x000002b0,
    HatWonky = 0x000002b1,
    MaskTeddyPink = 0x000002b2,
    MaskTeddyBlue = 0x000002b3,
    PantsShortsLove = 0x000002b4,
    DressBallerina = 0x000002b5,
    ShoesBallerinaLacedPink = 0x000002b6,
    ShoesLeisure = 0x000002b7,
    PantsLeisure = 0x000002b8,
    ShirtLeisure = 0x000002b9,
    PantsCandyShorts = 0x000002ba,
    ShoesChoco = 0x000002bb,
    ShoesCandyShoes = 0x000002bc,
    WeaponLollipop = 0x000002bd,
    ShoesHeffnerSlippers = 0x000002be,
    BeardMoustachePink = 0x000002bf,
    HairCottonCandy = 0x000002c0,
    HeartBlock = 0x000002c1,
    GummyBearOrange = 0x000002c2,
    GummyBearGreen = 0x000002c3,
    GummyBearRed = 0x000002c4,
    OrbCandyBackground = 0x000002c5,
    CandyPillar = 0x000002c6,
    CoatHeffner = 0x000002c7,
    HairHairbandBlack = 0x000002c8,
    HeartWallpaper = 0x000002c9,
    DressCocktailBubblegum = 0x000002ca,
    ShoesBubbleGum = 0x000002cb,
    NeckRedRubyAdminEndless = 0x000002cc,
    HairAdminEndless = 0x000002cd,
    CoatAdminEndless = 0x000002ce,
    MaskAdminEndless = 0x000002cf,
    SuitTeddyPink = 0x000002d0,
    SuitTeddyBlue = 0x000002d1,
    ShoesTeddyPink = 0x000002d2,
    ShoesTeddyBlue = 0x000002d3,
    WingsCherubPink = 0x000002d4,
    SuitOverallsCandy = 0x000002d5,
    WeaponCandySceptre = 0x000002d6,
    GlassesSunHeart = 0x000002d7,
    CoatCandy = 0x000002d8,
    HairPonytailRed = 0x000002d9,
    HairLongPurple = 0x000002da,
    WeaponAdminBanHammer = 0x000002db,
    PantsCamoBlue = 0x000002dc,
    HatSlouchyBeanieBlue = 0x000002dd,
    ShoesSneakersWhite = 0x000002de,
    ShirtJerseyYellow = 0x000002df,
    CoatRainBlue = 0x000002e0,
    ShirtTSkullBlue = 0x000002e1,
    ShirtTanktopBlue = 0x000002e2,
    SkirtYellow = 0x000002e3,
    HatStetsonBeige = 0x000002e4,
    ShirtTGrey = 0x000002e5,
    CapeAchievementBlue = 0x000002e6,
    AchievementMedalBronze = 0x000002e7,
    AchievementMedalSilver = 0x000002e8,
    AchievementMedalGold = 0x000002e9,
    AchievementGobletBronze = 0x000002ea,
    AchievementGobletSilver = 0x000002eb,
    AchievementGobletGold = 0x000002ec,
    MaskPlagueDoc = 0x000002ed,
    PotOfGems = 0x000002ee,
    CloverLeafBackground = 0x000002ef,
    IrishBalloons = 0x000002f0,
    LuckyHorseshoe = 0x000002f1,
    CloverLeafBlock = 0x000002f2,
    GreenGiftwrapBackground = 0x000002f3,
    PennantGreen = 0x000002f4,
    MushroomGreen = 0x000002f5,
    RainbowBackground = 0x000002f6,
    LeprechaunGnome = 0x000002f7,
    GoldenHorseshoe = 0x000002f8,
    LuckyCloverLeaf = 0x000002f9,
    PotOfGold = 0x000002fa,
    WindowClover = 0x000002fb,
    HairAdminDev = 0x000002fc,
    PantsSpandexGreen = 0x000002fd,
    GlovesWristbandStPaddy = 0x000002fe,
    HatStetsonGreen = 0x000002ff,
    HairBobstyleGreen = 0x00000300,
    DressIrishMaid = 0x00000301,
    HatTophatIrish = 0x00000302,
    CoatLeprechaun = 0x00000303,
    PantsLeprechaun = 0x00000304,
    ShoesLeprechaun = 0x00000305,
    CoatGnome = 0x00000306,
    PantsShortsGnome = 0x00000307,
    GlassesRoundGlassesGreen = 0x00000308,
    ScarfIrish = 0x00000309,
    HairStPaddy = 0x0000030a,
    BeardStPaddy = 0x0000030b,
    ShoesGnome = 0x0000030c,
    HatStPaddy = 0x0000030d,
    WeaponFluteStPaddy = 0x0000030e,
    IrishPennantString = 0x0000030f,
    InfluencerWickerHat = 0x00000310,
    QuestNPC = 0x00000311,
    CloverLeaf = 0x00000312,
    WeaponSwordGallowglass = 0x00000313,
    HatBowlerLeprechaun = 0x00000314,
    WeaponStickLeprechaun = 0x00000315,
    CapeLeprechaunCape = 0x00000316,
    WingsCloverWings = 0x00000317,
    MaskIrishCharm = 0x00000318,
    NeckLuckyCharm = 0x00000319,
    WeaponGuitarAdminDev = 0x0000031a,
    BeardAdminDev = 0x0000031b,
    LockPlatinum = 0x0000031c,
    HatHelmetLion = 0x0000031d,
    HatCapBlack = 0x0000031e,
    HatTophatDecoBlack = 0x0000031f,
    HatBunnyEarsPink = 0x00000320,
    EasterBlockBlue = 0x00000321,
    EasterBlockGreen = 0x00000322,
    EasterBlockPurple = 0x00000323,
    EasterBlockRed = 0x00000324,
    EasterBlockYellow = 0x00000325,
    EasterSpheresBackground = 0x00000326,
    EasterStripesBackground = 0x00000327,
    EasterTilesBackground = 0x00000328,
    EasterEggDecorationOrange = 0x00000329,
    EasterEggDecorationBlue = 0x0000032a,
    EasterEggDecorationViolet = 0x0000032b,
    EasterEggBasket = 0x0000032c,
    EasterEggTrophy = 0x0000032d,
    WaterColorBlock = 0x0000032e,
    BunnyPlushToy = 0x0000032f,
    ChickPlushToy = 0x00000330,
    Serpentine = 0x00000331,
    SerpentineAndEggs = 0x00000332,
    TailEasterBunny = 0x00000333,
    NoseEasterBunny = 0x00000334,
    WeaponAxeEaster = 0x00000335,
    ShoesEasterBunny = 0x00000336,
    ShardGreen = 0x00000337,
    ShardRed = 0x00000338,
    ShardBlue = 0x00000339,
    ShardYellow = 0x0000033a,
    ShardOrange = 0x0000033b,
    ShardClear = 0x0000033c,
    ShardPink = 0x0000033d,
    ShardGrey = 0x0000033e,
    ShardAir = 0x0000033f,
    ShardFire = 0x00000340,
    ShardWater = 0x00000341,
    ShardEarth = 0x00000342,
    ShardSpirit = 0x00000343,
    ShardElectro = 0x00000344,
    ShardSilicon = 0x00000345,
    ShardDoom = 0x00000346,
    ShardAmber = 0x00000347,
    ShardPixie = 0x00000348,
    ShardCircuit = 0x00000349,
    ShardMagic = 0x0000034a,
    ShardFusion = 0x0000034b,
    ShardEaster = 0x0000034c,
    ShardNightmare = 0x0000034d,
    ShardHeart = 0x0000034e,
    Replicator = 0x0000034f,
    OrbHalloweenTowerBackground = 0x00000350,
    BlueprintHatHelmetVisorPWR = 0x00000351,
    BlueprintGlovesPWR = 0x00000352,
    BlueprintShoesPWR = 0x00000353,
    BlueprintSuitPWR = 0x00000354,
    BlueprintWeaponSwordLaserGreen = 0x00000355,
    BlueprintWeaponSwordLaserRed = 0x00000356,
    BlueprintWeaponSwordLaserBlue = 0x00000357,
    BlueprintOrbSpaceBackground = 0x00000358,
    BlueprintCapeDark = 0x00000359,
    BlueprintMaskBunnyDark = 0x0000035a,
    BlueprintSuitBunnyDark = 0x0000035b,
    BlueprintShoesBunnyDark = 0x0000035c,
    BlueprintMaskTiki = 0x0000035d,
    BlueprintJetPackPlasma = 0x0000035e,
    BlueprintNecklaceGlimmer = 0x0000035f,
    BlueprintWeaponSwordFlaming = 0x00000360,
    HatHelmetVisorPWR = 0x00000361,
    GlovesPWR = 0x00000362,
    ShoesPWR = 0x00000363,
    SuitPWR = 0x00000364,
    WeaponSwordLaserGreen = 0x00000365,
    WeaponSwordLaserRed = 0x00000366,
    WeaponSwordLaserBlue = 0x00000367,
    CapeDark = 0x00000368,
    MaskBunnyDark = 0x00000369,
    SuitBunnyDark = 0x0000036a,
    ShoesBunnyDark = 0x0000036b,
    MaskTiki = 0x0000036c,
    JetPackPlasma = 0x0000036d,
    NecklaceGlimmer = 0x0000036e,
    ShirtHoodieSupport = 0x0000036f,
    WingsDragonBlue = 0x00000370,
    JetPackSoda = 0x00000371,
    LockWorldDark = 0x00000372,
    MaskChick = 0x00000373,
    SuitChick = 0x00000374,
    ShoesChick = 0x00000375,
    MaskBunnyGreen = 0x00000376,
    SuitBunnyGreen = 0x00000377,
    ShoesBunnyGreen = 0x00000378,
    HairChick = 0x00000379,
    CapeEasterWitch = 0x0000037a,
    HatBunnyEars = 0x0000037b,
    MaskEggDetector = 0x0000037c,
    HatEasterWitchHeadScarf = 0x0000037d,
    WeaponEasterBranch = 0x0000037e,
    ShoesEasterWitch = 0x0000037f,
    DressEasterWitch = 0x00000380,
    WeaponEasterWitchBroom = 0x00000381,
    GlovesSkiGlovesGreen = 0x00000382,
    ShoesSkiBoots = 0x00000383,
    SuitOverallsSkiSuitRetro = 0x00000384,
    HairSkimaskedBlonde = 0x00000385,
    HairSkimaskedBrown = 0x00000386,
    HairSkimaskedBlack = 0x00000387,
    HairFringeSpikyBrown = 0x00000388,
    ContactLensesBlue = 0x00000389,
    ContactLensesGreen = 0x0000038a,
    ContactLensesGold = 0x0000038b,
    ContactLensesBrown = 0x0000038c,
    ContactLensesSilver = 0x0000038d,
    ContactLensesPurple = 0x0000038e,
    ContactLensesWhite = 0x0000038f,
    ContactLensesPink = 0x00000390,
    ContactLensesTurquoise = 0x00000391,
    HairUndercutLongBlonde = 0x00000392,
    HairUndercutLongBrown = 0x00000393,
    HairUndercutLongBlack = 0x00000394,
    HairUndercutLongRed = 0x00000395,
    HairUndercutWavyBrown = 0x00000396,
    HairUndercutWavyReddish = 0x00000397,
    HairUndercutWavyBlack = 0x00000398,
    HairUndercutWavyBlonde = 0x00000399,
    HairRockaBillyBlack = 0x0000039a,
    HairJPopRed = 0x0000039b,
    HairJPopBlue = 0x0000039c,
    HairJPopPurple = 0x0000039d,
    HairJPopGreen = 0x0000039e,
    HairAfroBrown = 0x0000039f,
    HairAfroBlack = 0x000003a0,
    HairAfroReddish = 0x000003a1,
    HairCurlyCurtainsBlonde = 0x000003a2,
    HairCurlyCurtainsBlack = 0x000003a3,
    HairCurlyCurtainsBrown = 0x000003a4,
    HairEmoBlack = 0x000003a5,
    GlovesRingFrost = 0x000003a6,
    GlovesRingGoblin = 0x000003a7,
    HairPuffyBlue = 0x000003a8,
    HairPuffyRed = 0x000003a9,
    HairSideyBrown = 0x000003aa,
    HairSiippaLongBrown = 0x000003ab,
    HairSiippaLongBlack = 0x000003ac,
    HairSiippaLongRed = 0x000003ad,
    HairZefBlonde = 0x000003ae,
    HairZefBrown = 0x000003af,
    HairSpikyPunkBlue = 0x000003b0,
    HairSpikyPunkRed = 0x000003b1,
    HairMohawkGreen = 0x000003b2,
    HairMohawkRed = 0x000003b3,
    HairLongArchyBlonde = 0x000003b4,
    HairLongArchyRed = 0x000003b5,
    HairFringeSpikyBlonde = 0x000003b6,
    HairFringeSpikyBlack = 0x000003b7,
    HairFringeSpikyPink = 0x000003b8,
    Deflector = 0x000003b9,
    PinballBumper = 0x000003ba,
    SpringBoard = 0x000003bb,
    TrapdoorMetalPlatform = 0x000003bc,
    PoisonTrap = 0x000003bd,
    Elevator = 0x000003be,
    SpikeBall = 0x000003bf,
    ShootingLaser = 0x000003c0,
    TeslaSphere = 0x000003c1,
    MovingPlatform = 0x000003c2,
    PressurePlate = 0x000003c3,
    ForceField = 0x000003c4,
    GlueBlock = 0x000003c5,
    GiftBox = 0x000003c6,
    ScoreBoard = 0x000003c7,
    FinishLine = 0x000003c8,
    StartPoint = 0x000003c9,
    DeathCounter = 0x000003ca,
    CapeAdminMidnightWalkerDouble = 0x000003cb,
    CapeAdminMidnightWalkerParachute = 0x000003cc,
    MaskHorseHead = 0x000003cd,
    OrientalTeaSet = 0x000003ce,
    ToriiGate = 0x000003cf,
    Hokora = 0x000003d0,
    YinYangBlock = 0x000003d1,
    SamuraiBlock = 0x000003d2,
    SamuraiBackground = 0x000003d3,
    TaikoDrum = 0x000003d4,
    KatanaDecoration = 0x000003d5,
    CherryBonsai = 0x000003d6,
    Bamboo = 0x000003d7,
    BambooWall = 0x000003d8,
    ManekiNekoL = 0x000003d9,
    DailyQuestNPC = 0x000003da,
    HatHelmetSamuraiRed = 0x000003db,
    ShirtSamuraiArmorRed = 0x000003dc,
    PantsSamuraiArmorRedBlack = 0x000003dd,
    ShoesSamuraiArmorYellowBlack = 0x000003de,
    HatHelmetSamuraiBlack = 0x000003df,
    ShirtSamuraiArmorBlack = 0x000003e0,
    PantsSamuraiArmorRedYellow = 0x000003e1,
    ShoesSamuraiArmorWhiteBrown = 0x000003e2,
    MaskSamuraiRed = 0x000003e3,
    MaskSamuraiBlack = 0x000003e4,
    GloveNinjaPurple = 0x000003e5,
    GloveNinjaGreyBlue = 0x000003e6,
    GloveNinjaDarkRed = 0x000003e7,
    HatHoodNinjaPurple = 0x000003e8,
    HatHoodNinjaBlue = 0x000003e9,
    MaskNinjaRed = 0x000003ea,
    ShirtNinjaBlue = 0x000003eb,
    ShirtNinjaPurple = 0x000003ec,
    ShirtNinjaDarkRed = 0x000003ed,
    PantsNinjaBlue = 0x000003ee,
    PantsNinjaDark = 0x000003ef,
    PantsNinjaGrey = 0x000003f0,
    ShoesNinjaGrey = 0x000003f1,
    ShoesNinjaRed = 0x000003f2,
    ShoesNinjaPurple = 0x000003f3,
    DressGeishaBlue = 0x000003f4,
    DressGeishaRed = 0x000003f5,
    HairSamurai = 0x000003f6,
    HairShogun = 0x000003f7,
    HairGeisha = 0x000003f8,
    WeaponSai = 0x000003f9,
    WeaponSamuraiKatana = 0x000003fa,
    WeaponNaginata = 0x000003fb,
    ShoesGeishaRed = 0x000003fc,
    ShoesGeishaBlack = 0x000003fd,
    PantsBrokenHoleBlack = 0x000003fe,
    ShirtHoodieSupportFemale = 0x000003ff,
    GlassesRetro = 0x00000400,
    TailDevil = 0x00000401,
    HatSteampunk = 0x00000402,
    BlueprintHatHelmetSamuraiBlack = 0x00000403,
    BlueprintMaskSamuraiBlack = 0x00000404,
    BlueprintShogunArmorShirt = 0x00000405,
    BlueprintShogunArmorPants = 0x00000406,
    BlueprintShogunShoes = 0x00000407,
    BlueprintShogunKatana = 0x00000408,
    WeaponShogunKatana = 0x00000409,
    CapeShogunRed = 0x0000040a,
    BackDecorativeBackKatana = 0x0000040b,
    BlueprintShogunCape = 0x0000040c,
    HairBuzzcutBlack = 0x0000040d,
    ShirtHoodieMod = 0x0000040e,
    SandCastleSmall = 0x0000040f,
    SandCastleMedium = 0x00000410,
    SandCastleLarge = 0x00000411,
    SunUmbrellaBlue = 0x00000412,
    SunUmbrellaRed = 0x00000413,
    SunUmbrellaGold = 0x00000414,
    ShirtSportsTopBlue = 0x00000415,
    ShirtSportsTopRed = 0x00000416,
    ShirtSportsTopGold = 0x00000417,
    PantsSpeedosBlue = 0x00000418,
    PantsSpeedosRed = 0x00000419,
    PantsSpeedosGolden = 0x0000041a,
    GlassesSunBlue = 0x0000041b,
    GlassesSunRed = 0x0000041c,
    GlassesSunGolden = 0x0000041d,
    NeckFloaterDuck = 0x0000041e,
    NeckFloaterWalrus = 0x0000041f,
    NeckFloaterDog = 0x00000420,
    ShoesFlippersBlue = 0x00000421,
    ShoesFlippersRed = 0x00000422,
    ShoesFlippersGold = 0x00000423,
    MaskSnorkelBlue = 0x00000424,
    MaskSnorkelRed = 0x00000425,
    MaskSnorkelGold = 0x00000426,
    WeaponGunWaterSmall = 0x00000427,
    WeaponGunWaterMedium = 0x00000428,
    WeaponGunWaterLarge = 0x00000429,
    WeaponSummerHammer = 0x0000042a,
    CollectableQuestSummer = 0x0000042b,
    QuestStarterItemSummer = 0x0000042c,
    BreakableItemQuestSummer = 0x0000042d,
    Fertilizer = 0x0000042e,
    ShirtLifeVestOrange = 0x0000042f,
    WeaponSurfboardGreen = 0x00000430,
    WeaponSurfboardYellow = 0x00000431,
    WeaponSurfboardPurple = 0x00000432,
    HairTrump = 0x00000433,
    LifeBuoy = 0x00000434,
    LifeGuardChair = 0x00000435,
    EntrancePortalMover = 0x00000436,
    HairAdminEndlessDeath = 0x00000437,
    ShirtTopAdminEndlessDeath = 0x00000438,
    GlassesAdminEndlessDeath = 0x00000439,
    WristBandsAdminEndlessDeath = 0x0000043a,
    ShoesAdminEndlessDeath = 0x0000043b,
    PantsAdminEndlessDeath = 0x0000043c,
    WingsSongo = 0x0000043d,
    FamiliarGremlin1A = 0x0000043e,
    FamiliarGremlin2A = 0x0000043f,
    FamiliarGremlin3A = 0x00000440,
    FamiliarGremlin4A = 0x00000441,
    FamiliarGremlin4B = 0x00000442,
    FamiliarGremlin5A = 0x00000443,
    FamiliarGremlin5C = 0x00000444,
    FamiliarCrow1A = 0x00000445,
    FamiliarCrow2A = 0x00000446,
    FamiliarBunny1A = 0x00000447,
    FamiliarBunny2A = 0x00000448,
    FamiliarBunny3A = 0x00000449,
    FamiliarBunny4A = 0x0000044a,
    FamiliarBunny4B = 0x0000044b,
    FamiliarBot1A = 0x0000044c,
    FamiliarBot2A = 0x0000044d,
    FamiliarBot3A = 0x0000044e,
    FamiliarBot3B = 0x0000044f,
    FAMFoodCookieRed = 0x00000450,
    FAMFoodCookieBlue = 0x00000451,
    FAMFoodCookiePurple = 0x00000452,
    FAMFoodCookieGreen = 0x00000453,
    FAMFoodCookieYellow = 0x00000454,
    FAMFoodCandyRed = 0x00000455,
    FAMFoodCandyBlue = 0x00000456,
    FAMFoodCandyPurple = 0x00000457,
    FAMFoodCandyGreen = 0x00000458,
    FAMFoodCandyYellow = 0x00000459,
    FAMFoodJelloRed = 0x0000045a,
    FAMFoodJelloBlue = 0x0000045b,
    FAMFoodJelloPurple = 0x0000045c,
    FAMFoodJelloGreen = 0x0000045d,
    FAMFoodJelloYellow = 0x0000045e,
    FAMFoodSandwichRed = 0x0000045f,
    FAMFoodSandwichBlue = 0x00000460,
    FAMFoodSandwichPurple = 0x00000461,
    FAMFoodSandwichGreen = 0x00000462,
    FAMFoodSandwichYellow = 0x00000463,
    WindowCastle = 0x00000464,
    FAMFoodMachine = 0x00000465,
    FAMEvolverator = 0x00000466,
    FamiliarNinjaPickle1A = 0x00000467,
    FamiliarWhale1A = 0x00000468,
    KiddieRide = 0x00000469,
    LegendarySoilBlock = 0x0000046a,
    LockWorldBattle = 0x0000046b,
    LockBattle = 0x0000046c,
    BattleBarrierBasic = 0x0000046d,
    BattleScoreBoard = 0x0000046e,
    LockPart = 0x0000046f,
    BoneDust = 0x00000470,
    FossilPuzzle = 0x00000471,
    FossilTRexPart1 = 0x00000472,
    FossilTRexPart2 = 0x00000473,
    FossilTRexPart3 = 0x00000474,
    FossilTRexPart4 = 0x00000475,
    FossilTRexPart5 = 0x00000476,
    FossilTRexPart6 = 0x00000477,
    FossilTRexPart7 = 0x00000478,
    FossilTRexPart8 = 0x00000479,
    FossilTRexPart9 = 0x0000047a,
    FossilAlligatorPart1 = 0x0000047b,
    FossilAlligatorPart2 = 0x0000047c,
    FossilAlligatorPart3 = 0x0000047d,
    FossilAlligatorPart4 = 0x0000047e,
    FossilAngelPart1 = 0x0000047f,
    FossilAngelPart2 = 0x00000480,
    FossilAngelPart3 = 0x00000481,
    FossilAngelPart4 = 0x00000482,
    CheeseBlock = 0x00000483,
    Concrete1x1Block = 0x00000484,
    Concrete1x2Block = 0x00000485,
    Concrete2x2Block = 0x00000486,
    GlowBlockBlue = 0x00000487,
    GlowBlockGreen = 0x00000488,
    GlowBlockOrange = 0x00000489,
    GlowBlockRed = 0x0000048a,
    HazardBlock = 0x0000048b,
    MetalStudded = 0x0000048c,
    ArmoredBackground = 0x0000048d,
    DiagonalCheckerBlack = 0x0000048e,
    DiagonalCheckerBlue = 0x0000048f,
    DiagonalCheckerRed = 0x00000490,
    HerringboneTilesDirty = 0x00000491,
    HerringboneTilesGrey = 0x00000492,
    IllusionGreyBackground = 0x00000493,
    IllusionRedBackground = 0x00000494,
    JailBackground = 0x00000495,
    LavaBackground = 0x00000496,
    MetalBackground1 = 0x00000497,
    MetalBackground2 = 0x00000498,
    MetalBackground3 = 0x00000499,
    MoireSquareBackground = 0x0000049a,
    SpiralMosaic = 0x0000049b,
    TileBlack = 0x0000049c,
    UnslipperyMetal = 0x0000049d,
    FenceWooden = 0x0000049e,
    HousePlant = 0x0000049f,
    OldWallLamp = 0x000004a0,
    Vine = 0x000004a1,
    ToiletSeat = 0x000004a2,
    WeaponCleaver = 0x000004a3,
    HatBucketRed = 0x000004a4,
    BeardGoateeBlack = 0x000004a5,
    HatHelmetVisorPWRRed = 0x000004a6,
    GlovesPWRRed = 0x000004a7,
    ShoesPWRRed = 0x000004a8,
    SuitPWRRed = 0x000004a9,
    BlueprintHatHelmetVisorPWRRed = 0x000004aa,
    BlueprintGlovesPWRRed = 0x000004ab,
    BlueprintShoesPWRRed = 0x000004ac,
    BlueprintSuitPWRRed = 0x000004ad,
    MoireRoundBackground = 0x000004ae,
    GreenScreen = 0x000004af,
    HairLongNutturaBlack = 0x000004b0,
    HairLongNutturaBrown = 0x000004b1,
    HairEmoBlue = 0x000004b2,
    HairEmoRed = 0x000004b3,
    HairLongStripedBlackPurple = 0x000004b4,
    WeaponBone = 0x000004b5,
    HatHelmetBone = 0x000004b6,
    SuitArmorBone = 0x000004b7,
    WeaponMace = 0x000004b8,
    HatHelmetVikingChainMail = 0x000004b9,
    HatHelmetVikingSkyrim = 0x000004ba,
    HatHelmetVikingTHorns = 0x000004bb,
    HatHelmetVikingSimpleMasked = 0x000004bc,
    HatHelmetVikingSideIron = 0x000004bd,
    HatHelmetVikingWarlord = 0x000004be,
    HatHelmetVikingThor = 0x000004bf,
    HatHoodVikingLadyBlonde = 0x000004c0,
    HatHoodVikingLadyBrown = 0x000004c1,
    HairVikingSideyBrown = 0x000004c2,
    HairVikingSideyBlack = 0x000004c3,
    HairVikingSideyBlonde = 0x000004c4,
    HairVikingMaidenBraidFrontBlonde = 0x000004c5,
    HairVikingMaidenBraidSideBlonde = 0x000004c6,
    HairVikingMaidenBraidSideBrown = 0x000004c7,
    HairVikingOpenBrown = 0x000004c8,
    HairVikingOdinLongWhite = 0x000004c9,
    BeardOdinLongWhite = 0x000004ca,
    BeardVikingLongBrown = 0x000004cb,
    BeardVikingBrown = 0x000004cc,
    BeardVikingBlonde = 0x000004cd,
    BeardVikingBlack = 0x000004ce,
    BeardVikingSideburnsBrown = 0x000004cf,
    FacialVikingMoustacheBrown = 0x000004d0,
    ShoesVikingWarlord = 0x000004d1,
    CoatVikingWarlord = 0x000004d2,
    CapeVikingWarlord = 0x000004d3,
    DressVikingShieldmaidenGreen = 0x000004d4,
    ShoesVikingShieldmaidenGreen = 0x000004d5,
    ShoesVikingBerserker = 0x000004d6,
    PantsVikingBerserker = 0x000004d7,
    ShirtVikingBerserker = 0x000004d8,
    CapeVikingBerserker = 0x000004d9,
    ShoesVikingThor = 0x000004da,
    CoatVikingThor = 0x000004db,
    CoatVikingSeer = 0x000004dc,
    CoatDracula = 0x000004dd,
    ShirtVikingWarriorChainmail = 0x000004de,
    ShoesVikingWarriorBrown = 0x000004df,
    ShirtVikingWarriorLeather = 0x000004e0,
    ShoesVikingWarriorStrapped = 0x000004e1,
    MaskMummy = 0x000004e2,
    CoatVikingLady = 0x000004e3,
    HairJHorror = 0x000004e4,
    ShoesVikingLadyPurple = 0x000004e5,
    HatVikingSwordThroughHead = 0x000004e6,
    WeaponVikingAxeDouble = 0x000004e7,
    WeaponVikingAxeGreat = 0x000004e8,
    WeaponVikingAxeCurved = 0x000004e9,
    WeaponVikingAxeMedium = 0x000004ea,
    WeaponVikingSword = 0x000004eb,
    WeaponVikingSpear = 0x000004ec,
    WeaponVikingShieldRed = 0x000004ed,
    WeaponVikingShieldGreen = 0x000004ee,
    WeaponVikingShieldBlue = 0x000004ef,
    WeaponVikingShieldThor = 0x000004f0,
    WeaponVikingHammerThor = 0x000004f1,
    BackhandItemVikingShield = 0x000004f2,
    WingsValkyria = 0x000004f3,
    VampireFangs = 0x000004f4,
    VikingBlock = 0x000004f5,
    VikingArmorBlock = 0x000004f6,
    VikingWoodBackground = 0x000004f7,
    VikingStoneBackground = 0x000004f8,
    VikingRuneBackground = 0x000004f9,
    VikingWoodenWall1 = 0x000004fa,
    VikingWoodenWall2 = 0x000004fb,
    VikingWoodenWall3 = 0x000004fc,
    VikingWoodenWall4 = 0x000004fd,
    RunestoneBlue = 0x000004fe,
    RunestoneRed = 0x000004ff,
    RunestoneGreen = 0x00000500,
    RunestoneOrange = 0x00000501,
    Bonfire = 0x00000502,
    VikingWeaponRack = 0x00000503,
    RavenTree = 0x00000504,
    VikingShieldDecoration = 0x00000505,
    VikingFigurehead = 0x00000506,
    BackhandItemVikingShieldGold = 0x00000507,
    BackhandItemVikingShieldIron = 0x00000508,
    BlueprintWingsValkyria = 0x00000509,
    WeaponSeerStaff = 0x0000050a,
    OrbCemeteryBackground = 0x0000050b,
    HairDracula = 0x0000050c,
    GlovesRingDemon = 0x0000050d,
    HatHornsDemon = 0x0000050e,
    HatBrainsOut = 0x0000050f,
    MaskJason = 0x00000510,
    MaskPumpkin = 0x00000511,
    CapeDracula = 0x00000512,
    DressCountessBathory = 0x00000513,
    HatBrownFedora = 0x00000514,
    ShirtKruger = 0x00000515,
    GlovesKrugerClaw = 0x00000516,
    PantsKruger = 0x00000517,
    MaskKruger = 0x00000518,
    WeaponScythe = 0x00000519,
    WeaponPoisonBlade = 0x0000051a,
    WeaponBreadKnife = 0x0000051b,
    DressMistressOfTheDark = 0x0000051c,
    HairMistressOfTheDark = 0x0000051d,
    MaskPaintSkull = 0x0000051e,
    MaskCorpsePaint = 0x0000051f,
    FamiliarGhost1A = 0x00000520,
    FamiliarSkull1A = 0x00000521,
    FamiliarPumpkin1A = 0x00000522,
    FamiliarEye1A = 0x00000523,
    MaskHoodBlack = 0x00000524,
    MaskPinhead = 0x00000525,
    CoatPinhead = 0x00000526,
    HairCountessBathory = 0x00000527,
    HairChucky = 0x00000528,
    OverallsChucky = 0x00000529,
    MaskChuckyScars = 0x0000052a,
    PotionWerewolf = 0x0000052b,
    CostumeWerewolf = 0x0000052c,
    MaskPhantom = 0x0000052d,
    MaskNamelessGhoul = 0x0000052e,
    MaskIt = 0x0000052f,
    MaskFrankenstein = 0x00000530,
    MaskCthulhu = 0x00000531,
    MaskSawBillyPuppet = 0x00000532,
    WingsDarkCherub = 0x00000533,
    MaskSkull = 0x00000534,
    ContactLensesSnake = 0x00000535,
    BlackCandles = 0x00000536,
    PumpkinLantern = 0x00000537,
    Ghost = 0x00000538,
    DungeonWallBars = 0x00000539,
    OuijaBoard = 0x0000053a,
    ElectricChair = 0x0000053b,
    Spikes = 0x0000053c,
    ChurchBell = 0x0000053d,
    SpiderWeb = 0x0000053e,
    Blood = 0x0000053f,
    Acid = 0x00000540,
    StonePlatform = 0x00000541,
    TombStone = 0x00000542,
    MimicCoffin = 0x00000543,
    CheckpointBonfire = 0x00000544,
    CapeMidnight = 0x00000545,
    WingsCthulhu = 0x00000546,
    BlueprintCapeMidnight = 0x00000547,
    CollectableLostSoulHalloween = 0x00000548,
    ZombieTrap = 0x00000549,
    Fog = 0x0000054a,
    BattleBarrierBones = 0x0000054b,
    DemonAltar = 0x0000054c,
    SpiritCage = 0x0000054d,
    RuleBot = 0x0000054e,
    SpiralPillar = 0x0000054f,
    FamiliarGhost2A = 0x00000550,
    FamiliarGhost2B = 0x00000551,
    FamiliarSkull2A = 0x00000552,
    Headstone = 0x00000553,
    CelticCross = 0x00000554,
    GraveSlant = 0x00000555,
    TowerGrandPrizeLowerLeft = 0x00000556,
    TowerGrandPrizeLowerRight = 0x00000557,
    TowerGrandPrizeUpperLeft = 0x00000558,
    TowerGrandPrizeUpperRight = 0x00000559,
    WotwTrophy = 0x0000055a,
    AIEnemySpawnerBasic = 0x0000055b,
    NetherLavaFall = 0x0000055c,
    NetherBridge = 0x0000055d,
    NetherCaveBackground = 0x0000055e,
    NetherChainRingBlock = 0x0000055f,
    NetherCrumbles = 0x00000560,
    NetherFirefly = 0x00000561,
    NetherGlowPlant = 0x00000562,
    NetherGrass = 0x00000563,
    NetherGreystone = 0x00000564,
    NetherLavastone = 0x00000565,
    NetherMushrooms = 0x00000566,
    NetherPillar = 0x00000567,
    NetherPlatform = 0x00000568,
    NetherRedstone = 0x00000569,
    NetherRedstoneGlow = 0x0000056a,
    NetherStalactitesTop = 0x0000056b,
    NetherStalactitesBottom = 0x0000056c,
    NetherSupport = 0x0000056d,
    NetherTileBackground1 = 0x0000056e,
    NetherTileBackground2 = 0x0000056f,
    NetherGiftBox = 0x00000570,
    DoorMarker = 0x00000571,
    OrbNetherBackground = 0x00000572,
    JumpsuitAnniversary = 0x00000573,
    CapeAdminMidnightWalkerLongJump = 0x00000574,
    CapeAdminMidnightWalkerNormal = 0x00000575,
    TreasureSpawner = 0x00000576,
    CheckPointSpawner = 0x00000577,
    NetherTreasure = 0x00000578,
    FireBallShooterTrap = 0x00000579,
    ConsumableRedScroll = 0x0000057a,
    ConsumableRedScrollLarge = 0x0000057b,
    ConsumableNetherFlameStone = 0x0000057c,
    HatVainamoinen = 0x0000057d,
    HatPilgrim = 0x0000057e,
    TurkeyMeal = 0x0000057f,
    NetherFireTrap = 0x00000580,
    NetherSpikeTrap = 0x00000581,
    NetherFireBallShooterTrap = 0x00000582,
    NetherDeathCounter = 0x00000583,
    WeaponNetherBlade = 0x00000584,
    HatNetherHood = 0x00000585,
    ShoesNetherPaws = 0x00000586,
    TailNetherTail = 0x00000587,
    PantsNetherPants = 0x00000588,
    ShirtNetherArmor = 0x00000589,
    BackhandItemNetherShield = 0x0000058a,
    NetherExit = 0x0000058b,
    NetherKey = 0x0000058c,
    NetherCrystal = 0x0000058d,
    WingsAnniversary = 0x0000058e,
    FamiliarNetherBall1A = 0x0000058f,
    FinnishPennant = 0x00000590,
    FireworksSmall1 = 0x00000591,
    FireworksSmall2 = 0x00000592,
    FireworksSmall3 = 0x00000593,
    FireworksSmall4 = 0x00000594,
    FireworksMedium1 = 0x00000595,
    FireworksMedium2 = 0x00000596,
    FireworksMedium3 = 0x00000597,
    FireworksLarge1 = 0x00000598,
    FireworksLarge2 = 0x00000599,
    FireworksHuge1 = 0x0000059a,
    MaskSnowman = 0x0000059b,
    SuitSnowman = 0x0000059c,
    HairIcicleMohawk = 0x0000059d,
    MoustacheFrostache = 0x0000059e,
    WeaponFrostSpear = 0x0000059f,
    SkirtXmas17 = 0x000005a0,
    HatXmas17Blonde = 0x000005a1,
    HatXmas17Brunette = 0x000005a2,
    HatXmas17Black = 0x000005a3,
    ShoesXmas17Red = 0x000005a4,
    ShirtHoodieXmas17 = 0x000005a5,
    ScarfXmas17 = 0x000005a6,
    NecklaceFrost = 0x000005a7,
    ShirtXmas17Sweater = 0x000005a8,
    BackhandItemFrostShield = 0x000005a9,
    ConsumableXmasPresent = 0x000005aa,
    GingerbreadSign = 0x000005ab,
    GingerbreadFence = 0x000005ac,
    SnowyFence = 0x000005ad,
    SnowLantern = 0x000005ae,
    BlueprintNecklaceFrost = 0x000005af,
    ShoesIceSkatesXmas17 = 0x000005b0,
    FamiliarNinjaPickle2A = 0x000005b1,
    FamiliarSnowman1A = 0x000005b2,
    FamiliarSnowman2A = 0x000005b3,
    FamiliarSnowman3A = 0x000005b4,
    FamiliarBunny2B = 0x000005b5,
    FamiliarGremlin2B = 0x000005b6,
    FamiliarPenguin1A = 0x000005b7,
    FamiliarPenguin2A = 0x000005b8,
    FamiliarPenguin3A = 0x000005b9,
    WeaponFrostSword = 0x000005ba,
    ConsumableBloodScroll = 0x000005bb,
    NetherVendorBackground1 = 0x000005bc,
    NetherVendorBackground2 = 0x000005bd,
    NetherVendorBackground3 = 0x000005be,
    NetherVendorBackground4 = 0x000005bf,
    NetherVendorBackground5 = 0x000005c0,
    NetherVendorBackground6 = 0x000005c1,
    NetherVendorBackground7 = 0x000005c2,
    NetherVendorBackground8 = 0x000005c3,
    NetherVendorBackground9 = 0x000005c4,
    NetherVendorBackground10 = 0x000005c5,
    NetherVendorBackground11 = 0x000005c6,
    NetherVendorBackground12 = 0x000005c7,
    AnniversaryCake = 0x000005c8,
    AnniversaryPortal = 0x000005c9,
    VendorNPC = 0x000005ca,
    NetherBarsBackground1 = 0x000005cb,
    NetherBarsBackground2 = 0x000005cc,
    NetherBarsBackground3 = 0x000005cd,
    NetherBarsBackground4 = 0x000005ce,
    NetherCandleHoleBackground = 0x000005cf,
    NetherWallCandle = 0x000005d0,
    NetherConcrete = 0x000005d1,
    NetherConcreteA = 0x000005d2,
    NetherMetalBlock = 0x000005d3,
    NetherPots = 0x000005d4,
    NetherTileBackground3 = 0x000005d5,
    WeaponDarkSword = 0x000005d6,
    HatNetherMask = 0x000005d7,
    WeaponNetherAxe = 0x000005d8,
    BlueprintJetPackDark = 0x000005d9,
    JetPackDark = 0x000005da,
    FertilizerLarge = 0x000005db,
    ShardNether = 0x000005dc,
    ConsumableNetherSpark = 0x000005dd,
    DeepNetherExit = 0x000005de,
    MagicSpeechBubbleDark = 0x000005df,
    NetherSign = 0x000005e0,
    HatRoyale = 0x000005e1,
    NetherConcreteDirty = 0x000005e2,
    HatWinterCap = 0x000005e3,
    GlassesClearLight = 0x000005e4,
    NecklaceUntouchable = 0x000005e5,
    Bush1 = 0x000005e6,
    Bush2 = 0x000005e7,
    Bush3 = 0x000005e8,
    GrassTall = 0x000005e9,
    HangingLeaves = 0x000005ea,
    Rocks1 = 0x000005eb,
    Rocks2 = 0x000005ec,
    TreeStump = 0x000005ed,
    VegetationBlock1 = 0x000005ee,
    TreeTrunk1 = 0x000005ef,
    ConsumableCameraSelfie = 0x000005f0,
    ConsumableCameraWorld = 0x000005f1,
    ConsumableCameraValentinesDay = 0x000005f2,
    HubNeonText1A = 0x000005f3,
    HubNeonText1B = 0x000005f4,
    HubNeonText1C = 0x000005f5,
    HubNeonText1D = 0x000005f6,
    HubNeonText1E = 0x000005f7,
    HubNeonText1F = 0x000005f8,
    HubNeonText2A = 0x000005f9,
    HubNeonText2B = 0x000005fa,
    HubNeonText2C = 0x000005fb,
    HubNeonText2D = 0x000005fc,
    HubNeonText2E = 0x000005fd,
    HubNeonText2F = 0x000005fe,
    ScifiArrow = 0x000005ff,
    ScifiBackground3 = 0x00000600,
    ScifiBackground4 = 0x00000601,
    ScifiBlock1 = 0x00000602,
    ScifiBlock2 = 0x00000603,
    ScifiBlock3 = 0x00000604,
    ScifiBlock4 = 0x00000605,
    ScifiBlock5 = 0x00000606,
    ScifiInterface1 = 0x00000607,
    ScifiPillar1 = 0x00000608,
    ScifiWindow1 = 0x00000609,
    ScifiWindow2 = 0x0000060a,
    ScifiWindow3 = 0x0000060b,
    HubSignDailyBonus1 = 0x0000060c,
    HubSignDailyBonus2 = 0x0000060d,
    HubSignDailyBonus3 = 0x0000060e,
    HubSignDailyQuest1 = 0x0000060f,
    HubSignDailyQuest2 = 0x00000610,
    HubSignDailyQuest3 = 0x00000611,
    HubSignEvents1 = 0x00000612,
    HubSignEvents2 = 0x00000613,
    HubSignEvents3 = 0x00000614,
    HubSignHelp1 = 0x00000615,
    HubSignHelp2 = 0x00000616,
    HubSignHelp3 = 0x00000617,
    HubSignNether1 = 0x00000618,
    HubSignNether2 = 0x00000619,
    HubSignNether3 = 0x0000061a,
    HubSignWOTW1 = 0x0000061b,
    HubSignWOTW2 = 0x0000061c,
    HubSignWOTW3 = 0x0000061d,
    BoomBox = 0x0000061e,
    ConsumableValentinesDayPresent = 0x0000061f,
    InfoNPC = 0x00000620,
    ShoesHighheelsPink = 0x00000621,
    DressMaidPink = 0x00000622,
    HatBowtiePink = 0x00000623,
    GlovesWristbandPink = 0x00000624,
    EarRingPink = 0x00000625,
    HatTieraCandyQueen = 0x00000626,
    WeaponUmbrellaPink = 0x00000627,
    ShirtRainbow = 0x00000628,
    CapeLove = 0x00000629,
    MouthTeethCandy = 0x0000062a,
    BackhandItemHeartShield = 0x0000062b,
    BeardPink = 0x0000062c,
    MaskBubbleGum = 0x0000062d,
    MaskPacifierPink = 0x0000062e,
    MaskPacifierBlue = 0x0000062f,
    HairAfroPink = 0x00000630,
    ContactLensesPinkLove = 0x00000631,
    HairHarlequin = 0x00000632,
    FamiliarHeart1A = 0x00000633,
    FamiliarHeart2A = 0x00000634,
    FamiliarHeart2B = 0x00000635,
    WeaponDusterRainbow = 0x00000636,
    HatUnicornHornPink = 0x00000637,
    DressMaidBlue = 0x00000638,
    CookieBlock = 0x00000639,
    RosePink = 0x0000063a,
    CupidStatue = 0x0000063b,
    PortalWOTW = 0x0000063c,
    BubblegumMachine = 0x0000063d,
    DrippingChocolateBackground = 0x0000063e,
    NeonHeart = 0x0000063f,
    JellybeanPile = 0x00000640,
    BlueprintCapeLove = 0x00000641,
    GlassesVisorAchievement = 0x00000642,
    ShirtBaseballHeart = 0x00000643,
    Spotlight = 0x00000644,
    PWETerminal = 0x00000645,
    HubSignPWE1 = 0x00000646,
    HubSignPWE2 = 0x00000647,
    HubSignPWE3 = 0x00000648,
    SuitUnelias = 0x00000649,
    IcePlatform = 0x0000064a,
    GluePlatform = 0x0000064b,
    RedJelloPlatform = 0x0000064c,
    ConcretePlatform = 0x0000064d,
    MaskGas = 0x0000064e,
    CoatLeafBoi = 0x0000064f,
    BeardLeaf = 0x00000650,
    HairLeaf = 0x00000651,
    WeaponStaffLeaf = 0x00000652,
    ShirtHoodieGreen = 0x00000653,
    MaskTurtle = 0x00000654,
    ShoesTurtle = 0x00000655,
    SuitTurtle = 0x00000656,
    GlassesTintedGreen = 0x00000657,
    GlassesFunnyMan = 0x00000658,
    WeaponSwordGreen = 0x00000659,
    HatMushroom = 0x0000065a,
    SuitMushroom = 0x0000065b,
    FamiliarClover1A = 0x0000065c,
    FamiliarClover2A = 0x0000065d,
    HatHelmetGreen = 0x0000065e,
    HairIrishRed = 0x0000065f,
    WingsLeaf = 0x00000660,
    NeonOrangeBackground = 0x00000661,
    NeonGreenBackground = 0x00000662,
    NeonBlueBackground = 0x00000663,
    NeonVioletBackground = 0x00000664,
    BigTileBlue = 0x00000665,
    BigTileGrey = 0x00000666,
    BigTileBrown = 0x00000667,
    BigTileRed = 0x00000668,
    BigTileGreen = 0x00000669,
    DirtyWall1 = 0x0000066a,
    DirtyWall2 = 0x0000066b,
    GlowWireGreen = 0x0000066c,
    GlowWiresOrange = 0x0000066d,
    RuinSlantBackground = 0x0000066e,
    RuinSlantBrokenBackground = 0x0000066f,
    RuinTileBackground = 0x00000670,
    WoodenPlankBackground = 0x00000671,
    SpheresBlueBackground = 0x00000672,
    SpheresRedBackground = 0x00000673,
    SpheresGreyBackground = 0x00000674,
    SpheresGreenBackground = 0x00000675,
    WirefenceBackground = 0x00000676,
    BloodClawMarks = 0x00000677,
    BloodDrip = 0x00000678,
    BloodSplash = 0x00000679,
    CobraStatue = 0x0000067a,
    ConstructionBarricade = 0x0000067b,
    LeaningPlanks = 0x0000067c,
    MayanStatue = 0x0000067d,
    OldBrickPile = 0x0000067e,
    PotteryCracked = 0x0000067f,
    RuinsPillar = 0x00000680,
    ShovelInSand = 0x00000681,
    Shower = 0x00000682,
    TrafficCone = 0x00000683,
    TwistedWoodPillar = 0x00000684,
    BeigeBrick = 0x00000685,
    BlueBrick = 0x00000686,
    CoalBlock = 0x00000687,
    MetalSlant = 0x00000688,
    RedDarkBlock = 0x00000689,
    RuinSlant = 0x0000068a,
    RuinSlantPattern1 = 0x0000068b,
    RuinSlantPattern2 = 0x0000068c,
    RuinWall = 0x0000068d,
    RuinWallBroken = 0x0000068e,
    RuinWallMossy = 0x0000068f,
    ContactLensesWearyEyes = 0x00000690,
    FossilPicaPart1 = 0x00000691,
    FossilPicaPart2 = 0x00000692,
    FossilPicaPart3 = 0x00000693,
    FossilPicaPart4 = 0x00000694,
    ButterflyDaySmall = 0x00000695,
    ButterflyDayLarge = 0x00000696,
    ButterflyNightSmall = 0x00000697,
    ButterflyNightLarge = 0x00000698,
    ButterflyDayZebraLongtail = 0x00000699,
    ButterflyDayTigerLongtail = 0x0000069a,
    ButterflyDayEmpress = 0x0000069b,
    ButterflyDayOrangeTipper = 0x0000069c,
    ButterflyDayPinkHeart = 0x0000069d,
    ButterflyDayBlackLightning = 0x0000069e,
    ButterflyDayMonkeyBum = 0x0000069f,
    ButterflyDayGardenMaid = 0x000006a0,
    ButterflyDayNightSky = 0x000006a1,
    ButterflyDayBlueEmperor = 0x000006a2,
    ButterflyDayGrayGlassWing = 0x000006a3,
    ButterflyDayRedOrchae = 0x000006a4,
    ButterflyDayRainbowChitoria = 0x000006a5,
    ButterflyDayPearlHeath = 0x000006a6,
    ButterflyDaySmallTortoiseshell = 0x000006a7,
    ButterflyDaySmallBrimstone = 0x000006a8,
    ButterflyDayBlueEyedEmpress = 0x000006a9,
    ButterflyDayAdmiral = 0x000006aa,
    ButterflyDayBirchGlider = 0x000006ab,
    ButterflyDayBlueBottom = 0x000006ac,
    ButterflyDayPinkCheeks = 0x000006ad,
    ButterflyDayNeonStriper = 0x000006ae,
    ButterflyDayShadowLongtail = 0x000006af,
    ButterflyDayOrangeTigerTip = 0x000006b0,
    ButterflyDayApollon = 0x000006b1,
    ButterflyDayBlueIvory = 0x000006b2,
    ButterflyDayPaleLegate = 0x000006b3,
    ButterflyDayLiliumHaste = 0x000006b4,
    ButterflyDayLavaAglais = 0x000006b5,
    ButterflyDayPurpleHaze = 0x000006b6,
    ButterflyDayCrushPearl = 0x000006b7,
    ButterflyDayDirtyLemon = 0x000006b8,
    ButterflyDayAzureFlapper = 0x000006b9,
    ButterflyDayVioletColossus = 0x000006ba,
    ButterflyDayPinkDelight = 0x000006bb,
    ButterflyDayBlueKnight = 0x000006bc,
    ButterflyDayGreenDwarf = 0x000006bd,
    ButterflyDayYellowDwarf = 0x000006be,
    ButterflyDayBlueDwarf = 0x000006bf,
    ButterflyDayPaperKite = 0x000006c0,
    ButterflyNightDiaperMoth = 0x000006c1,
    ButterflyNightRoseMoth = 0x000006c2,
    ButterflyNightPoisonWing = 0x000006c3,
    ButterflyNightGreenNurse = 0x000006c4,
    ButterflyNightSalamanderMoth = 0x000006c5,
    ButterflyNightSirenHawkMoth = 0x000006c6,
    ButterflyNightPolillaGigante = 0x000006c7,
    ButterflyNightCamouflageMoth = 0x000006c8,
    ButterflyNightWhiteNun = 0x000006c9,
    ButterflyNightGreenNun = 0x000006ca,
    ButterflyNightBedstrawHawkMoth = 0x000006cb,
    ButterflyNightStudMoth = 0x000006cc,
    ButterflyNightBittyweeHawkMoth = 0x000006cd,
    ButterflyNightPeacockMoth = 0x000006ce,
    ButterflyNightBlueNight = 0x000006cf,
    ButterflyNightLemonMoth = 0x000006d0,
    ButterflyNightSkullHawkMoth = 0x000006d1,
    ButterflyNightWillowherbHawkMoth = 0x000006d2,
    ButterflyNightPeacockBehemoth = 0x000006d3,
    ButterflyNightRedDotMoth = 0x000006d4,
    ButterflyNightBurpMoth = 0x000006d5,
    ButterflyNightBloodMoth = 0x000006d6,
    ButterflyNightLavaMoth = 0x000006d7,
    ButterflyNightEmeraldHawkMoth = 0x000006d8,
    BackTurtleShell = 0x000006d9,
    HatWingDecorationRaven = 0x000006da,
    HubSignButterfly1 = 0x000006db,
    HubSignButterfly2 = 0x000006dc,
    HubSignButterfly3 = 0x000006dd,
    OrbCityBackground = 0x000006de,
    WingsButterfly = 0x000006df,
    FamiliarButterfly1A = 0x000006e0,
    ShirtHoodieNether = 0x000006e1,
    ContactLensesMulticolored = 0x000006e2,
    GlassesButterfly = 0x000006e3,
    ScarfButterfly = 0x000006e4,
    MaskRamSkull = 0x000006e5,
    Keg = 0x000006e6,
    GreenBrick = 0x000006e7,
    HatEggbasket = 0x000006e8,
    HatSpring = 0x000006e9,
    HatCatEarsBlue = 0x000006ea,
    HatBunnyEarsFloppyPink = 0x000006eb,
    MaskSuperBunnyBlue = 0x000006ec,
    MaskSuperBunnyPink = 0x000006ed,
    WeaponCarrot = 0x000006ee,
    HairSpikyJPopYellow = 0x000006ef,
    MouthTeethBunny = 0x000006f0,
    WeaponMachette = 0x000006f1,
    HairArtemis = 0x000006f2,
    HairPartzival = 0x000006f3,
    WillowCatkin = 0x000006f4,
    EasterChicks = 0x000006f5,
    PsychoBunny = 0x000006f6,
    SpringFlowers = 0x000006f7,
    Calendar13Fri = 0x000006f8,
    PicnicTable = 0x000006f9,
    ConsumableEasterEggPresent = 0x000006fa,
    EasterEggPrize1 = 0x000006fb,
    EasterEggPrize2 = 0x000006fc,
    EasterEggPrize3 = 0x000006fd,
    EasterEggPrize4 = 0x000006fe,
    EasterEggPrize5 = 0x000006ff,
    EasterEggPrize6 = 0x00000700,
    EasterEggPrize7 = 0x00000701,
    HatEasterRichboy = 0x00000702,
    ShoesEasterRichboy = 0x00000703,
    CoatEasterRichboy = 0x00000704,
    GlassesEasterRichboy = 0x00000705,
    WeaponCaneEasterRichboy = 0x00000706,
    NetherGroupPortal = 0x00000707,
    Moai = 0x00000708,
    HairSpikyJPopBlue = 0x00000709,
    HairSpikyJPopRed = 0x0000070a,
    HairSpikyJPopBlack = 0x0000070b,
    PantsEasterRichboy = 0x0000070c,
    WeaponEggHunterTribe = 0x0000070d,
    SkirtEggHunterTribe = 0x0000070e,
    TopEggHunterTribe = 0x0000070f,
    MaskEggHunterTribe = 0x00000710,
    HatPacifist = 0x00000711,
    JumpsuitBruceLee = 0x00000712,
    ShirtClassyBlack = 0x00000713,
    PantsClassyBlack = 0x00000714,
    ShoesClassyBlack = 0x00000715,
    ShirtPunk = 0x00000716,
    PantsPunk = 0x00000717,
    ShoesPunk = 0x00000718,
    HairPunkPurple = 0x00000719,
    EarringPunk = 0x0000071a,
    BeardPiercingPunk = 0x0000071b,
    PantsJeansBlue = 0x0000071c,
    ShirtJeanVest = 0x0000071d,
    ShirtConstructionVest = 0x0000071e,
    HatConstructionHelmet = 0x0000071f,
    DressClassyBlack = 0x00000720,
    ShirtSuspendersWhite = 0x00000721,
    ShirtMcFlyVest = 0x00000722,
    PantsBaggyOrange = 0x00000723,
    PantsDropping = 0x00000724,
    ShirtCollegeBlue = 0x00000725,
    ShirtCollegeRed = 0x00000726,
    HatRapperScarfWhite = 0x00000727,
    HatSkaterCapBlue = 0x00000728,
    HatPorkPieRed = 0x00000729,
    HatFlatCapWhite = 0x0000072a,
    HatCapWithScarfBlue = 0x0000072b,
    HairRapperBraids = 0x0000072c,
    NeckRapperGold = 0x0000072d,
    ShoesBasketballWhite = 0x0000072e,
    WeaponShovel = 0x0000072f,
    MaskBoxHead = 0x00000730,
    ShirtTopRapperBlack = 0x00000731,
    ACUnit = 0x00000732,
    CanopyBlue = 0x00000733,
    CanopyRed = 0x00000734,
    ConcreteElementDark1 = 0x00000735,
    ConcreteElementDark2 = 0x00000736,
    ConcreteElementDark3 = 0x00000737,
    ConcreteElementLight1 = 0x00000738,
    ConcreteElementLight2 = 0x00000739,
    ConcreteElementLight3 = 0x0000073a,
    DrainPipeDark = 0x0000073b,
    DrainPipeLight = 0x0000073c,
    EmergencyStairsGrey = 0x0000073d,
    EmergencyStairsRed = 0x0000073e,
    FuseBox = 0x0000073f,
    FuseBoxWall = 0x00000740,
    Graffiti1a = 0x00000741,
    Graffiti1b = 0x00000742,
    Graffiti1c = 0x00000743,
    Graffiti1d = 0x00000744,
    Graffiti1e = 0x00000745,
    Graffiti1f = 0x00000746,
    Graffiti2a = 0x00000747,
    Graffiti2b = 0x00000748,
    Graffiti2c = 0x00000749,
    Graffiti2d = 0x0000074a,
    Graffiti2e = 0x0000074b,
    Graffiti2f = 0x0000074c,
    Graffiti3a = 0x0000074d,
    Graffiti3b = 0x0000074e,
    Graffiti3c = 0x0000074f,
    Graffiti3d = 0x00000750,
    Graffiti4a = 0x00000751,
    Graffiti4b = 0x00000752,
    Graffiti4c = 0x00000753,
    Graffiti4d = 0x00000754,
    Graffiti4e = 0x00000755,
    Graffiti4f = 0x00000756,
    Graffiti5a = 0x00000757,
    Graffiti5b = 0x00000758,
    UrbanWoodenFence = 0x00000759,
    Graffiti6 = 0x0000075a,
    MetalBeamBlock = 0x0000075b,
    MetalBeamPlatform = 0x0000075c,
    MetalBeamsBackground = 0x0000075d,
    MetalElementBackgroundBlack1 = 0x0000075e,
    MetalElementBackgroundBlack2 = 0x0000075f,
    MetalElementBackgroundGrey1 = 0x00000760,
    MetalElementBackgroundGrey2 = 0x00000761,
    MetalElementBackgroundBrown1 = 0x00000762,
    MetalElementBackgroundBrown2 = 0x00000763,
    NeonSignIcecream = 0x00000764,
    NeonSignSoda = 0x00000765,
    OldTyres = 0x00000766,
    PavementDark = 0x00000767,
    PavementLight = 0x00000768,
    PhoneLinePole = 0x00000769,
    PipeBlock = 0x0000076a,
    ScaffoldBackground1 = 0x0000076b,
    ScaffoldBackground2 = 0x0000076c,
    SkyscraperWindow1 = 0x0000076d,
    SkyscraperWindow2 = 0x0000076e,
    SkyscraperWindow3 = 0x0000076f,
    SkyscraperWindow4 = 0x00000770,
    SewageDrain = 0x00000771,
    SewerPipeBlack = 0x00000772,
    SewerPipeRusty = 0x00000773,
    SignElectricity = 0x00000774,
    SignExclamation = 0x00000775,
    SignFalling = 0x00000776,
    StoreBackground1 = 0x00000777,
    StoreBackground2 = 0x00000778,
    StoreBackground3 = 0x00000779,
    StreetBench = 0x0000077a,
    StreetFence = 0x0000077b,
    TrafficLights = 0x0000077c,
    Truss = 0x0000077d,
    TVAntenna = 0x0000077e,
    UrbanArrowSign = 0x0000077f,
    UrbanPoster1 = 0x00000780,
    UrbanPoster2 = 0x00000781,
    RecyclerBasic = 0x00000782,
    Pinata = 0x00000783,
    Spraycan = 0x00000784,
    MaskStreetArtist = 0x00000785,
    ScarfStreetArtist = 0x00000786,
    PantsStreetArtist = 0x00000787,
    ShirtStreetArtist = 0x00000788,
    ShoesStreetArtist = 0x00000789,
    ShoesSloMo = 0x0000078a,
    HatFedoraWhite = 0x0000078b,
    HatFedoraPink = 0x0000078c,
    HatFedoraPeige = 0x0000078d,
    HatFedoraYellow = 0x0000078e,
    Glasses3D = 0x0000078f,
    ContactLensesRadioActive = 0x00000790,
    HatHazMat = 0x00000791,
    SuitHazMat = 0x00000792,
    Poop = 0x00000793,
    WeaponBaseballBat = 0x00000794,
    LabBackDoor1 = 0x00000795,
    LabBackDoor2 = 0x00000796,
    LabBackDoor3 = 0x00000797,
    LabBackDoor4 = 0x00000798,
    LabBackground1 = 0x00000799,
    LabBackground2 = 0x0000079a,
    LabBackground3 = 0x0000079b,
    LabBackground4 = 0x0000079c,
    LabFence = 0x0000079d,
    LabBlockBlue1 = 0x0000079e,
    LabBlockBlue2 = 0x0000079f,
    LabBlockGreen1 = 0x000007a0,
    LabBlockGreen2 = 0x000007a1,
    LabBlockGrey2 = 0x000007a2,
    LabComputer1 = 0x000007a3,
    LabComputer2 = 0x000007a4,
    LabElectricWireBlue = 0x000007a5,
    LabElectricWireLarge = 0x000007a6,
    LabElectricWireRed = 0x000007a7,
    LabEquipment1 = 0x000007a8,
    LabEquipment2 = 0x000007a9,
    LabEquipment3 = 0x000007aa,
    LabGreenCanister = 0x000007ab,
    LabGreenCanisterCube = 0x000007ac,
    LabGreenCanisterHoseCenter = 0x000007ad,
    LabGreenCanisterHoseLeft = 0x000007ae,
    LabGreenCanisterHoseRight = 0x000007af,
    LabHangingWires1 = 0x000007b0,
    LabHangingWires2 = 0x000007b1,
    LabHoseLarge = 0x000007b2,
    LabLightLine = 0x000007b3,
    LabLightRed = 0x000007b4,
    LabLightRound = 0x000007b5,
    LabMeter = 0x000007b6,
    LabPlatform = 0x000007b7,
    LabPoster1 = 0x000007b8,
    LabPoster2 = 0x000007b9,
    LabRobotArm1 = 0x000007ba,
    LabRobotArm2 = 0x000007bb,
    LabServer1 = 0x000007bc,
    LabSwitch1 = 0x000007bd,
    LabWallHole = 0x000007be,
    LabWhiteboard = 0x000007bf,
    LabWindow1 = 0x000007c0,
    LabWindow2 = 0x000007c1,
    LabWindow3 = 0x000007c2,
    LabWindow4 = 0x000007c3,
    LabRayMachine = 0x000007c4,
    MaskTopHeadHeroBlack = 0x000007c5,
    MaskTopHeadHeroBlue = 0x000007c6,
    MaskTopHeadHeroGreen = 0x000007c7,
    MaskTopHeadHeroRed = 0x000007c8,
    MaskTopHeadHeroPurple = 0x000007c9,
    LabEnterPortal = 0x000007ca,
    LabExitPortal = 0x000007cb,
    MaskEyesHeroBlack = 0x000007cc,
    MaskEyesHeroBlue = 0x000007cd,
    MaskEyesHeroGreen = 0x000007ce,
    MaskEyesHeroRed = 0x000007cf,
    MaskEyesHeroPurple = 0x000007d0,
    BluePortal = 0x000007d1,
    ConsumableBlueParticle = 0x000007d2,
    DeflectorSuper = 0x000007d3,
    ElectricTrap = 0x000007d4,
    LaserShooterTrap = 0x000007d5,
    LabPoisonTrap = 0x000007d6,
    LaserBeamTrap = 0x000007d7,
    GravityModifier = 0x000007d8,
    ShirtSuperHeroBlue = 0x000007d9,
    PantsSuperHeroBlue = 0x000007da,
    ShirtSuperHeroBlack = 0x000007db,
    PantsSuperHeroBlack = 0x000007dc,
    ShirtSuperHeroPurple = 0x000007dd,
    PantsSuperHeroPurple = 0x000007de,
    ShirtSuperHeroGreen = 0x000007df,
    PantsSuperHeroGreen = 0x000007e0,
    ShirtSuperHeroRed = 0x000007e1,
    PantsSuperHeroRed = 0x000007e2,
    GlovesSuperHeroRed = 0x000007e3,
    ShoesSuperHeroRed = 0x000007e4,
    GlovesSuperHeroWhite = 0x000007e5,
    ShoesSuperHeroWhite = 0x000007e6,
    ShoesSuperHeroPurple = 0x000007e7,
    ShoesSuperHeroGreen = 0x000007e8,
    MaskSuperHeroBlue = 0x000007e9,
    MaskSuperHeroRed = 0x000007ea,
    CapeSuperHeroPurple = 0x000007eb,
    CapeSuperHeroBlack = 0x000007ec,
    MaskSuperHeroKettle = 0x000007ed,
    MaskSuperHeroGreen = 0x000007ee,
    MaskSuperHeroBlack = 0x000007ef,
    EarsSuperHeroFox = 0x000007f0,
    TailSuperHeroFox = 0x000007f1,
    WeaponSuperHeroShieldGreen = 0x000007f2,
    ShirtSuperHeroineBlack = 0x000007f3,
    PantsSuperHeroineBlack = 0x000007f4,
    GlovesSuperHeroineWristBlack = 0x000007f5,
    ShirtLabCoat = 0x000007f6,
    ShoesSuperHeroineBlack = 0x000007f7,
    HairSuperHeroineBlack = 0x000007f8,
    HairSuperHeroGreen = 0x000007f9,
    GlassesSuperHeroVisorRed = 0x000007fa,
    WeaponShoutGun = 0x000007fb,
    ShoesBouncy = 0x000007fc,
    JetPackLongJump = 0x000007fd,
    LabBossBackground1 = 0x000007fe,
    LabBossBackground2 = 0x000007ff,
    LabBossBuilding1 = 0x00000800,
    LabBossBuilding2 = 0x00000801,
    LabFan = 0x00000802,
    LabHangarDoor1 = 0x00000803,
    LabHangarDoor2 = 0x00000804,
    LabHangarDoor3 = 0x00000805,
    LabHangarDoor4 = 0x00000806,
    LabHangarDoorEdges1 = 0x00000807,
    LabHangarDoorEdges2 = 0x00000808,
    LabHangarDoorEdges3 = 0x00000809,
    LabHangarDoorEdges4 = 0x0000080a,
    LabHangarDoorEdges5 = 0x0000080b,
    LabHangarDoorEdges6 = 0x0000080c,
    LabHangarDoorEdges7 = 0x0000080d,
    LabHangarDoorEdges8 = 0x0000080e,
    LabPortalEnterSign = 0x0000080f,
    LabPortalExitSign = 0x00000810,
    BattleBarrierLab = 0x00000811,
    LabGiftBox = 0x00000812,
    WeaponLaserGunSmall = 0x00000813,
    GlovesCrabHands = 0x00000814,
    WorldHologram = 0x00000815,
    SpotlightFloor = 0x00000816,
    CapeSuperHeroGenericBlue = 0x00000817,
    CapeSuperHeroGenericBlack = 0x00000818,
    CapeSuperHeroGenericGreen = 0x00000819,
    CapeSuperHeroGenericRed = 0x0000081a,
    CapeSuperHeroGenericPurple = 0x0000081b,
    NukeDecoration = 0x0000081c,
    MaskSuperHeroineBlack = 0x0000081d,
    SuperHeroPinballBumper = 0x0000081e,
    SuperHeroSpringBoard = 0x0000081f,
    SoilFadeBlockMedium = 0x00000820,
    SoilFadeBlockDark = 0x00000821,
    PantsHeroTightsBlack = 0x00000822,
    PantsHeroTightsBlue = 0x00000823,
    PantsHeroTightsRed = 0x00000824,
    PantsHeroTightsGreen = 0x00000825,
    PantsHeroTightsPurple = 0x00000826,
    QuantumSafe = 0x00000827,
    GlassesBlindfold = 0x00000828,
    HatHeadbandRed = 0x00000829,
    HatHeroHoodBlack = 0x0000082a,
    GlovesSuperHeroBlack = 0x0000082b,
    ShoesSuperHeroBlack = 0x0000082c,
    TailCatBlack = 0x0000082d,
    HatEarsCatBlack = 0x0000082e,
    WeaponCrowbar = 0x0000082f,
    SuitInvisibility = 0x00000830,
    PantsSummerShorts = 0x00000831,
    DressSummerRed = 0x00000832,
    HatSummerHiabi = 0x00000833,
    GlassesSummerRed = 0x00000834,
    ShirtSailorSweater = 0x00000835,
    HatSummerWide = 0x00000836,
    WeaponFish = 0x00000837,
    HatOctopus = 0x00000838,
    WeaponIceCream = 0x00000839,
    MaskScubagear = 0x0000083a,
    WingsFishfins = 0x0000083b,
    WeaponHarpoon = 0x0000083c,
    ShoesRollerblades = 0x0000083d,
    GoldenPopsicleStatue = 0x0000083e,
    WeaponSunHammer = 0x0000083f,
    NeckFloaterTurtle = 0x00000840,
    GiantClam = 0x00000841,
    HoneyCombBackground = 0x00000842,
    KettleGrill = 0x00000843,
    SandCastleCommon = 0x00000844,
    SlicedPineappleBlock = 0x00000845,
    Sunchair = 0x00000846,
    TikiTorch = 0x00000847,
    TurtleFloaterProp = 0x00000848,
    XtremeSpeaker = 0x00000849,
    WildBeeHive = 0x0000084a,
    SunUmbrellaCommon = 0x0000084b,
    FlowerArrangement = 0x0000084c,
    OrbBlueSkyBackground = 0x0000084d,
    FamiliarTurtle1A = 0x0000084e,
    FamiliarTurtle2A = 0x0000084f,
    FamiliarTurtle3A = 0x00000850,
    FamiliarSun1A = 0x00000851,
    FamiliarSun2A = 0x00000852,
    FamiliarSquid1A = 0x00000853,
    FamiliarSquid2A = 0x00000854,
    FamiliarSquid3A = 0x00000855,
    FamiliarSquid4A = 0x00000856,
    FamiliarSquid4B = 0x00000857,
    SurfStand = 0x00000858,
    TikiBar = 0x00000859,
    HatHelmetLords = 0x0000085a,
    GlassesScifiVisorBlack = 0x0000085b,
    WeaponGunLaserScifi = 0x0000085c,
    WeaponSwordSlayer = 0x0000085d,
    BlueprintWeaponGunAK47 = 0x0000085e,
    BlueprintGlassesScifiVisorBlack = 0x0000085f,
    SuitUnisexSwimsuit = 0x00000860,
    FavouriteWorldsProp = 0x00000861,
    DisplayBlock = 0x00000862,
    ShardGunmetal = 0x00000863,
    RuleBotWeapon = 0x00000864,
    HatHelmetVisorPWRBlack = 0x00000865,
    GlovesPWRBlack = 0x00000866,
    ShoesPWRBlack = 0x00000867,
    SuitPWRBlack = 0x00000868,
    HatFishFin = 0x00000869,
    Graffiti7a = 0x0000086a,
    Graffiti7b = 0x0000086b,
    Graffiti7c = 0x0000086c,
    Graffiti7d = 0x0000086d,
    Graffiti7e = 0x0000086e,
    Graffiti7f = 0x0000086f,
    DressFantasyRed = 0x00000870,
    ShoesFantasyRed = 0x00000871,
    BlueprintHatHelmetVisorPWRBlack = 0x00000872,
    BlueprintGlovesPWRBlack = 0x00000873,
    BlueprintShoesPWRBlack = 0x00000874,
    BlueprintSuitPWRBlack = 0x00000875,
    Mannequin = 0x00000876,
    CoatFantasyWoodElf = 0x00000877,
    PantsFantasyWoodElf = 0x00000878,
    ShoesFantasyWoodElf = 0x00000879,
    HairFantasyWoodElf = 0x0000087a,
    MaskFantasyWoodElf = 0x0000087b,
    WeaponSwordsDualWoodElf = 0x0000087c,
    CapeFantasyWoodElf = 0x0000087d,
    EarsFantasyElf = 0x0000087e,
    CoatFantasyHighElf = 0x0000087f,
    PantsFantasyHighElf = 0x00000880,
    ShoesFantasyHighElf = 0x00000881,
    HairFantasyHighElf = 0x00000882,
    HatFantasyHighElf = 0x00000883,
    CapeFantasyHighElf = 0x00000884,
    WeaponLanceHighElf = 0x00000885,
    HatHalo = 0x00000886,
    WingsGoldNBlack = 0x00000887,
    HatHelmetChaos = 0x00000888,
    ShirtArmorChaos = 0x00000889,
    PantsChaos = 0x0000088a,
    ShoesChaos = 0x0000088b,
    WeaponSwordChaos = 0x0000088c,
    WeaponSwordBlood = 0x0000088d,
    ShirtSuperHeroSirLaser = 0x0000088e,
    PantsSuperHeroSirLaser = 0x0000088f,
    ShoesSuperHeroSirLaser = 0x00000890,
    GlovesSuperHeroSirLaser = 0x00000891,
    ShirtSuperHeroGloomyClubber = 0x00000892,
    PantsSuperHeroGloomyClubber = 0x00000893,
    ShoesSuperHeroGloomyClubber = 0x00000894,
    BackSuperHeroGloomyDualSticks = 0x00000895,
    WeaponSuperHeroGloomyDualSticks = 0x00000896,
    MaskSuperHeroGloomyClubber = 0x00000897,
    BackhandItemFantasyHighElf = 0x00000898,
    CapeBerserkerPolar = 0x00000899,
    MaskHorseHeadUnicorn = 0x0000089a,
    DoorLevelVIP = 0x0000089b,
    DoorLevel = 0x0000089c,
    DoorVIP = 0x0000089d,
    HatchLevelVIP = 0x0000089e,
    HatchLevel = 0x0000089f,
    HatchVIP = 0x000008a0,
    SuitOnepiecePink = 0x000008a1,
    VIPNeonSign = 0x000008a2,
    StereosGreen = 0x000008a3,
    LockWorldNoob = 0x000008a4,
    HomeWorldEdgeBlock = 0x000008a5,
    VegetationBackground = 0x000008a6,
    FantasyBlueIndentBackground1 = 0x000008a7,
    FantasyBlueIndentBackground2 = 0x000008a8,
    FantasyBlueIndentBackground3 = 0x000008a9,
    FantasyBluePatternBackground1 = 0x000008aa,
    FantasyBluePatternBackground2 = 0x000008ab,
    FantasyBlueShinglesBackground = 0x000008ac,
    FantasyLightBrickBackground = 0x000008ad,
    FantasyLightTileBackground = 0x000008ae,
    FantasyLightWindow1 = 0x000008af,
    FantasyLightWindow2 = 0x000008b0,
    FantasyLightWindow3 = 0x000008b1,
    FantasyLightWindow4 = 0x000008b2,
    FantasyMetalBackground = 0x000008b3,
    FantasyPurpleBrickBackground = 0x000008b4,
    FantasyPurpleIndentBackground1 = 0x000008b5,
    FantasyPurpleIndentBackground2 = 0x000008b6,
    FantasyPurpleIndentBackground3 = 0x000008b7,
    FantasyPurpleTileBackground = 0x000008b8,
    FantasyPurpleWindow1 = 0x000008b9,
    FantasyPurpleWindow2 = 0x000008ba,
    FantasyPurpleWindow3 = 0x000008bb,
    FantasyPurpleWindow4 = 0x000008bc,
    FantasyDarkBlock1 = 0x000008bd,
    FantasyDarkBlock2 = 0x000008be,
    FantasyDarkBlock3 = 0x000008bf,
    FantasyLightBlock1 = 0x000008c0,
    FantasyLightBlock2 = 0x000008c1,
    FantasyLightBlock3 = 0x000008c2,
    FantasyLightBlock4 = 0x000008c3,
    FantasyMetalRingBlock = 0x000008c4,
    FantasyBlueLight = 0x000008c5,
    FantasyRedLight = 0x000008c6,
    FantasyCrateWooden = 0x000008c7,
    FantasyDarkBanner = 0x000008c8,
    FantasyDarkFenceTall = 0x000008c9,
    FantasyDarkPillar = 0x000008ca,
    FantasyDarkSign = 0x000008cb,
    FantasyDarkSupportBeam = 0x000008cc,
    FantasyLightBanner = 0x000008cd,
    FantasyLightFence = 0x000008ce,
    FantasyLightPillar = 0x000008cf,
    FantasyLightSign = 0x000008d0,
    FantasyLightSupportBeam = 0x000008d1,
    FantasyWell = 0x000008d2,
    HatHelmetBloodLord = 0x000008d3,
    ShirtBloodLord = 0x000008d4,
    PantsBloodLord = 0x000008d5,
    ShoesBloodLord = 0x000008d6,
    PantsFaun = 0x000008d7,
    BeardFaun = 0x000008d8,
    HatHornsFaun = 0x000008d9,
    NeckFaun = 0x000008da,
    EarsFaun = 0x000008db,
    TailFaun = 0x000008dc,
    CoatWarlock = 0x000008dd,
    StorageForUntradeables = 0x000008de,
    EyebrowsFaun = 0x000008df,
    EarsOrc = 0x000008e0,
    FantasyScrollTable = 0x000008e1,
    FantasySwordInStone = 0x000008e2,
    WeaponSwordExcalibur = 0x000008e3,
    LockWorldOutline = 0x000008e4,
    BeardMoustacheHandlebarBlack = 0x000008e5,
    HatJingasa = 0x000008e6,
    WeaponCrookStaff = 0x000008e7,
    CoatElfMage = 0x000008e8,
    HatHornsElk = 0x000008e9,
    HatHoodBloodLord = 0x000008ea,
    HatHornsTormentor = 0x000008eb,
    BeardHornsTormentor = 0x000008ec,
    TailTormentor = 0x000008ed,
    ContactLensesTormentor = 0x000008ee,
    HatHelmetPaladin = 0x000008ef,
    ShirtArmorPaladin = 0x000008f0,
    PantsPaladin = 0x000008f1,
    ShoesPaladin = 0x000008f2,
    WeaponMacePaladin = 0x000008f3,
    WingsTormentor = 0x000008f4,
    WeaponScytheWarlock = 0x000008f5,
    HatHoodWarlock = 0x000008f6,
    HatHoodElfMage = 0x000008f7,
    CapeChaos = 0x000008f8,
    BackhandItemChaosShield = 0x000008f9,
    OrangeJello = 0x000008fa,
    BlackJello = 0x000008fb,
    Firefly = 0x000008fc,
    FantasyLightWindow5 = 0x000008fd,
    FantasyLightWindow6 = 0x000008fe,
    PotionHealing = 0x000008ff,
    PotionDamageBlocks = 0x00000900,
    PotionDamageFighting = 0x00000901,
    PotionSpeechBubbleElf = 0x00000902,
    PotionWarpToExit = 0x00000903,
    PotionWarpToKey = 0x00000904,
    PotionInstantGrowth = 0x00000905,
    FantasyPlatformLight = 0x00000906,
    FantasyPlatformDark = 0x00000907,
    BeardOrcChin = 0x00000908,
    ShirtTopTribalOrc = 0x00000909,
    PantsSkirtTribalOrc = 0x0000090a,
    ShoesTribalOrc = 0x0000090b,
    HairTribalOrc = 0x0000090c,
    VegetationBlockBrown = 0x0000090d,
    VegetationBlockSilver = 0x0000090e,
    VegetationBackgroundBrown = 0x0000090f,
    VegetationBackgroundSilver = 0x00000910,
    TreeTrunkSilver = 0x00000911,
    FantasyThroneDark = 0x00000912,
    FantasyThroneLight = 0x00000913,
    FantasyDrippingSlime1 = 0x00000914,
    FantasyDrippingSlime2 = 0x00000915,
    PotionCureLycanthropy = 0x00000916,
    NetherSoul = 0x00000917,
    LabBolt = 0x00000918,
    WeaponOrcClub = 0x00000919,
    TutorialQuestNPC = 0x0000091a,
    WeaponSwordCalibur = 0x0000091b,
    RuleBotPotion = 0x0000091c,
    WeaponThrowableAxe = 0x0000091d,
    HairInfluencerTery = 0x0000091e,
    BeardInfluencerTery = 0x0000091f,
    PotionSpeechBubbleOrc = 0x00000920,
    ExtraDropSnail = 0x00000921,
    ExtraDropShinyPebble = 0x00000922,
    ExtraDropFeather = 0x00000923,
    OverallsPlainBlack = 0x00000924,
    OverallsSkeleton = 0x00000925,
    OldAltar = 0x00000926,
    Recall = 0x00000927,
    SlimeShooterTrap = 0x00000928,
    SpikeTrapHalloween = 0x00000929,
    UnholyGround = 0x0000092a,
    UnholyBackground = 0x0000092b,
    ShirtBlackbird = 0x0000092c,
    GlovesBlackbird = 0x0000092d,
    ShoesBlackbird = 0x0000092e,
    MaskBlackbird = 0x0000092f,
    CapeBlackbird = 0x00000930,
    ShirtStraightJacket = 0x00000931,
    MaskScarecrow = 0x00000932,
    MaskScream = 0x00000933,
    MaskFlaming = 0x00000934,
    WingsRaven = 0x00000935,
    JetPackLongJumpPumpkin = 0x00000936,
    WingsSkeleton = 0x00000937,
    MaskCrow = 0x00000938,
    WeaponGuitarCrow = 0x00000939,
    MaskHannibal = 0x0000093a,
    HatTopHatRocker = 0x0000093b,
    HairCrow = 0x0000093c,
    CoatCrow = 0x0000093d,
    PantsCrow = 0x0000093e,
    MaskDemonic = 0x0000093f,
    FamiliarBat1A = 0x00000940,
    WeaponGunGoldenEagle = 0x00000941,
    WeaponThrowableHammer = 0x00000942,
    FamiliarPoop1A = 0x00000943,
    WeaponSwordButcher = 0x00000944,
    WeaponInsultingBat = 0x00000945,
    WeaponFlyingCane = 0x00000946,
    CapePurpleHeroGlide = 0x00000947,
    WeaponMaceOfCorruption = 0x00000948,
    MaskTormentor = 0x00000949,
    WaterDarkRiver = 0x0000094a,
    FogDark = 0x0000094b,
    SwordThrone = 0x0000094c,
    HalloweenCandy = 0x0000094d,
    BurnedBackground = 0x0000094e,
    PantsBlackbird = 0x0000094f,
    ShirtArmorPumpkinBlackTower = 0x00000950,
    PantsPumpkinBlackTower = 0x00000951,
    MaskPumpkinBlackTower = 0x00000952,
    WeaponSwordPumpkinBlackTower = 0x00000953,
    BackhandItemShieldPumpkinBlackTower = 0x00000954,
    BloodyChest = 0x00000955,
    AntiqueChair = 0x00000956,
    ZombieTrapRed = 0x00000957,
    AntiqueTable = 0x00000958,
    PumpkinLanternBlack = 0x00000959,
    ShirtHoodiePurple = 0x0000095a,
    PantsSweatPurple = 0x0000095b,
    CoatRobecaster = 0x0000095c,
    OverallsMummy = 0x0000095d,
    TailWolf = 0x0000095e,
    SkullBlockGolden = 0x0000095f,
    BatAlbino = 0x00000960,
    TombStoneMarble = 0x00000961,
    HugeMetalFanRed = 0x00000962,
    SmallChestBlackGold = 0x00000963,
    SoilBlockDark = 0x00000964,
    SoilBlockGrey = 0x00000965,
    FishingRodBambooBasic = 0x00000966,
    FishingRodBambooFine = 0x00000967,
    FishingRodBambooSuperior = 0x00000968,
    FishingRodBambooFlawless = 0x00000969,
    FishingRodFiberglassBasic = 0x0000096a,
    FishingRodFiberglassFine = 0x0000096b,
    FishingRodFiberglassSuperior = 0x0000096c,
    FishingRodFiberglassFlawless = 0x0000096d,
    FishingRodCarbonFiberBasic = 0x0000096e,
    FishingRodCarbonFiberFine = 0x0000096f,
    FishingRodCarbonFiberSuperior = 0x00000970,
    FishingRodCarbonFiberFlawless = 0x00000971,
    FishingRodTitaniumBasic = 0x00000972,
    FishingRodTitaniumFine = 0x00000973,
    FishingRodTitaniumSuperior = 0x00000974,
    FishingRodTitaniumFlawless = 0x00000975,
    FishHerringTiny = 0x00000976,
    FishHerringSmall = 0x00000977,
    FishHerringMedium = 0x00000978,
    FishHerringLarge = 0x00000979,
    FishHerringHuge = 0x0000097a,
    FishKingfishTiny = 0x0000097b,
    FishKingfishSmall = 0x0000097c,
    FishKingfishMedium = 0x0000097d,
    FishKingfishLarge = 0x0000097e,
    FishKingfishHuge = 0x0000097f,
    FishButterflyfishTiny = 0x00000980,
    FishButterflyfishSmall = 0x00000981,
    FishButterflyfishMedium = 0x00000982,
    FishButterflyfishLarge = 0x00000983,
    FishButterflyfishHuge = 0x00000984,
    FishGoldfishTiny = 0x00000985,
    FishGoldfishSmall = 0x00000986,
    FishGoldfishMedium = 0x00000987,
    FishGoldfishLarge = 0x00000988,
    FishGoldfishHuge = 0x00000989,
    FishCarpTiny = 0x0000098a,
    FishCarpSmall = 0x0000098b,
    FishCarpMedium = 0x0000098c,
    FishCarpLarge = 0x0000098d,
    FishCarpHuge = 0x0000098e,
    FishHalibutTiny = 0x0000098f,
    FishHalibutSmall = 0x00000990,
    FishHalibutMedium = 0x00000991,
    FishHalibutLarge = 0x00000992,
    FishHalibutHuge = 0x00000993,
    FishSeaAnglerTiny = 0x00000994,
    FishSeaAnglerSmall = 0x00000995,
    FishSeaAnglerMedium = 0x00000996,
    FishSeaAnglerLarge = 0x00000997,
    FishSeaAnglerHuge = 0x00000998,
    FishTunaTiny = 0x00000999,
    FishTunaSmall = 0x0000099a,
    FishTunaMedium = 0x0000099b,
    FishTunaLarge = 0x0000099c,
    FishTunaHuge = 0x0000099d,
    LureWorm = 0x0000099e,
    LureBreadcrumb = 0x0000099f,
    LureSmallMinnowGreen = 0x000009a0,
    LureSmallMinnowPink = 0x000009a1,
    LureTungstenJigBlack = 0x000009a2,
    LureTungstenJigRed = 0x000009a3,
    LureSpoonGold = 0x000009a4,
    LureSpoonStripes = 0x000009a5,
    LureSpoonNeon = 0x000009a6,
    LureJigTwirltailPurple = 0x000009a7,
    LureJigTwirltailGreen = 0x000009a8,
    LureFlyYellow = 0x000009a9,
    LureFlyRed = 0x000009aa,
    LureJerkGreen = 0x000009ab,
    LureJerkRed = 0x000009ac,
    LureGoldenSpinner = 0x000009ad,
    LureGreenSpinner = 0x000009ae,
    LureLongMinnowSilver = 0x000009af,
    LureLongMinnowBlue = 0x000009b0,
    LureGlowstickGreen = 0x000009b1,
    LureGlowstickRed = 0x000009b2,
    FishingIngredientBottle = 0x000009b3,
    FishingIngredientBoot = 0x000009b4,
    FishingIngredientAnchor = 0x000009b5,
    FishingIngredientPropeller = 0x000009b6,
    FishingIngredientSeaShell = 0x000009b7,
    FishingIngredientWheel = 0x000009b8,
    FishingIngredientGlasses = 0x000009b9,
    FishingIngredientPearl = 0x000009ba,
    FishingIngredientRing = 0x000009bb,
    TrophyFishHerring = 0x000009bc,
    TrophyFishKingfish = 0x000009bd,
    TrophyFishButterflyfish = 0x000009be,
    TrophyFishGoldfish = 0x000009bf,
    TrophyFishCarp = 0x000009c0,
    TrophyFishHalibut = 0x000009c1,
    TrophyFishSeaAngler = 0x000009c2,
    TrophyFishTuna = 0x000009c3,
    TrophyFishingTournamentFirst = 0x000009c4,
    TrophyFishingTournamentSecond = 0x000009c5,
    TrophyFishingTournamentThird = 0x000009c6,
    FishingTackleStation = 0x000009c7,
    FishingRecycler = 0x000009c8,
    FishingGearStation = 0x000009c9,
    FishingRodUpgradeStation = 0x000009ca,
    CoatNetherWright = 0x000009cb,
    ShirtArmoredWalker = 0x000009cc,
    PantsArmoredWalker = 0x000009cd,
    ShoesArmoredWalker = 0x000009ce,
    HatHelmetArmoredWalker = 0x000009cf,
    WeaponSwordArmoredWalker = 0x000009d0,
    HatHelmetOldDiveSuit = 0x000009d1,
    OverallsOldDiveSuit = 0x000009d2,
    GlovesOldDiveSuit = 0x000009d3,
    ShoesOldDiveSuit = 0x000009d4,
    FishmongerBackground1 = 0x000009d5,
    FishmongerBackground2 = 0x000009d6,
    FishmongerBackground3 = 0x000009d7,
    FishmongerBackground4 = 0x000009d8,
    FishmongerBackground5 = 0x000009d9,
    FishmongerBackground6 = 0x000009da,
    FishmongerBackground7 = 0x000009db,
    FishmongerBackground8 = 0x000009dc,
    FishmongerBackground9 = 0x000009dd,
    FishTournamentBackground1 = 0x000009de,
    FishTournamentBackground2 = 0x000009df,
    FishTournamentBackground3 = 0x000009e0,
    FishTournamentBackground4 = 0x000009e1,
    FishTournamentBackground5 = 0x000009e2,
    FishTournamentBackground6 = 0x000009e3,
    FishTournamentBackground7 = 0x000009e4,
    FishTournamentBackground8 = 0x000009e5,
    FishTournamentBackground9 = 0x000009e6,
    FishingScoreBoard = 0x000009e7,
    GlovesArmoredWalker = 0x000009e8,
    FishFashionBackground1 = 0x000009e9,
    FishFashionBackground2 = 0x000009ea,
    FishFashionBackground3 = 0x000009eb,
    FishFashionBackground4 = 0x000009ec,
    FishFashionBackground5 = 0x000009ed,
    FishFashionBackground6 = 0x000009ee,
    FishFashionBackground7 = 0x000009ef,
    FishFashionBackground8 = 0x000009f0,
    FishFashionBackground9 = 0x000009f1,
    FishUpgradeBackground1 = 0x000009f2,
    FishUpgradeBackground2 = 0x000009f3,
    FishUpgradeBackground3 = 0x000009f4,
    FishUpgradeBackground4 = 0x000009f5,
    FishUpgradeBackground5 = 0x000009f6,
    FishUpgradeBackground6 = 0x000009f7,
    FishUpgradeBackground7 = 0x000009f8,
    FishUpgradeBackground8 = 0x000009f9,
    FishUpgradeBackground9 = 0x000009fa,
    RobeStaffCaster = 0x000009fb,
    HatFisherRainYellow = 0x000009fc,
    ShirtFisherRainYellow = 0x000009fd,
    PantsFisherWoodenLeg = 0x000009fe,
    BeardFisherSeadog = 0x000009ff,
    HatFisherRodman = 0x00000a00,
    ShirtFisherRodman = 0x00000a01,
    ShoesFisherRodmanSandals = 0x00000a02,
    BackhandItemFisherRodmanNet = 0x00000a03,
    BackFisherRodmanBasket = 0x00000a04,
    HatFisherProBlue = 0x00000a05,
    GlassesFisherProBlue = 0x00000a06,
    MaskFisherScarfProBlue = 0x00000a07,
    OverallsFisherProBlue = 0x00000a08,
    HatFisherBaitHatBlue = 0x00000a09,
    HatFisherBaitHatGreen = 0x00000a0a,
    ShirtFisherVestPeige = 0x00000a0b,
    ShirtFisherVestGreen = 0x00000a0c,
    HatFisherFishHead = 0x00000a0d,
    ShoesFisherFishes = 0x00000a0e,
    TailFisherWorm = 0x00000a0f,
    HatFisherSnufnomad = 0x00000a10,
    NeckFisherScarfSnufnomad = 0x00000a11,
    MaskFisherPipeBubble = 0x00000a12,
    MaskFisherWhistle = 0x00000a13,
    NeckFisherTalisman = 0x00000a14,
    TopEarRingFisherBait = 0x00000a15,
    PantsXMasCalendar = 0x00000a16,
    GlovesXMasCalendar = 0x00000a17,
    HatHoodXMasCalendar = 0x00000a18,
    ShoesXMasCalendar = 0x00000a19,
    HubSignFishing1 = 0x00000a1a,
    HubSignFishing2 = 0x00000a1b,
    HatLuckyCapRed = 0x00000a1c,
    BeardMoustacheStanLee = 0x00000a1d,
    GlassesStanLee = 0x00000a1e,
    PeoplesChoiceAward = 0x00000a1f,
    ShirtSuperheroTridentist = 0x00000a20,
    PantsSuperheroTridentist = 0x00000a21,
    GlovesSuperheroTridentist = 0x00000a22,
    ShoesSuperheroTridentist = 0x00000a23,
    WeaponSuperheroTridentist = 0x00000a24,
    MaskSuperheroTridentist = 0x00000a25,
    TeethSuperheroTridentist = 0x00000a26,
    OnepieceGingerbread = 0x00000a27,
    HatHollyWreath = 0x00000a28,
    HatAntlersReindeer = 0x00000a29,
    HatCrownFrostLord = 0x00000a2a,
    WeaponSceptreFrostLord = 0x00000a2b,
    WeaponHandBell = 0x00000a2c,
    HatXmasBeanieRed = 0x00000a2d,
    HatXmasBeanieGreen = 0x00000a2e,
    HatXMasTophat = 0x00000a2f,
    WingsWinter = 0x00000a30,
    FamiliarSnowperson1A = 0x00000a31,
    PotionSpeechBubbleSanta = 0x00000a32,
    RedCandle = 0x00000a33,
    DungeonDoorWhite = 0x00000a34,
    SoilFrosted = 0x00000a35,
    PennantWhite = 0x00000a36,
    WOTWWorldsProp = 0x00000a37,
    TrophyFishingTournamentFirstBaby = 0x00000a38,
    TrophyFishingTournamentSecondBaby = 0x00000a39,
    TrophyFishingTournamentThirdBaby = 0x00000a3a,
    TrophyFishingTournamentFirstFisherman = 0x00000a3b,
    TrophyFishingTournamentSecondFisherman = 0x00000a3c,
    TrophyFishingTournamentThirdFisherman = 0x00000a3d,
    AnniversaryCake2 = 0x00000a3e,
    AnniversaryRadio = 0x00000a3f,
    WeaponAnniversarySword = 0x00000a40,
    CapeSuperheroDaBomba = 0x00000a41,
    ShirtSuperheroDaBomba = 0x00000a42,
    PantsSuperheroDaBomba = 0x00000a43,
    GlovesSuperheroDaBomba = 0x00000a44,
    ShoesSuperheroDaBomba = 0x00000a45,
    MaskSuperheroDaBomba = 0x00000a46,
    MoustacheSuperheroDaBomba = 0x00000a47,
    FamiliarCoffeeCup1A = 0x00000a48,
    ShirtAugmented = 0x00000a49,
    PantsAugmented = 0x00000a4a,
    ShoesAugmented = 0x00000a4b,
    MaskAugmented = 0x00000a4c,
    HatAntennasAugmented = 0x00000a4d,
    GlassesMonocleAugmented = 0x00000a4e,
    HatHelmetGalacticChampion = 0x00000a4f,
    ShirtGalacticChampion = 0x00000a50,
    PantsGalacticChampion = 0x00000a51,
    ShoesGalacticChampion = 0x00000a52,
    WeaponSwordLaserClaymore = 0x00000a53,
    WeaponGunGalacticChampion = 0x00000a54,
    TailNanotech = 0x00000a55,
    PantsStellarScout = 0x00000a56,
    ShirtStellarScout = 0x00000a57,
    HatHelmetStellarScout = 0x00000a58,
    EarsHeadphonesScifi = 0x00000a59,
    BeardRavenous = 0x00000a5a,
    HairTentacles = 0x00000a5b,
    HatExtraEyes = 0x00000a5c,
    BeardTrunkNose = 0x00000a5d,
    WeaponDualWinterAxes = 0x00000a5e,
    HatWinterSeal = 0x00000a5f,
    WeaponSuperheroDaBomba = 0x00000a60,
    HatCrownFae = 0x00000a61,
    HatWeddingVeil = 0x00000a62,
    DressWedding = 0x00000a63,
    EarRingRuby = 0x00000a64,
    GloveRingRuby = 0x00000a65,
    HairPinkbowtieBlonde = 0x00000a66,
    WeaponBoquette = 0x00000a67,
    HairClassyBlack = 0x00000a68,
    ShirtTuxedo = 0x00000a69,
    PantsTuxedo = 0x00000a6a,
    ShoesTuxedo = 0x00000a6b,
    HairIcecream = 0x00000a6c,
    WeaponCandyFloss = 0x00000a6d,
    GlassesLovePatch = 0x00000a6e,
    WingsHeart = 0x00000a6f,
    HatHelmetVisorPWRPink = 0x00000a70,
    GlovesPWRPink = 0x00000a71,
    ShoesPWRPink = 0x00000a72,
    SuitPWRPink = 0x00000a73,
    BlueprintHatHelmetVisorPWRPink = 0x00000a74,
    BlueprintGlovesPWRPink = 0x00000a75,
    BlueprintShoesPWRPink = 0x00000a76,
    BlueprintSuitPWRPink = 0x00000a77,
    PinkBrick = 0x00000a78,
    HeartTrap = 0x00000a79,
    BaroqueBed = 0x00000a7a,
    CandySpikes = 0x00000a7b,
    Graffiti8a = 0x00000a7c,
    Graffiti8b = 0x00000a7d,
    Graffiti8c = 0x00000a7e,
    Graffiti8d = 0x00000a7f,
    Graffiti8e = 0x00000a80,
    Graffiti8f = 0x00000a81,
    Graffiti8g = 0x00000a82,
    Graffiti8h = 0x00000a83,
    Graffiti8i = 0x00000a84,
    HeartSign = 0x00000a85,
    HangingHearts = 0x00000a86,
    ConsumableMessageBottleEmpty = 0x00000a87,
    ConsumableMessageBottleNote = 0x00000a88,
    FossilDragonPart1 = 0x00000a89,
    FossilDragonPart2 = 0x00000a8a,
    FossilDragonPart3 = 0x00000a8b,
    FossilDragonPart4 = 0x00000a8c,
    FossilDragonPart5 = 0x00000a8d,
    FossilDragonPart6 = 0x00000a8e,
    FossilDragonPart7 = 0x00000a8f,
    HairBieberBrown = 0x00000a90,
    HairWitcher = 0x00000a91,
    HairBobRoss = 0x00000a92,
    HairJPopBlack = 0x00000a93,
    HairJPopBlonde = 0x00000a94,
    HairHighPonytailPurple = 0x00000a95,
    HairTentacious = 0x00000a96,
    HairPonytailBluePurple = 0x00000a97,
    HairOldtimer = 0x00000a98,
    HairSideyBlack2 = 0x00000a99,
    HairLovejoy = 0x00000a9a,
    PocketGamerAward = 0x00000a9b,
    HatSheriff = 0x00000a9c,
    HatHelmetLeaf = 0x00000a9d,
    ShirtArmorLeaf = 0x00000a9e,
    PantsLeaf = 0x00000a9f,
    ShoesLeaf = 0x00000aa0,
    BackhandItemShieldLeaf = 0x00000aa1,
    WeaponSwordClaymoreLeaf = 0x00000aa2,
    WeaponSwordRapierClover = 0x00000aa3,
    FamiliarStpatrickTreasure1A = 0x00000aa4,
    FamiliarStpatrickTreasure2A = 0x00000aa5,
    HatBowtieGreen = 0x00000aa6,
    EarEarringGreen = 0x00000aa7,
    NeckTieGreen = 0x00000aa8,
    HatBowlerPatrick = 0x00000aa9,
    SkirtKiltGreen = 0x00000aaa,
    WingsFaerie = 0x00000aab,
    DressFaerieGreen = 0x00000aac,
    WeaponPaintbrushGreen = 0x00000aad,
    ShirtSmokingJacketBlue = 0x00000aae,
    GemSoil = 0x00000aaf,
    CelticColumn = 0x00000ab0,
    FairyDust = 0x00000ab1,
    WeaponGlovesBoxing = 0x00000ab2,
    Graffiti9a = 0x00000ab3,
    Graffiti9b = 0x00000ab4,
    Graffiti9c = 0x00000ab5,
    Graffiti9d = 0x00000ab6,
    Graffiti9e = 0x00000ab7,
    Graffiti9f = 0x00000ab8,
    Graffiti9g = 0x00000ab9,
    Graffiti9h = 0x00000aba,
    Graffiti9i = 0x00000abb,
    TailPeafowl = 0x00000abc,
    MaskBunnynator = 0x00000abd,
    SuitBunnynator = 0x00000abe,
    ShoesBunnynator = 0x00000abf,
    GlovesBunnynator = 0x00000ac0,
    WeaponGunBunnynator = 0x00000ac1,
    MaskEggHunterTribe19 = 0x00000ac2,
    TailSuperheroRetributor = 0x00000ac3,
    ShirtSuperheroRetributor = 0x00000ac4,
    PantsSuperheroRetributor = 0x00000ac5,
    JetPackLongJumpRetributor = 0x00000ac6,
    MaskSuperheroRetributor = 0x00000ac7,
    WingsSuperheroBuzzkill = 0x00000ac8,
    ShirtSuperheroBuzzkill = 0x00000ac9,
    PantsSuperheroBuzzkill = 0x00000aca,
    ShoesSuperheroBuzzkill = 0x00000acb,
    MaskSuperheroBuzzkill = 0x00000acc,
    LabGreenCanisterHoseShort = 0x00000acd,
    TutorialSleepPod = 0x00000ace,
    TutorialSleepPodOpen = 0x00000acf,
    TutorialFloorCenter = 0x00000ad0,
    TutorialFloorRight = 0x00000ad1,
    TutorialFloorLeft = 0x00000ad2,
    TutorialCable = 0x00000ad3,
    HairSuperheroBuzzkill = 0x00000ad4,
    HieroglyphA03 = 0x00000ad5,
    HieroglyphA04 = 0x00000ad6,
    HieroglyphA05 = 0x00000ad7,
    HieroglyphA06 = 0x00000ad8,
    HieroglyphB03 = 0x00000ad9,
    HieroglyphB04 = 0x00000ada,
    HieroglyphB05 = 0x00000adb,
    HieroglyphB06 = 0x00000adc,
    HieroglyphB07 = 0x00000add,
    HieroglyphC01 = 0x00000ade,
    HieroglyphC02 = 0x00000adf,
    HieroglyphC03 = 0x00000ae0,
    HieroglyphC04 = 0x00000ae1,
    HieroglyphC05 = 0x00000ae2,
    HieroglyphC06 = 0x00000ae3,
    HieroglyphC07 = 0x00000ae4,
    HieroglyphC08 = 0x00000ae5,
    HieroglyphD01 = 0x00000ae6,
    HieroglyphD02 = 0x00000ae7,
    HieroglyphD03 = 0x00000ae8,
    HieroglyphD04 = 0x00000ae9,
    HieroglyphD05 = 0x00000aea,
    HieroglyphD06 = 0x00000aeb,
    HieroglyphD07 = 0x00000aec,
    HieroglyphD08 = 0x00000aed,
    HieroglyphE02 = 0x00000aee,
    HieroglyphE03 = 0x00000aef,
    HieroglyphE04 = 0x00000af0,
    HieroglyphE05 = 0x00000af1,
    HieroglyphE06 = 0x00000af2,
    HieroglyphE07 = 0x00000af3,
    HieroglyphF01 = 0x00000af4,
    HieroglyphF02 = 0x00000af5,
    HieroglyphF03 = 0x00000af6,
    HieroglyphF04 = 0x00000af7,
    HieroglyphF05 = 0x00000af8,
    HieroglyphF06 = 0x00000af9,
    HieroglyphF07 = 0x00000afa,
    HieroglyphF08 = 0x00000afb,
    HieroglyphG01 = 0x00000afc,
    HieroglyphG02 = 0x00000afd,
    HieroglyphG03 = 0x00000afe,
    HieroglyphG04 = 0x00000aff,
    HieroglyphG05 = 0x00000b00,
    HieroglyphG06 = 0x00000b01,
    HieroglyphG07 = 0x00000b02,
    HieroglyphG08 = 0x00000b03,
    HieroglyphH02 = 0x00000b04,
    HieroglyphH03 = 0x00000b05,
    HieroglyphH04 = 0x00000b06,
    HieroglyphH05 = 0x00000b07,
    HieroglyphH06 = 0x00000b08,
    HieroglyphH07 = 0x00000b09,
    HieroglyphI01 = 0x00000b0a,
    HieroglyphI02 = 0x00000b0b,
    HieroglyphI03 = 0x00000b0c,
    HieroglyphI04 = 0x00000b0d,
    HieroglyphI05 = 0x00000b0e,
    HieroglyphI06 = 0x00000b0f,
    HieroglyphI07 = 0x00000b10,
    HieroglyphI08 = 0x00000b11,
    HieroglyphJ01 = 0x00000b12,
    HieroglyphJ02 = 0x00000b13,
    HieroglyphJ03 = 0x00000b14,
    HieroglyphJ04 = 0x00000b15,
    HieroglyphJ05 = 0x00000b16,
    HieroglyphJ06 = 0x00000b17,
    HieroglyphJ07 = 0x00000b18,
    HieroglyphJ08 = 0x00000b19,
    HieroglyphK02 = 0x00000b1a,
    HieroglyphK03 = 0x00000b1b,
    HieroglyphK04 = 0x00000b1c,
    HieroglyphK05 = 0x00000b1d,
    HieroglyphK06 = 0x00000b1e,
    HieroglyphK07 = 0x00000b1f,
    HieroglyphL01 = 0x00000b20,
    HieroglyphL02 = 0x00000b21,
    HieroglyphL03 = 0x00000b22,
    HieroglyphL04 = 0x00000b23,
    HieroglyphL05 = 0x00000b24,
    HieroglyphL06 = 0x00000b25,
    HieroglyphL07 = 0x00000b26,
    HieroglyphL08 = 0x00000b27,
    HieroglyphM01 = 0x00000b28,
    HieroglyphM02 = 0x00000b29,
    HieroglyphM03 = 0x00000b2a,
    HieroglyphM04 = 0x00000b2b,
    HieroglyphM05 = 0x00000b2c,
    HieroglyphM06 = 0x00000b2d,
    HieroglyphM07 = 0x00000b2e,
    HieroglyphM08 = 0x00000b2f,
    HieroglyphN03 = 0x00000b30,
    HieroglyphN04 = 0x00000b31,
    HieroglyphN05 = 0x00000b32,
    HieroglyphN06 = 0x00000b33,
    HieroglyphO01 = 0x00000b34,
    HieroglyphO02 = 0x00000b35,
    HieroglyphO03 = 0x00000b36,
    HieroglyphO04 = 0x00000b37,
    HieroglyphO05 = 0x00000b38,
    HieroglyphO06 = 0x00000b39,
    HieroglyphO07 = 0x00000b3a,
    HieroglyphO08 = 0x00000b3b,
    HieroglyphP02 = 0x00000b3c,
    HieroglyphP03 = 0x00000b3d,
    HieroglyphP04 = 0x00000b3e,
    HieroglyphP05 = 0x00000b3f,
    HieroglyphP06 = 0x00000b40,
    HieroglyphP07 = 0x00000b41,
    HieroglyphQ02 = 0x00000b42,
    HieroglyphQ03 = 0x00000b43,
    HieroglyphQ04 = 0x00000b44,
    HieroglyphQ05 = 0x00000b45,
    HieroglyphQ06 = 0x00000b46,
    HieroglyphQ07 = 0x00000b47,
    HieroglyphBlank = 0x00000b48,
    WeaponSuperheroBuzzkill = 0x00000b49,
    WeaponGunEasterBazooka = 0x00000b4a,
    Graffiti10a = 0x00000b4b,
    Graffiti10b = 0x00000b4c,
    Graffiti10c = 0x00000b4d,
    Graffiti10d = 0x00000b4e,
    Graffiti10e = 0x00000b4f,
    Graffiti10f = 0x00000b50,
    Graffiti10g = 0x00000b51,
    Graffiti10h = 0x00000b52,
    Graffiti10i = 0x00000b53,
    WingsFaerieEaster = 0x00000b54,
    HatEasterFlowers = 0x00000b55,
    DressFaerieEaster = 0x00000b56,
    SuitBarrel = 0x00000b57,
    TutorialCablePortal = 0x00000b58,
    LabBackground1HitThrough = 0x00000b59,
    LabBackground4HitThrough = 0x00000b5a,
    HieroglyphBlender01 = 0x00000b5b,
    HieroglyphBlender02 = 0x00000b5c,
    HieroglyphBlender03 = 0x00000b5d,
    HieroglyphBlender04 = 0x00000b5e,
    HieroglyphBlender05 = 0x00000b5f,
    HieroglyphBlender06 = 0x00000b60,
    HieroglyphBlender07 = 0x00000b61,
    HieroglyphBlender08 = 0x00000b62,
    HieroglyphTextA01 = 0x00000b63,
    HieroglyphTextA02 = 0x00000b64,
    HieroglyphTextA03 = 0x00000b65,
    HieroglyphTextA04 = 0x00000b66,
    HieroglyphTextB01 = 0x00000b67,
    HieroglyphTextB02 = 0x00000b68,
    HieroglyphTextB03 = 0x00000b69,
    HieroglyphTextB04 = 0x00000b6a,
    DarknessStatueA01 = 0x00000b6b,
    DarknessStatueA02 = 0x00000b6c,
    DarknessStatueA03 = 0x00000b6d,
    DarknessStatueA04 = 0x00000b6e,
    DarknessStatueA05 = 0x00000b6f,
    DarknessStatueA06 = 0x00000b70,
    DarknessStatueA07 = 0x00000b71,
    DarknessStatueA08 = 0x00000b72,
    DarknessStatueA08A = 0x00000b73,
    DarknessStatueA09 = 0x00000b74,
    DarknessStatueA10 = 0x00000b75,
    DarknessStatueA11 = 0x00000b76,
    DarknessStatueA11A = 0x00000b77,
    DarknessStatueA11AB = 0x00000b78,
    DarknessStatueA11ABC = 0x00000b79,
    DarknessStatueA11AC = 0x00000b7a,
    DarknessStatueA11BC = 0x00000b7b,
    DarknessStatueA12 = 0x00000b7c,
    DarknessStatueB01 = 0x00000b7d,
    DarknessStatueB02 = 0x00000b7e,
    DarknessStatueB03 = 0x00000b7f,
    DarknessStatueB04 = 0x00000b80,
    DarknessStatueB05 = 0x00000b81,
    DarknessStatueB06 = 0x00000b82,
    DarknessStatueB07 = 0x00000b83,
    DarknessStatueB08 = 0x00000b84,
    DarknessStatueB09 = 0x00000b85,
    DarknessStatueB10 = 0x00000b86,
    DarknessStatueB11 = 0x00000b87,
    DarknessStatueB12 = 0x00000b88,
    LightStatueA01 = 0x00000b89,
    LightStatueA02 = 0x00000b8a,
    LightStatueA03 = 0x00000b8b,
    LightStatueA04 = 0x00000b8c,
    LightStatueA05 = 0x00000b8d,
    LightStatueA06 = 0x00000b8e,
    LightStatueA07 = 0x00000b8f,
    LightStatueA08 = 0x00000b90,
    LightStatueA08A = 0x00000b91,
    LightStatueA09 = 0x00000b92,
    LightStatueA10 = 0x00000b93,
    LightStatueA11 = 0x00000b94,
    LightStatueA11A = 0x00000b95,
    LightStatueA11AB = 0x00000b96,
    LightStatueA11ABC = 0x00000b97,
    LightStatueA11AC = 0x00000b98,
    LightStatueA11BC = 0x00000b99,
    LightStatueA12 = 0x00000b9a,
    LightStatueB01 = 0x00000b9b,
    LightStatueB02 = 0x00000b9c,
    LightStatueB03 = 0x00000b9d,
    LightStatueB04 = 0x00000b9e,
    LightStatueB05 = 0x00000b9f,
    LightStatueB06 = 0x00000ba0,
    LightStatueB07 = 0x00000ba1,
    LightStatueB08 = 0x00000ba2,
    LightStatueB09 = 0x00000ba3,
    LightStatueB10 = 0x00000ba4,
    LightStatueB11 = 0x00000ba5,
    LightStatueB12 = 0x00000ba6,
    DarknessEntrance = 0x00000ba7,
    LightEntrance = 0x00000ba8,
    BrokenComputer = 0x00000ba9,
    PantsBunny = 0x00000baa,
    GlovesSuperheroRetributor = 0x00000bab,
    StalactitesBrown = 0x00000bac,
    StalactitesGrey = 0x00000bad,
    StalagmitesBrown = 0x00000bae,
    StalagmitesGrey = 0x00000baf,
    RiftPortal = 0x00000bb0,
    AlienCrackedBlock = 0x00000bb1,
    AlienCraterBlock = 0x00000bb2,
    AlienCryptoniteBlock = 0x00000bb3,
    AlienFlowers = 0x00000bb4,
    AlienLightPlant = 0x00000bb5,
    AlienMushroom = 0x00000bb6,
    AlienPoisonPlant = 0x00000bb7,
    AlienPurpleBackground = 0x00000bb8,
    AlienRockBlock = 0x00000bb9,
    AlienBlockRuins1 = 0x00000bba,
    AlienBlockRuins2 = 0x00000bbb,
    AlienPillarRuins = 0x00000bbc,
    AlienSlime = 0x00000bbd,
    AlienSoilBlock = 0x00000bbe,
    AlienTentacleTrap = 0x00000bbf,
    AlienTree = 0x00000bc0,
    AlienArrowSign = 0x00000bc1,
    AlienBackgroundDark1 = 0x00000bc2,
    AlienBackgroundDark2 = 0x00000bc3,
    AlienBackgroundDark3 = 0x00000bc4,
    AlienBackgroundDark4 = 0x00000bc5,
    AlienBackgroundDark5 = 0x00000bc6,
    AlienBackgroundDark6 = 0x00000bc7,
    AlienBackgroundPurple1 = 0x00000bc8,
    AlienBackgroundPurple2 = 0x00000bc9,
    AlienBackgroundPurple3 = 0x00000bca,
    AlienBackgroundPurple4 = 0x00000bcb,
    AlienBackgroundPurple5 = 0x00000bcc,
    AlienBackgroundPurple6 = 0x00000bcd,
    AlienBlockBlue1 = 0x00000bce,
    AlienBlockBlue2 = 0x00000bcf,
    AlienBlockBlue3 = 0x00000bd0,
    AlienBlockBlue4 = 0x00000bd1,
    AlienBlockDark1 = 0x00000bd2,
    AlienBlockDark2 = 0x00000bd3,
    AlienBlockDark3 = 0x00000bd4,
    AlienBlockDark4 = 0x00000bd5,
    AlienChair = 0x00000bd6,
    AlienChest = 0x00000bd7,
    AlienColumn = 0x00000bd8,
    AlienComputer = 0x00000bd9,
    AlienDarkWindow = 0x00000bda,
    AlienPurpleWindow = 0x00000bdb,
    AlienElevator = 0x00000bdc,
    AlienLightGreen = 0x00000bdd,
    AlienLightPurple = 0x00000bde,
    AlienHangingLightGreen = 0x00000bdf,
    AlienHangingLightPurple = 0x00000be0,
    AlienInfoScreen = 0x00000be1,
    AlienLaserTrap = 0x00000be2,
    AlienLightPillar = 0x00000be3,
    AlienMine = 0x00000be4,
    AlienPipes = 0x00000be5,
    AlienPlatform = 0x00000be6,
    AlienPodBlue = 0x00000be7,
    AlienPodPurple = 0x00000be8,
    AlienSign = 0x00000be9,
    AlienTable = 0x00000bea,
    AlienTurret = 0x00000beb,
    AdTV = 0x00000bec,
    FamiliarLock1A = 0x00000bed,
    FamiliarLock2A = 0x00000bee,
    FamiliarLock3A = 0x00000bef,
    FamiliarLock4A = 0x00000bf0,
    FamiliarLock5A = 0x00000bf1,
    FamiliarLock6A = 0x00000bf2,
    FamiliarLock6B = 0x00000bf3,
    FamiliarLock6C = 0x00000bf4,
    FamiliarLock7A = 0x00000bf5,
    FamiliarGem1A = 0x00000bf6,
    FamiliarGem2A = 0x00000bf7,
    FamiliarGem3A = 0x00000bf8,
    FamiliarGem4A = 0x00000bf9,
    FamiliarGem5A = 0x00000bfa,
    FamiliarBlockSoil1A = 0x00000bfb,
    FamiliarBlockWood1A = 0x00000bfc,
    FamiliarBlockMarble1A = 0x00000bfd,
    FamiliarBlockSteel1A = 0x00000bfe,
    FamiliarBlockObsidian1A = 0x00000bff,
    FamiliarBlockMagicstuff1A = 0x00000c00,
    FamiliarBlockSand1A = 0x00000c01,
    FamiliarBlockGranite1A = 0x00000c02,
    FamiliarBlockWater1A = 0x00000c03,
    FamiliarBlockLava1A = 0x00000c04,
    BackDecorativeBackpack = 0x00000c05,
    HatEarsFoxySkin = 0x00000c06,
    NeckSpaceStrapsPurple = 0x00000c07,
    NeckSpaceStrapsGreen = 0x00000c08,
    MaskDeepOne = 0x00000c09,
    WingsMechanicalGolden = 0x00000c0a,
    AlienStonesBlock = 0x00000c0b,
    TailAlien = 0x00000c0c,
    GlovesRingYellow = 0x00000c0d,
    GlovesRingTurquoise = 0x00000c0e,
    GlovesRingRose = 0x00000c0f,
    ContactLensesAlien = 0x00000c10,
    BlueprintWingsMechanicalGolden = 0x00000c11,
    MessagingComputer = 0x00000c12,
    BlueprintWeaponSwordLaserClaymore = 0x00000c13,
    KukouriBlockBlack = 0x00000c14,
    Pinata2019 = 0x00000c15,
    HatSombrero2019 = 0x00000c16,
    SuitSuperheroHulkBlue = 0x00000c17,
    SuperHeroAltar = 0x00000c18,
    WeaponWiringTool = 0x00000c19,
    WiringTriggerSwitch = 0x00000c1a,
    WiringTriggerButton = 0x00000c1b,
    WiringTriggerLever = 0x00000c1c,
    WiringTriggerPressurePad = 0x00000c1d,
    WiringTriggerProximitySensor = 0x00000c1e,
    WiringLogicGateAND = 0x00000c1f,
    WiringLogicGateNAND = 0x00000c20,
    WiringLogicGateOR = 0x00000c21,
    WiringLogicGateNOR = 0x00000c22,
    WiringLogicGateXOR = 0x00000c23,
    WiringLogicGateXNOR = 0x00000c24,
    WiringLogicGateNOT = 0x00000c25,
    FireballTriggerTrap = 0x00000c26,
    OnOffLight = 0x00000c27,
    DisappearingBlock = 0x00000c28,
    WeatherMachine = 0x00000c29,
    HatFrog = 0x00000c2a,
    WeaponSunUmbrella = 0x00000c2b,
    GlassesSwimGoggles = 0x00000c2c,
    NeckFloaterCat = 0x00000c2d,
    DressHawaiian = 0x00000c2e,
    ShirtFakeMuscles = 0x00000c2f,
    PantsMermaid = 0x00000c30,
    NeckHawaiianFlowers = 0x00000c31,
    ShoesBeachSlippers = 0x00000c32,
    WeaponLifeguardFloater = 0x00000c33,
    BackSharkFin = 0x00000c34,
    SoapBubbleMachine = 0x00000c35,
    Outhouse = 0x00000c36,
    CampingTent = 0x00000c37,
    ColaFridge = 0x00000c38,
    WiringInput = 0x00000c39,
    WiringOutput = 0x00000c3a,
    WiringInputAndOutput = 0x00000c3b,
    WeaponTridentPoseidon = 0x00000c3c,
    HatCrownPoseidon = 0x00000c3d,
    CapePoseidon = 0x00000c3e,
    HatHavaiianFlower = 0x00000c3f,
    PantsShortsLifeguard = 0x00000c40,
    HatSummerTurquoise = 0x00000c41,
    WiringLogicGateRANDOMIZER = 0x00000c42,
    YoutubeAward = 0x00000c43,
    ConsumableEpicPWRStone = 0x00000c44,
    FlameConstantTrap = 0x00000c45,
    SpikeTriggerTrap = 0x00000c46,
    WiringLogicGateDELAYTIMER = 0x00000c47,
    WiringLogicGateSIGNALHOLDER = 0x00000c48,
    WiringLogicGateTIMER = 0x00000c49,
    WiringLogicGateSIGNALDIVIDER = 0x00000c4a,
    GreenRedLight = 0x00000c4b,
    WiringTriggerButtonScifi = 0x00000c4c,
    WiringTriggerPushButton = 0x00000c4d,
    WiringTriggerGroundLeverWooden = 0x00000c4e,
    WiringTriggerSwitchScifi = 0x00000c4f,
    WiringTriggerPowerSwitch = 0x00000c50,
    PoisonConstantTrap = 0x00000c51,
    TrafficLightBlock = 0x00000c52,
    HatHelmetIceHockey = 0x00000c53,
    TrapdoorWired = 0x00000c54,
    WarningLight = 0x00000c55,
    PalmTree = 0x00000c56,
    MaskTurtlesHeroTurquoise = 0x00000c57,
    MaskTurtlesHeroYellow = 0x00000c58,
    MaskTurtlesHeroPink = 0x00000c59,
    MaskTurtlesHeroOrange = 0x00000c5a,
    NeckHeroUtilityBeltTurquoise = 0x00000c5b,
    NeckHeroUtilityBeltYellow = 0x00000c5c,
    NeckHeroUtilityBeltPink = 0x00000c5d,
    NeckHeroUtilityBeltOrange = 0x00000c5e,
    WiringLogicGateTOGGLE = 0x00000c5f,
    WiringTriggerButtonStone = 0x00000c60,
    ShirtSailor = 0x00000c61,
    PantsSailor = 0x00000c62,
    HatScarfSailor = 0x00000c63,
    PantsWheelchair = 0x00000c64,
    SuitSuperheroHulkRed = 0x00000c65,
    SuitSuperheroHulkGreen = 0x00000c66,
    SuitSuperheroHulkBlack = 0x00000c67,
    SuitSuperheroHulkPink = 0x00000c68,
    IronBarsBackground = 0x00000c69,
    SailBottom = 0x00000c6a,
    SailMiddle = 0x00000c6b,
    SailTop = 0x00000c6c,
    ShipWall = 0x00000c6d,
    ShipWallEnforced = 0x00000c6e,
    ShipWallSupported = 0x00000c6f,
    StoneBrickWall = 0x00000c70,
    StoneBrickWallBroken = 0x00000c71,
    StoneBrickWallIndent1 = 0x00000c72,
    StoneBrickWallIndent2 = 0x00000c73,
    StoneBrickWallIndent3 = 0x00000c74,
    StoneBrickWallIndent4 = 0x00000c75,
    StoneBrickWallIndent5 = 0x00000c76,
    StoneBrickWallIndent6 = 0x00000c77,
    TimberWall = 0x00000c78,
    TimberWallSupported = 0x00000c79,
    TimberWallWindow = 0x00000c7a,
    DeadEyeBase = 0x00000c7b,
    ShipGunPort = 0x00000c7c,
    WoodenShipHull = 0x00000c7d,
    WoodenShipHullFramed = 0x00000c7e,
    WoodenShipHullNailed = 0x00000c7f,
    WoodenShipHullEnforced = 0x00000c80,
    CannonBalls = 0x00000c81,
    ChainDarkLarge = 0x00000c82,
    ChainDarkMedium = 0x00000c83,
    ChainDarkSmall = 0x00000c84,
    DeadEyes = 0x00000c85,
    GunnyBags = 0x00000c86,
    LongDinnerTable = 0x00000c87,
    OilLantern = 0x00000c88,
    PierSupportPole = 0x00000c89,
    PirateCannon = 0x00000c8a,
    PirateFlag = 0x00000c8b,
    Ratlines = 0x00000c8c,
    RopeFence = 0x00000c8d,
    RopeOnTheWall = 0x00000c8e,
    ShipBoom = 0x00000c8f,
    ShipCabinSupport = 0x00000c90,
    ShipMast = 0x00000c91,
    ShipPlatform = 0x00000c92,
    ShipRope = 0x00000c93,
    ShipWheel = 0x00000c94,
    ShipWoodenRailing = 0x00000c95,
    GreenParrot = 0x00000c96,
    TortureCage = 0x00000c97,
    WoodenBucket = 0x00000c98,
    WoodenCupboard = 0x00000c99,
    WoodenPier = 0x00000c9a,
    WoodenStool = 0x00000c9b,
    Barnacles = 0x00000c9c,
    CoralGorgonian = 0x00000c9d,
    CoralMontipora = 0x00000c9e,
    CoralTable = 0x00000c9f,
    CoralTube = 0x00000ca0,
    JellyfishBlue = 0x00000ca1,
    JellyfishElectric = 0x00000ca2,
    PufferFishTrap = 0x00000ca3,
    SeaGrass = 0x00000ca4,
    SeastarLarge = 0x00000ca5,
    SeastarSmall = 0x00000ca6,
    Seaweed = 0x00000ca7,
    SunkenAnchor = 0x00000ca8,
    SunkenDivingHelmet = 0x00000ca9,
    WaterFall = 0x00000caa,
    BloodFall = 0x00000cab,
    AcidFall = 0x00000cac,
    WaterDarkRiverFall = 0x00000cad,
    EarPirateRing = 0x00000cae,
    HairPirateDreadlocks = 0x00000caf,
    HatPrivateerRed = 0x00000cb0,
    HatPrivateerBlue = 0x00000cb1,
    HatPrivateerPurple = 0x00000cb2,
    GlassesPirateEyepatch = 0x00000cb3,
    BeardPirateBlackBeard = 0x00000cb4,
    HatBlackBeard = 0x00000cb5,
    CoatBlackBeard = 0x00000cb6,
    PantsBlackBeard = 0x00000cb7,
    ShoesBlackBeard = 0x00000cb8,
    DressColonialLady = 0x00000cb9,
    GlassesEyesmudge = 0x00000cba,
    HatBuccaneer = 0x00000cbb,
    ShirtBuccaneer = 0x00000cbc,
    PantsBuccaneer = 0x00000cbd,
    CoatNavalOfficer = 0x00000cbe,
    HairWigNavalOfficer = 0x00000cbf,
    HatNavalOfficer = 0x00000cc0,
    PantsNavalOfficer = 0x00000cc1,
    ShoesNavalOfficer = 0x00000cc2,
    CoatPirateCaptain = 0x00000cc3,
    HatPirateCaptain = 0x00000cc4,
    PantsPirateCaptain = 0x00000cc5,
    ShoesPirateCaptain = 0x00000cc6,
    ShirtPirateCaribbean = 0x00000cc7,
    PantsPirateCaribbean = 0x00000cc8,
    BeardPirateCaribbean = 0x00000cc9,
    WeaponSwordFalchion = 0x00000cca,
    WeaponSwordRapier = 0x00000ccb,
    WeaponSwordSabre = 0x00000ccc,
    WeaponAxeBoarding = 0x00000ccd,
    WeaponGunFlintlock = 0x00000cce,
    HatColonialLady = 0x00000ccf,
    FamiliarParrot1A = 0x00000cd0,
    FamiliarParrot2A = 0x00000cd1,
    FamiliarParrot3A = 0x00000cd2,
    FamiliarParrot4A = 0x00000cd3,
    ThinRope = 0x00000cd4,
    ShirtBirdTribe = 0x00000cd5,
    PantsBirdTribe = 0x00000cd6,
    MaskBirdTribe = 0x00000cd7,
    HairBirdTribe = 0x00000cd8,
    MaskPixelbot = 0x00000cd9,
    HatPixelJester = 0x00000cda,
    MaskPixelJester = 0x00000cdb,
    OverallsPixelJester = 0x00000cdc,
    ShoesPixelJester = 0x00000cdd,
    WeaponClubPixelJester = 0x00000cde,
    WeaponGoldenClaymore = 0x00000cdf,
    GlassesSilver = 0x00000ce0,
    CapeThousandDays = 0x00000ce1,
    MaskSnorkelGreen = 0x00000ce2,
    ShoesFlippersGreen = 0x00000ce3,
    SuitMannequin = 0x00000ce4,
    PantsWoodyTwoLegs = 0x00000ce5,
    WeaponStaffCaster = 0x00000ce6,
    ArmchairWhite = 0x00000ce7,
    BathtubGolden = 0x00000ce8,
    BedBlack = 0x00000ce9,
    ClassicPaintingLarge = 0x00000cea,
    GlassPlatform = 0x00000ceb,
    FireplaceGothic = 0x00000cec,
    LanternBlue = 0x00000ced,
    LanternRed = 0x00000cee,
    LanternGreen = 0x00000cef,
    MirrorOval = 0x00000cf0,
    MirrorRectangle = 0x00000cf1,
    Oil = 0x00000cf2,
    PunchingBag = 0x00000cf3,
    RockPillar = 0x00000cf4,
    SandWall = 0x00000cf5,
    SofaBrown = 0x00000cf6,
    Telescope = 0x00000cf7,
    TilePurple = 0x00000cf8,
    TileGlassRed = 0x00000cf9,
    TileGlassYellow = 0x00000cfa,
    TileGlassGreen = 0x00000cfb,
    TileGlassBlue = 0x00000cfc,
    TileGlassPurple = 0x00000cfd,
    TileGlassBlack = 0x00000cfe,
    TreeTrunkBlock = 0x00000cff,
    TreeTrunkWall = 0x00000d00,
    WallShelfWooden = 0x00000d01,
    WashingMachine = 0x00000d02,
    WaterClear = 0x00000d03,
    WaterClearFall = 0x00000d04,
    HatHelmetJigasa = 0x00000d05,
    HatHoodNinjaBlack = 0x00000d06,
    MaskSamuraiGolden = 0x00000d07,
    WeaponSwordNinjato = 0x00000d08,
    ShirtNinjaBlack = 0x00000d09,
    ShirtArmorKnight = 0x00000d0a,
    PantsArmorKnight = 0x00000d0b,
    HatHelmetArmorKnight = 0x00000d0c,
    WeaponSwordKnight = 0x00000d0d,
    BlueprintShirtArmorKnight = 0x00000d0e,
    BlueprintPantsArmorKnight = 0x00000d0f,
    BlueprintHatHelmetArmorKnight = 0x00000d10,
    BlueprintWeaponSwordKnight = 0x00000d11,
    WeaponSwordWooden = 0x00000d12,
    CapeAchievement120 = 0x00000d13,
    FishDumbFishTiny = 0x00000d14,
    FishDumbFishSmall = 0x00000d15,
    FishDumbFishMedium = 0x00000d16,
    FishDumbFishLarge = 0x00000d17,
    FishDumbFishHuge = 0x00000d18,
    LureRadioactiveWorm = 0x00000d19,
    FishAcidPufferTiny = 0x00000d1a,
    FishAcidPufferSmall = 0x00000d1b,
    FishAcidPufferMedium = 0x00000d1c,
    FishAcidPufferLarge = 0x00000d1d,
    FishAcidPufferHuge = 0x00000d1e,
    TrophyFishAcidPuffer = 0x00000d1f,
    TrophyFishDumbFish = 0x00000d20,
    ConsumableTreasureChestBronze = 0x00000d21,
    ConsumableTreasureChestSilver = 0x00000d22,
    ConsumableTreasureChestGolden = 0x00000d23,
    ConsumableGemPouchBronze = 0x00000d24,
    ConsumableGemPouchSilver = 0x00000d25,
    ConsumableGemPouchGolden = 0x00000d26,
    ConsumableTreasureKeyBronze = 0x00000d27,
    ConsumableTreasureKeySilver = 0x00000d28,
    ConsumableTreasureKeyGolden = 0x00000d29,
    OrbWeatherNone = 0x00000d2a,
    OrbWeatherHeavyRain = 0x00000d2b,
    OrbWeatherPixelTrail = 0x00000d2c,
    PixelBlockToledo = 0x00000d2d,
    PixelBlockCabSav = 0x00000d2e,
    PixelBlockTawnyPort = 0x00000d2f,
    PixelBlockCopperRust = 0x00000d30,
    PixelBlockChestnutRose = 0x00000d31,
    PixelBlockRajah = 0x00000d32,
    PixelBlockAlbescentWhite = 0x00000d33,
    PixelBlockStarship = 0x00000d34,
    PixelBlockApple = 0x00000d35,
    PixelBlockSalem = 0x00000d36,
    PixelBlockEden = 0x00000d37,
    PixelBlockBlack = 0x00000d38,
    PixelBlockShipGray = 0x00000d39,
    PixelBlockSaltBox = 0x00000d3a,
    PixelBlockAmethystSmoke = 0x00000d3b,
    PixelBlockMoonRaker = 0x00000d3c,
    PixelBlockWhite = 0x00000d3d,
    PixelBlockAnakiwa = 0x00000d3e,
    PixelBlockCyan = 0x00000d3f,
    PixelBlockScienceBlue = 0x00000d40,
    PixelBlockResolutionBlue = 0x00000d41,
    PixelBlockBlackRock = 0x00000d42,
    PixelBlockValhalla = 0x00000d43,
    PixelBlockSeance = 0x00000d44,
    PixelBlockBrilliantRose = 0x00000d45,
    PixelBlockClassicRose = 0x00000d46,
    PixelBlockSaffron = 0x00000d47,
    PixelBlockTango = 0x00000d48,
    PixelBlockRed = 0x00000d49,
    PixelBlockTamarillo = 0x00000d4a,
    PixelBlockDeluge = 0x00000d4b,
    PixelBlockAstronaut = 0x00000d4c,
    PixelBackgroundToledo = 0x00000d4d,
    PixelBackgroundCabSav = 0x00000d4e,
    PixelBackgroundTawnyPort = 0x00000d4f,
    PixelBackgroundCopperRust = 0x00000d50,
    PixelBackgroundChestnutRose = 0x00000d51,
    PixelBackgroundRajah = 0x00000d52,
    PixelBackgroundAlbescentWhite = 0x00000d53,
    PixelBackgroundStarship = 0x00000d54,
    PixelBackgroundApple = 0x00000d55,
    PixelBackgroundSalem = 0x00000d56,
    PixelBackgroundEden = 0x00000d57,
    PixelBackgroundBlack = 0x00000d58,
    PixelBackgroundShipGray = 0x00000d59,
    PixelBackgroundSaltBox = 0x00000d5a,
    PixelBackgroundAmethystSmoke = 0x00000d5b,
    PixelBackgroundMoonRaker = 0x00000d5c,
    PixelBackgroundWhite = 0x00000d5d,
    PixelBackgroundAnakiwa = 0x00000d5e,
    PixelBackgroundCyan = 0x00000d5f,
    PixelBackgroundScienceBlue = 0x00000d60,
    PixelBackgroundResolutionBlue = 0x00000d61,
    PixelBackgroundBlackRock = 0x00000d62,
    PixelBackgroundValhalla = 0x00000d63,
    PixelBackgroundSeance = 0x00000d64,
    PixelBackgroundBrilliantRose = 0x00000d65,
    PixelBackgroundClassicRose = 0x00000d66,
    PixelBackgroundSaffron = 0x00000d67,
    PixelBackgroundTango = 0x00000d68,
    PixelBackgroundRed = 0x00000d69,
    PixelBackgroundTamarillo = 0x00000d6a,
    PixelBackgroundDeluge = 0x00000d6b,
    PixelBackgroundAstronaut = 0x00000d6c,
    ColorOMat = 0x00000d6d,
    PortalPassword = 0x00000d6e,
    WeaponGunBazookaDubstep = 0x00000d6f,
    BlueprintWeaponGunBazookaDubstep = 0x00000d70,
    OilFall = 0x00000d71,
    ScreenshotForbidden = 0x00000d72,
    OrbWeatherSandStorm = 0x00000d73,
    OrbWeatherLightRain = 0x00000d74,
    OrbWeatherLightSnow = 0x00000d75,
    OrbWeatherSnowStorm = 0x00000d76,
    MaskTentacleshooter = 0x00000d77,
    GlovesFlameEnemy = 0x00000d78,
    EarsTiger = 0x00000d79,
    ExtraDropFragmentLight = 0x00000d7a,
    ExtraDropFragmentDark = 0x00000d7b,
    OrbWeatherDeepNether = 0x00000d7c,
    ShirtHoodieOrange = 0x00000d7d,
    ShoesLemmy = 0x00000d7e,
    PantsLemmy = 0x00000d7f,
    ShirtLemmy = 0x00000d80,
    Graffiti11a = 0x00000d81,
    Graffiti11b = 0x00000d82,
    Graffiti11c = 0x00000d83,
    Graffiti11d = 0x00000d84,
    Graffiti11e = 0x00000d85,
    Graffiti11f = 0x00000d86,
    Graffiti11g = 0x00000d87,
    Graffiti11h = 0x00000d88,
    Graffiti11i = 0x00000d89,
    ClanTotem = 0x00000d8a,
    HairPuffyYellow = 0x00000d8b,
    HairSpikyJPopGreen = 0x00000d8c,
    HairCynthia = 0x00000d8d,
    HairAfroAuburn = 0x00000d8e,
    HairEtika = 0x00000d8f,
    HairArchyBlack = 0x00000d90,
    HairPuffyPurple = 0x00000d91,
    HairDeVil = 0x00000d92,
    HairCurlyCurtainsPink = 0x00000d93,
    HairFringeSpikyBlue = 0x00000d94,
    HairLongRedBlack = 0x00000d95,
    HairFringeSpikyGreen = 0x00000d96,
    HairCarrotTop = 0x00000d97,
    HairKhaleesiBlonde = 0x00000d98,
    WingsDarkSprite = 0x00000d99,
    HatHaloBlood = 0x00000d9a,
    WeaponSpiritClaw = 0x00000d9b,
    MaskTaunter = 0x00000d9c,
    HatHelmetDemonic = 0x00000d9d,
    ContactLensesScreamingEyes = 0x00000d9e,
    MaskScaryFace = 0x00000d9f,
    TailTaunter = 0x00000da0,
    HatHornsTaunter = 0x00000da1,
    ShirtScaryGreenStripe = 0x00000da2,
    MaskGhoulFemale = 0x00000da3,
    HairFranksBride = 0x00000da4,
    SuitGhost = 0x00000da5,
    HatImmisCat = 0x00000da6,
    NecklaceSpectral = 0x00000da7,
    BlueprintNecklaceSpectral = 0x00000da8,
    HatCleaverThroughHead = 0x00000da9,
    HalloweenCannon = 0x00000daa,
    OrbWeatherHalloween = 0x00000dab,
    ClanQuestBot = 0x00000dac,
    OrbWeatherHalloweenTower = 0x00000dad,
    BlueprintSuitGhost = 0x00000dae,
    Cockroach = 0x00000daf,
    MaskHauntedMonkey = 0x00000db0,
    ShirtHauntedMonkey = 0x00000db1,
    PantsHauntedMonkey = 0x00000db2,
    TailHauntedMonkey = 0x00000db3,
    WeaponDualBananas = 0x00000db4,
    BlueprintWeaponSwordWolfBlade = 0x00000db5,
    WeaponSwordWolfBlade = 0x00000db6,
    BlueprintWeaponSwordFish = 0x00000db7,
    WeaponSwordFish = 0x00000db8,
    ShirtFrostBorn = 0x00000db9,
    PantsFrostBorn = 0x00000dba,
    ShoesFrostBorn = 0x00000dbb,
    HoodFrostBorn = 0x00000dbc,
    WeaponSwordFrostBorn = 0x00000dbd,
    BackhandItemShieldFrostBorn = 0x00000dbe,
    HatHelmetRacingSanta = 0x00000dbf,
    BeardSideburnsSanta = 0x00000dc0,
    HatWinterHat = 0x00000dc1,
    OverallsPenguin = 0x00000dc2,
    HatHoodPenguin = 0x00000dc3,
    BlueprintJetPackSnow = 0x00000dc4,
    JetPackSnow = 0x00000dc5,
    FamiliarOwlSnow1A = 0x00000dc6,
    BlueprintWeaponStaffSunrise = 0x00000dc7,
    WeaponStaffSunrise = 0x00000dc8,
    WingsCombo = 0x00000dc9,
    MaskFacePaintClanLight = 0x00000dca,
    MaskFacePaintClanDark = 0x00000dcb,
    ShirtHoodieClanLight = 0x00000dcc,
    ShirtHoodieClanDark = 0x00000dcd,
    WingsClanLight = 0x00000dce,
    WingsClanDark = 0x00000dcf,
    WeaponSwordClanLight = 0x00000dd0,
    WeaponSwordClanDark = 0x00000dd1,
    MaskGasClanLight = 0x00000dd2,
    MaskGasClanDark = 0x00000dd3,
    GlassesVisorClanLight = 0x00000dd4,
    GlassesVisorClanDark = 0x00000dd5,
    HatCrownClanLight = 0x00000dd6,
    HatCrownClanDark = 0x00000dd7,
    NecklaceClanLight = 0x00000dd8,
    NecklaceClanDark = 0x00000dd9,
    WeaponShieldClanLight = 0x00000dda,
    WeaponShieldClanDark = 0x00000ddb,
    FamiliarClanLight1A = 0x00000ddc,
    FamiliarClanDark1A = 0x00000ddd,
    ShirtFatSanta = 0x00000dde,
    GlovesWristbandsRed = 0x00000ddf,
    HatWoolyBlue = 0x00000de0,
    HatWoolyRed = 0x00000de1,
    HubSignClans1 = 0x00000de2,
    HubSignClans2 = 0x00000de3,
    HubSignClans3 = 0x00000de4,
    MaskKitsune = 0x00000de5,
    HatTophatSilly = 0x00000de6,
    DoorClan = 0x00000de7,
    Graffiti12a = 0x00000de8,
    Graffiti12b = 0x00000de9,
    Graffiti12c = 0x00000dea,
    Graffiti12d = 0x00000deb,
    Graffiti12e = 0x00000dec,
    Graffiti12f = 0x00000ded,
    Graffiti12g = 0x00000dee,
    Graffiti12h = 0x00000def,
    Graffiti12i = 0x00000df0,
    Graffiti13a = 0x00000df1,
    Graffiti13b = 0x00000df2,
    Graffiti13c = 0x00000df3,
    Graffiti13d = 0x00000df4,
    Graffiti13e = 0x00000df5,
    Graffiti13f = 0x00000df6,
    MaskFaceScarfRed = 0x00000df7,
    SafeBox = 0x00000df8,
    MaskFaceScarfGreen = 0x00000df9,
    WeaponGunIceRifle = 0x00000dfa,
    HatBaseballCapRed = 0x00000dfb,
    FamiliarLock7B = 0x00000dfc,
    HubSignBank1 = 0x00000dfd,
    HubSignBank2 = 0x00000dfe,
    HubSignBank3 = 0x00000dff,
    BankBackground1 = 0x00000e00,
    BankBackground2 = 0x00000e01,
    BankBackground3 = 0x00000e02,
    BankBackground4 = 0x00000e03,
    BankBackground5 = 0x00000e04,
    BankBackground6 = 0x00000e05,
    BankBackground7 = 0x00000e06,
    BankBackground8 = 0x00000e07,
    BankBackground9 = 0x00000e08,
    BankBackground10 = 0x00000e09,
    BankBackground11 = 0x00000e0a,
    ShardFrost = 0x00000e0b,
    LockBattleFaction = 0x00000e0c,
    BattleScoreBoardFaction = 0x00000e0d,
    CheckPointFactionDark = 0x00000e0e,
    CheckPointFactionLight = 0x00000e0f,
    PortalFactionDark = 0x00000e10,
    PortalFactionLight = 0x00000e11,
    DoorFactionDark = 0x00000e12,
    DoorFactionLight = 0x00000e13,
    DonationBox = 0x00000e14,
    GuestBook = 0x00000e15,
    LockWorldBattleFaction = 0x00000e16,
    HatChineseCapRed = 0x00000e17,
    WeaponSwordSabreChinese = 0x00000e18,
    AnniversaryCake3 = 0x00000e19,
    AnniversaryJukebox = 0x00000e1a,
    PaperLantern = 0x00000e1b,
    GoldenRatStatue = 0x00000e1c,
    BlueprintWeaponSwordHellhound = 0x00000e1d,
    WeaponSwordHellhound = 0x00000e1e,
    WeaponAxeClover = 0x00000e1f,
    HatPatricksHorned = 0x00000e20,
    HatEarsCatGreen = 0x00000e21,
    ShirtTartan = 0x00000e22,
    SkirtTartan = 0x00000e23,
    ShoesTartan = 0x00000e24,
    HatTartan = 0x00000e25,
    HairAfroGreen = 0x00000e26,
    SuitMorphsuitGreen = 0x00000e27,
    DecorativeRedFan = 0x00000e28,
    HatCrownRat = 0x00000e29,
    FireworksHuge2 = 0x00000e2a,
    CapeAdminMidnightWalkerTriple = 0x00000e2b,
    WiringTriggerPressurePadSecret = 0x00000e2c,
    DisappearingBlockSecret01 = 0x00000e2d,
    DisappearingBlockSecret02 = 0x00000e2e,
    DisappearingBlockSecret03 = 0x00000e2f,
    DarknessFactionLight = 0x00000e30,
    LightFactionLight = 0x00000e31,
    TimeFactionLight = 0x00000e32,
    PowerLift = 0x00000e33,
    TeslaSphereConstant = 0x00000e34,
    ShirtHoodieBlue = 0x00000e35,
    ShardFlame = 0x00000e36,
    DonationBoxValentines = 0x00000e37,
    ShirtPinkTuxedo = 0x00000e38,
    WeaponSwordHeartBreaker = 0x00000e39,
    ShirtGopnik = 0x00000e3a,
    PantsGopnik = 0x00000e3b,
    HatHeartAntennas = 0x00000e3c,
    ToffeeBlock = 0x00000e3d,
    DressWedding20 = 0x00000e3e,
    SofaRed = 0x00000e3f,
    CottonCandyPlatform = 0x00000e40,
    OrbWeatherHearts = 0x00000e41,
    ShirtHoodiePink = 0x00000e42,
    HeartLamp = 0x00000e43,
    CandyCanePlatform = 0x00000e44,
    BlueprintWeaponSwordBananasplit = 0x00000e45,
    WeaponSwordBananasplit = 0x00000e46,
    PantsSnake = 0x00000e47,
    Graffiti14a = 0x00000e48,
    Graffiti14b = 0x00000e49,
    Graffiti14c = 0x00000e4a,
    Graffiti14d = 0x00000e4b,
    Graffiti14e = 0x00000e4c,
    Graffiti14f = 0x00000e4d,
    Graffiti14g = 0x00000e4e,
    Graffiti14h = 0x00000e4f,
    Graffiti14i = 0x00000e50,
    Graffiti15a = 0x00000e51,
    Graffiti15b = 0x00000e52,
    Graffiti15c = 0x00000e53,
    Graffiti15d = 0x00000e54,
    Graffiti15e = 0x00000e55,
    Graffiti15f = 0x00000e56,
    Graffiti15g = 0x00000e57,
    Graffiti15h = 0x00000e58,
    Graffiti15i = 0x00000e59,
    ShirtPyjamasPink = 0x00000e5a,
    PantsPyjamasPink = 0x00000e5b,
    MaskOldTV = 0x00000e5c,
    LoreBot = 0x00000e5d,
    LoreSign = 0x00000e5e,
    WingsPegasus = 0x00000e5f,
    NecklaceWorm = 0x00000e60,
    FishPiranhaTiny = 0x00000e61,
    FishPiranhaSmall = 0x00000e62,
    FishPiranhaMedium = 0x00000e63,
    FishPiranhaLarge = 0x00000e64,
    FishPiranhaHuge = 0x00000e65,
    TrophyFishPiranha = 0x00000e66,
    WeaponGunPlasmaBazooka = 0x00000e67,
    ShirtSchoolUniMale = 0x00000e68,
    PantsSchoolUniMale = 0x00000e69,
    ShirtSchoolUniFemale = 0x00000e6a,
    SkirtSchoolUniFemale = 0x00000e6b,
    PixelBlockBalticSea = 0x00000e6c,
    PixelBlockBittersweet = 0x00000e6d,
    PixelBlockBracken = 0x00000e6e,
    PixelBlockCafeRoyale = 0x00000e6f,
    PixelBlockDarkTan = 0x00000e70,
    PixelBlockDodgerBlue = 0x00000e71,
    PixelBlockEndeavour = 0x00000e72,
    PixelBlockForestGreen = 0x00000e73,
    PixelBlockJapaneseLaurel = 0x00000e74,
    PixelBlockKorma = 0x00000e75,
    PixelBlockTuscany = 0x00000e76,
    PixelBackgroundBalticSea = 0x00000e77,
    PixelBackgroundBittersweet = 0x00000e78,
    PixelBackgroundBracken = 0x00000e79,
    PixelBackgroundCafeRoyale = 0x00000e7a,
    PixelBackgroundDarkTan = 0x00000e7b,
    PixelBackgroundDodgerBlue = 0x00000e7c,
    PixelBackgroundEndeavour = 0x00000e7d,
    PixelBackgroundForestGreen = 0x00000e7e,
    PixelBackgroundJapaneseLaurel = 0x00000e7f,
    PixelBackgroundKorma = 0x00000e80,
    PixelBackgroundTuscany = 0x00000e81,
    PixelPlatformToledo = 0x00000e82,
    PixelPlatformCabSav = 0x00000e83,
    PixelPlatformTawnyPort = 0x00000e84,
    PixelPlatformCopperRust = 0x00000e85,
    PixelPlatformChestnutRose = 0x00000e86,
    PixelPlatformRajah = 0x00000e87,
    PixelPlatformAlbescentWhite = 0x00000e88,
    PixelPlatformStarship = 0x00000e89,
    PixelPlatformApple = 0x00000e8a,
    PixelPlatformSalem = 0x00000e8b,
    PixelPlatformEden = 0x00000e8c,
    PixelPlatformBlack = 0x00000e8d,
    PixelPlatformShipGray = 0x00000e8e,
    PixelPlatformSaltBox = 0x00000e8f,
    PixelPlatformAmethystSmoke = 0x00000e90,
    PixelPlatformMoonRaker = 0x00000e91,
    PixelPlatformWhite = 0x00000e92,
    PixelPlatformAnakiwa = 0x00000e93,
    PixelPlatformCyan = 0x00000e94,
    PixelPlatformScienceBlue = 0x00000e95,
    PixelPlatformResolutionBlue = 0x00000e96,
    PixelPlatformBlackRock = 0x00000e97,
    PixelPlatformValhalla = 0x00000e98,
    PixelPlatformSeance = 0x00000e99,
    PixelPlatformBrilliantRose = 0x00000e9a,
    PixelPlatformClassicRose = 0x00000e9b,
    PixelPlatformSaffron = 0x00000e9c,
    PixelPlatformTango = 0x00000e9d,
    PixelPlatformRed = 0x00000e9e,
    PixelPlatformTamarillo = 0x00000e9f,
    PixelPlatformDeluge = 0x00000ea0,
    PixelPlatformAstronaut = 0x00000ea1,
    PixelPlatformBalticSea = 0x00000ea2,
    PixelPlatformBittersweet = 0x00000ea3,
    PixelPlatformBracken = 0x00000ea4,
    PixelPlatformCafeRoyale = 0x00000ea5,
    PixelPlatformDarkTan = 0x00000ea6,
    PixelPlatformDodgerBlue = 0x00000ea7,
    PixelPlatformEndeavour = 0x00000ea8,
    PixelPlatformForestGreen = 0x00000ea9,
    PixelPlatformJapaneseLaurel = 0x00000eaa,
    PixelPlatformKorma = 0x00000eab,
    PixelPlatformTuscany = 0x00000eac,
    BlueprintWeaponSwordMantel = 0x00000ead,
    WeaponSwordMantel = 0x00000eae,
    BlueprintWeaponAxeOutlander = 0x00000eaf,
    WeaponAxeOutlander = 0x00000eb0,
    WingsEmerald = 0x00000eb1,
    OverallsRobochick = 0x00000eb2,
    GlovesRobochick = 0x00000eb3,
    MaskRobochick = 0x00000eb4,
    WeaponGunTeslapistol = 0x00000eb5,
    BlueprintWeaponGunTeslapistol = 0x00000eb6,
    BlueprintWeaponSwordTentacle = 0x00000eb7,
    WeaponSwordTentacle = 0x00000eb8,
    PetDog = 0x00000eb9,
    ShirtTuxedoGreen = 0x00000eba,
    HatEarmuffsSilencer = 0x00000ebb,
    MaskLiarsNose = 0x00000ebc,
    MaskSurgicalWhite = 0x00000ebd,
    LureLuckyLure = 0x00000ebe,
    MaskEggHunterTribe20 = 0x00000ebf,
    WeaponEggHunterTribe20 = 0x00000ec0,
    EarRingGoldspeech = 0x00000ec1,
    FamiliarByteCoin1A = 0x00000ec2,
    ConsumableNetherPresent = 0x00000ec3,
    WeaponNetherKey = 0x00000ec4,
    WeaponDualNetherBlades = 0x00000ec5,
    PotionDamageFightingNetherMiniboss1 = 0x00000ec6,
    OverallsHotDog = 0x00000ec7,
    HatFoil = 0x00000ec8,
    HatHelmetVisorPWRYellow = 0x00000ec9,
    GlovesPWRYellow = 0x00000eca,
    ShoesPWRYellow = 0x00000ecb,
    SuitPWRYellow = 0x00000ecc,
    BlueprintHatHelmetVisorPWRYellow = 0x00000ecd,
    BlueprintGlovesPWRYellow = 0x00000ece,
    BlueprintShoesPWRYellow = 0x00000ecf,
    BlueprintSuitPWRYellow = 0x00000ed0,
    HatStrawberry = 0x00000ed1,
    HatCookingPot = 0x00000ed2,
    HatTrafficCone = 0x00000ed3,
    MaskBanditSkull = 0x00000ed4,
    MaskOwl = 0x00000ed5,
    MaskEarth = 0x00000ed6,
    MaskSynthwave = 0x00000ed7,
    HatAlienController = 0x00000ed8,
    SuitSuperheroHulkYellow = 0x00000ed9,
    HatCrab = 0x00000eda,
    HatHelmetLegionaryPlain = 0x00000edb,
    HatHelmetLegionaryOfficer = 0x00000edc,
    HatHelmetLegionaryGeneral = 0x00000edd,
    HatHelmetSpartan = 0x00000ede,
    ShoesLegionary = 0x00000edf,
    ShoesSpartan = 0x00000ee0,
    ShirtLegionaryPlain = 0x00000ee1,
    ShirtLegionaryOfficer = 0x00000ee2,
    ShirtSpartan = 0x00000ee3,
    TogaSenator = 0x00000ee4,
    HatCrownSenator = 0x00000ee5,
    HatHelmetGladiator = 0x00000ee6,
    PetCat = 0x00000ee7,
    PetSlime = 0x00000ee8,
    GlovesSpartanWristGuards = 0x00000ee9,
    DressGreek = 0x00000eea,
    SuitSleevlesRed = 0x00000eeb,
    HatSombrero2020 = 0x00000eec,
    Pinata2020 = 0x00000eed,
    VirtualPetDog = 0x00000eee,
    VirtualPetCat = 0x00000eef,
    VirtualPetSlime = 0x00000ef0,
    DressWaterfall = 0x00000ef1,
    HatIceCream = 0x00000ef2,
    GlassesSunRetrospectacular = 0x00000ef3,
    NeckFloaterDoughnut = 0x00000ef4,
    WeaponVihta = 0x00000ef5,
    WingsWatermelon = 0x00000ef6,
    WeaponStaffStarfish = 0x00000ef7,
    PetShopBackground1 = 0x00000ef8,
    PetShopBackground2 = 0x00000ef9,
    PetShopBackground3 = 0x00000efa,
    PetShopBackground4 = 0x00000efb,
    PetShopBackground5 = 0x00000efc,
    PetShopBackground6 = 0x00000efd,
    PetShopBackground7 = 0x00000efe,
    PetShopBackground8 = 0x00000eff,
    PetShopBackground9 = 0x00000f00,
    PetShopBackground10 = 0x00000f01,
    PetShopBackground11 = 0x00000f02,
    PetShopBackground12 = 0x00000f03,
    PetShopBackground13 = 0x00000f04,
    PetShopBackground14 = 0x00000f05,
    PetShopBackground15 = 0x00000f06,
    OverallsBanana = 0x00000f07,
    RobesLight = 0x00000f08,
    HubSignPetShop1 = 0x00000f09,
    HubSignPetShop2 = 0x00000f0a,
    HubSignPetShop3 = 0x00000f0b,
    HubSignPetShop4 = 0x00000f0c,
    HubSignPetShop5 = 0x00000f0d,
    HubSignPetShop6 = 0x00000f0e,
    PetFoodDogBasic = 0x00000f0f,
    PetFoodDogPremium = 0x00000f10,
    PetFoodCatBasic = 0x00000f11,
    PetFoodCatPremium = 0x00000f12,
    PetFoodSlimeBasic = 0x00000f13,
    PetFoodSlimePremium = 0x00000f14,
    PetMedicineBasic = 0x00000f15,
    PetMedicinePremium = 0x00000f16,
    FamiliarTeddy1A = 0x00000f17,
    FamiliarTeddy2A = 0x00000f18,
    FamiliarTeddy3A = 0x00000f19,
    HatHoodLight = 0x00000f1a,
    HatHelmetSpace = 0x00000f1b,
    ShoesSpace = 0x00000f1c,
    GlowesSpace = 0x00000f1d,
    OverallsSpace = 0x00000f1e,
    HatHelmetLight = 0x00000f1f,
    ShirtArmorLight = 0x00000f20,
    PantsArmorLight = 0x00000f21,
    ShoesLight = 0x00000f22,
    HatHelmetHercules = 0x00000f23,
    ShirtArmorHercules = 0x00000f24,
    WeaponClubHercules = 0x00000f25,
    WeaponSpearRoman = 0x00000f26,
    WeaponSwordSpartan = 0x00000f27,
    WeaponSwordRoman = 0x00000f28,
    BackHandShieldRoman = 0x00000f29,
    BackHandShieldSpartan = 0x00000f2a,
    WiringTriggerPressurePadCustom = 0x00000f2b,
    CeilingLampLight = 0x00000f2c,
    CeilingLampDark = 0x00000f2d,
    WiringTriggerPuzzleLoreLight = 0x00000f2e,
    WiringTriggerPuzzleLoreDark = 0x00000f2f,
    FamiliarCrown1A = 0x00000f30,
    BubblegumMachinePink = 0x00000f31,
    ConsumableBubblegumTokenBronze = 0x00000f32,
    ConsumableBubblegumTokenSilver = 0x00000f33,
    ConsumableBubblegumTokenGold = 0x00000f34,
    WeaponPopsicle = 0x00000f35,
    HatHaloSpectral = 0x00000f36,
    JetPackSpectral = 0x00000f37,
    WingsSpectral = 0x00000f38,
    ContactLensesSpectral = 0x00000f39,
    NecklaceRainbow = 0x00000f3a,
    GlassesVisorSpectral = 0x00000f3b,
    WeaponSwordSpectral = 0x00000f3c,
    WeaponGunSpectral = 0x00000f3d,
    HairSpectral = 0x00000f3e,
    BlueprintWeaponSwordPiranha = 0x00000f3f,
    WeaponSwordPiranha = 0x00000f40,
    MetalBackgroundSpecial = 0x00000f41,
    BackgroundCryptic01 = 0x00000f42,
    BackgroundCryptic02 = 0x00000f43,
    BackgroundCryptic03 = 0x00000f44,
    BackgroundCryptic04 = 0x00000f45,
    BackgroundCryptic05 = 0x00000f46,
    BackgroundCryptic06 = 0x00000f47,
    BlockFaction1 = 0x00000f48,
    BlockFaction2 = 0x00000f49,
    HairDreadlocksBlue = 0x00000f4a,
    ShirtBeachBelly = 0x00000f4b,
    HatBeach = 0x00000f4c,
    SkirtTowel = 0x00000f4d,
    PantsShortsGreen = 0x00000f4e,
    WeaponBoomerang = 0x00000f4f,
    HatSteam3yo = 0x00000f50,
    OrbLightingNone = 0x00000f51,
    OrbLightingDark = 0x00000f52,
    TempleBrick1 = 0x00000f53,
    TempleBrick2 = 0x00000f54,
    TempleBrick3 = 0x00000f55,
    TempleBlock = 0x00000f56,
    TempleBlockDecorative1 = 0x00000f57,
    TempleBlockDecorative2 = 0x00000f58,
    TempleBrickBackground = 0x00000f59,
    TempleIndentTopBackground = 0x00000f5a,
    TempleIndentMiddleBackground = 0x00000f5b,
    TempleIndentBottomBackground = 0x00000f5c,
    TempleStripesBackground = 0x00000f5d,
    TemplePlainBackground = 0x00000f5e,
    TemplePatternBackground = 0x00000f5f,
    TemplePlainDirtyBackground = 0x00000f60,
    TempleDecorationTopLeftBackground = 0x00000f61,
    TempleDecorationTopRightBackground = 0x00000f62,
    TempleDecorationBottomLeftBackground = 0x00000f63,
    TempleDecorationBottomRightBackground = 0x00000f64,
    TempleDecorationTopBackground = 0x00000f65,
    TempleDecorationBottomBackground = 0x00000f66,
    TempleDecorationLeftBackground = 0x00000f67,
    TempleDecorationRightBackground = 0x00000f68,
    TempleDecorationStoneBackground = 0x00000f69,
    TempleDarkPlainBackground = 0x00000f6a,
    TempleDarkStipesBackground = 0x00000f6b,
    TempleDarkDecorationBackground = 0x00000f6c,
    TemplePillar = 0x00000f6d,
    TempleRocks = 0x00000f6e,
    TempleWoodenPlatform = 0x00000f6f,
    TempleStonePlatform = 0x00000f70,
    TempleStoneTable = 0x00000f71,
    TempleBench = 0x00000f72,
    TempleWoodenSupport = 0x00000f73,
    TempleBrazier = 0x00000f74,
    TempleHangingBrazier = 0x00000f75,
    TempleRoofLeft = 0x00000f76,
    TempleRoofRight = 0x00000f77,
    IvyPlant = 0x00000f78,
    SaunaStove = 0x00000f79,
    SoapBubbleMachineFrog = 0x00000f7a,
    ArtificialSun = 0x00000f7b,
    PortalCryptic = 0x00000f7c,
    PortalPixelMines = 0x00000f7d,
    PortalMineExit = 0x00000f7e,
    MiningCartClaim = 0x00000f7f,
    MiningTombStone = 0x00000f80,
    ConsumableMineKeyLevel2 = 0x00000f81,
    ConsumableMineKeyLevel3 = 0x00000f82,
    ConsumableMineKeyLevel4 = 0x00000f83,
    ConsumableMineKeyLevel5 = 0x00000f84,
    OrbLightingMining = 0x00000f85,
    MiningLightCrystalSmall = 0x00000f86,
    MiningLightCrystalMedium = 0x00000f87,
    MiningLightCrystalLarge = 0x00000f88,
    MiningTimeCrystalSmall = 0x00000f89,
    MiningTimeCrystalMedium = 0x00000f8a,
    MiningTimeCrystalLarge = 0x00000f8b,
    MiningSoil1 = 0x00000f8c,
    MiningSoil2 = 0x00000f8d,
    MiningSoil3 = 0x00000f8e,
    MiningSoil4 = 0x00000f8f,
    MiningSoil5 = 0x00000f90,
    MiningRockHard2 = 0x00000f91,
    MiningRockHard3 = 0x00000f92,
    MiningLava1 = 0x00000f93,
    MiningBedrock3 = 0x00000f94,
    MiningRockSoft1 = 0x00000f95,
    MiningBedrock2 = 0x00000f96,
    MiningRockMedium1 = 0x00000f97,
    MiningRockHard1 = 0x00000f98,
    MiningBedrock1 = 0x00000f99,
    MiningWoodBlock1 = 0x00000f9a,
    MiningGemStoneDiamond = 0x00000f9b,
    MiningGemStoneEmerald = 0x00000f9c,
    MiningGemStoneMoonStone = 0x00000f9d,
    MiningGemStoneOpal = 0x00000f9e,
    MiningGemStoneRuby = 0x00000f9f,
    MiningGemStoneSapphire = 0x00000fa0,
    MiningGemStoneSunStone = 0x00000fa1,
    MiningGemStoneTopaz = 0x00000fa2,
    MiningGemStoneZircon = 0x00000fa3,
    MiningBackground1 = 0x00000fa4,
    MiningBackground2 = 0x00000fa5,
    MiningBackground3 = 0x00000fa6,
    MiningBackground4 = 0x00000fa7,
    MiningBackground5 = 0x00000fa8,
    MiningBackground6 = 0x00000fa9,
    MiningBackground7 = 0x00000faa,
    MiningBackground8 = 0x00000fab,
    MiningGemDiamondTiny = 0x00000fac,
    MiningGemDiamondSmall = 0x00000fad,
    MiningGemDiamondMedium = 0x00000fae,
    MiningGemDiamondLarge = 0x00000faf,
    MiningGemDiamondHuge = 0x00000fb0,
    MiningGemEmeraldTiny = 0x00000fb1,
    MiningGemEmeraldSmall = 0x00000fb2,
    MiningGemEmeraldMedium = 0x00000fb3,
    MiningGemEmeraldLarge = 0x00000fb4,
    MiningGemEmeraldHuge = 0x00000fb5,
    MiningGemMoonStoneTiny = 0x00000fb6,
    MiningGemMoonStoneSmall = 0x00000fb7,
    MiningGemMoonStoneMedium = 0x00000fb8,
    MiningGemMoonStoneLarge = 0x00000fb9,
    MiningGemMoonStoneHuge = 0x00000fba,
    MiningGemOpalTiny = 0x00000fbb,
    MiningGemOpalSmall = 0x00000fbc,
    MiningGemOpalMedium = 0x00000fbd,
    MiningGemOpalLarge = 0x00000fbe,
    MiningGemOpalHuge = 0x00000fbf,
    MiningGemRubyTiny = 0x00000fc0,
    MiningGemRubySmall = 0x00000fc1,
    MiningGemRubyMedium = 0x00000fc2,
    MiningGemRubyLarge = 0x00000fc3,
    MiningGemRubyHuge = 0x00000fc4,
    MiningGemSapphireTiny = 0x00000fc5,
    MiningGemSapphireSmall = 0x00000fc6,
    MiningGemSapphireMedium = 0x00000fc7,
    MiningGemSapphireLarge = 0x00000fc8,
    MiningGemSapphireHuge = 0x00000fc9,
    MiningGemSunStoneTiny = 0x00000fca,
    MiningGemSunStoneSmall = 0x00000fcb,
    MiningGemSunStoneMedium = 0x00000fcc,
    MiningGemSunStoneLarge = 0x00000fcd,
    MiningGemSunStoneHuge = 0x00000fce,
    MiningGemTopazTiny = 0x00000fcf,
    MiningGemTopazSmall = 0x00000fd0,
    MiningGemTopazMedium = 0x00000fd1,
    MiningGemTopazLarge = 0x00000fd2,
    MiningGemTopazHuge = 0x00000fd3,
    MiningGemZirconTiny = 0x00000fd4,
    MiningGemZirconSmall = 0x00000fd5,
    MiningGemZirconMedium = 0x00000fd6,
    MiningGemZirconLarge = 0x00000fd7,
    MiningGemZirconHuge = 0x00000fd8,
    MiningEntranceBackground0 = 0x00000fd9,
    MiningEntranceBackground1 = 0x00000fda,
    MiningEntranceBackground2 = 0x00000fdb,
    MiningEntranceBackground3 = 0x00000fdc,
    MiningEntranceBackground4 = 0x00000fdd,
    MiningEntranceBackground5 = 0x00000fde,
    MiningEntranceBackground6 = 0x00000fdf,
    MiningEntranceBackground7 = 0x00000fe0,
    MiningEntranceBackground8 = 0x00000fe1,
    MiningEntranceBackground9 = 0x00000fe2,
    MiningEntranceBackground10 = 0x00000fe3,
    MiningEntranceBackground11 = 0x00000fe4,
    MiningEntranceBackground12 = 0x00000fe5,
    MiningEntranceBackground13 = 0x00000fe6,
    MiningEntranceBackground14 = 0x00000fe7,
    MiningEntranceBackground15 = 0x00000fe8,
    MiningEntranceBackground16 = 0x00000fe9,
    MiningEntranceBackground17 = 0x00000fea,
    MiningEntranceBackground18 = 0x00000feb,
    MiningEntranceBackground19 = 0x00000fec,
    MiningEntranceBackground20 = 0x00000fed,
    MiningEntranceBackground21 = 0x00000fee,
    MiningShaftBackground0 = 0x00000fef,
    MiningShaftBackground1 = 0x00000ff0,
    MiningShaftBackground2 = 0x00000ff1,
    MiningShaftBackground3 = 0x00000ff2,
    MiningShaftBackground4 = 0x00000ff3,
    MiningShaftBackground5 = 0x00000ff4,
    MiningCartProp = 0x00000ff5,
    InvisibleBackground = 0x00000ff6,
    WeaponPickaxeCrappy = 0x00000ff7,
    WeaponPickaxeFlimsy = 0x00000ff8,
    WeaponPickaxeBasic = 0x00000ff9,
    WeaponPickaxeSturdy = 0x00000ffa,
    WeaponPickaxeHeavy = 0x00000ffb,
    WeaponPickaxeMaster = 0x00000ffc,
    WeaponPickaxeEpic = 0x00000ffd,
    TrophyMiningGemstoneDiamond = 0x00000ffe,
    TrophyMiningGemstoneEmerald = 0x00000fff,
    TrophyMiningGemstoneMoonStone = 0x00001000,
    TrophyMiningGemstoneOpal = 0x00001001,
    TrophyMiningGemstoneRuby = 0x00001002,
    TrophyMiningGemstoneSapphire = 0x00001003,
    TrophyMiningGemstoneSunStone = 0x00001004,
    TrophyMiningGemstoneTopaz = 0x00001005,
    TrophyMiningGemstoneZircon = 0x00001006,
    PortalMiningEntry = 0x00001007,
    MiningHideEntrancePortalWater = 0x00001008,
    NecklacePendantBrightness = 0x00001009,
    NecklacePendantMoment = 0x0000100a,
    GlassesDeepDweller = 0x0000100b,
    GlassesExcavator = 0x0000100c,
    HatBandHeadlamp = 0x0000100d,
    HatHelmetMining = 0x0000100e,
    HatHelmetExcavator = 0x0000100f,
    HatDeepDweller = 0x00001010,
    GlassesMonocleAppraisal = 0x00001011,
    ShoesExcavator = 0x00001012,
    GlovesExcavator = 0x00001013,
    ShoesDeepDweller = 0x00001014,
    MoustacheExcavator = 0x00001015,
    BeardDeepDweller = 0x00001016,
    BackMinerBackpack = 0x00001017,
    MaskGasMiner = 0x00001018,
    HatEarsMouse = 0x00001019,
    TailMouse = 0x0000101a,
    ShirtDeepDweller = 0x0000101b,
    PantsDeepDweller = 0x0000101c,
    BackhandItemCanaryBird = 0x0000101d,
    OrbWeatherMining = 0x0000101e,
    MiningMushrooms1 = 0x0000101f,
    MiningMushrooms2 = 0x00001020,
    MiningMushrooms3 = 0x00001021,
    MiningCrate1 = 0x00001022,
    MiningIngredientShoe = 0x00001023,
    MiningIngredientRustyNail = 0x00001024,
    MiningIngredientRope = 0x00001025,
    MiningIngredientTinCan = 0x00001026,
    MiningIngredientMatchBox = 0x00001027,
    MiningIngredientBucket = 0x00001028,
    MiningIngredientGoldTooth = 0x00001029,
    MiningIngredientSilverCoin = 0x0000102a,
    MiningIngredientPocketWatch = 0x0000102b,
    ShirtExcavator = 0x0000102c,
    OrbLightingLesserDark = 0x0000102d,
    OrbLightingGreatDark = 0x0000102e,
    MiningStalactitesTop = 0x0000102f,
    MiningStalactitesBottom = 0x00001030,
    MiningRocks1 = 0x00001031,
    MiningRocks2 = 0x00001032,
    MiningStackedRocks1 = 0x00001033,
    MiningStackedRocks2 = 0x00001034,
    MiningCrate2 = 0x00001035,
    MiningCrate3 = 0x00001036,
    MiningBat = 0x00001037,
    MiningSpider = 0x00001038,
    MiningTorch = 0x00001039,
    MiningNuggetBronze = 0x0000103a,
    MiningNuggetSilver = 0x0000103b,
    MiningNuggetGold = 0x0000103c,
    MiningNuggetPlatinum = 0x0000103d,
    HatHelmetWatermelon = 0x0000103e,
    MaskFaceSkull = 0x0000103f,
    CapeNecromancer = 0x00001040,
    ConsumableMiningPickaxeRepairKit = 0x00001041,
    MiningNuggetDark = 0x00001042,
    HubSignMining1 = 0x00001043,
    HubSignMining2 = 0x00001044,
    HubSignMining3 = 0x00001045,
    HubSignMining4 = 0x00001046,
    HubSignMining5 = 0x00001047,
    HubSignMining6 = 0x00001048,
    MiningWheelOfFortune = 0x00001049,
    MiningDarkStone = 0x0000104a,
    ConsumableMiningToken = 0x0000104b,
    JetPackLongJumpAchievement = 0x0000104c,
    MiningDarkVendorBackground1 = 0x0000104d,
    MiningDarkVendorBackground2 = 0x0000104e,
    MiningDarkVendorBackground3 = 0x0000104f,
    MiningDarkVendorBackground4 = 0x00001050,
    MiningDarkVendorBackground5 = 0x00001051,
    MiningDarkVendorBackground6 = 0x00001052,
    MiningDarkVendorBackground7 = 0x00001053,
    MiningDarkVendorBackground8 = 0x00001054,
    MiningDarkVendorBackground9 = 0x00001055,
    ShirtHoodieWhite = 0x00001056,
    WeaponAxeBone = 0x00001057,
    WeaponSwordSabreGolden = 0x00001058,
    CoatWitchHunter = 0x00001059,
    PantsWitchHunter = 0x0000105a,
    HatWitchHunter = 0x0000105b,
    ShoesWitchHunter = 0x0000105c,
    MaskWitchHunter = 0x0000105d,
    WeaponDualWitchHunter = 0x0000105e,
    WeaponCrossbowMechanical = 0x0000105f,
    WeaponSwordSwiftSlicer = 0x00001060,
    FamiliarBabyFireWyvern1A = 0x00001061,
    HatHelmetMiningGolden = 0x00001062,
    WeaponPickaxeDark = 0x00001063,
    FishingRodCarbonFiberDark = 0x00001064,
    WingsTripple = 0x00001065,
    CoatRainRed = 0x00001066,
    JetRaceBasicBlock1 = 0x00001067,
    JetRaceBasicBlock2 = 0x00001068,
    JetRaceBasicBlock3 = 0x00001069,
    JetRaceBasicBlock4 = 0x0000106a,
    JetRaceBasicBlock5 = 0x0000106b,
    JetRaceBasicBlock6 = 0x0000106c,
    JetRaceBasicBlock7 = 0x0000106d,
    JetRaceBasicBlock8 = 0x0000106e,
    JetRaceBasicBlock9 = 0x0000106f,
    JetRaceBasicBlock10 = 0x00001070,
    JetRaceBasicBlock11 = 0x00001071,
    JetRaceBasicBlock12 = 0x00001072,
    JetRaceBasicBlock13 = 0x00001073,
    JetRaceBasicBlock14 = 0x00001074,
    JetRaceBasicBlock15 = 0x00001075,
    JetRaceBasicBlock16 = 0x00001076,
    JetRaceBasicBlock17 = 0x00001077,
    JetRaceBasicBlock18 = 0x00001078,
    JetRaceBasicBlock19 = 0x00001079,
    JetRaceBasicBlock20 = 0x0000107a,
    JetRaceBasicBlock21 = 0x0000107b,
    JetRaceBasicBlock22 = 0x0000107c,
    JetRaceBasicBlock23 = 0x0000107d,
    JetRaceBasicBlock24 = 0x0000107e,
    JetRaceBasicBlock25 = 0x0000107f,
    JetRaceBasicBlock26 = 0x00001080,
    JetRaceBasicBlock27 = 0x00001081,
    JetRaceBasicBlock28 = 0x00001082,
    JetRaceBasicBlock29 = 0x00001083,
    JetRaceBasicBlock30 = 0x00001084,
    JetRaceBasicBlock31 = 0x00001085,
    JetRaceBackgroundIndent1 = 0x00001086,
    JetRaceBackgroundIndent2 = 0x00001087,
    JetRaceBackgroundIndent3 = 0x00001088,
    JetRaceBackgroundIndent4 = 0x00001089,
    JetRaceBackgroundIndent5 = 0x0000108a,
    JetRaceBackgroundIndent6 = 0x0000108b,
    JetRaceBackgroundIndent7 = 0x0000108c,
    JetRaceBackgroundTiles1 = 0x0000108d,
    JetRaceBackgroundTiles2 = 0x0000108e,
    JetRaceBackgroundTiles3 = 0x0000108f,
    JetRaceBackgroundTiles4 = 0x00001090,
    JetRaceBackgroundPlate = 0x00001091,
    JetRaceBackgroundWindow1 = 0x00001092,
    JetRaceBackgroundWindow2 = 0x00001093,
    JetRaceBackgroundWindow3 = 0x00001094,
    JetRaceBackgroundWindow4 = 0x00001095,
    JetRaceBackgroundWindow5 = 0x00001096,
    JetRaceBackgroundWindow6 = 0x00001097,
    MountFlyingJetRed = 0x00001098,
    JetRaceAirVent = 0x00001099,
    JetRaceAwardGate1 = 0x0000109a,
    JetRaceAwardGate2 = 0x0000109b,
    JetRaceAwardGate3 = 0x0000109c,
    JetRaceDoor = 0x0000109d,
    JetRaceElectronicsPanel = 0x0000109e,
    JetRaceHalogenLamp = 0x0000109f,
    JetRacePillar = 0x000010a0,
    JetRacePinballBumper = 0x000010a1,
    JetRaceDoorEdge = 0x000010a2,
    JetRaceSquarePillar = 0x000010a3,
    JetRacePipe = 0x000010a4,
    JetRaceSpeedBoost = 0x000010a5,
    JetRaceWireVertical = 0x000010a6,
    MaskDraugr = 0x000010a7,
    MaskFacehugger = 0x000010a8,
    MaskDarkIfrit = 0x000010a9,
    WingsFlaming = 0x000010aa,
    WingsGhost = 0x000010ab,
    WingsDarkIfrit = 0x000010ac,
    SuitGhostBlue = 0x000010ad,
    BeardDarkIfrit = 0x000010ae,
    PantsDarkIfrit = 0x000010af,
    SuitMorphsuitBlack = 0x000010b0,
    PantsJorogumo = 0x000010b1,
    IngredientZombieHand = 0x000010b2,
    FishingIngredientFishBone = 0x000010b3,
    TorchUnholy = 0x000010b4,
    HelloBotSkeleton = 0x000010b5,
    OrbJetRaceBackground = 0x000010b6,
    MaskBurger = 0x000010b7,
    RobesCultist = 0x000010b8,
    WeaponSwordsDualSpirit = 0x000010b9,
    GlowesBraceletDarkEfreet = 0x000010ba,
    JetRaceBasicBlock32 = 0x000010bb,
    JetRaceBasicBlock33 = 0x000010bc,
    JetRaceElectricWireLarge = 0x000010bd,
    JetRaceForcefieldStart = 0x000010be,
    JetRaceElectricConstantTrap = 0x000010bf,
    JetRaceTrampoline = 0x000010c0,
    JetRacePlasmaBlock = 0x000010c1,
    MountFlyingUfoBasic = 0x000010c2,
    MountFlyingPropellerWooden = 0x000010c3,
    MountFlyingRocketSkull = 0x000010c4,
    OverallsJetPilot = 0x000010c5,
    HatHelmetJetPilot = 0x000010c6,
    MaskOxygenJetPilot = 0x000010c7,
    OverallsBumblebee = 0x000010c8,
    HatBumblebee = 0x000010c9,
    GlassesBumblebee = 0x000010ca,
    WingsBumblebee = 0x000010cb,
    HatFlightCaptain = 0x000010cc,
    CoatFlightCaptain = 0x000010cd,
    PantsFlightCaptain = 0x000010ce,
    ShirtFlightCaptain = 0x000010cf,
    CoatAviator = 0x000010d0,
    PantsAviator = 0x000010d1,
    HatAviatorBrown = 0x000010d2,
    HatAviatorBlack = 0x000010d3,
    GlassesAviator = 0x000010d4,
    NeckScarfAviator = 0x000010d5,
    HatForeheadGlasses = 0x000010d6,
    CoatPilotGreen = 0x000010d7,
    CoatPilotBrown = 0x000010d8,
    GlassesPilot = 0x000010d9,
    HatHelmetRacerVisorUpYellow = 0x000010da,
    HatHelmetRacerVisorUpRed = 0x000010db,
    HatHelmetRacerVisorUpGreen = 0x000010dc,
    HatHelmetRacerVisorUpBlue = 0x000010dd,
    HatHelmetRacerVisorUpWhite = 0x000010de,
    HatHelmetRacerVisorUpBlack = 0x000010df,
    HatHelmetRacerYellow = 0x000010e0,
    HatHelmetRacerRed = 0x000010e1,
    HatHelmetRacerGreen = 0x000010e2,
    HatHelmetRacerBlue = 0x000010e3,
    HatHelmetRacerWhite = 0x000010e4,
    HatHelmetRacerBlack = 0x000010e5,
    MaskOxygenRacerYellow = 0x000010e6,
    MaskOxygenRacerRed = 0x000010e7,
    MaskOxygenRacerGreen = 0x000010e8,
    MaskOxygenRacerBlue = 0x000010e9,
    MaskOxygenRacerWhite = 0x000010ea,
    MaskOxygenRacerBlack = 0x000010eb,
    HatHelmetSpaceFighterPilot1 = 0x000010ec,
    HatHelmetSpaceFighterPilot2 = 0x000010ed,
    OverallsSpaceFighterPilot = 0x000010ee,
    MoustacheBaron = 0x000010ef,
    HatTiaraGoldenWings = 0x000010f0,
    HatTiaraBirdTribeShaman = 0x000010f1,
    NeckAmuletBirdTribeShaman = 0x000010f2,
    WingsBirdTribeShaman = 0x000010f3,
    TailBirdTribeShaman = 0x000010f4,
    BackParachute = 0x000010f5,
    HatParatrooperBeretPurple = 0x000010f6,
    HatPropeller = 0x000010f7,
    HatSideCapBlue = 0x000010f8,
    HatSideCapBrown = 0x000010f9,
    HatSideCapGreen = 0x000010fa,
    FamiliarKite1A = 0x000010fb,
    GlassesPilotVisorBlack = 0x000010fc,
    GlassesPilotVisorClear = 0x000010fd,
    GlassesPilotVisorRed = 0x000010fe,
    GlassesPilotVisorGreen = 0x000010ff,
    GlassesPilotVisorBlue = 0x00001100,
    GlassesPilotVisorYellow = 0x00001101,
    HatEarmuffsPink = 0x00001102,
    MountFlyingBathtub = 0x00001103,
    MountFlyingRocketBomb = 0x00001104,
    MountFlyingEasterEgg = 0x00001105,
    MountFlyingHotRod = 0x00001106,
    MountFlyingPropellerYellow = 0x00001107,
    MountFlyingPropellerFighter = 0x00001108,
    MountFlyingPropellerBlue = 0x00001109,
    MountFlyingStarFighter = 0x0000110a,
    MountFlyingJetBlue = 0x0000110b,
    MountFlyingRocketSpace = 0x0000110c,
    MountFlyingSantaSledge = 0x0000110d,
    JetRaceFinishline = 0x0000110e,
    RuleBotMount = 0x0000110f,
    JetRaceMysteryChest = 0x00001110,
    JetRaceIngredientSilver = 0x00001111,
    JetRaceIngredientGold = 0x00001112,
    JetRaceCrestSilver = 0x00001113,
    JetRaceCrestGold = 0x00001114,
    JetRaceGroupPortal = 0x00001115,
    JetRaceMysteryChestBackground1 = 0x00001116,
    JetRaceMysteryChestBackground2 = 0x00001117,
    JetRaceMysteryChestBackground3 = 0x00001118,
    JetRaceMysteryChestBackground4 = 0x00001119,
    JetRaceMysteryChestSign = 0x0000111a,
    ShirtXmasWoollyRed = 0x0000111b,
    PantsSeasonalRed = 0x0000111c,
    HatSeasonalRed = 0x0000111d,
    HatPomPomPink = 0x0000111e,
    NeckScarfSeasonalBlue = 0x0000111f,
    MaskNoseRudolf = 0x00001120,
    HoodieXmasBlack = 0x00001121,
    JetRaceMountVendorBackground1 = 0x00001122,
    JetRaceMountVendorBackground2 = 0x00001123,
    JetRaceMountVendorBackground3 = 0x00001124,
    JetRaceMountVendorBackground4 = 0x00001125,
    JetRaceMountVendorBackground5 = 0x00001126,
    JetRaceMountVendorBackground6 = 0x00001127,
    JetRaceMountVendorSign = 0x00001128,
    JetRaceInfoNPCBackground1 = 0x00001129,
    JetRaceInfoNPCBackground2 = 0x0000112a,
    JetRaceInfoNPCBackground3 = 0x0000112b,
    JetRaceInfoNPCBackground4 = 0x0000112c,
    JetRaceInfoNPCBackground5 = 0x0000112d,
    JetRaceInfoNPCBackground6 = 0x0000112e,
    JetRaceInfoNPCSign = 0x0000112f,
    JetRaceMountVendorBackground7 = 0x00001130,
    JetRaceMountVendorBackground8 = 0x00001131,
    JetRaceMountVendorBackground9 = 0x00001132,
    JetRaceInfoNPCBackground7 = 0x00001133,
    JetRaceInfoNPCBackground8 = 0x00001134,
    JetRaceInfoNPCBackground9 = 0x00001135,
    JetRaceMysteryChestBackground5 = 0x00001136,
    JetRaceMysteryChestBackground6 = 0x00001137,
    JetRaceStartBackground1 = 0x00001138,
    JetRaceStartBackground2 = 0x00001139,
    JetRaceStartBackground3 = 0x0000113a,
    JetRaceStartBackground4 = 0x0000113b,
    JetRaceStartBackground5 = 0x0000113c,
    JetRaceStartBackground6 = 0x0000113d,
    JetRaceStartBackground7 = 0x0000113e,
    JetRaceStartBackground8 = 0x0000113f,
    JetRaceStartBackground9 = 0x00001140,
    JetRaceStartSign = 0x00001141,
    HatBabyCloud = 0x00001142,
    JetRaceMine = 0x00001143,
    JetRacePercentageBlock1 = 0x00001144,
    JetRacePercentageBlock2 = 0x00001145,
    JetRacePercentageBlock3 = 0x00001146,
    JetRaceCyanDoorEdge = 0x00001147,
    JetRaceCyanSquarePillar = 0x00001148,
    JetRaceBackgroundTilesCyan = 0x00001149,
    HatWinterFox = 0x0000114a,
    ShoesWinterFox = 0x0000114b,
    GlowesWinterFox = 0x0000114c,
    OverallsWinterFox = 0x0000114d,
    TailWinterFox = 0x0000114e,
    HatCrownIceQueen = 0x0000114f,
    DressIceQueen = 0x00001150,
    CapeIceQueen = 0x00001151,
    WeaponStaffIceQueen = 0x00001152,
    MaskFlamingIce = 0x00001153,
    OrbWeatherAuroraBorealis = 0x00001154,
    SnowDrift = 0x00001155,
    RobesIceShaman = 0x00001156,
    HatHoodIceShaman = 0x00001157,
    WeaponStaffIceShaman = 0x00001158,
    HairPuffyGreen = 0x00001159,
    HairBieberBlack = 0x0000115a,
    HairCottonCandyDream = 0x0000115b,
    HairSemilongBlonde = 0x0000115c,
    HairShortAnimeRed = 0x0000115d,
    HairCrewcutPink = 0x0000115e,
    HairCrewcutBlue = 0x0000115f,
    HairStarbridge = 0x00001160,
    HairExotic = 0x00001161,
    HairCurlySideyBrown = 0x00001162,
    HairRetroPotBrown = 0x00001163,
    HairEilish = 0x00001164,
    HairPamela = 0x00001165,
    HairBiden = 0x00001166,
    GlassesThick = 0x00001167,
    NeckTieBlue = 0x00001168,
    FrostTrap = 0x00001169,
    FrostConstantTrap = 0x0000116a,
    GrassFrosted = 0x0000116b,
    HangingLeavesSilver = 0x0000116c,
    RocksSnowy1 = 0x0000116d,
    RocksSnowy2 = 0x0000116e,
    SnowPillar = 0x0000116f,
    SpikesIce = 0x00001170,
    VineSilver = 0x00001171,
    BushSnowy1 = 0x00001172,
    BushSnowy2 = 0x00001173,
    BushSnowy3 = 0x00001174,
    TreeStumpSnowy = 0x00001175,
    TorchBlue = 0x00001176,
    WeaponGunSnowball = 0x00001177,
    MountFlyingTurboSledge = 0x00001178,
    FamiliarBabyWaterWyvern1A = 0x00001179,
    AnniversaryCake4 = 0x0000117a,
    GuestBookAnniversary = 0x0000117b,
    LoreBotLeft = 0x0000117c,
    BestSetBackground1 = 0x0000117d,
    BestSetBackground2 = 0x0000117e,
    BestSetBackground3 = 0x0000117f,
    BestSetBackground4 = 0x00001180,
    BestSetBackground5 = 0x00001181,
    BestSetBackground6 = 0x00001182,
    BestSetBackground7 = 0x00001183,
    BestSetBackground8 = 0x00001184,
    BestSetBackground9 = 0x00001185,
    BestSetNeonSign = 0x00001186,
    BestSetPhotoSign = 0x00001187,
    BestSetPlatform = 0x00001188,
    BestSetSpotLightLeft = 0x00001189,
    BestSetSpotLightRight = 0x0000118a,
    BestSetPhotoBooth = 0x0000118b,
    ShirtArmorCandyKnight = 0x0000118c,
    PantsArmorCandyKnight = 0x0000118d,
    HatHelmetArmorCandyKnight = 0x0000118e,
    WeaponSwordCandyKnight = 0x0000118f,
    ShirtTuxedoRed = 0x00001190,
    PantsTuxedoRed = 0x00001191,
    FamiliarPhoenix1A = 0x00001192,
    WeaponSwordAcidFlame = 0x00001193,
    HatHelmetOx = 0x00001194,
    HatOrientalRed = 0x00001195,
    PantsBrokenHoleBlue = 0x00001196,
    BestSetTrophy = 0x00001197,
    ShirtVestedRed = 0x00001198,
    ShirtWintercoatYellow = 0x00001199,
    HatHoodWinterCoatYellow = 0x0000119a,
    FamiliarBabyEarthWyvern1A = 0x0000119b,
    FamiliarBabyAirWyvern1A = 0x0000119c,
    FamiliarBabyLightWyvern1A = 0x0000119d,
    FamiliarBabyDarkWyvern1A = 0x0000119e,
    ShoesWinterbootsYellow = 0x0000119f,
    ShirtBowlingBlack = 0x000011a0,
    ContactLensesOdin = 0x000011a1,
    FamiliarSeagul1A = 0x000011a2,
    FamiliarSwallow1A = 0x000011a3,
    FamiliarBee1A = 0x000011a4,
    ShirtWintercoatBlue = 0x000011a5,
    HatHoodWinterCoatBlue = 0x000011a6,
    ShirtWintercoatPink = 0x000011a7,
    HatHoodWinterCoatPink = 0x000011a8,
    ShirtWintercoatGreen = 0x000011a9,
    HatHoodWinterCoatGreen = 0x000011aa,
    WeaponSwordCrimson = 0x000011ab,
    ShoesCandyKnight = 0x000011ac,
    JewelBlockBlack = 0x000011ad,
    JewelBlockBlue = 0x000011ae,
    JewelBlockCyan = 0x000011af,
    JewelBlockGreen = 0x000011b0,
    JewelBlockOrange = 0x000011b1,
    JewelBlockRed = 0x000011b2,
    JewelBlockTurquoise = 0x000011b3,
    JewelBlockPurple = 0x000011b4,
    JewelBlockWhite = 0x000011b5,
    JewelBlockYellow = 0x000011b6,
    TurquoiseBlock = 0x000011b7,
    BounceBlobGreen = 0x000011b8,
    BounceBlobOrange = 0x000011b9,
    BounceBlobPurple = 0x000011ba,
    SinkWhite = 0x000011bb,
    GrassExtraTall = 0x000011bc,
    LeavesPlant = 0x000011bd,
    DecorativePinkFan = 0x000011be,
    GoldenOxStatue = 0x000011bf,
    FishingTutorialSign = 0x000011c0,
    WallClockAnalog = 0x000011c1,
    ForSaleSign = 0x000011c2,
    PebblePillar = 0x000011c3,
    WoodenSignPlanks = 0x000011c4,
    RoadMarkerStone = 0x000011c5,
    FireExtinguisher = 0x000011c6,
    TrapdoorWoodenPlatform = 0x000011c7,
    AlienCactus = 0x000011c8,
    WeaponBaseballbatStPatricks = 0x000011c9,
    WeaponEggHunterTribe21 = 0x000011ca,
    MaskEggHunterTribe21 = 0x000011cb,
    WingsStPatricks21 = 0x000011cc,
    DressEasterYellow = 0x000011cd,
    WeaponStPatricks21 = 0x000011ce,
    ShirtCollegePurple = 0x000011cf,
    MaskDragonBlue = 0x000011d0,
    LureNoob = 0x000011d1,
    DiagonalLargeTiles = 0x000011d2,
    DiagonalLargePlating = 0x000011d3,
    HatCrownStPatricks = 0x000011d4,
    MaskFaceStPatricks = 0x000011d5,
    BeardStubbed = 0x000011d6,
    WeaponGunStPatricks = 0x000011d7,
    DressStPatricks = 0x000011d8,
    PantsBorat = 0x000011d9,
    BeardZappa = 0x000011da,
    OverallsPickle = 0x000011db,
    HatHoodGreen = 0x000011dc,
    CandyWorm = 0x000011dd,
    LoveThrone = 0x000011de,
    WeaponChineseDualMaces = 0x000011df,
    MountFlyingJetSpaceWarrior = 0x000011e0,
    WeaponEasterBynnyrai = 0x000011e1,
    ShirtEasterBunnyrai = 0x000011e2,
    PantsEasterBunnyrai = 0x000011e3,
    HatHelmetEasterBunnyrai = 0x000011e4,
    ShoesEasterBunnyrai = 0x000011e5,
    HatEasterEggShell = 0x000011e6,
    EarsCatAlbino = 0x000011e7,
    SignLocalized = 0x000011e8,
    LureCrabBait = 0x000011e9,
    FishCrabTiny = 0x000011ea,
    FishCrabSmall = 0x000011eb,
    FishCrabMedium = 0x000011ec,
    FishCrabLarge = 0x000011ed,
    FishCrabHuge = 0x000011ee,
    MaskBunnyrai = 0x000011ef,
    TrophyFishCrab = 0x000011f0,
    MonolithPuzzle = 0x000011f1,
    MonolithLightPart1 = 0x000011f2,
    MonolithLightPart2 = 0x000011f3,
    MonolithLightPart3 = 0x000011f4,
    MonolithLightPart4 = 0x000011f5,
    MonolithLightPart5 = 0x000011f6,
    MonolithLightPart6 = 0x000011f7,
    MonolithLightPart7 = 0x000011f8,
    MonolithLightPart8 = 0x000011f9,
    MonolithDarkPart1 = 0x000011fa,
    MonolithDarkPart2 = 0x000011fb,
    MonolithDarkPart3 = 0x000011fc,
    MonolithDarkPart4 = 0x000011fd,
    MonolithDarkPart5 = 0x000011fe,
    MonolithDarkPart6 = 0x000011ff,
    MonolithDarkPart7 = 0x00001200,
    MonolithDarkPart8 = 0x00001201,
    SuitSwimsuitRetro = 0x00001202,
    SuitSwimsuitPink = 0x00001203,
    DressLongSummerYellow = 0x00001204,
    NeckFannyBag = 0x00001205,
    GoldenCask = 0x00001206,
    HotTubGolden = 0x00001207,
    GoldDust = 0x00001208,
    PotionSpeechBubbleCrescentTongue = 0x00001209,
    BlueprintChassisMountFlyingJetSpaceWarrior = 0x0000120a,
    ChassisMountFlyingJetSpaceWarrior = 0x0000120b,
    GlassPot = 0x0000120c,
    PotionDamageBlocksElixirOfFlame = 0x0000120d,
    FishingRodBambooReinforced = 0x0000120e,
    Naphtha = 0x0000120f,
    NaphthaFall = 0x00001210,
    Fluff = 0x00001211,
    AncientPressureCooker = 0x00001212,
    PlasticBlockTransparent = 0x00001213,
    NeckFloaterFlamingo = 0x00001214,
    ArcheologyBoxBackground01 = 0x00001215,
    ArcheologyBoxBackground02 = 0x00001216,
    ArcheologyBoxBackground03 = 0x00001217,
    ArcheologyBoxBackground04 = 0x00001218,
    ArcheologyBoxBackground05 = 0x00001219,
    ArcheologyBoxBackground06 = 0x0000121a,
    ArcheologyBoxBackground07 = 0x0000121b,
    ArcheologyBoxBackground08 = 0x0000121c,
    ArcheologyBoxBackground09 = 0x0000121d,
    ArcheologyBoxBackgroundDark01 = 0x0000121e,
    ArcheologyBoxBackgroundDark02 = 0x0000121f,
    ArcheologyBoxBackgroundDark03 = 0x00001220,
    ArcheologyBoxBackgroundDark04 = 0x00001221,
    ArcheologyBoxBackgroundDark05 = 0x00001222,
    ArcheologyBoxBackgroundDark06 = 0x00001223,
    ArcheologyBoxBackgroundDark07 = 0x00001224,
    ArcheologyBoxBackgroundDark08 = 0x00001225,
    ArcheologyBoxBackgroundDark09 = 0x00001226,
    JetRaceIngredientEaster = 0x00001227,
    HatHelmetMiningFlameBooster = 0x00001228,
    SignSwitchableTextWooden = 0x00001229,
    MaskCostumePig = 0x0000122a,
    SuitCostumePig = 0x0000122b,
    ShoesCostumePig = 0x0000122c,
    GlovesCostumePig = 0x0000122d,
    TailCostumePig = 0x0000122e,
    MaskCostumeWolf = 0x0000122f,
    SuitCostumeWolf = 0x00001230,
    ShoesCostumeWolf = 0x00001231,
    GlovesCostumeWolf = 0x00001232,
    TailCostumeWolf = 0x00001233,
    MaskCostumeKangaroo = 0x00001234,
    SuitCostumeKangaroo = 0x00001235,
    ShoesCostumeKangaroo = 0x00001236,
    GlovesCostumeKangaroo = 0x00001237,
    TailCostumeKangaroo = 0x00001238,
    MaskCostumeMallard = 0x00001239,
    SuitCostumeMallard = 0x0000123a,
    ShoesCostumeMallard = 0x0000123b,
    GlovesCostumeMallard = 0x0000123c,
    MaskCostumeCat = 0x0000123d,
    SuitCostumeCat = 0x0000123e,
    ShoesCostumeCat = 0x0000123f,
    GlovesCostumeCat = 0x00001240,
    TailCostumeCat = 0x00001241,
    MaskCostumeDog = 0x00001242,
    SuitCostumeDog = 0x00001243,
    ShoesCostumeDog = 0x00001244,
    GlovesCostumeDog = 0x00001245,
    TailCostumeDog = 0x00001246,
    MaskCostumeMouse = 0x00001247,
    SuitCostumeMouse = 0x00001248,
    ShoesCostumeMouse = 0x00001249,
    GlovesCostumeMouse = 0x0000124a,
    TailCostumeMouse = 0x0000124b,
    MaskCostumeRacoon = 0x0000124c,
    SuitCostumeRacoon = 0x0000124d,
    ShoesCostumeRacoon = 0x0000124e,
    GlovesCostumeRacoon = 0x0000124f,
    TailCostumeRacoon = 0x00001250,
    WeaponSwordLava = 0x00001251,
    WeaponSwordLightning = 0x00001252,
    MaskCarnivorousPlant = 0x00001253,
    SuitCamouflageSoilblock = 0x00001254,
    WingsDrakeBlue = 0x00001255,
    HatSombrero2021 = 0x00001256,
    FamiliarLordOfElementsWyvern1A = 0x00001257,
    END_OF_THE_ENUM = 0x00001258,
};