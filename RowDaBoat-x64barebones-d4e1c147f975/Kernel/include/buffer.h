#ifndef _BUFFER_H
#define _BUFFER_H
    
#define BUFFER_SIZE 256
    
    int bufferIsEmpty();

    int bufferIsFull();

// Ingresa un caracter en el Buffer.
// Retrona 1 si lo ingreso correctamente, 0 si no.
    int putChar(unsigned char c);
    
// Obtiene el ultimo caracter, borrandolo del Buffer.
    unsigned char readChar();

// Copia todo el buffer en string, dejandolo vacio.
    void readBuffer(unsigned char * string, int dim);
    
// Obtiene el ultimo caracter.
    unsigned char peekBuffer();

// Copia todo el buffer en string.
    void peekAllBuffer(unsigned char * string, int dim);

// Limpia el Buffer.
    void cleanBuffer();

#endif