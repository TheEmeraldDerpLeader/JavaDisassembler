#include "JavaRepresentation.hpp"

#include <algorithm>

/*
MonicToOp generator
std::fstream strem("CodeAttrStuff.txt");
std::vector<std::string> names;
//std::vector<int> opVals;
while (strem.good())
{
	std::string opName = ""; strem >> opName;
	std::string opVal = ""; strem >> opVal;
	std::string opPNum = ""; strem >> opPNum;
	opName.erase(0, 5);

	names.push_back(opName);

	opVal.erase(0, 2);
	//opVals.push_back(HexaCharToInt(opVal.data(), 2));
}

int maxName = 0; for (int i = 0; i < names.size(); i++) maxName = std::max(maxName, int(names[i].length()));
std::vector<std::string> preKeys; preKeys.resize(names.size());
std::vector<bool> consider; consider.resize(maxName); for (int i = 0; i < consider.size(); i++) consider[i] = false; consider[0] = true;
std::vector<bool> minTest; int minTestVal = 1000;
if (false)
{
	std::cout << "Calculating minimal key set:\n";
	while (true)
	{
		for (int i = 0; i < preKeys.size(); i++) preKeys[i] = "" + std::to_string(names[i].length()) + names[i].back();
		int checkC = 0;
		for (int i = 0; i < consider.size(); i++)
			if (consider[i])
				checkC++;
		if (checkC == 0)
			break;

		if (checkC < minTestVal)
		{
			//int pow = ('Z'-'A')+1;
			for (int i = 0; i < consider.size(); i++)
			{
				if (consider[i])
				{
					for (int j = 0; j < preKeys.size(); j++)
					{
						std::string& name = names[j];
						if (i >= name.length())
							continue;
						else
							//preKeys[j] += pow*(name[i]-'A');
							preKeys[j] += name[i];
					}
					//pow *= ('Z'-'A')+1;
					//pow *= 6;
				}
			}

			bool dupe = false;
			for (int i = 0; i < preKeys.size(); i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (preKeys[i] == preKeys[j])
					{
						dupe = true;
						break;
					}
				}
				if (dupe)
					break;
			}
			if (!dupe)
			{
				minTest = consider;
				minTestVal = checkC;
			}
		}

		for (int i = 0; i < consider.size(); i++)
		{
			if (!consider[i])
			{
				consider[i] = true;
				break;
			}
			else
			{
				consider[i] = false;
			}
		}
	}
}
else
minTest = { 1,0,1,1,0,0,0,1,0,0,0,0,0,0,0 };

// 1 0 1 1 0 0 0 1 0 0 0 0 0 0 0 + length + last
std::cout << "Generating and verifying keys:\n";
std::vector<int> keys; keys.resize(preKeys.size()); for (int i = 0; i < keys.size(); i++) keys[i] = names[i].length()+names[i].back();
int pow = 16;
for (int i = 0; i < minTest.size(); i++)
{
	if (minTest[i])
	{
		for (int j = 0; j < keys.size(); j++)
		{
			std::string& name = names[j];
			if (i >= name.length())
				continue;
			else
				keys[j] += name[i]*pow;
		}
		pow *= 8;
	}
}
bool dupe = false;
for (int i = 0; i < keys.size(); i++)
{
	for (int j = 0; j < i; j++)
	{
		if (keys[i] == keys[j])
		{
			dupe = true;
			break;
		}
	}
	if (dupe)
		break;
}


std::cout << "Generating switch:\n";
for (int i = 0; i < names.size(); i++)
{
	std::cout << "case " << keys[i] << ": return CODE_" << names[i] << "; break;";
	if (i%4 == 3)
		std::cout << '\n';
	else
		std::cout << ' ';
}
return 0;
*/

