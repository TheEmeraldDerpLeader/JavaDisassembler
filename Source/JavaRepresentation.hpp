#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

inline char IntToHexaChar(int i) { switch (i) { case 0: return '0'; case 1: return '1'; case 2: return '2'; case 3: return '3'; case 4: return '4'; case 5: return '5'; case 6: return '6'; case 7: return '7';
case 8: return '8'; case 9: return '9'; case 10: return 'A'; case 11: return 'B'; case 12: return 'C'; case 13: return 'D'; case 14: return 'E'; case 15: return 'F'; default: return '-';}}
int HexaCharToInt(const char* c, int count);
int HexaCharToInt(const std::string str, int count, int index = 0);
std::string ByteToHexa(int byte);
void ReadAt(unsigned char* hbuf, std::fstream& stream, int bytes, int index);
#define TAG_STRING 1
#define TAG_INT 3
#define TAG_FLOAT 4
#define TAG_LONG 5
#define TAG_DOUBLE 6
#define TAG_CLASS 7
#define TAG_STRING_REF 8
#define TAG_FIELD_REF 9
#define TAG_METHOD_REF 10
#define TAG_INTERFACE_METHOD_REF 11
#define TAG_NAME_AND_TYPE 12
#define TAG_METHOD_HANDLE 15
#define TAG_METHOD_TYPE 16
#define TAG_DYNAMIC 17
#define TAG_INVOKE_DYNAMIC 18
#define TAG_MODULE 19
#define TAG_PACKAGE 20
std::string CPTagSwitch(unsigned char tag);
std::string OpToMonic(unsigned char op);
unsigned char MonicToOp(std::string Monic);
int OpParaCount(unsigned char op);

class CPString
{
public:
	int length = 0;
	unsigned char* data = nullptr;

	CPString() = delete;
	CPString(int lengthInt)
	{
		length = lengthInt; 
		data = new unsigned char[length];
	}
	~CPString() { if (data != nullptr) delete[] data; }

	CPString(CPString& stringRef);
	CPString& operator= (CPString& stringRef);
	CPString(CPString&& stringTemp);
	CPString& operator= (CPString&& stringTemp);

	std::string getString();

};
struct CPInt
{
public:
	int value = 0;
	CPInt() = delete;
	CPInt(int valueInt) : value(valueInt) {}
};
struct CPFloat
{
public:
	int tag = TAG_FLOAT;
	float value = 0;
	CPFloat() = delete;
	CPFloat(float valueFloat) : value(valueFloat) {}
};
struct CPLong
{
public:
	int tag = TAG_LONG;
	long long value = 0;
	CPLong() = delete;
	CPLong(long long valueLong) : value(valueLong) {}
};
struct CPDouble
{
public:
	double value = 0;
	CPDouble() = delete;
	CPDouble(double valueDoub) : value(valueDoub) {}
};
struct CPClass
{
public:
	int nameIndex = 0;
	CPClass() = delete;
	CPClass(int nameIndexInt) : nameIndex(nameIndexInt) {}
};
struct CPStringRef
{
public:
	int stringIndex = 0;
	CPStringRef() = delete;
	CPStringRef(int stringIndexInt) : stringIndex(stringIndexInt) {}
};
struct CPFieldRef
{
public:
	int classIndex = 0;
	int natIndex = 0;
	CPFieldRef() = delete;
	CPFieldRef(int classIndexInt, int natIndexInt) : classIndex(classIndexInt),natIndex(natIndexInt) {}
};
struct CPMethodRef
{
public:
	int classIndex = 0;
	int natIndex = 0;
	CPMethodRef() = delete;
	CPMethodRef(int classIndexInt, int natIndexInt) : classIndex(classIndexInt),natIndex(natIndexInt) {}
};
struct CPInterfaceMethodRef
{
public:
	int classIndex = 0;
	int natIndex = 0;
	CPInterfaceMethodRef() = delete;
	CPInterfaceMethodRef(int classIndexInt, int natIndexInt) : classIndex(classIndexInt),natIndex(natIndexInt) {}
};
struct CPNameAndType
{
public:
	int nameIndex = 0;
	int descIndex = 0;
	CPNameAndType() = delete;
	CPNameAndType(int nameIndexInt, int descIndexInt) : nameIndex(nameIndexInt),descIndex(descIndexInt) {}
};
struct CPMethodHandle
{
public:
	int kind = 0;
	int refIndex = 0;
	CPMethodHandle() = delete;
	CPMethodHandle(int kindInt, int refIndexInt) : kind(kindInt),refIndex(refIndexInt) {}
};
struct CPMethodType
{
public:
	int descIndex = 0;
	CPMethodType() = delete;
	CPMethodType(int descIndexInt) : descIndex(descIndexInt) {}
};
struct CPDynamic
{
public:
	int bsIndex = 0;
	int natIndex = 0;
	CPDynamic() = delete;
	CPDynamic(int bsIndexInt, int natIndexInt) : bsIndex(bsIndexInt),natIndex(natIndexInt) {}
};
struct CPInvokeDynamic
{
public:
	int bsIndex = 0;
	int natIndex = 0;
	CPInvokeDynamic() = delete;
	CPInvokeDynamic(int bsIndexInt, int natIndexInt) : bsIndex(bsIndexInt),natIndex(natIndexInt) {}
};
struct CPModule
{
public:
	int nameIndex = 0;
	CPModule() = delete;
	CPModule(int nameIndexInt) : nameIndex(nameIndexInt) {}
};
struct CPPackage
{
public:
	int nameIndex = 0;
	CPPackage() = delete;
	CPPackage(int nameIndexInt) : nameIndex(nameIndexInt) {}
};

