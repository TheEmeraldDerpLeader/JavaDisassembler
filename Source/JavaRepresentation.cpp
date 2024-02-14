#include "JavaRepresentation.hpp"

int HexaCharToInt(const char* c, int count)
{
	int sum = 0;
	int pow = (1<<((count-1)*4));
	for (int i = 0; i < count; i++)
	{
		switch (c[i])
		{
		case '0': sum += 0*pow; break; case '1': sum += 1*pow; break; case '2': sum += 2*pow; break; case '3': sum += 3*pow; break;
		case '4': sum += 4*pow; break; case '5': sum += 5*pow; break; case '6': sum += 6*pow; break; case '7': sum += 7*pow; break;
		case '8': sum += 8*pow; break; case '9': sum += 9*pow; break; case 'A': sum += 10*pow; break; case 'B': sum += 11*pow; break;
		case 'C': sum += 12*pow; break; case 'D': sum += 13*pow; break; case 'E': sum += 14*pow; break; case 'F': sum += 15*pow; break;
		default: sum += 0;
		}
		pow /= 16;
	}
	return sum;
}
int HexaCharToInt(const std::string str, int count, int index)
{
	return HexaCharToInt(str.data()+index,count);
}
std::string ByteToHexa(int byte)
{
	return (std::string("")+IntToHexaChar(byte/16))+IntToHexaChar(byte%16);
}
void ReadAt(unsigned char* hbuf, std::fstream& stream, int bytes, int index)
{
	stream.clear();
	stream.seekg(index);
	stream.read(reinterpret_cast<char*>(hbuf),bytes);
}
std::string CPTagSwitch(unsigned char tag)
{
	switch (tag)
	{
	default: return "Invalid Tag"; break; case TAG_STRING: return "String"; break;
	case TAG_INT: return "Int"; break; case TAG_FLOAT: return "Float"; break;
	case TAG_LONG: return "Long"; break; case TAG_DOUBLE: return "Double"; break;
	case TAG_CLASS: return "Class"; break; 
	case TAG_STRING_REF: return "String Ref"; break;
	case TAG_FIELD_REF: return "Field Ref"; break; case TAG_METHOD_REF: return "Method Ref"; break;
	case TAG_INTERFACE_METHOD_REF: return "Interface Method Ref"; break; case TAG_NAME_AND_TYPE: return "Name and Type"; break;
	case TAG_METHOD_HANDLE: return "Method Handle"; break; case TAG_METHOD_TYPE: return "Method Type"; break;
	case TAG_DYNAMIC: return "Dynamic"; break; case TAG_INVOKE_DYNAMIC: return "Invoke Dynamic"; break;
	case TAG_MODULE: return "Module"; break; case TAG_PACKAGE: return "Package"; break;
	}
}

std::string CPString::getString()
{
	std::string hold;
	for (int i = 0; i < length; i++)
	{
		unsigned char v1 = data[i];
		if (v1 != 0 && v1 < 0x80)
			hold += *reinterpret_cast<char*>(&v1);
		else
		{
			hold += '-';
			unsigned char v2 = data[i+1];
			if (v2 < 0x08)
				i++;
			else
				i += 2;
		}
	}
	return hold;
}

CPString::CPString(CPString& stringRef)
{
	length = stringRef.length;
	data = new unsigned char[length];
	for (int i = 0; i < length; i++)
		data[i] = stringRef.data[i];
}

CPString& CPString::operator=(CPString& stringRef)
{
	if (data != nullptr)
		delete data;
	length = stringRef.length;
	data = new unsigned char[length];
	for (int i = 0; i < length; i++)
		data[i] = stringRef.data[i];
	return *this;
}

CPString::CPString(CPString&& stringTemp)
{
	length = stringTemp.length;
	data = stringTemp.data;
	stringTemp.data = nullptr;
}

CPString& CPString::operator=(CPString&& stringTemp)
{
	if (data != nullptr)
		delete data;
	length = stringTemp.length;
	data = stringTemp.data;
	stringTemp.data = nullptr;
	return *this;
}

