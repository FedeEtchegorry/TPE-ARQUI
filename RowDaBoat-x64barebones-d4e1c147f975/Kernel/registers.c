#include <colours.h>
#include <systemCalls.h>
#include <videoDriver.h>
#include <stringPrinter.h>
#include <buffer.h>
#include <rtcDriver.h>
#include <time.h>
extern unsigned long long* register_saviour();

static char output[17]={'\0'};
void registerToString(unsigned long long value) {
    char temp[17]; //buffer temp para ir guardando el numero
    int index = 0;
    do {
        int digit = value & 0xF;
        temp[index++] = (digit < 10) ? (char)('0' + digit) : (char)('a' + digit - 10);
        value >>= 4;
    } while (value > 0);
    //la longitud de mi string depende del indice
    int length = index;

    // empiexo a dar vuelta el string
    for (int i = 0; i < length; i++) {
        output[i] = temp[length - 1 - i];
    }
    //le pongo NULL al final
    output[length] = '\0';
}

void outputRegisterCaller(unsigned long long* registerArray,int i){
    registerToString(registerArray[i]);
    printRegisterDefault(output);
    printRegisterDefault("\n");
}
void registerRetriever() {
    unsigned long long* registerArray=register_saviour();
    int i=0;
    printRegisterDefault("RAX: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("RBX: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("RCX: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("RDX: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("RSI: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("RDI: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("RBP: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("RSP: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R8:  ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R9:  ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R10: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R11: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R12: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R13: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R14: ");
    outputRegisterCaller(registerArray, i++);
    printRegisterDefault("R15: ");
    outputRegisterCaller(registerArray, i++);
}

