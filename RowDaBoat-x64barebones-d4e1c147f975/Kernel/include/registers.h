#ifndef _REGISTERS_H
#define _REGISTERS_H


unsigned long long* register_saviour();
void registerRetriever();
void outputRegisterCaller(unsigned long long* registerArray,int i);
void registerToString(unsigned long long value);

#endif