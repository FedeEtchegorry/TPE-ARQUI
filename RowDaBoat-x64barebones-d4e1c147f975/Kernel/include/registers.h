#ifndef _REGISTERS_H
#define _REGISTERS_H
#include <stdint.h>

unsigned long long* register_saviour();
void registerRetriever();
void outputRegisterCaller(uint64_t * registerArray,int i);
void registerToString(uint64_t value);
void registerPrintFull(uint64_t *registerInfo);

#endif