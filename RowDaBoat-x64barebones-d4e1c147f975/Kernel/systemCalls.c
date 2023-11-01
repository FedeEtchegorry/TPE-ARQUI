#include <colours.h>
#include <systemCalls.h>
#include <videoDriver.h>
#include <stringPrinter.h>
#include <buffer.h>
#include <rtcDriver.h>
#include <time.h>

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
void timeManager(){
    char* time=getTime();
    printTextDefault(time, WHITE, BLACK);
}
void makeTextBigger(){
    biggerText();
}
void makeTextSmaller(){
    smallerText();
}

void exitProgram(){
    fillScreen(BLACK);
    haltcpu();          //queda trabado acá y no puede hacer nada más

}

static unsigned long seed = 0x5A5A5A5A;

unsigned long rand()	{

	unsigned long ans = 1103515245;

	char * currentTime = getTime();

	ans *= currentTime[1] * currentTime[0] + 
		currentTime[3] * currentTime[4] + 
		currentTime[6] * currentTime[7] + 
		currentTime[9] * currentTime[10] + 
		currentTime[12] * currentTime[13] +
		currentTime[15] * currentTime[16] * currentTime[17] * currentTime[18];

	ans += ((unsigned long) currentTime) << 11;

	seed = seed ^ ans;
	ans -= seed;

	ans *= ticks_elapsed();

	return ans & 0x7fffffff;

}
