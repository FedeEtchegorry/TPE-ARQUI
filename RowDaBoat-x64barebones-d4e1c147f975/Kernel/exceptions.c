#include <stdint.h>
#include <colours.h>
#include <videoDriver.h>
#include <stringPrinter.h>
#include <registers.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_EXCEPTION_ID 6

#define ZERO_EXCEPTION_MESSAGE ((unsigned char *)"Excepcion numero 0: Divide por cero")
#define INVALID_OPCODE_MESSAGE ((unsigned char *)"Excepcion numero 1: Operacion Invalida")

static void zero_division(uint64_t * registers);
static void invalid_opcode(uint64_t * registers);


void exceptionDispatcher(int exception, uint64_t* registers) {
    
    switch (exception) {
        case ZERO_EXCEPTION_ID: {
            zero_division(registers);
            break;
    }
        case INVALID_OPCODE_EXCEPTION_ID: {   
            invalid_opcode(registers);
            break;
    }
        default:
            break;
    }
}


static void zero_division(uint64_t * registers) {
	printTextDefault(ZERO_EXCEPTION_MESSAGE, RED, BLACK);
    registerPrintFull(registers);
}
static void invalid_opcode(uint64_t * registers){
	printTextDefault(INVALID_OPCODE_MESSAGE, RED, BLACK);
    registerPrintFull(registers);
}