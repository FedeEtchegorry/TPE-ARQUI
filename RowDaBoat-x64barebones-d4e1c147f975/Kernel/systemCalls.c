#include <colours.h>
#include <systemCalls.h>

#define STDOUT 0x01
#define STDERR 0x02


void sysWrite(unsigned int fd, const char * buffer)	{
	
	switch(fd)	{
	// fd = 1 : Salida estandar
		case STDOUT:	
			printTextDefault(buffer, WHITE, BLACK);
			break;
	// fd = 2 : Salida de error (salida estandar pero en rojo)
		case STDERR:	
			printTextDefault(buffer, RED, BLACK);
			break;
	}

}
