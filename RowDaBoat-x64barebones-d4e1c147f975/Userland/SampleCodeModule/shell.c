#include <userlib.h>
#include <shell.h>


extern void time_getter();
extern void exit_shell();

//typedef void (*shellFunctions)(void);
//static shellFunctions menuFunctions[10]={&help, &snake1, &snake2, &time, &biggerText, &smallerText, &exitProgram};
char* menuNames[10]= {"help", "snake 1", "snake 2", "time", "biggerText","smallerText", "exit"};
char* menuDescriptions[10]={"Gives information about the available commands to execute.",
                            "Starts a new Snake game, only one player.",
                            "Starts a new Snake game, two players at the same time.",
                            "Prints the RTC´s time on the screen .",
                            "Increases font size unless maximum size has been reached.",
                            "Decreases font size unless minimum size has been reached.",
                            "Closes the Shell and finishes the execution of the software."};

static int flag=1;

void initShell()    {
    killBuffer();
    print(INIT_MESSAGE);
}

void read(unsigned char * buffer)   {
    print("$> ");
    int i=0;
    char c;
    while((c = getChar())!='\n')    {
        if(c=='\b') {
            if(i!=0)    {
                buffer[--i] = '\0';
            }
            putChar(c);
        }
        else    {
            buffer[i++] = c;

            putChar(buffer[i-1]);
            putChar(c);
        }
    }
    buffer[i] = '\0';
}
void getMenu(unsigned char* buffer){
    int i=0;
    while (menu[i]!=0){
        if (strEquals(menuNames[i], buffer))
            menuFunctions[i]();
    }
}
void help(){
    for (int i = 0; menuNames[i]!=0; i++) {
        print(menuNames[i]);
        print(":");
        print(menuDescriptions[i]);
        print('\n');
    }
}
void time(){
    time_getter();
}

void snake1(){
    startSnake(1);
}
void snake2(){
    startSnake(2);
}
void biggerText(){
;
}
void smallerText(){

}
void exit(){
    flag=0;
    exit_shell();
}
int getFlag(){
    return flag;
}