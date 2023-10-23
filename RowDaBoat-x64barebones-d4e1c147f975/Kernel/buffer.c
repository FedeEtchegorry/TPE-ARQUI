
#include <buffer.h>

#define TRUE 1
#define FALSE !TRUE 

static unsigned char buffer [BUFFER_SIZE] = {'\0'};
static int current = 0;

int bufferIsEmpty() {
    return current == 0;
}

int bufferIsFull()  {
    return current == BUFFER_SIZE;
}

int putChar(unsigned char c)   {
    
    if(bufferIsFull())
        return FALSE;

    buffer[current++] = c;
    return TRUE;
}

unsigned char readChar() {
    
    unsigned char toReturn = buffer[current];
    
    if(!bufferIsEmpty())    
        buffer[--current] = '\0';
    
    return toReturn;
}

void readBuffer(unsigned char * string, int dim)    {
    
    for(int i=current-1; i>=0 && (current-1-i)<dim; --i)
        string[i] = readChar(); // está contemplado un buffer vacío

    if(dim < BUFFER_SIZE)
        cleanBuffer();

}

unsigned char peekBuffer()  {
    return buffer[current-1];
}

void peekAllBuffer(unsigned char * string, int dim) {
    
    for(int i=current-1; i>=0 && (current-1-i)<dim; --i)
        string[i] = peekBuffer();

    if(dim < BUFFER_SIZE)
        cleanBuffer();

}

void cleanBuffer()  {
    for(int i=0; i<BUFFER_SIZE; ++i)
        buffer[i] = '\0';
}


