#ifndef _VIDEODRIVER_H_
#define _VIDEODRIVER_H_

#include <stdint.h>

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);
void fillScreen(uint32_t hexColor);
void printText(char* string, int fgcolor, int bgcolor, int charSize);
void printTextDefault(char* string, int fgcolor, int bgcolor);
void drawchar(unsigned char c, int x, int y, int fgcolor, int bgcolor,int size);
void render(char *bitmap, int fgcolor, int bgcolor, int xinit, int yinit, int size);
void setCharWidth(unsigned int size);
void printNewline();
void printTab();
void backspace();
void setCurrentVideoLinePos(int linesToScroll);
void scroll(int lines);



#endif