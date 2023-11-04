#include <time.h>
#include <stdint.h>
#include <keyboard.h>
#include <videoDriver.h>
#include <colours.h>
#include <systemCalls.h>
#include <buffer.h>



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
	
	// if( alarmAt(5) )	{
	// 	char string [BUFFER_SIZE];
	// 	readBuffer(string, BUFFER_SIZE);
	// 	printTextDefault(string, WHITE, BLACK);
	// }
	
}

void int_21() {
    putChar(map(keyboard_handler()));
}

// Syscalls:
// La idea es que del userspace pueda hacer int 0x80 (en assembler) asi llama 
// a esta función.
void int_80(int id, unsigned int rbx,  char * rcx, unsigned int rdx, char rsi, unsigned int rdi){
	
	switch(id)	{
        case SYSTEM_EXIT_ID : {
            exitProgram();
            break;
        }
		case SYSTEM_WRITE_ID :	{
			sysWrite(rbx, rdx);
			break;
		}
		
		case SYSTEM_READ_ID :	{
			sysRead(rbx, rcx, rsi);
			break;
		}
        case SYSTEM_TIME_ID :{
            timeManager();
            break;
        }
		case SYSTEM_KILLBUFFER_ID :	{
			sysKillBuffer();
			break;
		}
        case SMALLER_TEXT : {
            makeTextSmaller();
            break;
        }
        case BIGGER_TEXT : {
            makeTextBigger();
            break;
        }
		case RANDLONG_ID :	{
			rand();
			break;
		}
        case RECOLOR:{
            changeColor(rbx,rdx);       //TODO falta asegurarse de guardar en los registros las cosas
            break;
        }
		default:	{
			break;
			}
	}
}

