#include <videoDriver.h>
#include <colours.h>




void printTextDefault(char* string, int fgcolor, int bgcolor){

    for (int i = 0; string[i] != '\0'; i++) {
        deleteSlash();
        drawCharOnCurrentPos(string[i], fgcolor, bgcolor);
        printCursor();
    }

}
void printNewline(){
    deleteSlash();
    newline();
    printCursor();
}
void printTab(){
    deleteSlash();
    char * tab="   ";
    printTextDefault(tab, BLACK, BLACK);
    printCursor();
}


void backspace(){
    deleteSlash();
    drawCharOnPreviousPosition(' ',BLACK, BLACK);
    printCursor();
}



