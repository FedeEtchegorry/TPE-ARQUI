#include <userlib.h>
unsigned int strLength(const char * str) {
    int i=0;
    while(str[i++]!='\0');
    return i-1;
}

unsigned int strEquals(char * s1, char * s2)  {
    int i=0;
    while(s1[i]!='\0' && s2[i]!='\0') {
        if(s1[i]!=s2[i])
            return 0;
        ++i;
    }
    return s1[i] == '\0' && s2[i] == '\0';
}