CPEntry::CPEntry(CPEntry& entryRef)
{
	tag = entryRef.tag;
	switch (tag)
	{
#define CASE_PLACEMENT_NEW(mName, cName, fName) case mName: tag = entryRef.tag; new (&fName) cName(entryRef.fName); break;
	default: uInt = CPInt(0); break;
		CASE_PLACEMENT_NEW(TAG_STRING, CPString, uString)
		CASE_PLACEMENT_NEW(TAG_INT, CPInt, uInt)
		CASE_PLACEMENT_NEW(TAG_FLOAT, CPFloat, uFloat)
		CASE_PLACEMENT_NEW(TAG_LONG, CPLong, uLong)
		CASE_PLACEMENT_NEW(TAG_DOUBLE, CPDouble, uDoub)
		CASE_PLACEMENT_NEW(TAG_CLASS, CPClass, uClass)
		CASE_PLACEMENT_NEW(TAG_STRING_REF, CPStringRef, uStrRef)
		CASE_PLACEMENT_NEW(TAG_FIELD_REF, CPFieldRef, uFieldRef)
		CASE_PLACEMENT_NEW(TAG_METHOD_REF, CPMethodRef, uMetRef)
		CASE_PLACEMENT_NEW(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
		CASE_PLACEMENT_NEW(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
		CASE_PLACEMENT_NEW(TAG_METHOD_TYPE, CPMethodType, uMetType)
		CASE_PLACEMENT_NEW(TAG_DYNAMIC, CPDynamic, uDyn)
		CASE_PLACEMENT_NEW(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
		CASE_PLACEMENT_NEW(TAG_MODULE, CPModule, uModule)
		CASE_PLACEMENT_NEW(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_PLACEMENT_NEW
	}
}

CPEntry& CPEntry::operator=(CPEntry& entryRef)
{
	if (tag != entryRef.tag)
	{
		switch (tag)
		{
#define CASE_DESTRUCT(mName, cName, fName) case mName: fName.~cName(); break;
		default: break;
			CASE_DESTRUCT(TAG_STRING, CPString, uString)
			CASE_DESTRUCT(TAG_INT, CPInt, uInt)
			CASE_DESTRUCT(TAG_FLOAT, CPFloat, uFloat)
			CASE_DESTRUCT(TAG_LONG, CPLong, uLong)
			CASE_DESTRUCT(TAG_DOUBLE, CPDouble, uDoub)
			CASE_DESTRUCT(TAG_CLASS, CPClass, uClass)
			CASE_DESTRUCT(TAG_STRING_REF, CPStringRef, uStrRef)
			CASE_DESTRUCT(TAG_FIELD_REF, CPFieldRef, uFieldRef)
			CASE_DESTRUCT(TAG_METHOD_REF, CPMethodRef, uMetRef)
			CASE_DESTRUCT(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
			CASE_DESTRUCT(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
			CASE_DESTRUCT(TAG_METHOD_TYPE, CPMethodType, uMetType)
			CASE_DESTRUCT(TAG_DYNAMIC, CPDynamic, uDyn)
			CASE_DESTRUCT(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
			CASE_DESTRUCT(TAG_MODULE, CPModule, uModule)
			CASE_DESTRUCT(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_DESTRUCT
		}

		tag = entryRef.tag;
		switch (tag)
		{
#define CASE_PLACEMENT_NEW(mName, cName, fName) case mName: tag = entryRef.tag; new (&fName) cName(entryRef.fName); break;
			default: break;
			CASE_PLACEMENT_NEW(TAG_STRING, CPString, uString)
			CASE_PLACEMENT_NEW(TAG_INT, CPInt, uInt)
			CASE_PLACEMENT_NEW(TAG_FLOAT, CPFloat, uFloat)
			CASE_PLACEMENT_NEW(TAG_LONG, CPLong, uLong)
			CASE_PLACEMENT_NEW(TAG_DOUBLE, CPDouble, uDoub)
			CASE_PLACEMENT_NEW(TAG_CLASS, CPClass, uClass)
			CASE_PLACEMENT_NEW(TAG_STRING_REF, CPStringRef, uStrRef)
			CASE_PLACEMENT_NEW(TAG_FIELD_REF, CPFieldRef, uFieldRef)
			CASE_PLACEMENT_NEW(TAG_METHOD_REF, CPMethodRef, uMetRef)
			CASE_PLACEMENT_NEW(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
			CASE_PLACEMENT_NEW(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
			CASE_PLACEMENT_NEW(TAG_METHOD_TYPE, CPMethodType, uMetType)
			CASE_PLACEMENT_NEW(TAG_DYNAMIC, CPDynamic, uDyn)
			CASE_PLACEMENT_NEW(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
			CASE_PLACEMENT_NEW(TAG_MODULE, CPModule, uModule)
			CASE_PLACEMENT_NEW(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_PLACEMENT_NEW
		}
	}
	else
	{
		switch (tag)
		{
#define CASE_ASSIGN(mName, cName, fName) case mName: tag = entryRef.tag; fName = entryRef.fName; break;
		default: break;
			CASE_ASSIGN(TAG_STRING, CPString, uString)
			CASE_ASSIGN(TAG_INT, CPInt, uInt)
			CASE_ASSIGN(TAG_FLOAT, CPFloat, uFloat)
			CASE_ASSIGN(TAG_LONG, CPLong, uLong)
			CASE_ASSIGN(TAG_DOUBLE, CPDouble, uDoub)
			CASE_ASSIGN(TAG_CLASS, CPClass, uClass)
			CASE_ASSIGN(TAG_STRING_REF, CPStringRef, uStrRef)
			CASE_ASSIGN(TAG_FIELD_REF, CPFieldRef, uFieldRef)
			CASE_ASSIGN(TAG_METHOD_REF, CPMethodRef, uMetRef)
			CASE_ASSIGN(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
			CASE_ASSIGN(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
			CASE_ASSIGN(TAG_METHOD_TYPE, CPMethodType, uMetType)
			CASE_ASSIGN(TAG_DYNAMIC, CPDynamic, uDyn)
			CASE_ASSIGN(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
			CASE_ASSIGN(TAG_MODULE, CPModule, uModule)
			CASE_ASSIGN(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_ASSIGN
		}
	}
	return *this;
}
CPEntry::CPEntry(CPEntry&& entryTemp)
{
	tag = entryTemp.tag;
	switch (tag)
	{
#define CASE_PLACEMENT_NEW(mName, cName, fName) case mName: tag = entryTemp.tag; new (&fName) cName(entryTemp.fName); break;
	default: uInt = CPInt(0);  break;
		CASE_PLACEMENT_NEW(TAG_STRING, CPString, uString)
		CASE_PLACEMENT_NEW(TAG_INT, CPInt, uInt)
		CASE_PLACEMENT_NEW(TAG_FLOAT, CPFloat, uFloat)
		CASE_PLACEMENT_NEW(TAG_LONG, CPLong, uLong)
		CASE_PLACEMENT_NEW(TAG_DOUBLE, CPDouble, uDoub)
		CASE_PLACEMENT_NEW(TAG_CLASS, CPClass, uClass)
		CASE_PLACEMENT_NEW(TAG_STRING_REF, CPStringRef, uStrRef)
		CASE_PLACEMENT_NEW(TAG_FIELD_REF, CPFieldRef, uFieldRef)
		CASE_PLACEMENT_NEW(TAG_METHOD_REF, CPMethodRef, uMetRef)
		CASE_PLACEMENT_NEW(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
		CASE_PLACEMENT_NEW(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
		CASE_PLACEMENT_NEW(TAG_METHOD_TYPE, CPMethodType, uMetType)
		CASE_PLACEMENT_NEW(TAG_DYNAMIC, CPDynamic, uDyn)
		CASE_PLACEMENT_NEW(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
		CASE_PLACEMENT_NEW(TAG_MODULE, CPModule, uModule)
		CASE_PLACEMENT_NEW(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_PLACEMENT_NEW
	}
}
CPEntry& CPEntry::operator=(CPEntry&& entryTemp)
{
	if (tag != entryTemp.tag)
	{
		switch (tag)
		{
#define CASE_DESTRUCT(mName, cName, fName) case mName: fName.~cName(); break;
		default: break;
			CASE_DESTRUCT(TAG_STRING, CPString, uString)
			CASE_DESTRUCT(TAG_INT, CPInt, uInt)
			CASE_DESTRUCT(TAG_FLOAT, CPFloat, uFloat)
			CASE_DESTRUCT(TAG_LONG, CPLong, uLong)
			CASE_DESTRUCT(TAG_DOUBLE, CPDouble, uDoub)
			CASE_DESTRUCT(TAG_CLASS, CPClass, uClass)
			CASE_DESTRUCT(TAG_STRING_REF, CPStringRef, uStrRef)
			CASE_DESTRUCT(TAG_FIELD_REF, CPFieldRef, uFieldRef)
			CASE_DESTRUCT(TAG_METHOD_REF, CPMethodRef, uMetRef)
			CASE_DESTRUCT(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
			CASE_DESTRUCT(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
			CASE_DESTRUCT(TAG_METHOD_TYPE, CPMethodType, uMetType)
			CASE_DESTRUCT(TAG_DYNAMIC, CPDynamic, uDyn)
			CASE_DESTRUCT(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
			CASE_DESTRUCT(TAG_MODULE, CPModule, uModule)
			CASE_DESTRUCT(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_DESTRUCT
		}

		tag = entryTemp.tag;
		switch (tag)
		{
#define CASE_PLACEMENT_NEW(mName, cName, fName) case mName: tag = entryTemp.tag; new (&fName) cName(entryTemp.fName); break;
		default: break;
			CASE_PLACEMENT_NEW(TAG_STRING, CPString, uString)
			CASE_PLACEMENT_NEW(TAG_INT, CPInt, uInt)
			CASE_PLACEMENT_NEW(TAG_FLOAT, CPFloat, uFloat)
			CASE_PLACEMENT_NEW(TAG_LONG, CPLong, uLong)
			CASE_PLACEMENT_NEW(TAG_DOUBLE, CPDouble, uDoub)
			CASE_PLACEMENT_NEW(TAG_CLASS, CPClass, uClass)
			CASE_PLACEMENT_NEW(TAG_STRING_REF, CPStringRef, uStrRef)
			CASE_PLACEMENT_NEW(TAG_FIELD_REF, CPFieldRef, uFieldRef)
			CASE_PLACEMENT_NEW(TAG_METHOD_REF, CPMethodRef, uMetRef)
			CASE_PLACEMENT_NEW(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
			CASE_PLACEMENT_NEW(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
			CASE_PLACEMENT_NEW(TAG_METHOD_TYPE, CPMethodType, uMetType)
			CASE_PLACEMENT_NEW(TAG_DYNAMIC, CPDynamic, uDyn)
			CASE_PLACEMENT_NEW(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
			CASE_PLACEMENT_NEW(TAG_MODULE, CPModule, uModule)
			CASE_PLACEMENT_NEW(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_PLACEMENT_NEW
		}
	}
	else
	{
		switch (tag)
		{
#define CASE_ASSIGN(mName, cName, fName) case mName: tag = entryTemp.tag; fName = entryTemp.fName; break;
		default: break;
			CASE_ASSIGN(TAG_STRING, CPString, uString)
			CASE_ASSIGN(TAG_INT, CPInt, uInt)
			CASE_ASSIGN(TAG_FLOAT, CPFloat, uFloat)
			CASE_ASSIGN(TAG_LONG, CPLong, uLong)
			CASE_ASSIGN(TAG_DOUBLE, CPDouble, uDoub)
			CASE_ASSIGN(TAG_CLASS, CPClass, uClass)
			CASE_ASSIGN(TAG_STRING_REF, CPStringRef, uStrRef)
			CASE_ASSIGN(TAG_FIELD_REF, CPFieldRef, uFieldRef)
			CASE_ASSIGN(TAG_METHOD_REF, CPMethodRef, uMetRef)
			CASE_ASSIGN(TAG_INTERFACE_METHOD_REF, CPInterfaceMethodRef, uInterMetRef)
			CASE_ASSIGN(TAG_NAME_AND_TYPE, CPNameAndType, uNat)
			CASE_ASSIGN(TAG_METHOD_TYPE, CPMethodType, uMetType)
			CASE_ASSIGN(TAG_DYNAMIC, CPDynamic, uDyn)
			CASE_ASSIGN(TAG_INVOKE_DYNAMIC, CPInvokeDynamic, uInvDyn)
			CASE_ASSIGN(TAG_MODULE, CPModule, uModule)
			CASE_ASSIGN(TAG_PACKAGE, CPPackage, uPack)
#undef CASE_ASSIGN
		}
	}
	return *this;
}

CPEntry::~CPEntry()
{
	if (tag == 1)
	{
		uString.~CPString();
	}
}