
#include <colours.h>
#include <videoDriver.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_EXCEPTION_ID 6

#define ZERO_EXCEPTION_MESSAGE "Excepcion numero 0: Divide por cero"
#define INVALID_OPCODE_MESSAGE "Excepcion numero 1: Operacion Invalida"

static void zero_division();
static void invalid_opcode();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID){
		zero_division();
	} else
        if (exception==INVALID_OPCODE_EXCEPTION_ID){
		invalid_opcode();
	};	
}

static void zero_division() {
	// Handler para manejar excepcíon
	printTextDefault(ZERO_EXCEPTION_MESSAGE, RED, BLACK);
	//TO_DO : Llamar al shel

}

static void invalid_opcode(){
	printTextDefault(INVALID_OPCODE_MESSAGE, RED, BLACK);
}