#include <userlib.h>
#include <shell.h>

void read(unsigned char * buffer)   {
    
    int i=0;
    unsigned char c [2];
    c[1] = '\0';
    while((*c = getAndPrintChar())!='\n')    {
        buffer[i++] = *c;
    }
    
    buffer[i] = 0;
}