#ifndef _BUFFER_H
#define _BUFFER_H
    
#define BUFFER_SIZE 256

// El ultimo caracter es siempre '\0'.
    
    int bufferIsEmpty();

    int bufferIsFull();

// Ingresa un caracter en el Buffer.
// Retrona 1 si lo ingreso correctamente, 0 si no.
    int putChar(unsigned char c);
    
// Obtiene el ultimo caracter, borrandolo del Buffer.
// Si el buffer esta vacío devuelve el caracter nulo: '\0'.
    unsigned char readChar();

// Copia todo el buffer en @string, dejandolo vacio.
    void readBuffer(unsigned char * string, int dim);
    
// Obtiene el ultimo caracter ingresado en el buffer.
// Si el buffer esta vacío devuelve el caracter nulo: '\0'.
    unsigned char peekBuffer();

// Copia todo el buffer en @string.
    void peekAllBuffer(unsigned char * string, int dim);

// Limpia el Buffer.
    void cleanBuffer();

#endif