
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "JavaRepresentation.hpp"
#include "Helpers.hpp"

//TO DO:
//Keep track of first table op
//Correctly update cp table etc...
//Insertion and deletion
//Function to save new class file

int main()
{
	std::cout << "Console Test\n";
	
	std::cout << "Input file name: ";
	
	std::string filename;
	std::cin >> filename;

	StreamBuffer sbuf(filename);

	if (!sbuf.stream.is_open())
	{
		std::cout << "Couldn't open file\n";
		return 0;
	}


	std::cout << "\nPrinting Hex contents:\n";
	int charInd = 0;
	while (sbuf.CanPop())
	{
		if (charInd == 32)
		{
			charInd = 0;
			std::cout << '\n';
		}
		charInd++;

		unsigned char c;
		c = sbuf.Pop();
		std::cout << ByteToHexa(c) << " ";
	}

	ClassData classD;

	std::cout << "\n\n";
	std::vector<CPEntry>& entries = classD.entries;
	entries.push_back(CPEntry());
	
	sbuf.Seek(0);
	if (sbuf[0]==0xCA&&sbuf[1]==0xFE&&sbuf[2]==0xBA&&sbuf[3]==0xBE)
	{
		std::cout << "Valid file signature\n";
	}
	classD.major = sbuf[7]+(256*sbuf[6]);
	classD.minor = sbuf[5]+(256*sbuf[4]);
	if (sbuf[7] <= 48)
		std::cout << "Major Version: JDK 1." << classD.major-40 << '\n';
	else
		std::cout << "Major Version: Java SE " << classD.major-48 << '\n';
	std::cout << "Minor Version: " << classD.minor << '\n';

	int cpC = sbuf[9]+(256*sbuf[8]);
	classD.entries.resize(cpC);
	std::cout << "---Constant memory pool count of size " << cpC << '\n';
	sbuf += 10;
	for (int i = 1; i < cpC; i++)
	{
		entries[i] = CPEntry();
		CPEntry& ent = entries[i];

		int tag = sbuf[0]; ent.tag = tag;
		std::string tagS = CPTagSwitch(tag);
		std::cout << "CP Entry " << i << ": " << tagS << '\n';
		switch (tag)
		{
		case TAG_STRING:
		{
			int length = sbuf[2]+(256*sbuf[1]);
			CPString& cpString = *(new(&ent.uString) CPString(length));
			std::cout << "Length is " << length << '\n';
			std::cout << "Value of string: ";
			for (int i = 0; i < length; i++)
			{
				unsigned char v1 = sbuf[3+i]; cpString.data[i] = v1;
			}
			std::cout << cpString.getString();
			std::cout << '\n';
			sbuf += 3+length;
		}
			break;
		case TAG_INT:
		{
			unsigned char temp[4]; temp[0] = sbuf[0]; temp[1] = sbuf[1]; temp[2] = sbuf[2]; temp[3] = sbuf[3];
			int val = *(reinterpret_cast<int*>(temp)); 
			ent.uInt = CPInt(val);
			std::cout << "Value of int: " << val << '\n';
			sbuf += 5;
		}
			break;
		case TAG_FLOAT:
		{
			unsigned char temp[4]; temp[0] = sbuf[0]; temp[1] = sbuf[3]; temp[2] = sbuf[2]; temp[3] = sbuf[1]; //idk why its formatted like this
			float val = *(reinterpret_cast<float*>(temp)); 
			ent.uFloat = CPFloat(val);
			std::cout << "Value of float: " << val << '\n';
			sbuf += 5;
		}
			break;
		case TAG_LONG:
		{
			unsigned char temp[8]; temp[0] = sbuf[0]; temp[1] = sbuf[1]; temp[2] = sbuf[2]; temp[3] = sbuf[3];
			temp[4] = sbuf[4]; temp[5] = sbuf[5]; temp[6] = sbuf[6]; temp[7] = sbuf[7];
			long long val = *(reinterpret_cast<long long*>(temp)); 
			ent.uLong = CPLong(val);
			std::cout << "Value of long: " << val << '\n';
			sbuf += 9;
		}
			break;
		case TAG_DOUBLE:
		{
			std::cout << "Cannot handle Doubles\n"; abort();
			unsigned char temp[8]; temp[0] = sbuf[0]; temp[1] = sbuf[1]; temp[2] = sbuf[2]; temp[3] = sbuf[3];
			temp[4] = sbuf[4]; temp[5] = sbuf[5]; temp[6] = sbuf[6]; temp[7] = sbuf[7];
			double val = *(reinterpret_cast<double*>(temp)); 
			ent.uDoub = CPDouble(val);
			std::cout << "Value of double: " << val << '\n';
			sbuf += 9;
		}
			break;
		case TAG_CLASS:
		{
			int nameIndex = sbuf[2]+(256*sbuf[1]);
			ent.uClass = CPClass(nameIndex);
			std::cout << "Name index is " << nameIndex << '\n';
			sbuf += 3;
		}
			break;
		case TAG_STRING_REF:
		{
			int stringIndex = sbuf[2]+(256*sbuf[1]);
			ent.uStrRef = CPStringRef(stringIndex);
			std::cout << "String index is " << stringIndex << '\n';
			sbuf += 3;
		}
			break;
		case TAG_FIELD_REF:
		{
			int classIndex = sbuf[2]+(256*sbuf[1]);
			int natIndex = sbuf[4]+(256*sbuf[3]);
			ent.uFieldRef = CPFieldRef(classIndex, natIndex);
			std::cout << "Class index: " << classIndex << '\n';
			std::cout << "Name and Type index: " << natIndex << '\n';
			sbuf += 5;
		}
			break;
		case TAG_METHOD_REF:
		{
			int classIndex = sbuf[2]+(256*sbuf[1]);
			int natIndex = sbuf[4]+(256*sbuf[3]);
			ent.uMetRef = CPMethodRef(classIndex, natIndex);
			std::cout << "Class index: " << classIndex << '\n';
			std::cout << "Name and Type index: " << natIndex << '\n';
			sbuf += 5;
		}
			break;
		case TAG_INTERFACE_METHOD_REF:
		{
			std::cout << "Cannot handle Interface Method References\n"; abort();
			break;
		}
		case TAG_NAME_AND_TYPE:
		{
			int nameIndex = sbuf[2]+(256*sbuf[1]);
			int descIndex = sbuf[4]+(256*sbuf[3]);
			ent.uNat = CPNameAndType(nameIndex, descIndex);
			std::cout << "Name index: " << nameIndex << '\n';
			std::cout << "Descriptor index: " << descIndex << '\n';
			sbuf += 5;
		}
			break;
		case TAG_METHOD_HANDLE:
		{
			int kind = sbuf[1];
			int refIndex = sbuf[3]+(256*sbuf[2]);
			ent.uMetHandle = CPMethodHandle(kind, refIndex);
			std::cout << "Reference kind: ";
			switch (kind)
			{
			case 1: std::cout << "getField"; break; case 2: std::cout << "getStatic"; break; case 3: std::cout << "putField"; break; case 4: std::cout << "putStatic"; break;
			case 5: std::cout << "invokeVirtual"; break; case 6: std::cout << "invokeStatic"; break; case 7: std::cout << "invokeSpecial"; break; case 8: std::cout << "newInvokeSpecial"; break;
			case 9: std::cout << "invokeInterface"; break; default: std::cout << "invalid"; break;
			}
			std::cout << '\n';
			std::cout << "Descriptor index: " << refIndex << '\n';
			sbuf += 4;
		}
			break;
		case TAG_METHOD_TYPE:
		{
			std::cout << "Cannot handle Method Types\n"; abort();
		}
			break;
		case TAG_DYNAMIC:
		{
			std::cout << "Cannot handle Dynamics\n"; abort();
		}
			break;
		case TAG_INVOKE_DYNAMIC:
		{
			int bsIndex = sbuf[2]+(256*sbuf[1]);
			int natIndex = sbuf[4]+(256*sbuf[3]);
			ent.uInvDyn = CPInvokeDynamic(bsIndex, natIndex);
			std::cout << "Bootstrap index: " << bsIndex << '\n';
			std::cout << "Name and Type index: " << natIndex << '\n';
			sbuf += 5;
		}
			break;
		case TAG_MODULE:
		{
			std::cout << "Cannot handle Modules\n"; abort();
		}
			break;
		case TAG_PACKAGE:
		{
			std::cout << "Cannot handle Packages\n"; abort();
		}
			break;
		default:
		{
			std::cout << "Invalid type: " << tag << '\n';
		}
			break;
		}
	std::cout << '\n';
	}

	int accFlags = sbuf[1]+(256*sbuf[0]);
	classD.accessFlags = accFlags;
	std::cout << "\nClass/Interface flags:\n";
	if (accFlags&0x0001)
		std::cout << "Public\n";
	if (accFlags&0x0010)
		std::cout << "Final\n";
	if (accFlags&0x0020)
		std::cout << "Super\n";
	if (accFlags&0x0200)
		std::cout << "Interface\n";
	if (accFlags&0x0400)
		std::cout << "Abstract\n";
	if (accFlags&0x1000)
		std::cout << "Synthetic\n";
	if (accFlags&0x2000)
		std::cout << "Annotation\n";
	if (accFlags&0x4000)
		std::cout << "Enum\n";
	if (accFlags&0x8000)
		std::cout << "Module\n";


	std::cout << '\n';
	sbuf += 2;
	int thisIndex = sbuf[1]+(256*sbuf[0]);
	classD.thisIndex = thisIndex;
	std::cout << "This Class index: " << thisIndex << '\n';

	sbuf += 2;
	int superIndex = sbuf[1]+(256*sbuf[0]);
	classD.superIndex = superIndex;
	std::cout << "Super Class index: " << superIndex << '\n';

	std::cout << '\n';
	sbuf += 2;
	int interCount = sbuf[1]+(256*sbuf[0]);
	classD.interfaces.resize(interCount);
	std::cout << "---Interfaces count: " << interCount << '\n';
	sbuf += 2;
	for (int i = 1; i <= interCount; i++)
	{
		std::cout << "Interface Entry: " << i << '\n';
		int classIndex = sbuf[1]+(256*sbuf[0]);
		classD.interfaces[i] = classIndex;
		std::cout << "Class index: " << classIndex << '\n';
		sbuf += 2;
		std::cout << '\n';
	}
	std::cout << '\n';

	int fieldsCount = sbuf[1]+(256*sbuf[0]);
	classD.fields.resize(fieldsCount);
	std::cout << "---Fields count: " << fieldsCount << '\n';
	std::vector<Field>& fieldEntries = classD.fields;
	sbuf += 2;
	for (int i = 0; i < fieldsCount; i++)
	{
		std::cout << "Field Entry: " << i << '\n';
		int accessFlags = sbuf[1]+(256*sbuf[0]);
		int nameIndex = sbuf[3]+(256*sbuf[2]);
		int descIndex = sbuf[5]+(256*sbuf[4]);
		int attrCount = sbuf[7]+(256*sbuf[6]);
		fieldEntries[i] = Field(&classD,accessFlags,nameIndex,descIndex,attrCount); fieldEntries[i].attrs.resize(attrCount);
		
		if (accessFlags&0x0001)
			std::cout << "Public\n";
		if (accessFlags&0x0002)
			std::cout << "Private\n";
		if (accessFlags&0x0004)
			std::cout << "Protected\n";
		if (accessFlags&0x0008)
			std::cout << "Static\n";
		if (accessFlags&0x0010)
			std::cout << "Final\n";
		if (accessFlags&0x0040)
			std::cout << "Volatile\n";
		if (accessFlags&0x0080)
			std::cout << "Transient\n";
		if (accessFlags&0x1000)
			std::cout << "Synthetic\n";
		if (accessFlags&0x4000)
			std::cout << "Enum\n";

		std::cout << "Name index: " << nameIndex << '\n';
		std::cout << "Descriptor index: " << descIndex << '\n';
		std::cout << "Attribute count: " << attrCount << '\n';
		sbuf += 8;
		for (int j = 0; j < attrCount; j++)
		{
			Attribute& attr = fieldEntries[i].attrs[j];
			int attrNameIndex = sbuf[1]+(256*sbuf[0]);
			unsigned int attrLength = sbuf[5]+(256*sbuf[4])+(256*256*sbuf[3])+(256*256*256*sbuf[2]);
			std::cout << "\tAttribute name index: " << attrNameIndex << '\n';
			std::cout << "\tAttribute info length: " << attrLength << '\n';
			std::string attrName = entries[attrNameIndex].uString.getString();
			std::cout << "\tAttribute name: " << attrName << '\n';
			attr.nameIndex = attrNameIndex; attr.info.resize(attrLength);
			sbuf += 6;
			for (int i = 0; i < attrLength; i++)
				attr.info[i] = sbuf.Pop();
			//Ignore Custom attributes
			//for (int k = 0; k < attrLength; k++)
			//{
			//	std::cout << "Can't handle attributes\n"; abort();
			//	return 0;
			//}
			std::cout << '\n';
		}
	}
	std::cout << '\n';

	int methodsCount = sbuf[1]+(256*sbuf[0]);
	classD.methods.resize(methodsCount);
	std::cout << "---Methods count: " << methodsCount << '\n';
	std::vector<Method>& methodEntries = classD.methods;
	sbuf += 2;
	for (int i = 0; i < methodsCount; i++)
	{
		std::cout << "Method Entry: " << i << '\n';
		int accessFlags = sbuf[1]+(256*sbuf[0]);
		int nameIndex = sbuf[3]+(256*sbuf[2]);
		int descIndex = sbuf[5]+(256*sbuf[4]);
		int attrCount = sbuf[7]+(256*sbuf[6]);
		methodEntries[i] = Method(&classD,accessFlags,nameIndex,descIndex,attrCount); methodEntries[i].attrs.resize(attrCount);

		if (accessFlags&0x0001)
			std::cout << "Public\n";
		if (accessFlags&0x0002)
			std::cout << "Private\n";
		if (accessFlags&0x0004)
			std::cout << "Protected\n";
		if (accessFlags&0x0008)
			std::cout << "Static\n";
		if (accessFlags&0x0010)
			std::cout << "Final\n";
		if (accessFlags&0x0020)
			std::cout << "Synchronized\n";
		if (accessFlags&0x0040)
			std::cout << "Bridge\n";
		if (accessFlags&0x0080)
			std::cout << "VarArgs\n";
		if (accessFlags&0x0100)
			std::cout << "Native\n";
		if (accessFlags&0x0400)
			std::cout << "Abstract\n";
		if (accessFlags&0x0800)
			std::cout << "Strict\n";
		if (accessFlags&0x1000)
			std::cout << "Synthetic\n";

		std::cout << "Name index: " << nameIndex << '\n';
		std::cout << "Descriptor index: " << descIndex << '\n';
		std::cout << "Attribute count: " << attrCount << '\n';
		sbuf += 8;
		for (int j = 0; j < attrCount; j++)
		{
			Attribute& attr = methodEntries[i].attrs[j];
			std::cout << "\tAttribute Entry: " << j << '\n';
			int attrNameIndex = sbuf[1]+(256*sbuf[0]);
			unsigned int attrLength = sbuf[5]+(256*sbuf[4])+(256*256*sbuf[3])+(256*256*256*sbuf[2]);
			std::cout << "\tAttribute name index: " << attrNameIndex << '\n';
			std::cout << "\tAttribute info length: " << attrLength << '\n';
			std::string attrName = entries[attrNameIndex].uString.getString();
			std::cout << "\tAttribute name: " << attrName << '\n';
			attr.nameIndex = attrNameIndex; attr.info.resize(attrLength);
			sbuf += 6;
			for (int i = 0; i < attrLength; i++)
				attr.info[i] = sbuf.Pop();
			if (attrName == "Code")
				methodEntries[i].PrintCode();
			std::cout << '\n';
		}
	}
	std::cout << '\n';

	int attrsCount = sbuf[1]+(256*sbuf[0]);
	classD.attrs.resize(attrsCount);
	std::cout << "---Attributes count: " << attrsCount << '\n';
	std::vector<Attribute>& attrs = classD.attrs;
	sbuf += 2;
	for (int i = 0; i < attrsCount; i++)
	{
		std::cout << "Attribute Entry: " << i << '\n';
		int attrNameIndex = sbuf[1]+(256*sbuf[0]);
		unsigned int attrLength = sbuf[5]+(256*sbuf[4])+(256*256*sbuf[3])+(256*256*256*sbuf[2]);
		std::cout << "Attribute name index: " << attrNameIndex << '\n';
		std::cout << "Attribute info length: " << attrLength << '\n';
		std::string attrName = entries[attrNameIndex].uString.getString();
		std::cout << "\tAttribute name: " << attrName << '\n';
		attrs[i].nameIndex = attrNameIndex; attrs[i].info.resize(attrLength);
		sbuf += 6;
		for (int j = 0; j < attrLength; j++)
			attrs[i].info[j] = sbuf.Pop();
		std::cout << '\n';
	}

	std::cout << '\n';


	//methodEntries[2].ModifyCodeLine("invokestatic 00 00", 10);
	methodEntries[2].PrintJumpTable();

	methodEntries[2].ModifyCodeLine("goto 00 08", 7);
	methodEntries[2].PrintCode();
	methodEntries[2].PrintJumpTable();
	std::cout << "Line 10: " << methodEntries[2].GetCodeLine(10) << ", Line 11: " << methodEntries[2].GetCodeLine(11) << ", Line 34: " << methodEntries[2].GetCodeLine(34) << '\n';
	methodEntries[2].ModifyCodeLine("nop", 25);
	methodEntries[2].PrintCode();
	methodEntries[2].PrintJumpTable();
	std::cout << "Line 10: " << methodEntries[2].GetCodeLine(10) << ", Line 11: " << methodEntries[2].GetCodeLine(11) << ", Line 34: " << methodEntries[2].GetCodeLine(34) << '\n';

	/*
	
	std::string input = "";
	std::getline(std::cin,input);
	std::string word = "";
	while (true)
	{
		if (!std::cin.good())
			std::cout << "Input an option (\"help\" for help):\n";
		std::getline(std::cin,input); //probably use a string buffer
		std::stringstream inputS(input);
		while (!inputS.eof())
		{
			inputS >> word; word = SToLower(word);
			char helpMessage[] =
				R"(Option list:
	exit, e: terminates program
		no parameters
	help, h: display this text
		no parameters
	method, m: view, modify, and add to methods
		must have an int to select a method
		-r: read the entire method
		-rl: read a line of the method, followed by int
		-rs: read a segment of the method, followed by lower index (inclusive) then higher index (exclusive)
		-ml: modify a line of the method, followed by index of line to modify then code to insert as string with hex parameters
		-il: insert a line into the method, followed by index of new line then code to insert as string with hex parameters
		-dl: delete a line of the method, followed by index of line to remove
	generate, g: generate a new class file from data
		must have a string to specify name of new file
		-d: output directory of file, followed by string of directory)";
			if (word == "help")
				std::cout << helpMessage << "\n\n";
			if (word == "exit")
				break;
			if (word == "method")
				ParseMethodManip(methodEntries, inputS);
		}
		if (word == "exit")
			break;
	}
	*/
	return 0;
}