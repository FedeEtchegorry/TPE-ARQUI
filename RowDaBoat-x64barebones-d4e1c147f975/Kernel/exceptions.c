
#include <colours.h>
#include <naiveConsole.h>

#define ZERO_EXCEPTION_ID 0
#define ZERO_EXCEPTION_MESSAGE "Excepcion numero 0 : Divide cero"

static void zero_division();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
}

static void zero_division() {
	// Handler para manejar excepcíon
	printTextDefault(ZERO_EXCEPTION_MESSAGE, RED, BLACK);
	//TO_DO : Llamar al shel
}