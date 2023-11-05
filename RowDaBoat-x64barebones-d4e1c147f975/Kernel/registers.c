#include <registers.h>
#include <buffer.h>
#include "./include/videoDriver.h"

void printRegisters(registerStruct * registers) {
	putString("RIP = 0x");
	drawRegisters(registers->rip);
	putString("RAX = 0x");
	drawRegisters(registers->rax);
	putString("RBX = 0x");
	drawRegisters(registers->rbx);
	putString("RCX = 0x");
	drawRegisters(registers->rcx);
	putString("RDX = 0x");
	drawRegisters(registers->rdx);
	putString("RSP = 0x");
	drawRegisters(registers->rsp);
	putString("RBP = 0x");
	drawRegisters(registers->rbp);
	putString("RSI = 0x");
	drawRegisters(registers->rsi);
	putString("RDI = 0x");
	drawRegisters(registers->rdi);
	putString("R8  = 0x");
	drawRegisters(registers->r8);
	putString("R9  = 0x");
	drawRegisters(registers->r9);
	putString("R10 = 0x");
	drawRegisters(registers->r10);
	putString("R11 = 0x");
	drawRegisters(registers->r11);
	putString("R12 = 0x");
	drawRegisters(registers->r12);
	putString("R13 = 0x");
	drawRegisters(registers->r13);
	putString("R14 = 0x");
	drawRegisters(registers->r14);
	putString("R15 = 0x");
	drawRegisters(registers->r15);
}