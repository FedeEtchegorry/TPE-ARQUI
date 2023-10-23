#include <keyboard.h>
#include <naiveConsole.h>
#include <videoDriver.h>

int caps=0;

static unsigned char kbd_US [128] =   {
            0,  '|', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\?', '!', '\b',   
        '\t', /* <-- Tab */
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '*', '+', '\n',     
            0, /* <-- control key */
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '}', '{', 0 ,  0, '/',
        'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-',   0,
        '*',0,  /* Alt */' ',  /* Space bar */'M',  /* Caps lock */
            0,  /* 59 - F1 key ... > */
            0,   0,   0,   0,   0,   0,   0,   0,
            0,  /* < ... F10 */
            0,  /* 69 - Num lock*/
            0,  /* Scroll Lock */
            0,  /* Home key */
            0,  /* Up Arrow */
            0,  /* Page Up */
        '-',
            0,  /* Left Arrow */
            0,
            0,  /* Right Arrow */
        '+',
        };

unsigned char map(unsigned char c)  {
    if (c<=78) {
        char letter=kbd_US[c];
        switch (letter) {
            case 'M' :  caps=!caps;
                        return '\0';
            case '\n':  printNewline();
                        return '\0';
            case '\t':  printTab();
                        return '\0';
            case '\b':  backspace();
                        return '\0';
            default: return ((caps && letter>='a' && letter<='z')?letter-32:letter);
        }
    }
    return '\0';
}

