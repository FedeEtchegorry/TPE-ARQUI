#include <videoDriver.h>
#include <colours.h>




void printTextDefault(char* string, int fgcolor, int bgcolor){
    for (int i = 0; string[i] != '\0'; i++)
        drawCharOnCurrentPos(string[i], fgcolor, bgcolor);
}
void printNewline(){
    newline();
}
void printTab(){
    deleteSlash();
    char * tab="   ";
    printTextDefault(tab, BLACK, BLACK);
}


void backspace(){
    deleteSlash();
    drawCharOnPreviousPosition(' ',BLACK, BLACK);
}