class CPEntry
{
public:
	int tag = 0;
	union
	{
		CPString uString;
		CPInt uInt;
		CPFloat uFloat;
		CPLong uLong;
		CPDouble uDoub;
		CPClass uClass;
		CPStringRef uStrRef;
		CPFieldRef uFieldRef;
		CPMethodRef uMetRef;
		CPInterfaceMethodRef uInterMetRef;
		CPNameAndType uNat;
		CPMethodHandle uMetHandle;
		CPMethodType uMetType;
		CPDynamic uDyn;
		CPInvokeDynamic uInvDyn;
		CPModule uModule;
		CPPackage uPack;
	};
	
	CPEntry() { uInt = CPInt(0); }
	CPEntry(int tagInt) : tag(tagInt) { uInt = CPInt(0); }
	~CPEntry();
	
	CPEntry(CPEntry& entryRef);
	CPEntry& operator=(CPEntry& entryRef);
	CPEntry(CPEntry&& entryTemp);
	CPEntry& operator=(CPEntry&& entryTemp);
};

class Attribute; class Field; class Method;

struct ClassData
{
public:
	int major = 0;
	int minor = 0;
	//int cpCount = 0;
	int accessFlags = 0;
	int thisIndex = 0;
	int superIndex = 0;
	//int interCount = 0;
	//int fieldsCount = 0;
	//int methodsCount = 0;
	//int attrsCount = 0;

	std::vector<CPEntry> entries;
	std::vector<int> interfaces;
	std::vector<Field> fields;
	std::vector<Method> methods;
	std::vector<Attribute> attrs;

	ClassData() {}
	ClassData(int majorInt, int minorInt, int cpCountInt, int accessFlagsInt, int thisIndexInt, int superIndexInt,
		int interCountInt, int fieldsCountInt, int methodsCountInt, int attrsCountInt) : major(majorInt), minor(minorInt),
		accessFlags(accessFlagsInt), thisIndex(thisIndexInt), superIndex(superIndexInt)
	{entries.resize(cpCountInt);interfaces.resize(interCountInt); fields.resize(fieldsCountInt); methods.resize(methodsCountInt); attrs.resize(attrsCountInt);}
};

class Attribute
{
public:
	int nameIndex = 0;
	std::vector<unsigned char> info;
};

class Field
{
public:
	ClassData* cd = nullptr;

	int accessFlags = 0;
	int nameIndex = 0;
	int descIndex = 0;
	int attrCount = 0;
	std::vector<Attribute> attrs;
	Field() {}
	Field(ClassData* cdPtr, int accessFlagsInt, int nameIndexInt, int descIndexInt, int attrCountInt) : cd(cdPtr),accessFlags(accessFlagsInt),nameIndex(nameIndexInt),descIndex(descIndexInt),attrCount(attrCountInt) {}
};

class CodeIndicesData
{ 
public:
	int lineIndex = 0;
	std::vector<int> indices;
	CodeIndicesData() {}
	CodeIndicesData(int lineIndexInt) : lineIndex(lineIndexInt) {}
	CodeIndicesData(int lineIndexInt, int indexInt) : lineIndex(lineIndexInt) { indices.push_back(indexInt); }
};
struct CodeIndexData
{ 
public:
	int lineIndex = 0;
	int index = 0;
	CodeIndexData() {}
	CodeIndexData(int lineIndexInt) : lineIndex(lineIndexInt) {}
	CodeIndexData(int lineIndexInt, int indexInt) : lineIndex(lineIndexInt) , index(indexInt) {}
};

