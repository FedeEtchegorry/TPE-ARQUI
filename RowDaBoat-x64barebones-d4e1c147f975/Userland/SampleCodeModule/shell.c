#include <userlib.h>
#include <shell.h>

void initShell()    {
    killBuffer();
    print(INIT_MESSAGE);
}

void read(unsigned char * buffer)   {
    
    print("$> ");

    int i=0;
    char c;
    while((c = getChar())!='\n')    {
        if(c=='\b') {
            if(i!=0)    {
                buffer[--i] = 0;
            }
            putChar(c);
        }
        else    {
            buffer[i++] = c;
            putChar(c);
        }
        
        
    }
    buffer[i] = 0;
}