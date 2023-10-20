#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>
#include <colours.h>

#define DEFAULT_COLOR collapseFB(LIGHT_GRAY, BLACK)

void putPixels();

void ncPrint(const char * string);
void ncPrintColored( char * string, unsigned char forAndBackColor );
void ncPrintChar(char character);
void ncNewline();
void ncBackspace();
void ncTab();
void WriteCharacterScroll(unsigned char c, unsigned char forAndBackColor, int x, int y);
void scrollScreen();
void setCurrentVideoLine();
void ncPrintDec(uint64_t value);
void ncPrintHex(uint64_t value);
void ncPrintBin(uint64_t value);
void ncPrintBase(uint64_t value, uint32_t base);
void ncClear();

#endif