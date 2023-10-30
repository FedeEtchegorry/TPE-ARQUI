#include <colours.h>
#include <systemCalls.h>
#include <videoDriver.h>
#include <stringPrinter.h>
#include <buffer.h>

extern void haltcpu();

unsigned char sysWrite(unsigned int fd, unsigned int count)	{

	switch(fd)	{
	// STDOUT : Salida estandar.
		case STDOUT :	{
			char s [count+1];
			readBuffer(s, count+1);
			printTextDefault(s, WHITE, BLACK);
			break;
		}
		case CHARSTDOUT : {
			printCharDefault(readChar(), WHITE, BLACK);
			break;
		}
	// STDERR : Salida de error (salida estandar pero en rojo).
		case STDERR :	{
			char s [count+1];
			readBuffer(s, count+1);
			printTextDefault(s, RED, BLACK);
			break;
		}
	// RETURN_CHAR : Devuelve en rax el ultimo caracter del buffer.
		case RETURN_CHAR :	{ 
			return readChar();
			break;
		}
		case RETURNANDSTDOUT_CHAR :	{
			unsigned char c = readChar();
			printCharDefault(c, WHITE, BLACK);
			return c;
		}

		default :
			break;
	}

	return 0;
}

void sysRead( unsigned int fd, const  char * s, char c)	{
	switch(fd)	{
		case STRING :	{
			putString(s);
			break;
		}
		case CHAR :	{
			putChar(c);
			break;
		}
		default :
			break;
	}
	
}

void sysKillBuffer()	{
	cleanBuffer();
}

void exitProgram(){
    fillScreen(BLACK);
    haltcpu();          //queda trabado acá y no puede hacer nada más

}