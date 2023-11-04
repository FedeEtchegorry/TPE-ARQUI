#ifndef _SHELL_H
#define _SHELL_H

    #define INIT_MESSAGE "Welcome to shell, write help if you want to know the available options\n"
    #define AVAILABLE_FUNCTIONS 7
    
    void initShell();
    void read(unsigned char * buffer);
    void getMenu(unsigned char* buffer);
    void help();
    void time();
    void snake();
    void textSize();
    void exitProgram();
    void colorChanging();
#endif