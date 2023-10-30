#include <colours.h>
#include <systemCalls.h>
#include <videoDriver.h>
#include <stringPrinter.h>
#include <buffer.h>

unsigned char sysWrite(unsigned int fd, unsigned int count)	{

	switch(fd)	{
	// STDOUT : Salida estandar.
		case STDOUT :	{
			char s [count+1];
			readBuffer(s, count+1);
			printTextDefault(s, WHITE, BLACK);
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
			char s[2];
			s[0] = readChar();
			s[1] = 0;
			printTextDefault(s, WHITE, BLACK);
			return s[0];
		}

		default :
			break;
	}

	return 0;
}

void sysRead(const  char * s)	{
	putString(s);
}

void sysKillBuffer()	{
	cleanBuffer();
}
