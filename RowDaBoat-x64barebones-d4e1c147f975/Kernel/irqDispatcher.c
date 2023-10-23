#include <time.h>
#include <stdint.h>
#include <naiveConsole.h>
#include <keyboard.h>
#include <videoDriver.h>
#include <colours.h>
#include <systemCalls.h>

#define TIMERTICK_INTERRUPTION_MESSAGE "Tick numero: "

static void int_21();
static void int_20();

typedef void (*int_xx)(void);

static int_xx interruptions[2] = {&int_20, &int_21};


void irqDispatcher(uint64_t irq) {
	interruptions[irq]();
	return;
}


void int_20() {
	timer_handler();
	
	if( alarmAt(5) )	
	{

		printTextDefault(TIMERTICK_INTERRUPTION_MESSAGE, WHITE, BLACK);

		char s[2] = {ticks_elapsed()+0x30, '\0'};
		printTextDefault(s, WHITE, BLACK);
	}
}

void int_21() {
    char c[2]= {map(keyboard_handler()), '\0'};
	if (*c!='\0')	
	    printTextDefault(c, WHITE, BLACK);
	
}

// Syscalls:
// La idea es que del userspace pueda hacer int 0x80 (en assembler) asi llama 
// a esta función, hay que ver como implementarlo.
void int_80(int id, uint64_t rbx, uint64_t rcx, uint64_t rdx, uint64_t esi, uint64_t edi){
	
	switch(id)	{
		case SYSTEM_WRITE_ID:	
			sysWrite( (unsigned int) rbx, (char *) rcx);
			break;

		//TO_DO : Excepcion por syscall invalida
		default:	
			break;
	}
}

