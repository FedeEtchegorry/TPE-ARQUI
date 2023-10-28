#include <videoDriver.h>
#include <colours.h>

void printTextDefault(char* string, int fgcolor, int bgcolor){
    blockBlink();
    for (int i = 0; string[i] != '\0'; i++) {
        deleteSlash();
        drawCharOnCurrentPos(string[i], fgcolor, bgcolor);
        printCursor();
    }
    allowBlink();
}
void printNewline(){
    blockBlink();
    deleteSlash();
    newline();
    printCursor();
    allowBlink();

}
void printTab(){
    blockBlink();
    deleteSlash();
    char * tab="   ";
    printTextDefault(tab, BLACK, BLACK);
    printCursor();
    allowBlink();
}


void backspace(){
    blockBlink();
    deleteSlash();
    drawCharOnPreviousPosition(' ',BLACK, BLACK);
    printCursor();
    allowBlink();
}



