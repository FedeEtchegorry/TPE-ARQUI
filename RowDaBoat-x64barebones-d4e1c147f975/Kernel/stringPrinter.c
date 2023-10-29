#include <videoDriver.h>
#include <colours.h>

#define SCREEN_BUFFER_SIZE 100
char buffer[SCREEN_BUFFER_SIZE]={'\0'};
int bufferColors[SCREEN_BUFFER_SIZE][2]={'\0'};
int position=0;
int positionTraveller=0;

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
void printTextDefault(char* string, int fgcolor, int bgcolor) {
    blockBlink();
    for (int i = 0; string[i] != '\0'; i++) {
        deleteSlash();
        if (string[i] == '\b') {
            backspace();
            if (position > 0) {
                position--;
            }
        } else {
                buffer[position] = string[i];
                bufferColors[position][0] = fgcolor;
                bufferColors[position++][1] = bgcolor+150;
            if (string[i] == '\n')
                printNewline();
            else if (string[i] == '\t')
                printTab();
            else
                drawCharOnCurrentPos(string[i], fgcolor, bgcolor);
        }
        printCursor();
    }
    allowBlink();
}



int charSizes[3]={8,16,24};
int size=1;
void smallerText(){
    if(size>0) {
        setCharWidth(charSizes[--size]);
        refillScreen();
    }
}
void biggerText(){
    if(size<2) {
        setCharWidth(charSizes[++size]);
        refillScreen();
    }
}
void refillScreen() {
    fillScreen(0x0);
    resetPosition();
    int i=positionTraveller;
    while(buffer[i]!='\0') {
        printTextDefault(buffer[i], bufferColors[i][0], bufferColors[i][1]);
        i++;
    }
    positionTraveller = position;
}




