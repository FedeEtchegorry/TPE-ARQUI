#include <userlib.h>

void putEnter() {
    putChar('\n');
}

void putnEnters(unsigned int n)    {

    while(n-->0)  
        putEnter();
    
}

void putBackSpace() {
    putChar('\b');
}

void putTab()   {
    putChar('\t');
}


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

int getUintDigits(unsigned int n )    {

// n=0 es un caso especial pues 0 = 00 = 000...0, etc...
    if(!n)  return 1;

    int digits=0;

    do  
        digits++;

    while(n/=10);
        
    return digits;
}

void uIntToString(unsigned int input, char * ans, int digits)   {

// Se asume que ans tiene la longitud necesaria para que entre la
// cantidad de digitos de input y el '\0' al final.
    ans[digits] = '\0';
    
    int i=digits-1;

    do  
        ans[i--] = (input % 10) + 0x30;  

    while(input/=10);

}


void printUinteger(unsigned int n)   {

    int digits = getUintDigits(n);
    char s[digits+1];
    uIntToString(n, s, digits);
    print(s);
}