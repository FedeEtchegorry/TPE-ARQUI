#include <time.h>
#include <stdint.h>
#include <naiveConsole.h>
#include <keyboard.h>

static void int_21();
static void int_20();


typedef void (*int_xx)(void);

static int_xx interruptions[2] = {&int_20, &int_21};

static uint8_t * string = "Tick numero: ";

void irqDispatcher(uint64_t irq) {
	interruptions[irq]();
	return;
}

void int_20() {
	timer_handler();
	
	if( alarmAt(5) )	
	{
		ncClear();
		ncPrint(string);
		ncPrintDec(ticks_elapsed());
	}
}

void int_21() {
	ncPrintChar(keyboard_handler());
}