class Method //implemented in MethodRepresentation.cpp
{
public:
	ClassData* cd = nullptr;

	int accessFlags = 0;
	int nameIndex = 0;
	int descIndex = 0;
	int attrCount = 0;
	int codeAttr = -2; //-2: code index not determined, -1: No code
	int firstTable = -1;
	std::vector<Attribute> attrs;
	std::vector<int> codeTable;
	std::vector<CodeIndicesData> jumpTable;
	std::vector<CodeIndexData> localVarTable;
	std::vector<CodeIndexData> cpRefTable;
	Method() {}
	Method(ClassData* cdPtr, int accessFlagsInt, int nameIndexInt, int descIndexInt, int attrCountInt) : cd(cdPtr),accessFlags(accessFlagsInt),nameIndex(nameIndexInt),descIndex(descIndexInt),attrCount(attrCountInt) {}

	void GenerateTables();
	void PrintCode();
	void PrintJumpTable();
	std::string GetCodeLine(int index);
	std::vector<std::string> GetCodeRegion(int lower, int higher); //exclusive
	void ModifyCodeLine(std::string code, int index);
	void InsertCodeLine(std::string code, int index); //index will be line number of new code
	void DeleteCodeLine(std::string code, int index);

	void GetCodeStartAndEnd(unsigned char*& start, unsigned char*& end); //GenerateTables does not use this

	void SetJumpOffset(unsigned char* opLoc, int offset, int subJump = 0); //sub jump is for lookupswitch and tableswitch
};

