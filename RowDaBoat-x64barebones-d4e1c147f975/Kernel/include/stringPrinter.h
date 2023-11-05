#ifndef TPE_ARQUI_STRINGPRINTER_H
#define TPE_ARQUI_STRINGPRINTER_H


void printText(char* string, int fgcolor, int bgcolor, int charSize);

void printTextDefault(char* string, int fgcolor, int bgcolor);
void printCharDefault(char c,int fgcolor, int bgcolor);
void registerPrintInit();
void printRegisterDefault(char* string);
//imprime salto de línea
void printNewline();
//imprime un tab
void printTab();
//hace un backspace
void backspace();
void biggerText();
void smallerText();
void refillScreen();
void changeColors(int fgcolor);



#endif //TPE_ARQUI_STRINGPRINTER_H
