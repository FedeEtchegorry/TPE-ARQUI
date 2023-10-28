#include <userlib.h>

unsigned int strLength(const unsigned char * str) {
    int i=0;
    while(str[i++]!='\0');
    return i-1;
}