std::string OpToMonic(unsigned char op)
{
	switch (op)
	{
	case CODE_AALOAD: return std::string("aaload"); break;
	case CODE_AASTORE: return std::string("aastore"); break;
	case CODE_ACONST_NULL: return std::string("aconst_null"); break;
	case CODE_ALOAD: return std::string("aload"); break;
	case CODE_ALOAD_0: return std::string("aload_0"); break;
	case CODE_ALOAD_1: return std::string("aload_1"); break;
	case CODE_ALOAD_2: return std::string("aload_2"); break;
	case CODE_ALOAD_3: return std::string("aload_3"); break;
	case CODE_ANEWARRAY: return std::string("anewarray"); break;
	case CODE_ARETURN: return std::string("areturn"); break;
	case CODE_ARRAYLENGTH: return std::string("arraylength"); break;
	case CODE_ASTORE: return std::string("astore"); break;
	case CODE_ASTORE_0: return std::string("astore_0"); break;
	case CODE_ASTORE_1: return std::string("astore_1"); break;
	case CODE_ASTORE_2: return std::string("astore_2"); break;
	case CODE_ASTORE_3: return std::string("astore_3"); break;
	case CODE_ATHROW: return std::string("athrow"); break;
	case CODE_BALOAD: return std::string("baload"); break;
	case CODE_BASTORE: return std::string("bastore"); break;
	case CODE_BIPUSH: return std::string("bipush"); break;
	case CODE_CALOAD: return std::string("caload"); break;
	case CODE_CASTORE: return std::string("castore"); break;
	case CODE_CHECKCAST: return std::string("checkcast"); break;
	case CODE_D2F: return std::string("d2f"); break;
	case CODE_D2I: return std::string("d2i"); break;
	case CODE_D2L: return std::string("d2l"); break;
	case CODE_DADD: return std::string("dadd"); break;
	case CODE_DALOAD: return std::string("daload"); break;
	case CODE_DASTORE: return std::string("dastore"); break;
	case CODE_DCMPG: return std::string("dcmpg"); break;
	case CODE_DCMPL: return std::string("dcmpl"); break;
	case CODE_DCONST_0: return std::string("dconst_0"); break;
	case CODE_DCONST_1: return std::string("dconst_1"); break;
	case CODE_DDIV: return std::string("ddiv"); break;
	case CODE_DLOAD: return std::string("dload"); break;
	case CODE_DLOAD_0: return std::string("dload_0"); break;
	case CODE_DLOAD_1: return std::string("dload_1"); break;
	case CODE_DLOAD_2: return std::string("dload_2"); break;
	case CODE_DLOAD_3: return std::string("dload_3"); break;
	case CODE_DMUL: return std::string("dmul"); break;
	case CODE_DNEG: return std::string("dneg"); break;
	case CODE_DREM: return std::string("drem"); break;
	case CODE_DRETURN: return std::string("dreturn"); break;
	case CODE_DSTORE: return std::string("dstore"); break;
	case CODE_DSTORE_0: return std::string("dstore_0"); break;
	case CODE_DSTORE_1: return std::string("dstore_1"); break;
	case CODE_DSTORE_2: return std::string("dstore_2"); break;
	case CODE_DSTORE_3: return std::string("dstore_3"); break;
	case CODE_DSUB: return std::string("dsub"); break;
	case CODE_DUP: return std::string("dup"); break;
	case CODE_DUP_X1: return std::string("dup_x1"); break;
	case CODE_DUP_X2: return std::string("dup_x2"); break;
	case CODE_DUP2: return std::string("dup2"); break;
	case CODE_DUP2_X1: return std::string("dup2_x1"); break;
	case CODE_DUP2_X2: return std::string("dup2_x2"); break;
	case CODE_F2D: return std::string("f2d"); break;
	case CODE_F2I: return std::string("f2i"); break;
	case CODE_F2L: return std::string("f2l"); break;
	case CODE_FADD: return std::string("fadd"); break;
	case CODE_FALOAD: return std::string("faload"); break;
	case CODE_FASTORE: return std::string("fastore"); break;
	case CODE_FCMPG: return std::string("fcmpg"); break;
	case CODE_FCMPL: return std::string("fcmpl"); break;
	case CODE_FCONST_0: return std::string("fconst_0"); break;
	case CODE_FCONST_1: return std::string("fconst_1"); break;
	case CODE_FCONST_2: return std::string("fconst_2"); break;
	case CODE_FDIV: return std::string("fdiv"); break;
	case CODE_FLOAD: return std::string("fload"); break;
	case CODE_FLOAD_0: return std::string("fload_0"); break;
	case CODE_FLOAD_1: return std::string("fload_1"); break;
	case CODE_FLOAD_2: return std::string("fload_2"); break;
	case CODE_FLOAD_3: return std::string("fload_3"); break;
	case CODE_FMUL: return std::string("fmul"); break;
	case CODE_FNEG: return std::string("fneg"); break;
	case CODE_FREM: return std::string("frem"); break;
	case CODE_FRETURN: return std::string("freturn"); break;
	case CODE_FSTORE: return std::string("fstore"); break;
	case CODE_FSTORE_0: return std::string("fstore_0"); break;
	case CODE_FSTORE_1: return std::string("fstore_1"); break;
	case CODE_FSTORE_2: return std::string("fstore_2"); break;
	case CODE_FSTORE_3: return std::string("fstore_3"); break;
	case CODE_FSUB: return std::string("fsub"); break;
	case CODE_GETFIELD: return std::string("getfield"); break;
	case CODE_GETSTATIC: return std::string("getstatic"); break;
	case CODE_GOTO: return std::string("goto"); break;
	case CODE_GOTO_W: return std::string("goto_w"); break;
	case CODE_I2B: return std::string("i2b"); break;
	case CODE_I2C: return std::string("i2c"); break;
	case CODE_I2D: return std::string("i2d"); break;
	case CODE_I2F: return std::string("i2f"); break;
	case CODE_I2L: return std::string("i2l"); break;
	case CODE_I2S: return std::string("i2s"); break;
	case CODE_IADD: return std::string("iadd"); break;
	case CODE_IALOAD: return std::string("iaload"); break;
	case CODE_IAND: return std::string("iand"); break;
	case CODE_IASTORE: return std::string("iastore"); break;
	case CODE_ICONST_M1: return std::string("iconst_m1"); break;
	case CODE_ICONST_0: return std::string("iconst_0"); break;
	case CODE_ICONST_1: return std::string("iconst_1"); break;
	case CODE_ICONST_2: return std::string("iconst_2"); break;
	case CODE_ICONST_3: return std::string("iconst_3"); break;
	case CODE_ICONST_4: return std::string("iconst_4"); break;
	case CODE_ICONST_5: return std::string("iconst_5"); break;
	case CODE_IDIV: return std::string("idiv"); break;
	case CODE_IF_ACMPEQ: return std::string("if_acmpeq"); break;
	case CODE_IF_ACMPNE: return std::string("if_acmpne"); break;
	case CODE_IF_ICMPEQ: return std::string("if_icmpeq"); break;
	case CODE_IF_ICMPNE: return std::string("if_icmpne"); break;
	case CODE_IF_ICMPLT: return std::string("if_icmplt"); break;
	case CODE_IF_ICMPGE: return std::string("if_icmpge"); break;
	case CODE_IF_ICMPGT: return std::string("if_icmpgt"); break;
	case CODE_IF_ICMPLE: return std::string("if_icmple"); break;
	case CODE_IFEQ: return std::string("ifeq"); break;
	case CODE_IFNE: return std::string("ifne"); break;
	case CODE_IFLT: return std::string("iflt"); break;
	case CODE_IFGE: return std::string("ifge"); break;
	case CODE_IFGT: return std::string("ifgt"); break;
	case CODE_IFLE: return std::string("ifle"); break;
	case CODE_IFNONNULL: return std::string("ifnonnull"); break;
	case CODE_IFNULL: return std::string("ifnull"); break;
	case CODE_IINC: return std::string("iinc"); break;
	case CODE_ILOAD: return std::string("iload"); break;
	case CODE_ILOAD_0: return std::string("iload_0"); break;
	case CODE_ILOAD_1: return std::string("iload_1"); break;
	case CODE_ILOAD_2: return std::string("iload_2"); break;
	case CODE_ILOAD_3: return std::string("iload_3"); break;
	case CODE_IMUL: return std::string("imul"); break;
	case CODE_INEG: return std::string("ineg"); break;
	case CODE_INSTANCEOF: return std::string("instanceof"); break;
	case CODE_INVOKEDYNAMIC: return std::string("invokedynamic"); break;
	case CODE_INVOKEINTERFACE: return std::string("invokeinterface"); break;
	case CODE_INVOKESPECIAL: return std::string("invokespecial"); break;
	case CODE_INVOKESTATIC: return std::string("invokestatic"); break;
	case CODE_INVOKEVIRTUAL: return std::string("invokevirtual"); break;
	case CODE_IOR: return std::string("ior"); break;
	case CODE_IREM: return std::string("irem"); break;
	case CODE_IRETURN: return std::string("ireturn"); break;
	case CODE_ISHL: return std::string("ishl"); break;
	case CODE_ISHR: return std::string("ishr"); break;
	case CODE_ISTORE: return std::string("istore"); break;
	case CODE_ISTORE_0: return std::string("istore_0"); break;
	case CODE_ISTORE_1: return std::string("istore_1"); break;
	case CODE_ISTORE_2: return std::string("istore_2"); break;
	case CODE_ISTORE_3: return std::string("istore_3"); break;
	case CODE_ISUB: return std::string("isub"); break;
	case CODE_IUSHR: return std::string("iushr"); break;
	case CODE_IXOR: return std::string("ixor"); break;
	case CODE_JSR: return std::string("jsr"); break;
	case CODE_JSR_W: return std::string("jsr_w"); break;
	case CODE_L2D: return std::string("l2d"); break;
	case CODE_L2F: return std::string("l2f"); break;
	case CODE_L2I: return std::string("l2i"); break;
	case CODE_LADD: return std::string("ladd"); break;
	case CODE_LALOAD: return std::string("laload"); break;
	case CODE_LAND: return std::string("land"); break;
	case CODE_LASTORE: return std::string("lastore"); break;
	case CODE_LCMP: return std::string("lcmp"); break;
	case CODE_LCONST_0: return std::string("lconst_0"); break;
	case CODE_LCONST_1: return std::string("lconst_1"); break;
	case CODE_LDC: return std::string("ldc"); break;
	case CODE_LDC_W: return std::string("ldc_w"); break;
	case CODE_LDC2_W: return std::string("ldc2_w"); break;
	case CODE_LDIV: return std::string("ldiv"); break;
	case CODE_LLOAD: return std::string("lload"); break;
	case CODE_LLOAD_0: return std::string("lload_0"); break;
	case CODE_LLOAD_1: return std::string("lload_1"); break;
	case CODE_LLOAD_2: return std::string("lload_2"); break;
	case CODE_LLOAD_3: return std::string("lload_3"); break;
	case CODE_LMUL: return std::string("lmul"); break;
	case CODE_LNEG: return std::string("lneg"); break;
	case CODE_LOR: return std::string("lor"); break;
	case CODE_LREM: return std::string("lrem"); break;
	case CODE_LRETURN: return std::string("lreturn"); break;
	case CODE_LSHL: return std::string("lshl"); break;
	case CODE_LSHR: return std::string("lshr"); break;
	case CODE_LSTORE: return std::string("lstore"); break;
	case CODE_LSTORE_0: return std::string("lstore_0"); break;
	case CODE_LSTORE_1: return std::string("lstore_1"); break;
	case CODE_LSTORE_2: return std::string("lstore_2"); break;
	case CODE_LSTORE_3: return std::string("lstore_3"); break;
	case CODE_LSUB: return std::string("lsub"); break;
	case CODE_LUSHR: return std::string("lushr"); break;
	case CODE_LXOR: return std::string("lxor"); break;
	case CODE_MONITORENTER: return std::string("monitorenter"); break;
	case CODE_MONITOREXIT: return std::string("monitorexit"); break;
	case CODE_MULTIANEWARRAY: return std::string("multianewarray"); break;
	case CODE_NEW: return std::string("new"); break;
	case CODE_NEWARRAY: return std::string("newarray"); break;
	case CODE_NOP: return std::string("nop"); break;
	case CODE_POP: return std::string("pop"); break;
	case CODE_POP2: return std::string("pop2"); break;
	case CODE_PUTFIELD: return std::string("putfield"); break;
	case CODE_PUTSTATIC: return std::string("putstatic"); break;
	case CODE_RET: return std::string("ret"); break;
	case CODE_RETURN: return std::string("return"); break;
	case CODE_SALOAD: return std::string("saload"); break;
	case CODE_SASTORE: return std::string("sastore"); break;
	case CODE_SIPUSH: return std::string("sipush"); break;
	case CODE_SWAP: return std::string("swap"); break;
	case CODE_LOOKUPSWITCH:  return std::string("lookupswitch"); break;
	case CODE_TABLESWITCH: return std::string("tableswitch"); break;
	case CODE_WIDE: return std::string("wide"); break;
	default: return std::string("Invalid opcode"); break;
	}
}
unsigned char MonicToOp(std::string monic) //not case sensitive
{
	int mLen = monic.length();
	int keyParse = mLen+std::toupper(monic[mLen-1]);
	if (mLen > 0)
		keyParse += 16*std::toupper(monic[0]);
	if (mLen > 2)
		keyParse += 16*8*std::toupper(monic[2]);
	if (mLen > 3)
		keyParse += 16*8*8*std::toupper(monic[3]);
	if (mLen > 7)
		keyParse += 16*8*8*8*std::toupper(monic[7]);
	switch (keyParse)
	{
	case 91738: return CODE_AALOAD; break; case 97756: return CODE_AASTORE; break; case 730087: return CODE_ACONST_NULL; break; case 77785: return CODE_ALOAD; break;
	case 77767: return CODE_ALOAD_0; break; case 77768: return CODE_ALOAD_1; break; case 77769: return CODE_ALOAD_2; break; case 77770: return CODE_ALOAD_3; break;
	case 631538: return CODE_ANEWARRAY; break; case 95973: return CODE_ARETURN; break; case 717155: return CODE_ARRAYLENGTH; break; case 92763: return CODE_ASTORE; break;
	case 485960: return CODE_ASTORE_0; break; case 494153: return CODE_ASTORE_1; break; case 502346: return CODE_ASTORE_2; break; case 510539: return CODE_ASTORE_3; break;
	case 94317: return CODE_ATHROW; break; case 91754: return CODE_BALOAD; break; case 97772: return CODE_BASTORE; break; case 98414: return CODE_BIPUSH; break;
	case 91770: return CODE_CALOAD; break; case 97788: return CODE_CASTORE; break; case 758541: return CODE_CHECKCAST; break; case 10121: return CODE_D2F; break;
	case 10508: return CODE_D2I; break; case 10895: return CODE_D2L; break; case 79496: return CODE_DADD; break; case 91786: return CODE_DALOAD; break;
	case 97804: return CODE_DASTORE; break; case 92940: return CODE_DCMPG; break; case 92945: return CODE_DCMPL; break; case 484344: return CODE_DCONST_0; break;
	case 492537: return CODE_DCONST_1; break; case 98586: return CODE_DDIV; break; case 77833: return CODE_DLOAD; break; case 77815: return CODE_DLOAD_0; break;
	case 77816: return CODE_DLOAD_1; break; case 77817: return CODE_DLOAD_2; break; case 77818: return CODE_DLOAD_3; break; case 89872: return CODE_DMUL; break;
	case 82699: return CODE_DNEG; break; case 88849: return CODE_DREM; break; case 96021: return CODE_DRETURN; break; case 92811: return CODE_DSTORE; break;
	case 486008: return CODE_DSTORE_0; break; case 494201: return CODE_DSTORE_1; break; case 502394: return CODE_DSTORE_2; break; case 510587: return CODE_DSTORE_3; break;
	case 79622: return CODE_DSUB; break; case 11411: return CODE_DUP; break; case 108663: return CODE_DUP_X1; break; case 108664: return CODE_DUP_X2; break;
	case 62582: return CODE_DUP2; break; case 62584: return CODE_DUP2_X1; break; case 62585: return CODE_DUP2_X2; break; case 9895: return CODE_F2D; break;
	case 10540: return CODE_F2I; break; case 10927: return CODE_F2L; break; case 79528: return CODE_FADD; break; case 91818: return CODE_FALOAD; break;
	case 97836: return CODE_FASTORE; break; case 92972: return CODE_FCMPG; break; case 92977: return CODE_FCMPL; break; case 484376: return CODE_FCONST_0; break;
	case 492569: return CODE_FCONST_1; break; case 500762: return CODE_FCONST_2; break; case 98618: return CODE_FDIV; break; case 77865: return CODE_FLOAD; break;
	case 77847: return CODE_FLOAD_0; break; case 77848: return CODE_FLOAD_1; break; case 77849: return CODE_FLOAD_2; break; case 77850: return CODE_FLOAD_3; break;
	case 89904: return CODE_FMUL; break; case 82731: return CODE_FNEG; break; case 88881: return CODE_FREM; break; case 96053: return CODE_FRETURN; break;
	case 92843: return CODE_FSTORE; break; case 486040: return CODE_FSTORE_0; break; case 494233: return CODE_FSTORE_1; break; case 502426: return CODE_FSTORE_2; break;
	case 510619: return CODE_FSTORE_3; break; case 79654: return CODE_FSUB; break; case 640700: return CODE_GETFIELD; break; case 694972: return CODE_GETSTATIC; break;
	case 92867: return CODE_GOTO; break; case 92877: return CODE_GOTO_W; break; case 9685: return CODE_I2B; break; case 9814: return CODE_I2C; break;
	case 9943: return CODE_I2D; break; case 10201: return CODE_I2F; break; case 10975: return CODE_I2L; break; case 11878: return CODE_I2S; break;
	case 79576: return CODE_IADD; break; case 91866: return CODE_IALOAD; break; case 80856: return CODE_IAND; break; case 97884: return CODE_IASTORE; break;
	case 721994: return CODE_ICONST_M1; break; case 484424: return CODE_ICONST_0; break; case 492617: return CODE_ICONST_1; break; case 500810: return CODE_ICONST_2; break;
	case 509003: return CODE_ICONST_3; break; case 517196: return CODE_ICONST_4; break; case 525389: return CODE_ICONST_5; break; case 98666: return CODE_IDIV; break;
	case 645226: return CODE_IF_ACMPEQ; break; case 718942: return CODE_IF_ACMPNE; break; case 653418: return CODE_IF_ICMPEQ; break; case 727134: return CODE_IF_ICMPNE; break;
	case 710765: return CODE_IF_ICMPLT; break; case 669790: return CODE_IF_ICMPGE; break; case 669805: return CODE_IF_ICMPGT; break; case 710750: return CODE_IF_ICMPLE; break;
	case 93029: return CODE_IFEQ; break; case 81881: return CODE_IFNE; break; case 97000: return CODE_IFLT; break; case 80985: return CODE_IFGE; break;
	case 96360: return CODE_IFGT; break; case 81625: return CODE_IFLE; break; case 714725: return CODE_IFNONNULL; break; case 98274: return CODE_IFNULL; break;
	case 79831: return CODE_IINC; break; case 77913: return CODE_ILOAD; break; case 77895: return CODE_ILOAD_0; break; case 77896: return CODE_ILOAD_1; break;
	case 77897: return CODE_ILOAD_2; break; case 77898: return CODE_ILOAD_3; break; case 89952: return CODE_IMUL; break; case 82779: return CODE_INEG; break;
	case 663136: return CODE_INSTANCEOF; break; case 822240: return CODE_INVOKEDYNAMIC; break; case 732132: return CODE_INVOKEINTERFACE; break; case 748521: return CODE_INVOKESPECIAL; break;
	case 781279: return CODE_INVOKESTATIC; break; case 691177: return CODE_INVOKEVIRTUAL; break; case 11749: return CODE_IOR; break; case 88929: return CODE_IREM; break;
	case 96101: return CODE_IRETURN; break; case 88288: return CODE_ISHL; break; case 94438: return CODE_ISHR; break; case 92891: return CODE_ISTORE; break;
	case 486088: return CODE_ISTORE_0; break; case 494281: return CODE_ISTORE_1; break; case 502474: return CODE_ISTORE_2; break; case 510667: return CODE_ISTORE_3; break;
	case 79702: return CODE_ISUB; break; case 85607: return CODE_IUSHR; break; case 95334: return CODE_IXOR; break; case 11765: return CODE_JSR; break;
	case 109052: return CODE_JSR_W; break; case 9991: return CODE_L2D; break; case 10249: return CODE_L2F; break; case 10636: return CODE_L2I; break;
	case 79624: return CODE_LADD; break; case 91914: return CODE_LALOAD; break; case 80904: return CODE_LAND; break; case 97932: return CODE_LASTORE; break;
	case 93076: return CODE_LCMP; break; case 484472: return CODE_LCONST_0; break; case 492665: return CODE_LCONST_1; break; case 9862: return CODE_LDC; break;
	case 107164: return CODE_LDC_W; break; case 61085: return CODE_LDC2_W; break; case 98714: return CODE_LDIV; break; case 77961: return CODE_LLOAD; break;
	case 77943: return CODE_LLOAD_0; break; case 77944: return CODE_LLOAD_1; break; case 77945: return CODE_LLOAD_2; break; case 77946: return CODE_LLOAD_3; break;
	case 90000: return CODE_LMUL; break; case 82827: return CODE_LNEG; break; case 800916: return CODE_LOOKUPSWITCH; break; case 11797: return CODE_LOR; break;
	case 88977: return CODE_LREM; break; case 96149: return CODE_LRETURN; break; case 88336: return CODE_LSHL; break; case 94486: return CODE_LSHR; break;
	case 92939: return CODE_LSTORE; break; case 486136: return CODE_LSTORE_0; break; case 494329: return CODE_LSTORE_1; break; case 502522: return CODE_LSTORE_2; break;
	case 510715: return CODE_LSTORE_3; break; case 79750: return CODE_LSUB; break; case 85655: return CODE_LUSHR; break; case 95382: return CODE_LXOR; break;
	case 651310: return CODE_MONITORENTER; break; case 651311: return CODE_MONITOREXIT; break; case 662327: return CODE_MULTIANEWARRAY; break; case 12474: return CODE_NEW; break;
	case 808129: return CODE_NEWARRAY; break; case 11571: return CODE_NOP; break; case 11603: return CODE_POP; break; case 62774: return CODE_POP2; break;
	case 640844: return CODE_PUTFIELD; break; case 695116: return CODE_PUTSTATIC; break; case 12151: return CODE_RET; break; case 99188: return CODE_RETURN; break;
	case 92026: return CODE_SALOAD; break; case 98044: return CODE_SASTORE; break; case 98686: return CODE_SIPUSH; break; case 91652: return CODE_SWAP; break;
	case 685715: return CODE_TABLESWITCH; break; case 80825: return CODE_WIDE; break; default: std::cout << "invalid input to MonicToOp\n"; abort(); break;
	}
}

