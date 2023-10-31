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

int isDigit(unsigned char c) {
    return digits[c];
}

unsigned int strToUint(char * s) {
    
    unsigned int ans = 0;
    int i=0;
    while(isDigit((unsigned char)s[i])) {
     
     putChar(s[i]);
        ans = ans*10 + s[i++]-0x30;

    }

// si s[i]!=0 entonces no lo recorrio entero
// si i == 0 entonces es el string vacio
    if(s[i]||!i)    {
        
        print("Error en strToUint: El string ingresado no representa un numero valido\n");
        return (unsigned int) -1;
    }
    
    return ans;
}