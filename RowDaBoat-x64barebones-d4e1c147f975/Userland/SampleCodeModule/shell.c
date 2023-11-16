#include <userlib.h>
#include <snake.h>
#include <frontSnake.h>
#include <shell.h>
#include <colours.h>

void initShell()    {
    print(INIT_MESSAGE);
}

void read(char * buffer)   {
    print("$> ");
    int i=0;
    char c;
    while((c = getChar())!='\n')    {
        
        if (c!='\0')    {
            
            if(c=='\b' ) {

                if(i!=0)    {
                
                    int pixelsToDelete = (buffer[i-1] == '\t')? 3 : 1; //Si borro un tab queda en 3 sino queda en 1
                    
                    for(int j=0; j<pixelsToDelete; ++j) {

                        putChar('\b');
                    }
                    
                    buffer[--i] = '\0';
                }
                
            }

            else    {

                buffer[i++] = c;
                putChar(buffer[i-1]);
                
            }
        }        
    }

    buffer[i] = '\0';
}

    static char function[15]={'\0'};
    static char argument[15]={'\0'};

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

    }
        
    else if (strEquals("2", argument))  {

        startSnake(2);

    }
        
    else print("Arguments are necessary or the argument written is not defined");

    initShell();

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

