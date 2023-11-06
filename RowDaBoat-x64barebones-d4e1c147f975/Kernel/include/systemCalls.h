#ifndef _SYSCALLS_H
#define _SYSCALLS_H

// Sys_Id en rax:
#define SYSTEM_EXIT_ID                  0x01
#define SYSTEM_READ_ID                  0x03
#define SYSTEM_WRITE_ID                 0x04
#define SYSTEM_TIME_ID                  0x98
#define SYSTEM_KILLBUFFER_ID            0x99
#define SYSTEM_DRAW_ID                  0x44
#define SYSTEM_CLEAR_ID                 0x45
#define SMALLER_TEXT                    0xA0
#define BIGGER_TEXT                     0xA1
#define RANDLONG_ID                     0x12
#define RECOLOR                         0xA2
#define TETRIS                          0xDE
    

// write @fd codes: (en rbx)
    #define STDOUT 						0x01
    #define CHARSTDOUT                  0x02
    #define STDERR 						0x03
    #define RETURN_CHAR                 0xA0	
    #define RETURNANDSTDOUT_CHAR        0xA1

// Devuelve segun fd lo que hay en el buffer, count caracteres:
    unsigned char sysWrite(unsigned int fd, unsigned int count);

// read @fd codes: (en rbx)
    #define STRING  0x02
    #define CHAR    0x01

// Carga en el buffer lo que hay en @s:
    void sysRead(unsigned int fd, const  char * s, char c);
    
// Borra el buffer:
    void killBuffer();

// sysDraw @model codes (en rbx):
    #define HEAD_LEFT   0x00
    #define HEAD_RIGHT  0x01
    #define HEAD_UP     0x02
    #define HEAD_DOWN   0x03
    #define BODY        0x04
    #define APPLE       0x05
    #define EMPTY       0xA0

// Pinta un pixel:
    void sysDraw(int model, int x, int y );

// Borra toda la pantalla:
    void sysClear();

// Deja el programa detenido indefinidamente
    void exitProgram();

//Imprime el horario en pantalla
    void timeManager();

//aumenta el tamaño de la letra
    void makeTextBigger();

//reduce el tamaño de la letra
    void makeTextSmaller();
//cambia el color de lo escrito hasta ahora
    void changeColor(unsigned int fgcolor);

// retorna un numero pseudo-random
    unsigned long rand();
//pone la canción del tetris
    void playTetrisSong();
#endif