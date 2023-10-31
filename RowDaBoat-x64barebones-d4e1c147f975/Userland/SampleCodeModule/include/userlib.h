#ifndef _USERLIB_H
#define _USERLIB_H

    #include <defs.h>

    void print(const unsigned char * str);

    unsigned char getChar();

    void putChar(char c);

    unsigned char getAndPrintChar();

    void killBuffer();

// Strings:

    unsigned int strLength(const char * str);

    unsigned int strEquals(char * s1, char * s2);

    unsigned int strToUint(char * s);

    int isDigit(unsigned char c);

#endif
