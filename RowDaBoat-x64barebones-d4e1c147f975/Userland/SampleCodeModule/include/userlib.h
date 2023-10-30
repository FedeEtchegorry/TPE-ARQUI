#ifndef _USERLIB_H
#define _USERLIB_H

    void print(const unsigned char * str);

    unsigned char getChar();

    void putChar(char c);

    unsigned char getAndPrintChar();

    unsigned int strLength(const char * str);

    unsigned int strEquals(char * s1, char * s2);

    void killBuffer();

#endif
