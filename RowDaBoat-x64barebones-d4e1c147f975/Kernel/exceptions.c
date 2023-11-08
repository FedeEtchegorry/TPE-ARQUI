#include <stdint.h>
#include <colours.h>
#include <videoDriver.h>
#include <stringPrinter.h>
#include <registers.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_EXCEPTION_ID 6

#define ZERO_EXCEPTION_MESSAGE "Excepcion numero 0: Divide por cero"
#define INVALID_OPCODE_MESSAGE "Excepcion numero 1: Operacion Invalida"

static void zero_division();
static void invalid_opcode();

uint64_t *registros;

void exceptionDispatcher(int exception, uint64_t* registers) {
    registros=registers;
    switch (exception) {
        case ZERO_EXCEPTION_ID:
            zero_division();
        case INVALID_OPCODE_EXCEPTION_ID:
            invalid_opcode();
        default:
            break;
    }
}


static void zero_division() {
	printTextDefault(ZERO_EXCEPTION_MESSAGE, RED, BLACK);
    registerPrintFull(registros);
}
void jumper(){

}

static void invalid_opcode(){
	printTextDefault(INVALID_OPCODE_MESSAGE, RED, BLACK);
    registerPrintFull(registros);
}