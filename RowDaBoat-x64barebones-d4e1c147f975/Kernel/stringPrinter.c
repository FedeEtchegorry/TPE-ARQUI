#include <videoDriver.h>
#include <colours.h>
#include <keyboard.h>
#include <time.h>

#define SCREEN_BUFFER_SIZE 100
static unsigned char screenBuffer[SCREEN_BUFFER_SIZE];
static unsigned int bufferColors[SCREEN_BUFFER_SIZE][2];
int position=0;
int positionTraveller=0;

int canBlink=1;

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
                position = (position - 1 + SCREEN_BUFFER_SIZE) % SCREEN_BUFFER_SIZE;
            }
        } else {
            screenBuffer[position] = string[i];
            bufferColors[position][0] = fgcolor;
            bufferColors[position][1] = bgcolor;
            position = (position + 1) % SCREEN_BUFFER_SIZE;
            if (position == positionTraveller) {
                positionTraveller++;
            }
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
void printCharDefault(char c,int fgcolor, int bgcolor){
    char aux[2]={c,'\0'};
    printTextDefault(aux, fgcolor, bgcolor);
}
void blink(){
    if (canBlink) {
        if (alarmAt(2))
            deleteSlash();
        if (alarmAt(3))
            printCursor();
    }
}
void allowBlink(){
    canBlink=1;
}
void blockBlink(){
    canBlink=0;
}


int charSizes[3]={8,16,32};
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
    int startPos = positionTraveller % SCREEN_BUFFER_SIZE;
    int endPos = position % SCREEN_BUFFER_SIZE;

    if (endPos < startPos) {
        endPos += SCREEN_BUFFER_SIZE; // Handle circular buffer wraparound
    }

    for (int i = startPos; i < endPos; i++) {
        int index = i % SCREEN_BUFFER_SIZE;
        printTextDefault(screenBuffer[index], bufferColors[index][0], bufferColors[index][1]);
    }
    positionTraveller = position;
}




