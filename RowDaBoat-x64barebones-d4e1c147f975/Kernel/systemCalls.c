#include <colours.h>
#include <systemCalls.h>
#include <videodriver.h>
#include <stringPrinter.h>
#include <buffer.h>

#define STDOUT 0x01
#define STDERR 0x02


void sysWrite(unsigned int fd, const char * s)	{
	
	switch(fd)	{
	// STDOUT : Salida estandar
		case STDOUT:	
			printTextDefault(s, WHITE, BLACK);
			break;
	// STDERR : Salida de error (salida estandar pero en rojo)
		case STDERR:	
			printTextDefault(s, RED, BLACK);
			break;
	}

}

#define STDIN 0x01

void sysRead(unsigned int fd, char * s, unsigned int count)	{
	switch(fd)	{
	// STDIN : Entrada estandar
	case STDIN :
	// Supongo que esto es correcto porque en el shell deberían de 
	// encargarse de dejar en el buffer
	// el argumento del llamado a la syscall.
		readBuffer(s, count);
		break;
	default : 
		break;
	}
}