int OpParaCount(unsigned char op)
{
	switch (op)
	{
		case CODE_ALOAD: return 1;break; case CODE_ANEWARRAY: return 2;break; case CODE_ASTORE: return 1;break; case CODE_BIPUSH: return 1;break;
		case CODE_CHECKCAST: return 2;break; case CODE_DLOAD: return 1;break; case CODE_DSTORE: return 1;break; case CODE_FLOAD: return 1;break;
		case CODE_FSTORE: return 1;break; case CODE_GETFIELD: return 2;break; case CODE_GETSTATIC: return 2;break; case CODE_GOTO: return 2;break;
		case CODE_GOTO_W: return 4;break; case CODE_IF_ACMPEQ: return 2;break; case CODE_IF_ACMPNE: return 2;break; case CODE_IF_ICMPEQ: return 2;break;
		case CODE_IF_ICMPNE: return 2;break; case CODE_IF_ICMPLT: return 2;break; case CODE_IF_ICMPGE: return 2;break; case CODE_IF_ICMPGT: return 2;break;
		case CODE_IF_ICMPLE: return 2;break; case CODE_IFEQ: return 2;break; case CODE_IFNE: return 2;break; case CODE_IFLT: return 2;break;
		case CODE_IFGE: return 2;break; case CODE_IFGT: return 2;break; case CODE_IFLE: return 2;break; case CODE_IFNONNULL: return 2;break;
		case CODE_IFNULL: return 2;break; case CODE_IINC: return 2;break; case CODE_ILOAD: return 1;break; case CODE_INSTANCEOF: return 2;break;
		case CODE_INVOKEDYNAMIC: return 4;break; case CODE_INVOKEINTERFACE: return 4;break; case CODE_INVOKESPECIAL: return 2;break; case CODE_INVOKESTATIC: return 2;break;
		case CODE_INVOKEVIRTUAL: return 2;break; case CODE_ISTORE: return 1;break; case CODE_JSR: return 2;break; case CODE_JSR_W: return 4;break;
		case CODE_LDC: return 1;break; case CODE_LDC_W: return 2;break; case CODE_LDC2_W: return 2;break; case CODE_LLOAD: return 1;break;
		case CODE_LSTORE: return 1;break; case CODE_MULTIANEWARRAY: return 3;break; case CODE_NEW: return 2;break; case CODE_NEWARRAY: return 1;break;
		case CODE_PUTFIELD: return 2; break; case CODE_PUTSTATIC: return 2; break; case CODE_RET: return 1; break; case CODE_SIPUSH: return 2; break; default: return 0;
	}
}

void Method::GenerateTables()
{
	codeTable.clear();
	codeAttr = -2;
	for (int i = 0; i < attrs.size(); i++)
	{
		if (cd->entries[attrs[i].nameIndex].uString.getString() == "Code")
		{
			codeAttr = i;
			break;
		}
	}
	if (codeAttr == -2)
	{
		codeAttr = -1;
		return;
	}

	Attribute& attr = attrs[codeAttr];
	unsigned char* buf = attr.info.data();
	int codeLength = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
	buf += 8; unsigned char* start = buf;
	for (; buf < start+codeLength;)
	{
		int code = buf[0];
		codeTable.push_back(buf-start);
		buf++; unsigned char* cData = buf;
		int lineNo = codeTable.size()-1;
		switch (code)
		{
		case CODE_ALOAD: buf+=1;break; case CODE_ANEWARRAY: buf+=2;break; case CODE_ASTORE: buf+=1;break; case CODE_BIPUSH: buf+=1;break;
		case CODE_CHECKCAST: buf+=2;break; case CODE_DLOAD: buf+=1;break; case CODE_DSTORE: buf+=1;break; case CODE_FLOAD: buf+=1;break;
		case CODE_FSTORE: buf+=1;break; case CODE_GETFIELD: buf+=2;break; case CODE_GETSTATIC: buf+=2;break; case CODE_GOTO: buf+=2;break;
		case CODE_GOTO_W: buf+=4;break; case CODE_IF_ACMPEQ: buf+=2;break; case CODE_IF_ACMPNE: buf+=2;break; case CODE_IF_ICMPEQ: buf+=2;break;
		case CODE_IF_ICMPNE: buf+=2;break; case CODE_IF_ICMPLT: buf+=2;break; case CODE_IF_ICMPGE: buf+=2;break; case CODE_IF_ICMPGT: buf+=2;break;
		case CODE_IF_ICMPLE: buf+=2;break; case CODE_IFEQ: buf+=2;break; case CODE_IFNE: buf+=2;break; case CODE_IFLT: buf+=2;break;
		case CODE_IFGE: buf+=2;break; case CODE_IFGT: buf+=2;break; case CODE_IFLE: buf+=2;break; case CODE_IFNONNULL: buf+=2;break;
		case CODE_IFNULL: buf+=2;break; case CODE_IINC: buf+=2;break; case CODE_ILOAD: buf+=1;break; case CODE_INSTANCEOF: buf+=2;break;
		case CODE_INVOKEDYNAMIC: buf+=4;break; case CODE_INVOKEINTERFACE: buf+=4;break; case CODE_INVOKESPECIAL: buf+=2;break; case CODE_INVOKESTATIC: buf+=2;break;
		case CODE_INVOKEVIRTUAL: buf+=2;break; case CODE_ISTORE: buf+=1;break; case CODE_JSR: buf+=2;break; case CODE_JSR_W: buf+=4;break;
		case CODE_LDC: buf+=1;break; case CODE_LDC_W: buf+=2;break; case CODE_LDC2_W: buf+=2;break; case CODE_LLOAD: buf+=1;break;
		case CODE_LSTORE: buf+=1;break; case CODE_MULTIANEWARRAY: buf+=3;break; case CODE_NEW: buf+=2;break; case CODE_NEWARRAY: buf+=1;break;
		case CODE_PUTFIELD: buf+=2;break; case CODE_PUTSTATIC: buf+=2;break; case CODE_RET: buf+=1;break; case CODE_SIPUSH: buf+=2;break;
		case CODE_LOOKUPSWITCH:
		{
			int pad = 3-((3+buf-start)%4); buf += pad;
			unsigned int pairs = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
			int punPairs = *reinterpret_cast<int*>(&pairs);
			buf += 8+(punPairs*8);
			if (firstTable == -1)
				firstTable = lineNo;
		}
		break;
		case CODE_TABLESWITCH:
		{
			int pad = 3-((3+buf-start)%4); buf += pad;
			unsigned int low = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
			unsigned int high = buf[11]+(256*buf[10])+(256*256*buf[9])+(256*256*256*buf[8]);
			int punL = *reinterpret_cast<int*>(&low);
			int punH = *reinterpret_cast<int*>(&high);
			buf += 12+(4*(1+punH-punL));
			if (firstTable == -1)
				firstTable = lineNo;
		}
		break;
		case CODE_WIDE: if (buf[0] == 0x84) buf += 3; else buf += 5; break;
		default: break;
		}
		
		//jumpTable
		switch (code)
		{ default: break;
		case CODE_GOTO_W: case CODE_JSR_W:
		{ 
			unsigned int offset = cData[3]+(256*cData[2])+(256*256*cData[1])+(256*256*256*cData[0]); int location = (cData-(start+1))+(*reinterpret_cast<int*>(&offset)); jumpTable.push_back(CodeIndicesData(lineNo, location));
		} break;
		case CODE_GOTO: case CODE_IF_ACMPEQ: case CODE_IF_ACMPNE: case CODE_IF_ICMPEQ: case CODE_IF_ICMPNE: case CODE_IF_ICMPLT: 
		case CODE_IF_ICMPGE: case CODE_IF_ICMPGT: case CODE_IF_ICMPLE: case CODE_IFEQ: case CODE_IFNE: case CODE_IFGE:
		case CODE_IFGT: case CODE_IFLE: case CODE_IFNONNULL: case CODE_IFNULL: case CODE_JSR:
		{ unsigned short offset = cData[1]+(256*cData[0]); int location = (cData-(start+1))+(*reinterpret_cast<short*>(&offset)); jumpTable.push_back(CodeIndicesData(lineNo, location)); } break;
		case CODE_LOOKUPSWITCH:
		{
			unsigned char* opLoc = cData-1;
			int pad = 3-((3+cData-start)%4); cData += pad;
			unsigned int pairs = cData[7]+(256*cData[6])+(256*256*cData[5])+(256*256*256*cData[4]);
			int punPairs = *reinterpret_cast<int*>(&pairs);
			jumpTable.push_back(lineNo);
			std::vector<int>& indices = jumpTable.back().indices;
			unsigned int offset = cData[3]+(256*cData[2])+(256*256*cData[1])+(256*256*256*cData[0]); int location = (cData-(start+1))+(*reinterpret_cast<int*>(&offset));
			indices.push_back(location);
			for (int i = 0; i < punPairs; i++)
			{
				unsigned int offset = cData[11+(8*i)]+(256*cData[10+(8*i)])+(256*256*cData[9+(8*i)])+(256*256*256*cData[8+(8*i)]); int location = (cData-(start+1))+(*reinterpret_cast<int*>(&offset));
				indices.push_back(location);
			}
		} break;
		case CODE_TABLESWITCH:
		{
			unsigned char* opLoc = cData-1;
			int pad = 3-((3+cData-start)%4); cData += pad;
			unsigned int low = cData[7]+(256*cData[6])+(256*256*cData[5])+(256*256*256*cData[4]);
			unsigned int high = cData[11]+(256*cData[10])+(256*256*cData[9])+(256*256*256*cData[8]);
			int punL = *reinterpret_cast<int*>(&low);
			int punH = *reinterpret_cast<int*>(&high);
			jumpTable.push_back(lineNo);
			std::vector<int>& indices = jumpTable.back().indices;
			unsigned int offset = cData[3]+(256*cData[2])+(256*256*cData[1])+(256*256*256*cData[0]); int location = (opLoc-start)+(*reinterpret_cast<int*>(&offset));
			indices.push_back(location);
			for (int i = 0; i < 1+punH-punL; i++)
			{
				unsigned int offset = cData[15+(4*i)]+(256*cData[14+(4*i)])+(256*256*cData[13+(4*i)])+(256*256*256*cData[12+(4*i)]); int location = (opLoc-start)+(*reinterpret_cast<int*>(&offset));
				indices.push_back(location);
			}
		} break;
		}
		//localVarTable
		switch (code)
		{ default: break;
		case CODE_ALOAD: case CODE_ASTORE: case CODE_DLOAD: case CODE_DSTORE: case CODE_FLOAD: case CODE_FSTORE:
		case CODE_IINC: case CODE_ILOAD: case CODE_ISTORE: case CODE_LLOAD: case CODE_LSTORE: case CODE_RET:
			localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_ALOAD_0: case CODE_ALOAD_1: case CODE_ALOAD_2: case CODE_ALOAD_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_ALOAD_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_ASTORE_0: case CODE_ASTORE_1: case CODE_ASTORE_2: case CODE_ASTORE_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_ASTORE_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_DLOAD_0: case CODE_DLOAD_1: case CODE_DLOAD_2: case CODE_DLOAD_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_DLOAD_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_DSTORE_0: case CODE_DSTORE_1: case CODE_DSTORE_2: case CODE_DSTORE_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_DSTORE_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_FLOAD_0: case CODE_FLOAD_1: case CODE_FLOAD_2: case CODE_FLOAD_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_FLOAD_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_FSTORE_0: case CODE_FSTORE_1: case CODE_FSTORE_2: case CODE_FSTORE_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_FSTORE_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_ILOAD_0: case CODE_ILOAD_1: case CODE_ILOAD_2: case CODE_ILOAD_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_ILOAD_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_ISTORE_0: case CODE_ISTORE_1: case CODE_ISTORE_2: case CODE_ISTORE_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_ISTORE_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_LLOAD_0: case CODE_LLOAD_1: case CODE_LLOAD_2: case CODE_LLOAD_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_LLOAD_0)); break;
		 localVarTable.push_back(CodeIndexData(lineNo,cData[0])); break;
		case CODE_LSTORE_0: case CODE_LSTORE_1: case CODE_LSTORE_2: case CODE_LSTORE_3: localVarTable.push_back(CodeIndexData(lineNo,code - CODE_LSTORE_0)); break;
		localVarTable.push_back(CodeIndexData(lineNo, cData[0])); break;
		case CODE_WIDE: localVarTable.push_back(CodeIndexData(lineNo, cData[1]+(256*cData[2]))); break;
		}
		//cpRefTable
		switch (code)
		{ default: break;
		case CODE_LDC: cpRefTable.push_back(CodeIndexData(lineNo, cData[0])); break;
		case CODE_ANEWARRAY: case CODE_CHECKCAST: case CODE_GETFIELD: case CODE_GETSTATIC: case CODE_INSTANCEOF: case CODE_INVOKEDYNAMIC: 
		case CODE_INVOKEINTERFACE: case CODE_INVOKESPECIAL: case CODE_INVOKESTATIC: case CODE_INVOKEVIRTUAL: case CODE_LDC_W: case CODE_LDC2_W:
		case CODE_MULTIANEWARRAY: case CODE_NEW: case CODE_PUTFIELD: case CODE_PUTSTATIC: cpRefTable.push_back(CodeIndexData(lineNo,cData[1]+(256*cData[0]))); break;
		}
	}
}

