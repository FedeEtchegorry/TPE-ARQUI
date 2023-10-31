#include <rtcDriver.h>
#include <naiveConsole.h>
#include <stringPrinter.h>
#include <colours.h>

extern int timeParam(int argument);

char numberBuffer[20]={'\0'};

unsigned int decode(unsigned int time){
    return (time>>4)* 10 + (time & 0x0F);				//FUNCION QUE PASA EL TIEMPO EN BCD(binary coded decimal) a un numero en decimal
}
static uint32_t numberToBase(uint64_t value, char * buffer, uint32_t base){
    char *p = buffer;
    char *p1, *p2;
    uint32_t digits = 0;

    //Calculate characters for each digit
    do
    {
        uint32_t remainder = value % base;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        digits++;
    }
    while (value /= base);

    // Terminate string in buffer.
    *p = 0;

    //Reverse string in buffer.
    p1 = buffer;
    p2 = p - 1;
    while (p1 < p2)
    {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }

    return digits;
}
char* getTime(){
    int hours = decode(timeParam(HOURS) + UTC_MINUS_3);
    int minutes = decode(timeParam(MINUTES));
    int seconds = decode(timeParam(SECONDS));
    int day = decode(timeParam(DAY));
    int month = decode(timeParam(MONTH));
    int year = decode(timeParam(YEAR));

    //si alguno es menor que 10 le enchufo un 0 adelante

    if (hours < 10) {
        numberBuffer[0] = '0';
        numberToBase(hours, numberBuffer+1, 10);
    } else {
        numberToBase(hours, numberBuffer, 10);
    }
    numberBuffer[2] = ':';


    if (minutes < 10) {
        numberBuffer[3] = '0';
        numberToBase(minutes, numberBuffer + 4, 10);
    } else {
        numberToBase(minutes, numberBuffer + 3, 10);
    }
    numberBuffer[5] = ':';

    if (seconds < 10) {
        numberBuffer[6] = '0';
        numberToBase(seconds, numberBuffer + 7, 10);
    } else {
        numberToBase(seconds, numberBuffer + 6, 10);
    }
    numberBuffer[8] = ' ';


    if (day < 10) {
        numberBuffer[9] = '0';
        numberToBase(day, numberBuffer + 10, 10);;
    } else {
        numberToBase(day, numberBuffer + 9, 10);
    }
    numberBuffer[11] = '/';

    if (month < 10) {
        numberBuffer[12] = '0';
        numberToBase(month, numberBuffer + 13, 10);;
    } else {
        numberToBase(month, numberBuffer + 12, 10);
    }
    numberBuffer[14] = '/';

    if (year < 10) {
        numberBuffer[15] = '0';
        numberToBase(year, numberBuffer + 16, 10);
    } else {
        numberToBase(year, numberBuffer + 15, 10);
    }

    return numberBuffer;
}