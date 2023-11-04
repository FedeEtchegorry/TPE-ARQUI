#include <userlib.h>
#include <shell.h>



typedef void (*shellFunctions)(void);
static shellFunctions menuFunctions[7]={&help, &snake, &time, &textSize, &exitProgram};
static char* menuNames[7]= {"help", "snake", "time", "size", "exit"};
static char* menuDescriptions[7]={"Gives information about the available commands to execute.",
                            "Starts a new Snake game, add '1' or '2' as argument according to the ammount of players wanted",
                            "Prints the RTC's time on the screen .",
                            "Changes font size unless minimum/maximum size has been reached. Use argument 'small' or 'bigger' after the space",
                            "Closes the Shell and finishes the execution of the software."};
//TODO aceptar colores en entrada estandar para imprimirlos
static int flag=1;
static char function[15]={'\0'};
static char argument[15]={'\0'};

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
                putChar(c);
                buffer[--i] = '\0';
            }

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
    stringTrimmerBySpace(buffer, function, argument);
    while (menuNames[i]){
        if (strEquals(menuNames[i], function)) {
            print("\n");
            menuFunctions[i]();
            print("\n");
            return;
        }
        i++;
    }
    print("\n");
    print("Unknown Command");
    print("\n");
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

void snake(){
    if (strEquals("1", argument))
        startSnake(1);
    else if (strEquals("2", argument))
        startSnake(2);
    else print("Arguments are necessary or the argument written is not defined");
}
void textSize(){
   if (strEquals("smaller", argument)){
       make_text_smaller();
   }
   else if (strEquals("bigger", argument)){
       make_text_bigger();
   }
   else print("Arguments are necessary or the argument written is not defined");
}

void exitProgram(){
    flag=0;
    exit_shell();
}
void colorChanging(){

}
int getFlag(){
    return flag;
}
