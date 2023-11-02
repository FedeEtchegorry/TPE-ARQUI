#ifndef _SYSCALLS_H
#define _SYSCALLS_H

// Sys_Id en rax:
#define SYSTEM_EXIT_ID                  0x01
#define SYSTEM_READ_ID                  0x03
#define SYSTEM_WRITE_ID                 0x04
#define SYSTEM_TIME_ID                  0x98
#define SYSTEM_KILLBUFFER_ID            0x99
#define SMALLER_TEXT                    0xa0
#define BIGGER_TEXT                     0xa1
#define RECOLOR                         0xa2
    
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

// Deja el programa detenido indefinidamente
    void exitProgram();

//Imprime el horario en pantalla
    void timeManager();

//aumenta el tamaño de la letra
    void makeTextBigger();

//reduce el tamaño de la letra
    void makeTextSmaller();
//cambia el color de lo escrito hasta ahora
    void changeColor(unsigned int fgcolor, unsigned int bgcolor);

#endif