#define CODE_AALOAD 0x32
#define CODE_AASTORE 0x53
#define CODE_ACONST_NULL 0x1
#define CODE_ALOAD 0x19
#define CODE_ALOAD_0 0x2A
#define CODE_ALOAD_1 0x2B
#define CODE_ALOAD_2 0x2C
#define CODE_ALOAD_3 0x2D
#define CODE_ANEWARRAY 0xBD
#define CODE_ARETURN 0xB0
#define CODE_ARRAYLENGTH 0xBE
#define CODE_ASTORE 0x3A
#define CODE_ASTORE_0 0x4B
#define CODE_ASTORE_1 0x4C
#define CODE_ASTORE_2 0x4D
#define CODE_ASTORE_3 0x4E
#define CODE_ATHROW 0xBF
#define CODE_BALOAD 0x33
#define CODE_BASTORE 0x54
#define CODE_BIPUSH 0x10
#define CODE_CALOAD 0x34
#define CODE_CASTORE 0x55
#define CODE_CHECKCAST 0xC0
#define CODE_D2F 0x90
#define CODE_D2I 0x8E
#define CODE_D2L 0x8F
#define CODE_DADD 0x63
#define CODE_DALOAD 0x31
#define CODE_DASTORE 0x52
#define CODE_DCMPG 0x98
#define CODE_DCMPL 0x97
#define CODE_DCONST_0 0xE
#define CODE_DCONST_1 0xF
#define CODE_DDIV 0x6F
#define CODE_DLOAD 0x18
#define CODE_DLOAD_0 0x26
#define CODE_DLOAD_1 0x27
#define CODE_DLOAD_2 0x28
#define CODE_DLOAD_3 0x29
#define CODE_DMUL 0x6B
#define CODE_DNEG 0x77
#define CODE_DREM 0x73
#define CODE_DRETURN 0xAF
#define CODE_DSTORE 0x39
#define CODE_DSTORE_0 0x47
#define CODE_DSTORE_1 0x48
#define CODE_DSTORE_2 0x49
#define CODE_DSTORE_3 0x4A
#define CODE_DSUB 0x67
#define CODE_DUP 0x59
#define CODE_DUP_X1 0x5A
#define CODE_DUP_X2 0x5B
#define CODE_DUP2 0x5C
#define CODE_DUP2_X1 0x5D
#define CODE_DUP2_X2 0x5E
#define CODE_F2D 0x8D
#define CODE_F2I 0x8B
#define CODE_F2L 0x8C
#define CODE_FADD 0x62
#define CODE_FALOAD 0x30
#define CODE_FASTORE 0x51
#define CODE_FCMPG 0x96
#define CODE_FCMPL 0x95
#define CODE_FCONST_0 0xB
#define CODE_FCONST_1 0xC
#define CODE_FCONST_2 0xD
#define CODE_FDIV 0x6E
#define CODE_FLOAD 0x17
#define CODE_FLOAD_0 0x22
#define CODE_FLOAD_1 0x23
#define CODE_FLOAD_2 0x24
#define CODE_FLOAD_3 0x25
#define CODE_FMUL 0x6A
#define CODE_FNEG 0x76
#define CODE_FREM 0x72
#define CODE_FRETURN 0xAE
#define CODE_FSTORE 0x38
#define CODE_FSTORE_0 0x43
#define CODE_FSTORE_1 0x44
#define CODE_FSTORE_2 0x45
#define CODE_FSTORE_3 0x46
#define CODE_FSUB 0x66
#define CODE_GETFIELD 0xB4
#define CODE_GETSTATIC 0xB2
#define CODE_GOTO 0xA7
#define CODE_GOTO_W 0xC8
#define CODE_I2B 0x91
#define CODE_I2C 0x92
#define CODE_I2D 0x87
#define CODE_I2F 0x86
#define CODE_I2L 0x85
#define CODE_I2S 0x93
#define CODE_IADD 0x60
#define CODE_IALOAD 0x2E
#define CODE_IAND 0x7E
#define CODE_IASTORE 0x4F
#define CODE_ICONST_M1 0x2
#define CODE_ICONST_0 0x3
#define CODE_ICONST_1 0x4
#define CODE_ICONST_2 0x5
#define CODE_ICONST_3 0x6
#define CODE_ICONST_4 0x7
#define CODE_ICONST_5 0x8
#define CODE_IDIV 0x6C
#define CODE_IF_ACMPEQ 0xA5
#define CODE_IF_ACMPNE 0xA6
#define CODE_IF_ICMPEQ 0x9F
#define CODE_IF_ICMPNE 0xA0
#define CODE_IF_ICMPLT 0xA1
#define CODE_IF_ICMPGE 0xA2
#define CODE_IF_ICMPGT 0xA3
#define CODE_IF_ICMPLE 0xA4
#define CODE_IFEQ 0x99
#define CODE_IFNE 0x9A
#define CODE_IFLT 0x9B
#define CODE_IFGE 0x9C
#define CODE_IFGT 0x9D
#define CODE_IFLE 0x9E
#define CODE_IFNONNULL 0xC7
#define CODE_IFNULL 0xC6
#define CODE_IINC 0x84
#define CODE_ILOAD 0x15
#define CODE_ILOAD_0 0x1A
#define CODE_ILOAD_1 0x1B
#define CODE_ILOAD_2 0x1C
#define CODE_ILOAD_3 0x1D
#define CODE_IMUL 0x68
#define CODE_INEG 0x74
#define CODE_INSTANCEOF 0xC1
#define CODE_INVOKEDYNAMIC 0xBA
#define CODE_INVOKEINTERFACE 0xB9
#define CODE_INVOKESPECIAL 0xB7
#define CODE_INVOKESTATIC 0xB8
#define CODE_INVOKEVIRTUAL 0xB6
#define CODE_IOR 0x80
#define CODE_IREM 0x70
#define CODE_IRETURN 0xAC
#define CODE_ISHL 0x78
#define CODE_ISHR 0x7A
#define CODE_ISTORE 0x36
#define CODE_ISTORE_0 0x3B
#define CODE_ISTORE_1 0x3C
#define CODE_ISTORE_2 0x3D
#define CODE_ISTORE_3 0x3E
#define CODE_ISUB 0x64
#define CODE_IUSHR 0x7C
#define CODE_IXOR 0x82
#define CODE_JSR 0xA8
#define CODE_JSR_W 0xC9
#define CODE_L2D 0x8A
#define CODE_L2F 0x89
#define CODE_L2I 0x88
#define CODE_LADD 0x61
#define CODE_LALOAD 0x2F
#define CODE_LAND 0x7F
#define CODE_LASTORE 0x50
#define CODE_LCMP 0x94
#define CODE_LCONST_0 0x9
#define CODE_LCONST_1 0xA
#define CODE_LDC 0x12
#define CODE_LDC_W 0x13
#define CODE_LDC2_W 0x14
#define CODE_LDIV 0x6D
#define CODE_LLOAD 0x16
#define CODE_LLOAD_0 0x1E
#define CODE_LLOAD_1 0x1F
#define CODE_LLOAD_2 0x20
#define CODE_LLOAD_3 0x21
#define CODE_LMUL 0x69
#define CODE_LNEG 0x75
#define CODE_LOOKUPSWITCH 0xAB
#define CODE_LOR 0x81
#define CODE_LREM 0x71
#define CODE_LRETURN 0xAD
#define CODE_LSHL 0x79
#define CODE_LSHR 0x7B
#define CODE_LSTORE 0x37
#define CODE_LSTORE_0 0x3F
#define CODE_LSTORE_1 0x40
#define CODE_LSTORE_2 0x41
#define CODE_LSTORE_3 0x42
#define CODE_LSUB 0x65
#define CODE_LUSHR 0x7D
#define CODE_LXOR 0x83
#define CODE_MONITORENTER 0xC2
#define CODE_MONITOREXIT 0xC3
#define CODE_MULTIANEWARRAY 0xC5
#define CODE_NEW 0xBB
#define CODE_NEWARRAY 0xBC
#define CODE_NOP 0x0
#define CODE_POP 0x57
#define CODE_POP2 0x58
#define CODE_PUTFIELD 0xB5
#define CODE_PUTSTATIC 0xB3
#define CODE_RET 0xA9
#define CODE_RETURN 0xB1
#define CODE_SALOAD 0x35
#define CODE_SASTORE 0x56
#define CODE_SIPUSH 0x11
#define CODE_SWAP 0x5F
#define CODE_TABLESWITCH 0xAA
#define CODE_WIDE 0xC4