void Method::PrintCode()
{
	if (codeAttr == -2)
		GenerateTables();
	if (codeAttr == -1)
	{
		std::cout << "This method has no code\n";
		return;
	}

	int consoleNumCount = 1;
	for (int i = codeTable.size(); i > 0; i /= 10)
		consoleNumCount++;

	Attribute& attr = attrs[codeAttr];
	unsigned char* buf = attr.info.data();
	int maxStack = buf[1]+(256*buf[0]);
	int maxLocals = buf[3]+(256*buf[2]);
	int codeLength = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
	std::cout << "\t\tMax operand stack: " << maxStack << '\n';
	std::cout << "\t\tMax local variables: " << maxLocals << '\n';
	std::cout << "\t\tCode length: " << codeLength << '\n';
	buf += 8; unsigned char* start = buf;
	for (int lineNum = 0; buf < start+codeLength; lineNum++)
	{
		{ //printing line numbers
			int lNumCount = 1; if (lineNum == 0) lNumCount = 2;
			for (int i = lineNum; i > 0; i /= 10)
				lNumCount++;
			for (int i = 0; i < consoleNumCount-lNumCount; i++)
				std::cout << "0";
			std::cout << lineNum << ": ";
		}
		int code = buf[0];
		buf++;
		switch (code)
		{
		case CODE_AALOAD: std::cout << "aaload" << '\n'; break;
		case CODE_AASTORE: std::cout << "aastore" << '\n'; break;
		case CODE_ACONST_NULL: std::cout << "aconst_null" << '\n'; break;
		case CODE_ALOAD: std::cout << "aload" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_ALOAD_0: std::cout << "aload_0" << '\n'; break;
		case CODE_ALOAD_1: std::cout << "aload_1" << '\n'; break;
		case CODE_ALOAD_2: std::cout << "aload_2" << '\n'; break;
		case CODE_ALOAD_3: std::cout << "aload_3" << '\n'; break;
		case CODE_ANEWARRAY: std::cout << "anewarray" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_ARETURN: std::cout << "areturn" << '\n'; break;
		case CODE_ARRAYLENGTH: std::cout << "arraylength" << '\n'; break;
		case CODE_ASTORE: std::cout << "astore" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_ASTORE_0: std::cout << "astore_0" << '\n'; break;
		case CODE_ASTORE_1: std::cout << "astore_1" << '\n'; break;
		case CODE_ASTORE_2: std::cout << "astore_2" << '\n'; break;
		case CODE_ASTORE_3: std::cout << "astore_3" << '\n'; break;
		case CODE_ATHROW: std::cout << "athrow" << '\n'; break;
		case CODE_BALOAD: std::cout << "baload" << '\n'; break;
		case CODE_BASTORE: std::cout << "bastore" << '\n'; break;
		case CODE_BIPUSH: std::cout << "bipush" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_CALOAD: std::cout << "caload" << '\n'; break;
		case CODE_CASTORE: std::cout << "castore" << '\n'; break;
		case CODE_CHECKCAST: std::cout << "checkcast" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_D2F: std::cout << "d2f" << '\n'; break;
		case CODE_D2I: std::cout << "d2i" << '\n'; break;
		case CODE_D2L: std::cout << "d2l" << '\n'; break;
		case CODE_DADD: std::cout << "dadd" << '\n'; break;
		case CODE_DALOAD: std::cout << "daload" << '\n'; break;
		case CODE_DASTORE: std::cout << "dastore" << '\n'; break;
		case CODE_DCMPG: std::cout << "dcmpg" << '\n'; break;
		case CODE_DCMPL: std::cout << "dcmpl" << '\n'; break;
		case CODE_DCONST_0: std::cout << "dconst_0" << '\n'; break;
		case CODE_DCONST_1: std::cout << "dconst_1" << '\n'; break;
		case CODE_DDIV: std::cout << "ddiv" << '\n'; break;
		case CODE_DLOAD: std::cout << "dload" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_DLOAD_0: std::cout << "dload_0" << '\n'; break;
		case CODE_DLOAD_1: std::cout << "dload_1" << '\n'; break;
		case CODE_DLOAD_2: std::cout << "dload_2" << '\n'; break;
		case CODE_DLOAD_3: std::cout << "dload_3" << '\n'; break;
		case CODE_DMUL: std::cout << "dmul" << '\n'; break;
		case CODE_DNEG: std::cout << "dneg" << '\n'; break;
		case CODE_DREM: std::cout << "drem" << '\n'; break;
		case CODE_DRETURN: std::cout << "dreturn" << '\n'; break;
		case CODE_DSTORE: std::cout << "dstore" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_DSTORE_0: std::cout << "dstore_0" << '\n'; break;
		case CODE_DSTORE_1: std::cout << "dstore_1" << '\n'; break;
		case CODE_DSTORE_2: std::cout << "dstore_2" << '\n'; break;
		case CODE_DSTORE_3: std::cout << "dstore_3" << '\n'; break;
		case CODE_DSUB: std::cout << "dsub" << '\n'; break;
		case CODE_DUP: std::cout << "dup" << '\n'; break;
		case CODE_DUP_X1: std::cout << "dup_x1" << '\n'; break;
		case CODE_DUP_X2: std::cout << "dup_x2" << '\n'; break;
		case CODE_DUP2: std::cout << "dup2" << '\n'; break;
		case CODE_DUP2_X1: std::cout << "dup2_x1" << '\n'; break;
		case CODE_DUP2_X2: std::cout << "dup2_x2" << '\n'; break;
		case CODE_F2D: std::cout << "f2d" << '\n'; break;
		case CODE_F2I: std::cout << "f2i" << '\n'; break;
		case CODE_F2L: std::cout << "f2l" << '\n'; break;
		case CODE_FADD: std::cout << "fadd" << '\n'; break;
		case CODE_FALOAD: std::cout << "faload" << '\n'; break;
		case CODE_FASTORE: std::cout << "fastore" << '\n'; break;
		case CODE_FCMPG: std::cout << "fcmpg" << '\n'; break;
		case CODE_FCMPL: std::cout << "fcmpl" << '\n'; break;
		case CODE_FCONST_0: std::cout << "fconst_0" << '\n'; break;
		case CODE_FCONST_1: std::cout << "fconst_1" << '\n'; break;
		case CODE_FCONST_2: std::cout << "fconst_2" << '\n'; break;
		case CODE_FDIV: std::cout << "fdiv" << '\n'; break;
		case CODE_FLOAD: std::cout << "fload" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_FLOAD_0: std::cout << "fload_0" << '\n'; break;
		case CODE_FLOAD_1: std::cout << "fload_1" << '\n'; break;
		case CODE_FLOAD_2: std::cout << "fload_2" << '\n'; break;
		case CODE_FLOAD_3: std::cout << "fload_3" << '\n'; break;
		case CODE_FMUL: std::cout << "fmul" << '\n'; break;
		case CODE_FNEG: std::cout << "fneg" << '\n'; break;
		case CODE_FREM: std::cout << "frem" << '\n'; break;
		case CODE_FRETURN: std::cout << "freturn" << '\n'; break;
		case CODE_FSTORE: std::cout << "fstore" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_FSTORE_0: std::cout << "fstore_0" << '\n'; break;
		case CODE_FSTORE_1: std::cout << "fstore_1" << '\n'; break;
		case CODE_FSTORE_2: std::cout << "fstore_2" << '\n'; break;
		case CODE_FSTORE_3: std::cout << "fstore_3" << '\n'; break;
		case CODE_FSUB: std::cout << "fsub" << '\n'; break;
		case CODE_GETFIELD: std::cout << "getfield" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_GETSTATIC: std::cout << "getstatic" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_GOTO: std::cout << "goto" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_GOTO_W: std::cout << "goto_w" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << ' ' << ByteToHexa(buf[2]) << ' ' << ByteToHexa(buf[3]) << '\n'; buf += 4; break;
		case CODE_I2B: std::cout << "i2b" << '\n'; break;
		case CODE_I2C: std::cout << "i2c" << '\n'; break;
		case CODE_I2D: std::cout << "i2d" << '\n'; break;
		case CODE_I2F: std::cout << "i2f" << '\n'; break;
		case CODE_I2L: std::cout << "i2l" << '\n'; break;
		case CODE_I2S: std::cout << "i2s" << '\n'; break;
		case CODE_IADD: std::cout << "iadd" << '\n'; break;
		case CODE_IALOAD: std::cout << "iaload" << '\n'; break;
		case CODE_IAND: std::cout << "iand" << '\n'; break;
		case CODE_IASTORE: std::cout << "iastore" << '\n'; break;
		case CODE_ICONST_M1: std::cout << "iconst_m1" << '\n'; break;
		case CODE_ICONST_0: std::cout << "iconst_0" << '\n'; break;
		case CODE_ICONST_1: std::cout << "iconst_1" << '\n'; break;
		case CODE_ICONST_2: std::cout << "iconst_2" << '\n'; break;
		case CODE_ICONST_3: std::cout << "iconst_3" << '\n'; break;
		case CODE_ICONST_4: std::cout << "iconst_4" << '\n'; break;
		case CODE_ICONST_5: std::cout << "iconst_5" << '\n'; break;
		case CODE_IDIV: std::cout << "idiv" << '\n'; break;
		case CODE_IF_ACMPEQ: std::cout << "if_acmpeq" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IF_ACMPNE: std::cout << "if_acmpne" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IF_ICMPEQ: std::cout << "if_icmpeq" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IF_ICMPNE: std::cout << "if_icmpne" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IF_ICMPLT: std::cout << "if_icmplt" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IF_ICMPGE: std::cout << "if_icmpge" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IF_ICMPGT: std::cout << "if_icmpgt" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IF_ICMPLE: std::cout << "if_icmple" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFEQ: std::cout << "ifeq" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFNE: std::cout << "ifne" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFLT: std::cout << "iflt" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFGE: std::cout << "ifge" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFGT: std::cout << "ifgt" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFLE: std::cout << "ifle" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFNONNULL: std::cout << "ifnonnull" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IFNULL: std::cout << "ifnull" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IINC: std::cout << "iinc" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_ILOAD: std::cout << "iload" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_ILOAD_0: std::cout << "iload_0" << '\n'; break;
		case CODE_ILOAD_1: std::cout << "iload_1" << '\n'; break;
		case CODE_ILOAD_2: std::cout << "iload_2" << '\n'; break;
		case CODE_ILOAD_3: std::cout << "iload_3" << '\n'; break;
		case CODE_IMUL: std::cout << "imul" << '\n'; break;
		case CODE_INEG: std::cout << "ineg" << '\n'; break;
		case CODE_INSTANCEOF: std::cout << "instanceof" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_INVOKEDYNAMIC: std::cout << "invokedynamic" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << ' ' << ByteToHexa(buf[2]) << ' ' << ByteToHexa(buf[3]) << '\n'; buf += 4; break;
		case CODE_INVOKEINTERFACE: std::cout << "invokeinterface" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << ' ' << ByteToHexa(buf[2]) << ' ' << ByteToHexa(buf[3]) << '\n'; buf += 4; break;
		case CODE_INVOKESPECIAL: std::cout << "invokespecial" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_INVOKESTATIC: std::cout << "invokestatic" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_INVOKEVIRTUAL: std::cout << "invokevirtual" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_IOR: std::cout << "ior" << '\n'; break;
		case CODE_IREM: std::cout << "irem" << '\n'; break;
		case CODE_IRETURN: std::cout << "ireturn" << '\n'; break;
		case CODE_ISHL: std::cout << "ishl" << '\n'; break;
		case CODE_ISHR: std::cout << "ishr" << '\n'; break;
		case CODE_ISTORE: std::cout << "istore" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_ISTORE_0: std::cout << "istore_0" << '\n'; break;
		case CODE_ISTORE_1: std::cout << "istore_1" << '\n'; break;
		case CODE_ISTORE_2: std::cout << "istore_2" << '\n'; break;
		case CODE_ISTORE_3: std::cout << "istore_3" << '\n'; break;
		case CODE_ISUB: std::cout << "isub" << '\n'; break;
		case CODE_IUSHR: std::cout << "iushr" << '\n'; break;
		case CODE_IXOR: std::cout << "ixor" << '\n'; break;
		case CODE_JSR: std::cout << "jsr" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_JSR_W: std::cout << "jsr_w" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << ' ' << ByteToHexa(buf[2]) << ' ' << ByteToHexa(buf[3]) << '\n'; buf += 4; break;
		case CODE_L2D: std::cout << "l2d" << '\n'; break;
		case CODE_L2F: std::cout << "l2f" << '\n'; break;
		case CODE_L2I: std::cout << "l2i" << '\n'; break;
		case CODE_LADD: std::cout << "ladd" << '\n'; break;
		case CODE_LALOAD: std::cout << "laload" << '\n'; break;
		case CODE_LAND: std::cout << "land" << '\n'; break;
		case CODE_LASTORE: std::cout << "lastore" << '\n'; break;
		case CODE_LCMP: std::cout << "lcmp" << '\n'; break;
		case CODE_LCONST_0: std::cout << "lconst_0" << '\n'; break;
		case CODE_LCONST_1: std::cout << "lconst_1" << '\n'; break;
		case CODE_LDC: std::cout << "ldc" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_LDC_W: std::cout << "ldc_w" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_LDC2_W: std::cout << "ldc2_w" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_LDIV: std::cout << "ldiv" << '\n'; break;
		case CODE_LLOAD: std::cout << "lload" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_LLOAD_0: std::cout << "lload_0" << '\n'; break;
		case CODE_LLOAD_1: std::cout << "lload_1" << '\n'; break;
		case CODE_LLOAD_2: std::cout << "lload_2" << '\n'; break;
		case CODE_LLOAD_3: std::cout << "lload_3" << '\n'; break;
		case CODE_LMUL: std::cout << "lmul" << '\n'; break;
		case CODE_LNEG: std::cout << "lneg" << '\n'; break;
		case CODE_LOR: std::cout << "lor" << '\n'; break;
		case CODE_LREM: std::cout << "lrem" << '\n'; break;
		case CODE_LRETURN: std::cout << "lreturn" << '\n'; break;
		case CODE_LSHL: std::cout << "lshl" << '\n'; break;
		case CODE_LSHR: std::cout << "lshr" << '\n'; break;
		case CODE_LSTORE: std::cout << "lstore" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_LSTORE_0: std::cout << "lstore_0" << '\n'; break;
		case CODE_LSTORE_1: std::cout << "lstore_1" << '\n'; break;
		case CODE_LSTORE_2: std::cout << "lstore_2" << '\n'; break;
		case CODE_LSTORE_3: std::cout << "lstore_3" << '\n'; break;
		case CODE_LSUB: std::cout << "lsub" << '\n'; break;
		case CODE_LUSHR: std::cout << "lushr" << '\n'; break;
		case CODE_LXOR: std::cout << "lxor" << '\n'; break;
		case CODE_MONITORENTER: std::cout << "monitorenter" << '\n'; break;
		case CODE_MONITOREXIT: std::cout << "monitorexit" << '\n'; break;
		case CODE_MULTIANEWARRAY: std::cout << "multianewarray" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << ' ' << ByteToHexa(buf[2]) << '\n'; buf += 3; break;
		case CODE_NEW: std::cout << "new" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_NEWARRAY: std::cout << "newarray" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_NOP: std::cout << "nop" << '\n'; break;
		case CODE_POP: std::cout << "pop" << '\n'; break;
		case CODE_POP2: std::cout << "pop2" << '\n'; break;
		case CODE_PUTFIELD: std::cout << "putfield" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_PUTSTATIC: std::cout << "putstatic" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_RET: std::cout << "ret" << ' ' << ByteToHexa(buf[0]) << '\n'; buf += 1; break;
		case CODE_RETURN: std::cout << "return" << '\n'; break;
		case CODE_SALOAD: std::cout << "saload" << '\n'; break;
		case CODE_SASTORE: std::cout << "sastore" << '\n'; break;
		case CODE_SIPUSH: std::cout << "sipush" << ' ' << ByteToHexa(buf[0]) << ' ' << ByteToHexa(buf[1]) << '\n'; buf += 2; break;
		case CODE_SWAP: std::cout << "swap" << '\n'; break;
		case CODE_LOOKUPSWITCH: std::cout << "lookupswitch";
		{ //buf is 1 + opcode location, 
			int pad = 3-((3+buf-start)%4); buf += pad;;
			unsigned int pairs = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
			int punPairs = *reinterpret_cast<int*>(&pairs);
			for (int i = 0; i < 8+(punPairs*8); i++)
				std::cout << ' ' << ByteToHexa(buf[i]);
			buf += 8+(punPairs*8);
			std::cout << '\n';
		}
		break;
		case CODE_TABLESWITCH: std::cout << "tableswitch";
		{
			int pad = 3-((3+buf-start)%4); buf += pad;;
			unsigned int low = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
			unsigned int high = buf[11]+(256*buf[10])+(256*256*buf[9])+(256*256*256*buf[8]);
			int punL = *reinterpret_cast<int*>(&low);
			int punH = *reinterpret_cast<int*>(&high);
			for (int i = 0; i < 12+(4*(1+punH-punL)); i++)
				std::cout << ' ' << ByteToHexa(buf[i]);
			buf += 12+(4*(1+punH-punL));
			std::cout << '\n';
		}
		break;
		case CODE_WIDE: std::cout << "wide";
		{
			if (buf[0] != CODE_IINC)
			{
				for (int i = 0; i < 3; i++)
					std::cout << ' ' << ByteToHexa(buf[i]);
				buf += 3;
			}
			else
			{
				for (int i = 0; i < 5; i++)
					std::cout << ' ' << ByteToHexa(buf[i]);
				buf += 5;
			}
			std::cout << '\n';
		}
		break;
		}
	}
	int exceptCount = buf[1]+(256*buf[0]);
	std::cout << "\t\tException count: " << exceptCount << '\n';
	buf += 2;
	for (int k = 0; k < exceptCount; k++)
	{
		std::cout << "\t\tException Entry: " << k << '\n';
		int start = buf[1]+(256*buf[0]);
		int end = buf[3]+(256*buf[2]);
		int handler = buf[5]+(256*buf[4]);
		int catchType = buf[7]+(256*buf[6]);
		std::cout << "\t\tStart line: " << start << '\n';
		std::cout << "\t\tEnd line: " << end << '\n';
		std::cout << "\t\tHandler line: " << handler << '\n';
		std::cout << "\t\tCatch type index: " << catchType << '\n';
		buf += 8;
	}
	int codeAttrCount = buf[1]+(256*buf[0]);
	std::cout << "\t\tAttribute count: " << codeAttrCount << '\n';
	buf += 2;
	for (int k = 0; k < codeAttrCount; k++)
	{
		std::cout << "\t\tAttribute Entry: " << k << '\n';
		int attrNameIndex = buf[1]+(256*buf[0]);
		unsigned int attrLength = buf[5]+(256*buf[4])+(256*256*buf[3])+(256*256*256*buf[2]);
		std::cout << "\t\tAttribute name index: " << attrNameIndex << '\n';
		std::cout << "\t\tAttribute info length: " << attrLength << '\n';
		std::string attrName = cd->entries[attrNameIndex].uString.getString();
		std::cout << "\t\tAttribute name: " << attrName << '\n';
		buf += 6+attrLength;
	}

}

