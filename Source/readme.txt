CodeAttrStuff lists all 202 Java SE 21 code attribute opcodes in the following format:

CODE_(name) 0x(opcode in hex) (parameter count as int)

each separated by a newline

Tableswitch, lookupswitch, and wide have 0 parameter count, "name" may or may not be different than that found on https://docs.oracle.com/javase/specs/jvms/se21/html/index.html , idk. Java maintains backwards compatibility with previous versions, so this list is accurate for versions before 21