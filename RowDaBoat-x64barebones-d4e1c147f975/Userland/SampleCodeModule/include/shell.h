#ifndef _SHELL_H
#define _SHELL_H

    #define INIT_MESSAGE "Welcome to shell, write help if you want to know the available options\n"
    
    void initShell();
    void read(unsigned char * buffer);
    void getMenu(unsigned char* buffer);
    void help();
    void time();
    void snake1();
    void snake2();
    void biggerText();
    void smallerText();
    void exitProgram();
#endif