void Method::PrintJumpTable()
{
	if (codeAttr == -2)
		GenerateTables();
	if (codeAttr == -1)
		return;
	for (int i = 0; i < jumpTable.size(); i++)
	{
		CodeIndicesData& jEntry = jumpTable[i];
		std::cout << "Line " << jEntry.lineIndex << ": " << GetCodeLine(jEntry.lineIndex) << '\n';
		std::vector<int>& indices = jEntry.indices;
		for (int j = 0; j < indices.size(); j++)
		{
			int index = std::distance(codeTable.begin(),std::lower_bound(codeTable.begin(),codeTable.end(),indices[j]));
			if (codeTable[index] != indices[j])
			{
				std::cout << "Either jump table or code table is corrupted\n";
				abort();
			}
			std::cout << "\tLine " << index << ": " << GetCodeLine(index) << '\n';
		}
		std::cout << '\n';
	}
}

std::string Method::GetCodeLine(int index)
{
	std::string hold;
	if (codeAttr == -2)
		GenerateTables();
	if (codeAttr == -1)
		return "Function doesn't contain code";
	if (index < 0 || index >= codeTable.size())
		return "Invalid index";
	unsigned char* buf = attrs[codeAttr].info.data()+8+codeTable[index]; unsigned char* start = attrs[codeAttr].info.data();
	int code = buf[0]; buf++;
	switch (code)
	{
	case CODE_AALOAD: hold = std::string("aaload");break;
	case CODE_AASTORE: hold = std::string("aastore");break;
	case CODE_ACONST_NULL: hold = std::string("aconst_null");break;
	case CODE_ALOAD: hold = std::string("aload")+' '+ByteToHexa(buf[0]);break;
	case CODE_ALOAD_0: hold = std::string("aload_0");break;
	case CODE_ALOAD_1: hold = std::string("aload_1");break;
	case CODE_ALOAD_2: hold = std::string("aload_2");break;
	case CODE_ALOAD_3: hold = std::string("aload_3");break;
	case CODE_ANEWARRAY: hold = std::string("anewarray")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_ARETURN: hold = std::string("areturn");break;
	case CODE_ARRAYLENGTH: hold = std::string("arraylength");break;
	case CODE_ASTORE: hold = std::string("astore")+' '+ByteToHexa(buf[0]);break;
	case CODE_ASTORE_0: hold = std::string("astore_0");break;
	case CODE_ASTORE_1: hold = std::string("astore_1");break;
	case CODE_ASTORE_2: hold = std::string("astore_2");break;
	case CODE_ASTORE_3: hold = std::string("astore_3");break;
	case CODE_ATHROW: hold = std::string("athrow");break;
	case CODE_BALOAD: hold = std::string("baload");break;
	case CODE_BASTORE: hold = std::string("bastore");break;
	case CODE_BIPUSH: hold = std::string("bipush")+' '+ByteToHexa(buf[0]);break;
	case CODE_CALOAD: hold = std::string("caload");break;
	case CODE_CASTORE: hold = std::string("castore");break;
	case CODE_CHECKCAST: hold = std::string("checkcast")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_D2F: hold = std::string("d2f");break;
	case CODE_D2I: hold = std::string("d2i");break;
	case CODE_D2L: hold = std::string("d2l");break;
	case CODE_DADD: hold = std::string("dadd");break;
	case CODE_DALOAD: hold = std::string("daload");break;
	case CODE_DASTORE: hold = std::string("dastore");break;
	case CODE_DCMPG: hold = std::string("dcmpg");break;
	case CODE_DCMPL: hold = std::string("dcmpl");break;
	case CODE_DCONST_0: hold = std::string("dconst_0");break;
	case CODE_DCONST_1: hold = std::string("dconst_1");break;
	case CODE_DDIV: hold = std::string("ddiv");break;
	case CODE_DLOAD: hold = std::string("dload")+' '+ByteToHexa(buf[0]);break;
	case CODE_DLOAD_0: hold = std::string("dload_0");break;
	case CODE_DLOAD_1: hold = std::string("dload_1");break;
	case CODE_DLOAD_2: hold = std::string("dload_2");break;
	case CODE_DLOAD_3: hold = std::string("dload_3");break;
	case CODE_DMUL: hold = std::string("dmul");break;
	case CODE_DNEG: hold = std::string("dneg");break;
	case CODE_DREM: hold = std::string("drem");break;
	case CODE_DRETURN: hold = std::string("dreturn");break;
	case CODE_DSTORE: hold = std::string("dstore")+' '+ByteToHexa(buf[0]);break;
	case CODE_DSTORE_0: hold = std::string("dstore_0");break;
	case CODE_DSTORE_1: hold = std::string("dstore_1");break;
	case CODE_DSTORE_2: hold = std::string("dstore_2");break;
	case CODE_DSTORE_3: hold = std::string("dstore_3");break;
	case CODE_DSUB: hold = std::string("dsub");break;
	case CODE_DUP: hold = std::string("dup");break;
	case CODE_DUP_X1: hold = std::string("dup_x1");break;
	case CODE_DUP_X2: hold = std::string("dup_x2");break;
	case CODE_DUP2: hold = std::string("dup2");break;
	case CODE_DUP2_X1: hold = std::string("dup2_x1");break;
	case CODE_DUP2_X2: hold = std::string("dup2_x2");break;
	case CODE_F2D: hold = std::string("f2d");break;
	case CODE_F2I: hold = std::string("f2i");break;
	case CODE_F2L: hold = std::string("f2l");break;
	case CODE_FADD: hold = std::string("fadd");break;
	case CODE_FALOAD: hold = std::string("faload");break;
	case CODE_FASTORE: hold = std::string("fastore");break;
	case CODE_FCMPG: hold = std::string("fcmpg");break;
	case CODE_FCMPL: hold = std::string("fcmpl");break;
	case CODE_FCONST_0: hold = std::string("fconst_0");break;
	case CODE_FCONST_1: hold = std::string("fconst_1");break;
	case CODE_FCONST_2: hold = std::string("fconst_2");break;
	case CODE_FDIV: hold = std::string("fdiv");break;
	case CODE_FLOAD: hold = std::string("fload")+' '+ByteToHexa(buf[0]);break;
	case CODE_FLOAD_0: hold = std::string("fload_0");break;
	case CODE_FLOAD_1: hold = std::string("fload_1");break;
	case CODE_FLOAD_2: hold = std::string("fload_2");break;
	case CODE_FLOAD_3: hold = std::string("fload_3");break;
	case CODE_FMUL: hold = std::string("fmul");break;
	case CODE_FNEG: hold = std::string("fneg");break;
	case CODE_FREM: hold = std::string("frem");break;
	case CODE_FRETURN: hold = std::string("freturn");break;
	case CODE_FSTORE: hold = std::string("fstore")+' '+ByteToHexa(buf[0]);break;
	case CODE_FSTORE_0: hold = std::string("fstore_0");break;
	case CODE_FSTORE_1: hold = std::string("fstore_1");break;
	case CODE_FSTORE_2: hold = std::string("fstore_2");break;
	case CODE_FSTORE_3: hold = std::string("fstore_3");break;
	case CODE_FSUB: hold = std::string("fsub");break;
	case CODE_GETFIELD: hold = std::string("getfield")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_GETSTATIC: hold = std::string("getstatic")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_GOTO: hold = std::string("goto")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_GOTO_W: hold = std::string("goto_w")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1])+' '+ByteToHexa(buf[2])+' '+ByteToHexa(buf[3]);break;
	case CODE_I2B: hold = std::string("i2b");break;
	case CODE_I2C: hold = std::string("i2c");break;
	case CODE_I2D: hold = std::string("i2d");break;
	case CODE_I2F: hold = std::string("i2f");break;
	case CODE_I2L: hold = std::string("i2l");break;
	case CODE_I2S: hold = std::string("i2s");break;
	case CODE_IADD: hold = std::string("iadd");break;
	case CODE_IALOAD: hold = std::string("iaload");break;
	case CODE_IAND: hold = std::string("iand");break;
	case CODE_IASTORE: hold = std::string("iastore");break;
	case CODE_ICONST_M1: hold = std::string("iconst_m1");break;
	case CODE_ICONST_0: hold = std::string("iconst_0");break;
	case CODE_ICONST_1: hold = std::string("iconst_1");break;
	case CODE_ICONST_2: hold = std::string("iconst_2");break;
	case CODE_ICONST_3: hold = std::string("iconst_3");break;
	case CODE_ICONST_4: hold = std::string("iconst_4");break;
	case CODE_ICONST_5: hold = std::string("iconst_5");break;
	case CODE_IDIV: hold = std::string("idiv");break;
	case CODE_IF_ACMPEQ: hold = std::string("if_acmpeq")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IF_ACMPNE: hold = std::string("if_acmpne")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IF_ICMPEQ: hold = std::string("if_icmpeq")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IF_ICMPNE: hold = std::string("if_icmpne")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IF_ICMPLT: hold = std::string("if_icmplt")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IF_ICMPGE: hold = std::string("if_icmpge")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IF_ICMPGT: hold = std::string("if_icmpgt")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IF_ICMPLE: hold = std::string("if_icmple")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFEQ: hold = std::string("ifeq")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFNE: hold = std::string("ifne")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFLT: hold = std::string("iflt")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFGE: hold = std::string("ifge")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFGT: hold = std::string("ifgt")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFLE: hold = std::string("ifle")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFNONNULL: hold = std::string("ifnonnull")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IFNULL: hold = std::string("ifnull")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IINC: hold = std::string("iinc")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_ILOAD: hold = std::string("iload")+' '+ByteToHexa(buf[0]);break;
	case CODE_ILOAD_0: hold = std::string("iload_0");break;
	case CODE_ILOAD_1: hold = std::string("iload_1");break;
	case CODE_ILOAD_2: hold = std::string("iload_2");break;
	case CODE_ILOAD_3: hold = std::string("iload_3");break;
	case CODE_IMUL: hold = std::string("imul");break;
	case CODE_INEG: hold = std::string("ineg");break;
	case CODE_INSTANCEOF: hold = std::string("instanceof")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_INVOKEDYNAMIC: hold = std::string("invokedynamic")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1])+' '+ByteToHexa(buf[2])+' '+ByteToHexa(buf[3]);break;
	case CODE_INVOKEINTERFACE: hold = std::string("invokeinterface")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1])+' '+ByteToHexa(buf[2])+' '+ByteToHexa(buf[3]);break;
	case CODE_INVOKESPECIAL: hold = std::string("invokespecial")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_INVOKESTATIC: hold = std::string("invokestatic")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_INVOKEVIRTUAL: hold = std::string("invokevirtual")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_IOR: hold = std::string("ior");break;
	case CODE_IREM: hold = std::string("irem");break;
	case CODE_IRETURN: hold = std::string("ireturn");break;
	case CODE_ISHL: hold = std::string("ishl");break;
	case CODE_ISHR: hold = std::string("ishr");break;
	case CODE_ISTORE: hold = std::string("istore")+' '+ByteToHexa(buf[0]);break;
	case CODE_ISTORE_0: hold = std::string("istore_0");break;
	case CODE_ISTORE_1: hold = std::string("istore_1");break;
	case CODE_ISTORE_2: hold = std::string("istore_2");break;
	case CODE_ISTORE_3: hold = std::string("istore_3");break;
	case CODE_ISUB: hold = std::string("isub");break;
	case CODE_IUSHR: hold = std::string("iushr");break;
	case CODE_IXOR: hold = std::string("ixor");break;
	case CODE_JSR: hold = std::string("jsr")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_JSR_W: hold = std::string("jsr_w")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1])+' '+ByteToHexa(buf[2])+' '+ByteToHexa(buf[3]);break;
	case CODE_L2D: hold = std::string("l2d");break;
	case CODE_L2F: hold = std::string("l2f");break;
	case CODE_L2I: hold = std::string("l2i");break;
	case CODE_LADD: hold = std::string("ladd");break;
	case CODE_LALOAD: hold = std::string("laload");break;
	case CODE_LAND: hold = std::string("land");break;
	case CODE_LASTORE: hold = std::string("lastore");break;
	case CODE_LCMP: hold = std::string("lcmp");break;
	case CODE_LCONST_0: hold = std::string("lconst_0");break;
	case CODE_LCONST_1: hold = std::string("lconst_1");break;
	case CODE_LDC: hold = std::string("ldc")+' '+ByteToHexa(buf[0]);break;
	case CODE_LDC_W: hold = std::string("ldc_w")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_LDC2_W: hold = std::string("ldc2_w")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_LDIV: hold = std::string("ldiv");break;
	case CODE_LLOAD: hold = std::string("lload")+' '+ByteToHexa(buf[0]);break;
	case CODE_LLOAD_0: hold = std::string("lload_0");break;
	case CODE_LLOAD_1: hold = std::string("lload_1");break;
	case CODE_LLOAD_2: hold = std::string("lload_2");break;
	case CODE_LLOAD_3: hold = std::string("lload_3");break;
	case CODE_LMUL: hold = std::string("lmul");break;
	case CODE_LNEG: hold = std::string("lneg");break;
	case CODE_LOR: hold = std::string("lor");break;
	case CODE_LREM: hold = std::string("lrem");break;
	case CODE_LRETURN: hold = std::string("lreturn");break;
	case CODE_LSHL: hold = std::string("lshl");break;
	case CODE_LSHR: hold = std::string("lshr");break;
	case CODE_LSTORE: hold = std::string("lstore")+' '+ByteToHexa(buf[0]);break;
	case CODE_LSTORE_0: hold = std::string("lstore_0");break;
	case CODE_LSTORE_1: hold = std::string("lstore_1");break;
	case CODE_LSTORE_2: hold = std::string("lstore_2");break;
	case CODE_LSTORE_3: hold = std::string("lstore_3");break;
	case CODE_LSUB: hold = std::string("lsub");break;
	case CODE_LUSHR: hold = std::string("lushr");break;
	case CODE_LXOR: hold = std::string("lxor");break;
	case CODE_MONITORENTER: hold = std::string("monitorenter");break;
	case CODE_MONITOREXIT: hold = std::string("monitorexit");break;
	case CODE_MULTIANEWARRAY: hold = std::string("multianewarray")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1])+' '+ByteToHexa(buf[2]);break;
	case CODE_NEW: hold = std::string("new")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_NEWARRAY: hold = std::string("newarray")+' '+ByteToHexa(buf[0]);break;
	case CODE_NOP: hold = std::string("nop");break;
	case CODE_POP: hold = std::string("pop");break;
	case CODE_POP2: hold = std::string("pop2");break;
	case CODE_PUTFIELD: hold = std::string("putfield")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_PUTSTATIC: hold = std::string("putstatic")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_RET: hold = std::string("ret")+' '+ByteToHexa(buf[0]);break;
	case CODE_RETURN: hold = std::string("return");break;
	case CODE_SALOAD: hold = std::string("saload");break;
	case CODE_SASTORE: hold = std::string("sastore");break;
	case CODE_SIPUSH: hold = std::string("sipush")+' '+ByteToHexa(buf[0])+' '+ByteToHexa(buf[1]);break;
	case CODE_SWAP: hold = std::string("swap");break;
	case CODE_LOOKUPSWITCH:
	{
		hold = "lookupswitch";
		int pad = 3-((3+buf-start)%4); buf += pad;;
		unsigned int pairs = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
		int punPairs = *reinterpret_cast<int*>(&pairs);
		for (int i = 0; i < 8+(punPairs*8); i++)
			hold += ' ' + ByteToHexa(buf[i]);
	}
	break;
	case CODE_TABLESWITCH:
	{
		hold = "tableswitch";
		int pad = 3-((3+buf-start)%4); buf += pad;;
		unsigned int low = buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
		unsigned int high = buf[11]+(256*buf[10])+(256*256*buf[9])+(256*256*256*buf[8]);
		int punL = *reinterpret_cast<int*>(&low);
		int punH = *reinterpret_cast<int*>(&high);
		for (int i = 0; i < 12+(4*(1+punH-punL)); i++)
			hold += ' ' + ByteToHexa(buf[i]);
	}
	break;
	case CODE_WIDE:
	{
		hold = "wide";
		if (buf[0] != CODE_IINC)
		{
			for (int i = 0; i < 3; i++)
				hold += ' ' + ByteToHexa(buf[i]);
		}
		else
		{
			for (int i = 0; i < 5; i++)
				hold += ' ' + ByteToHexa(buf[i]);
		}
	}
	break;
	}
	return hold;
}

