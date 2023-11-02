#include <userlib.h>
#include <shell.h>



typedef void (*shellFunctions)(void);
static shellFunctions menuFunctions[7]={&help, &snake1, &snake2, &time, &biggerText, &smallerText, &exitProgram};
static char* menuNames[7]= {"help", "snake 1", "snake 2", "time", "biggertext","smallertext", "exit"};
static char* menuDescriptions[7]={"Gives information about the available commands to execute.",
                            "Starts a new Snake game, only one player.",
                            "Starts a new Snake game, two players at the same time.",
                            "Prints the RTC's time on the screen .",
                            "Increases font size unless maximum size has been reached.",
                            "Decreases font size unless minimum size has been reached.",
                            "Closes the Shell and finishes the execution of the software."};
//TODO aceptar colores en entrada estandar para imprimirlos
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
        if (c=='\0')
            ;
        else if(c=='\b') {
            if(i!=0)    {
                buffer[--i] = '\0';
            }
            putChar(c);
        }
        else    {
            buffer[i++] = c;
            putChar(buffer[i-1]);

        }
    }
    buffer[i] = '\0';
}
void getMenu(unsigned char* buffer){
    int i=0;
    buffer=stringNormalizer(buffer);
    print(buffer);
    while (i<AVAILABLE_FUNCTIONS){
        if (strEquals(menuNames[i], buffer)) {
            print("\n");
            menuFunctions[i]();
            print("\n");
            return;
        }
        i++;
    }
    print("Unknown Command");
}
void help(){
    print("\n");
    for (int i = 0; menuNames[i]!=0; i++) {
        print(menuNames[i]);
        print(":");
        print(menuDescriptions[i]);
        print("\n");
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
    make_text_bigger();
}
void smallerText(){
    make_text_smaller();
}
void exitProgram(){
    flag=0;
    exit_shell();
}
int getFlag(){
    return flag;
}
