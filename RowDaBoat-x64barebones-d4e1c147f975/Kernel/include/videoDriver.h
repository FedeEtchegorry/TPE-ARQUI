#ifndef _VIDEODRIVER_H_
#define _VIDEODRIVER_H_

#include <stdint.h>

//si se cambia la resolución habría que cambiarlo
#define PIXELS 3
#define WIDTH 1024
#define HEIGHT 768


//pone un pixel de un color en una ubicación
void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);
//llena la pantalla de un solo color
void fillScreen(uint32_t hexColor);
//llama a render enviándole el subarray con los datos de una letra en específico
void drawCharWithoutDisplacement(unsigned char c,int fgcolor, int bgcolor);
void drawCharOnCurrentPos(unsigned char c,int fgcolor, int bgcolor);
void drawCharOnPreviousPosition(unsigned char c,int fgcolor, int bgcolor);
//imprime la letra en pantalla usando la fuente que se manda desde draw char
void render(char *bitmap, int fgcolor, int bgcolor, int xinit, int yinit, int charSize);
//permite cambiar el tamaño de la letra(en multiplos de 8)
void setCharWidth(unsigned int size);

//setea la dirección de video en función de las líneas que se desplazó la pantalla
void setCurrentVideoLinePos(int linesToScroll);
//mueve la pantalla hacia abajo
void scroll(int lines);
void printCursor();
void deleteSlash();
void newline();




void setCharWidth(unsigned int size);





#endif