/*
std::cout << "Generating Switch:\n";
	std::fstream strem("CodeAttrStuff.txt");
	while (strem.good())
	{
		std::string opName = ""; strem >> opName;
		std::string opVal = ""; strem >> opVal;
		std::string opPNum = ""; strem >> opPNum;
		
		opName.erase(0, 5);
		int opValNum = std::stoi(opPNum);

		if (opValNum != 0)
			std::cout << "case CODE_" << opName << ": " << "k+=" << opValNum <<  "; std::cout << \"" << SToLower(opName) <<
			"\" << ";
		else
			std::cout << "case CODE_" << opName << ": " << "std::cout << \"" << SToLower(opName) <<
			"\" << ";
		for (int i = 0; i < opValNum; i++)
			std::cout << "\' \' << ByteToHexa(sbuf.Pop()) << ";
		std::cout << "\'\\n\'; break;\n";
	}
	return 0;
	---------------------------------------------------
	new version
	std::cout << "Generating Switch:\n";
	std::fstream strem("CodeAttrStuff.txt");
	while (strem.good())
	{
	std::string opName = ""; strem >> opName;
	std::string opVal = ""; strem >> opVal;
	std::string opPNum = ""; strem >> opPNum;

	opName.erase(0, 5);
	int opValNum = std::stoi(opPNum);

	std::cout << "case CODE_" << opName << ": " << "std::cout << \"" << SToLower(opName) << "\" << ";
	for (int i = 0; i < opValNum; i++)
	std::cout << "\' \' << ByteToHexa(buf[" << i << "]) << ";
	std::cout << "\'\\n\'; ";
	if (opValNum != 0)
		std::cout << "buf+=" << opValNum <<  ";";
	std::cout << "break; \n";
	}
	return 0;
	-----------------------------------------------
	GenerateCodeTable
	std::cout << "Generating Switch:\n";
	std::fstream strem("CodeAttrStuff.txt");
	int ind = 0;
	while (strem.good())
	{
	std::string opName = ""; strem >> opName;
	std::string opVal = ""; strem >> opVal;
	std::string opPNum = ""; strem >> opPNum;

	opName.erase(0, 5);
	int opValNum = std::stoi(opPNum);

	if (opValNum != 0)
	std::cout << "case CODE_" << opName << ": " << "buf+=" << opValNum <<  ";";
	else
	continue;
	ind = (ind+1)%4;
	std::cout << "break;";
	if (ind == 0)
	std::cout << '\n';
	else
	std::cout << ' ';
	}
	return 0;
	-----------------------------------------------
	GetCodeEntry
	std::cout << "Generating Switch:\n";
	std::fstream strem("CodeAttrStuff.txt");
	while (strem.good())
	{
		std::string opName = ""; strem >> opName;
		std::string opVal = ""; strem >> opVal;
		std::string opPNum = ""; strem >> opPNum;

		opName.erase(0, 5);
		int opValNum = std::stoi(opPNum);

		std::cout << "case CODE_" << opName << ": " << "hold = std::string(\"" << SToLower(opName) << "\")";
		for (int i = 0; i < opValNum; i++)
		{
			std::cout << "+\' \'+ByteToHexa(buf[" << i << "])";
		}
		std::cout << ";break; \n";
	}
	return 0;
*/