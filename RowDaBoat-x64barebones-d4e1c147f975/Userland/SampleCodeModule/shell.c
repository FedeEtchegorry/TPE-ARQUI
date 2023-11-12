#include <userlib.h>
#include <snake.h>
#include <shell.h>
#include <colours.h>


typedef void (*shellFunctions)(void);
static shellFunctions menuFunctions[AVAILABLE_FUNCTIONS]={&help, &snake, &time, &textSize,&colorChanging, &exitProgram, &clear, &tetrisSong, &jingleBellsSong, &div0, &invalidOpcode};
static char* menuNames[AVAILABLE_FUNCTIONS]= {"help", "snake", "time", "size", "color", "exit", "clear","tetris", "jinglebells", "div0", "invalidopcode"};
static char* menuDescriptions[AVAILABLE_FUNCTIONS]={
                            "Gives information about the available commands to execute.",
                            "Starts a new Snake game, add '1' or '2' as argument according to the amount of players wanted",
                            "Prints the RTC's time on the screen .",
                            "Changes font size unless minimum/maximum size has been reached. Use argument 'small' or 'bigger' after the space",
                            "Changes the font's color, available arguments are 'white', 'red', 'blue', 'green', 'yellow', 'orange', 'violet'",
                            "Closes the Shell and finishes the execution of the software.",
                            "Cleans the terminal.",
                            "Plays tetris music.",
                            "Plays jinglebells",
                            "Div by 0 and throws the exception",
                            "Excecutes an invalid opcode and throws the exception"
                            };
//TODO aceptar colores en entrada estandar para imprimirlos
static char function[15]={'\0'};
static char argument[15]={'\0'};

void initShell()    {
    print(INIT_MESSAGE);
}

void read(char * buffer)   {
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
void getMenu(char* buffer){
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
    putnEnters(2);
    for (int i = 0; i<AVAILABLE_FUNCTIONS; i++) {
        print(menuNames[i]);
        print(":");
        print(menuDescriptions[i]);
        putnEnters(2);
    }
}
void time(){
    time_getter();
}

void snake(){

    if (strEquals("1", argument))   {

        startSnake(1);
        initShell();

    }
        
    else if (strEquals("2", argument))  {

        startSnake(2);
        initShell();
    }
        
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
    exit_shell();
}
void colorChanging(){
    if (strEquals(argument, "white")){
        recolor(WHITE);
    }
    else if (strEquals(argument, "red")){
        recolor(RED);
    }
    else if (strEquals(argument, "blue")){
        recolor(BLUE);
    }
    else if (strEquals(argument, "green")){
        recolor(GREEN);
    }
    else if (strEquals(argument, "yellow")){
        recolor(YELLOW);
    }
    else if (strEquals(argument, "orange")){
        recolor(ORANGE);
    }
    else if (strEquals(argument, "violet")){
        recolor(VIOLET);
    }
    else print("Arguments are necessary or the argument written is not defined");

}
void tetrisSong(){
    play_song(1);
}
void jingleBellsSong(){
    play_song(2);
}

void div0() {
    int i= 1/0;
}

