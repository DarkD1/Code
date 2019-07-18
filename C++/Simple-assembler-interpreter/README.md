# Simple-assembler-interpreter
We want to create a simple interpreter of assembler which will support the following instructions:

* mov x y - copies y (either a constant value or the content of a register) into register x
* inc x - increases the content of register x by one
* dec x - decreases the content of register x by one
* jnz x y - jumps to an instruction y steps away (positive means forward, negative means backward), but only if x (a constant or a register) is not zero
Register names are alphabetical (letters only). Constants are always integers (positive or negative).

Note: the jnz instruction moves relative to itself. For example, an offset of -1 would continue at the previous instruction, while an offset of 2 would skip over the next instruction.

The function will take an input list with the sequence of the program instructions and will return a dictionary with the contents of the registers.


27R3VDEFYFX4N0VC3FRTQZX
