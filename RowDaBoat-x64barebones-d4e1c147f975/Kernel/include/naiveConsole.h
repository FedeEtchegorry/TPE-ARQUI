#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>
#include <colours.h>

#define DEFAULT_COLOUR collapseFB(LIGHT_GRAY, BLACK)

void ncPrint(const char * string);
void ncPrintColored( char * string, unsigned char forAndBackolour );
void ncPrintChar(char character);
void ncNewline();
void ncBackspace();
void ncTab();
void WriteCharacterScroll(unsigned char c, unsigned char forAndBackolour, int x, int y);
void scrollScreen();
void setCurrentVideoLine();
void ncPrintDec(uint64_t value);
void ncPrintHex(uint64_t value);
void ncPrintBin(uint64_t value);
void ncPrintBase(uint64_t value, uint32_t base);
void ncClear();

#endif