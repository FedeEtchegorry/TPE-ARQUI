#include <colours.h>
#include <systemCalls.h>
#include <videodriver.h>
#include

#define STDOUT 0x01
#define STDERR 0x02


void sysWrite(unsigned int fd, const char * buffer)	{
	
	switch(fd)	{
	// STDOUT : Salida estandar
		case STDOUT:	
			printTextDefault(buffer, WHITE, BLACK);
			break;
	// STDERR : Salida de error (salida estandar pero en rojo)
		case STDERR:	
			printTextDefault(buffer, RED, BLACK);
			break;
	}

}

#define STDIN 0x01

void sysRead(unsigned int fd, char * buffer, unsigned int count)	{
	switch(fd)	{
	// STDIN : Entrada estandar
	case STDIN :
	// Supongo que esto es correcto porque en el shell deberían de 
	// encargarse de dejar en el buffer (del SO, no @buffer parametro)
	// el argumento del llamado a la syscall.
		readBuffer(buffer, count);
		break;
	default : 
		break;
	}
}