std::vector<std::string> Method::GetCodeRegion(int lower, int higher)
{
	if (higher <= lower)
		return std::vector<std::string>();
	std::vector<std::string> hold; hold.resize(higher-lower);
	for (int i = 0; i < higher-lower; i++)
		hold[i] = GetCodeLine(i+lower);
	return hold;
	
}
void Method::ModifyCodeLine(std::string code, int index) //So many computations would be faster by keeping track of the first table instance
{
	int newLength = 0;
	std::string monic;
	std::string params;
	{
		int codeInd = 0;
		for (; (code[codeInd] >= 'A' && code[codeInd] <= 'Z') || (code[codeInd] >= 'a' && code[codeInd] <= 'z') || code[codeInd] == '_' || (code[codeInd] >= '0' && code[codeInd] <= '9'); codeInd++)
			monic += code[codeInd];
		for (int i = codeInd; i < code.size(); i++)
			if (code[i] != ' ')
				params += code[i];
	}
	int op = MonicToOp(monic);
	std::vector<unsigned char> paraBytes; paraBytes.resize(params.size()/2);
	for (int i = 0; i < paraBytes.size(); i++)
		paraBytes[i] = HexaCharToInt(params, 2, i*2);
	int paraCount = OpParaCount(op);

	unsigned char* codeStart; unsigned char* codeEnd; GetCodeStartAndEnd(codeStart, codeEnd);

	unsigned char* cInfo = codeStart+codeTable[index];

	if (op == CODE_LOOKUPSWITCH)
	{
		unsigned int pairs = paraBytes[7]+(256*paraBytes[6])+(256*256*paraBytes[5])+(256*256*256*paraBytes[4]);
		int punPairs = *reinterpret_cast<int*>(&pairs);

		int pad = 3-(codeTable[index]%4);
		paraCount = 8+(8*punPairs)+pad;
		for (int i = 0; i < pad; i++)
			paraBytes.insert(paraBytes.begin(), 0);
	}
	else if (op == CODE_TABLESWITCH)
	{
		unsigned int low = paraBytes[7]+(256*paraBytes[6])+(256*256*paraBytes[5])+(256*256*256*paraBytes[4]);
		unsigned int high = paraBytes[11]+(256*paraBytes[10])+(256*256*paraBytes[9])+(256*256*256*paraBytes[8]);
		int punL = *reinterpret_cast<int*>(&low);
		int punH = *reinterpret_cast<int*>(&high);

		int pad = 3-((codeTable[index])%4);
		paraCount = 12+(4*(1+punH-punL))+pad;
		for (int i = 0; i < pad; i++)
			paraBytes.insert(paraBytes.begin(), 0);
	}
	else if (op == CODE_WIDE)
	{
		paraCount = 3;
		if (paraBytes[0] == CODE_IINC)
			paraCount = 5;
	}

	int otherOp = cInfo[0];
	int otherParaCount = OpParaCount(otherOp);
	if (otherOp == CODE_LOOKUPSWITCH)
	{
		int pad = 3-((codeTable[index])%4);
		cInfo += 1+pad;
		unsigned int pairs = cInfo[7]+(256*cInfo[6])+(256*256*cInfo[5])+(256*256*256*cInfo[4]);
		int punPairs = *reinterpret_cast<int*>(&pairs);
		otherParaCount = 8+(8*punPairs)+pad;
	}
	else if (otherOp == CODE_TABLESWITCH)
	{
		int pad = 3-((codeTable[index])%4);
		cInfo += 1+pad;;
		unsigned int low = cInfo[7]+(256*cInfo[6])+(256*256*cInfo[5])+(256*256*256*cInfo[4]);
		unsigned int high = cInfo[11]+(256*cInfo[10])+(256*256*cInfo[9])+(256*256*256*cInfo[8]);
		int punL = *reinterpret_cast<int*>(&low);
		int punH = *reinterpret_cast<int*>(&high);
		otherParaCount = 12+(4*(1+punH-punL))+pad;
	}
	else if (otherOp == CODE_WIDE)
	{
		otherParaCount = 3;
		if (cInfo[1] == CODE_IINC)
			otherParaCount = 5;
	}
	switch (otherOp)
	{
	default: break;
	case CODE_GOTO_W: case CODE_JSR_W: case CODE_GOTO: case CODE_IF_ACMPEQ: case CODE_IF_ACMPNE: case CODE_IF_ICMPEQ: case CODE_IF_ICMPNE: case CODE_IF_ICMPLT:
	case CODE_IF_ICMPGE: case CODE_IF_ICMPGT: case CODE_IF_ICMPLE: case CODE_IFEQ: case CODE_IFNE: case CODE_IFGE: case CODE_IFGT: case CODE_IFLE: case CODE_IFNONNULL:
	case CODE_IFNULL: case CODE_JSR: case CODE_LOOKUPSWITCH: case CODE_TABLESWITCH: 
		for (int i = 0; i < jumpTable.size();) if (jumpTable[i].lineIndex == index) jumpTable.erase(jumpTable.begin()+i); else i++; break;
	}
	int jumpTableInd = 0;
	for (; jumpTableInd < jumpTable.size(); jumpTableInd++)
		if (jumpTable[jumpTableInd].lineIndex > index)
			break;
	switch (op)
	{
	default: break;
	case CODE_GOTO_W: case CODE_JSR_W:
	{
		unsigned int offset = paraBytes[3]+(256*paraBytes[2])+(256*256*paraBytes[2])+(256*256*256*paraBytes[0]);
		jumpTable.insert(jumpTable.begin()+jumpTableInd, CodeIndicesData(index,codeTable[index]+(*reinterpret_cast<int*>(&offset))));
	} break;
	case CODE_GOTO: case CODE_IF_ACMPEQ: case CODE_IF_ACMPNE: case CODE_IF_ICMPEQ: case CODE_IF_ICMPNE: case CODE_IF_ICMPLT:
	case CODE_IF_ICMPGE: case CODE_IF_ICMPGT: case CODE_IF_ICMPLE: case CODE_IFEQ: case CODE_IFNE: case CODE_IFGE: case CODE_IFGT: case CODE_IFLE: case CODE_IFNONNULL:
	case CODE_IFNULL: case CODE_JSR: 
	{
		unsigned short offset = paraBytes[1]+(256*paraBytes[0]);
		jumpTable.insert(jumpTable.begin()+jumpTableInd, CodeIndicesData(index,codeTable[index]+(*reinterpret_cast<short*>(&offset))));
	} break;
	case CODE_LOOKUPSWITCH:
	{
		int pad = 3-(codeTable[index]%4);
		int paramInd = 8+pad;
		jumpTable.insert(jumpTable.begin()+jumpTableInd, CodeIndicesData(index));
		for (; paramInd < paraCount; paramInd += 8)
		{
			unsigned int offset = paraBytes[paramInd+7]+(256*paraBytes[paramInd+6])+(256*256*paraBytes[paramInd+5])+(256*256*256*paraBytes[paramInd+4]);
			jumpTable.back().indices.push_back(codeTable[index]+(*reinterpret_cast<int*>(&offset)));
		}

	} break;
	case CODE_TABLESWITCH:
	{
		int pad = 3-(codeTable[index]%4);
		int paramInd = 12+pad;
		jumpTable.insert(jumpTable.begin()+jumpTableInd, CodeIndicesData(index));
		for (; paramInd < paraCount; paramInd += 4)
		{
			unsigned int offset = paraBytes[paramInd+3]+(256*paraBytes[paramInd+2])+(256*256*paraBytes[paramInd+1])+(256*256*256*paraBytes[paramInd+0]);
			jumpTable.back().indices.push_back(codeTable[index]+(*reinterpret_cast<int*>(&offset)));
		}
	} break;
	}

	std::vector<unsigned char>& info = attrs[codeAttr].info;
	int dif = 0;
	if (paraCount > otherParaCount) //Extending info vector
	{
		dif = paraCount - otherParaCount;
		int padDif = 0;
		int padIndex = 0;
		for (int i = index+1; i < codeTable.size(); i++)
		{
			if (codeStart[codeTable[i]] == CODE_LOOKUPSWITCH || codeStart[codeTable[i]] == CODE_TABLESWITCH)
			{
				int pad = 3-((codeTable[i])%4);
				int newPad = 3-((dif+codeTable[i])%4);
				padDif = newPad-pad;
				dif += padDif;
				padIndex = i;
				break;
			}
		}

		unsigned int codeLength = (codeEnd - codeStart)+dif;
		info[4] = codeLength/(256*256*256);
		info[5] = codeLength/(256*256);
		info[6] = codeLength/(256);
		info[7] = codeLength;
		info.reserve(info.size()+dif);
		info.insert(info.begin()+8+codeTable[index], dif, 0);
		GetCodeStartAndEnd(codeStart, codeEnd);

		if (padDif < 0)
		{
			unsigned char* bufP = codeStart+codeTable[padIndex]+dif-padDif;
			unsigned char* bufN = bufP+padDif;
			for (; bufN >= codeStart+codeTable[index]+1+paraCount+padDif;)
			{
				bufP[0] = bufN[0];
				bufP--; bufN--;
			}

			for (int i = index+1; i <= padIndex; i++)
				codeTable[i] += dif-padDif;
			if (dif != 0)
				for (int i = padIndex+1; i < codeTable.size(); i++)
					codeTable[i] += dif;

			int modLoc = INT_MAX;
			if (index != codeTable.size())
				modLoc = codeTable[index];
			int padLoc = INT_MAX;
			if (padIndex < codeTable.size())
				padLoc = codeTable[padIndex];
			for (int i = 0; i < jumpTable.size(); i++)
			{
				std::vector<int>& indices = jumpTable[i].indices;
				for (int i = 0; i < indices.size();i++)
				{
					if (indices[i] <= modLoc)
						continue;
					else if (indices[i] <= padLoc)
					{
						indices[i] += dif-padDif;
						SetJumpOffset(codeStart+codeTable[jumpTable[i].lineIndex],indices[i],i); 
					}
					else
					{
						indices[i] += dif;
						SetJumpOffset(codeStart+codeTable[jumpTable[i].lineIndex],indices[i],i); 
					}
				}
			}

			//add or remove from tables for index

			dif = 0;
		}
		else
		{
			if (dif != 0)
				for (int i = index+1; i < codeTable.size(); i++)
					codeTable[i] += dif;
			dif = padDif;
		}
	}
	else
		dif = otherParaCount-paraCount;

	
	//In-place modify and remove
	unsigned char* bufP = codeStart+codeTable[index];
	bufP[0] = op;
	for (int i = 1; i < 1+paraCount; i++)
		bufP[i] = paraBytes[i-1];
	bufP += 1+paraCount;
	if (dif != 0 && index < codeTable.size()-1)
	{
		int padIndex = index+1;
		unsigned char* bufN = codeStart+codeTable[padIndex];
		bufP = bufN-dif;
		int padSplitAmount = -5;
		for (; bufN < codeEnd;)
		{
			if (padSplitAmount == -5 && bufN == codeStart+codeTable[padIndex])
			{
				if (bufN[0] == CODE_LOOKUPSWITCH || bufN[0] == CODE_TABLESWITCH)
				{
					int pad = 3-((bufN-codeStart)%4);
					int newPad = 3-((bufP-codeStart)%4);

					bufP[0] = bufN[0];
					for (int i = 1; i < newPad+1; i++)
						bufP[i] = 0;
					bufN += pad;
					bufP += newPad;
					padSplitAmount = (newPad-pad); //after first padding, all other paddings will remain the same
					dif -= padSplitAmount; //dif never ends up negative
				}
				else
				{
					padIndex++;
					bufP[0] = bufN[0];
				}
				if (dif == 0)
					break;
			}
			else
				bufP[0] = bufN[0];
			bufP++; bufN++;
		}
		if (dif != 0)
		{
			for (; bufN < info.data()+info.size();)
			{
				bufP[0] = bufN[0];
				bufP++; bufN++;
			}
		}
		info.resize(info.size()-dif);
		if (padSplitAmount == -5)
			padSplitAmount = 0;

		for (int i = index+1; i < codeTable.size(); i++)
			if (i <= padIndex)
				codeTable[i] -= dif+padSplitAmount;
			else
				codeTable[i] -= dif;
		int modLoc = INT_MAX;
		if (index != codeTable.size())
			modLoc = codeTable[index];
		int padLoc = INT_MAX;
		if (padIndex < codeTable.size())
			padLoc = codeTable[padIndex];
		for (int i = 0; i < jumpTable.size(); i++)
		{
			std::vector<int>& indices = jumpTable[i].indices;
			for (int i = 0; i < indices.size();i++)
			{
				if (indices[i] <= modLoc)
					continue;
				else if (indices[i] <= padLoc)
				{
					indices[i] -= dif+padSplitAmount;
					SetJumpOffset(codeStart+codeTable[jumpTable[i].lineIndex],indices[i],i); 
				}
				else
				{
					indices[i] -= dif;
					SetJumpOffset(codeStart+codeTable[jumpTable[i].lineIndex],indices[i],i); 
				}
			}
		}

		unsigned int codeLength = codeEnd - codeStart;
		if (padIndex == codeTable.size())
			codeLength -= dif-padSplitAmount;
		else
			codeLength -= dif;
		
		info[4] = codeLength/(256*256*256);
		info[5] = codeLength/(256*256);
		info[6] = codeLength/(256);
		info[7] = codeLength;
		

			
		//add or remove from tables for index

	}
}
void Method::InsertCodeLine(std::string code, int index)
{
	
}
void Method::DeleteCodeLine(std::string code, int index)
{
}

