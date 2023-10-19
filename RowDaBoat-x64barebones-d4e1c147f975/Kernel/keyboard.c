#include <keyboard.h>
#include <naiveConsole.h>

static unsigned char kbd_US [128] =   {
            0,  '|', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\?', '!', '\b',   
        '\t', /* <-- Tab */
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '*', '+', '\n',     
            0, /* <-- control key */
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '}', '{', 0 ,  0, '/', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-',   0,
        '*',0,  /* Alt */' ',  /* Space bar */0,  /* Caps lock */
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
            case '\n':  ncNewline();
                        return '\0';
            case '\t':  ncTab();
                        return '\0';
            case '\b':  ncBackspace();
                        return '\0';
            default: return letter;
        }
    }
    return '\0';
}

