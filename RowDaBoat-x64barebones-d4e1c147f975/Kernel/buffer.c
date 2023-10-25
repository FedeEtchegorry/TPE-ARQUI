
#include <buffer.h>

#define TRUE 1
#define FALSE 0

static unsigned char buffer [BUFFER_SIZE] = {'\0'};
static int next = 0;

int bufferIsEmpty() {
    return next == 0;
}

int bufferIsFull()  {
    return next == BUFFER_SIZE-1;
}

int putChar(unsigned char c)   {
    
    if(bufferIsFull())
        return FALSE;

    buffer[next++] = c;
    return TRUE;
}

unsigned char readChar() {
    
    unsigned char toReturn = peekBuffer();
    
    if(!bufferIsEmpty())
        buffer[--next] = '\0';
    
    return toReturn;
}

void readBuffer(unsigned char * string, int dim)    {
    
    peekAllBuffer(string, dim);
    cleanBuffer();

}

unsigned char peekBuffer()  {
    
    return bufferIsEmpty()? '\0' : buffer[next-1];
}

void peekAllBuffer(unsigned char * string, int dim) {
    
    int i=0;
    for(; i<dim-2 && i<next-1; ++i)    
        string[i] = buffer[i];

    string[i] = '\0';
}

void cleanBuffer()  {
    for(int i=0; i<BUFFER_SIZE; ++i)
        buffer[i] = '\0';
    next = 0;
}


