#include <userlib.h>
#include <shell.h>

//void * menuFunctions[10]={&help, &snake, &time, &biggerText, &smallerText, &exitProgram};
char* menuNames[10]= {"help", "snake", "time", "biggerText","smallerText", "exit"};


int flag=1;

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
                buffer[--i] = 0;
            }
            putChar(c);
        }
        else    {
            buffer[i++] = c;
            putChar(c);
        }
    }
    buffer[i] = 0;
}
//void getMenu(unsigned char* buffer){
//    int i=0;
//    while (menu[i]!=0){
//        if (strEquals(menuNames[i], buffer))
//            i=i;
//    }
//}
//void help(){
//    for (int i = 0; menuNames[i]!=0; i++) {
//        print(menuNames[i]);
//        print('\n');
//    }
//}
//void time(){
//;
//}
//void snake(){
//;
//}
//void biggerText(){
//;
//}
//void smallerText(){
//;
//}
void exit(){
    flag=0;
    exit_shell();
}
int getFlag(){
    return flag;
}