void Method::GetCodeStartAndEnd(unsigned char*& start, unsigned char*& end)
{
	unsigned char* buf = attrs[codeAttr].info.data();
	if (start != nullptr)
	{
		start = buf+8;
	}
	if (end != nullptr)
	{
		end = buf+8+buf[7]+(256*buf[6])+(256*256*buf[5])+(256*256*256*buf[4]);
	}
}

void Method::SetJumpOffset(unsigned char* opLoc, int offset, int subJump)
{
	int code = *opLoc;
	switch (code)
	{ default: std::cout << "Called SetJumpIndex on an op without jump parameters"; abort(); break;
	case CODE_GOTO_W: case CODE_JSR_W:
	{ 
		unsigned int pun = *reinterpret_cast<unsigned int*>(&offset);
		opLoc[1] = pun/(256*256*256); opLoc[2] = (pun/(256*256))%256; opLoc[3] = (pun/256)%256; opLoc[4] = pun%256;
	} break;
	case CODE_GOTO: case CODE_IF_ACMPEQ: case CODE_IF_ACMPNE: case CODE_IF_ICMPEQ: case CODE_IF_ICMPNE: case CODE_IF_ICMPLT: 
	case CODE_IF_ICMPGE: case CODE_IF_ICMPGT: case CODE_IF_ICMPLE: case CODE_IFEQ: case CODE_IFNE: case CODE_IFGE:
	case CODE_IFGT: case CODE_IFLE: case CODE_IFNONNULL: case CODE_IFNULL: case CODE_JSR:
	{
		unsigned int pun = *reinterpret_cast<unsigned int*>(&offset);
		opLoc[1] = pun/256; opLoc[2] = pun%256;
	} break;
	case CODE_LOOKUPSWITCH:
	{
		int pad = 3-((attrs[codeAttr].info.data()-opLoc)%4);
		if (subJump == 0)
		{
			opLoc += 1+pad;
			unsigned int pun = *reinterpret_cast<unsigned int*>(&offset);
			opLoc[0] = pun/(256*256*256); opLoc[1] = (pun/(256*256))%256; opLoc[2] = (pun/256)%256; opLoc[3] = pun%256;
		}
		else
		{
			opLoc += 1+pad+8;
			subJump--;
			unsigned int pun = *reinterpret_cast<unsigned int*>(&offset);
			opLoc[(8*subJump)+4] = pun/(256*256*256); opLoc[(8*subJump)+5] = (pun/(256*256))%256; opLoc[(8*subJump)+6] = (pun/256)%256; opLoc[(8*subJump)+7] = pun%256;
		}
	} break;
	case CODE_TABLESWITCH:
	{
		int pad = 3-((attrs[codeAttr].info.data()-opLoc)%4);
		if (subJump == 0)
		{
			opLoc += 1+pad;
			unsigned int pun = *reinterpret_cast<unsigned int*>(&offset);
			opLoc[0] = pun/(256*256*256); opLoc[1] = (pun/(256*256))%256; opLoc[2] = (pun/256)%256; opLoc[3] = pun%256;
		}
		else
		{
			opLoc += 1+pad+12;
			subJump--;
			unsigned int pun = *reinterpret_cast<unsigned int*>(&offset);
			opLoc[(4*subJump)+0] = pun/(256*256*256); opLoc[(4*subJump)+1] = (pun/(256*256))%256; opLoc[(4*subJump)+2] = (pun/256)%256; opLoc[(4*subJump)+3] = pun%256;
		}
	} break;
	}
}
