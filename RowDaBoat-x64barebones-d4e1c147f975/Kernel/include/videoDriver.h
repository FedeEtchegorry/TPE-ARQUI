#ifndef _VIDEODRIVER_H_
#define _VIDEODRIVER_H_

#include <stdint.h>


//pone un pixel de un color en una ubicación
void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);
//llena la pantalla de un solo color
void fillScreen(uint32_t hexColor);
//imprime un string que tenga un color de letra, un fondo y un tamaño de caracter
void printText(char* string, int fgcolor, int bgcolor, int charSize);
//idem printText solo que con el charSize guardado como variable default
void printTextDefault(char* string, int fgcolor, int bgcolor);
//llama a render enviándole el subarray con los datos de una letra en específico
void drawchar(unsigned char c, int x, int y, int fgcolor, int bgcolor,int size);
//imprime la letra en pantalla usando la fuente que se manda desde draw char
void render(char *bitmap, int fgcolor, int bgcolor, int xinit, int yinit, int size);
//permite cambiar el tamaño de la letra(en multiplos de 8)
void setCharWidth(unsigned int size);
//imprime salto de línea
void printNewline();
//imprime un tab
void printTab();
//hace un backspace
void backspace();
//setea la dirección de video en función de las líneas que se desplazó la pantalla
void setCurrentVideoLinePos(int linesToScroll);
//mueve la pantalla hacia abajo
void scroll(int lines);



#endif