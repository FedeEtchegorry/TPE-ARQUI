#ifndef RTCDRIVER_H
#define RTCDRIVER_H


#define SECONDS 0x0
#define MINUTES 0x2
#define HOURS   0x4
#define DAY     0x7
#define MONTH   0x8
#define YEAR    0x9

//USOS HORARIOS
#define UTC_MINUS_12 -12
#define UTC_MINUS_11 -11
#define UTC_MINUS_10 -10
#define UTC_MINUS_9  -9
#define UTC_MINUS_8  -8
#define UTC_MINUS_7  -7
#define UTC_MINUS_6  -6
#define UTC_MINUS_5  -5
#define UTC_MINUS_4  -4
#define UTC_MINUS_3  -3
#define UTC_MINUS_2  -2
#define UTC_MINUS_1  -1
#define UTC_0        0
#define UTC_PLUS_1   1
#define UTC_PLUS_2   2
#define UTC_PLUS_3   3
#define UTC_PLUS_4   4
#define UTC_PLUS_5   5
#define UTC_PLUS_6   6
#define UTC_PLUS_7   7
#define UTC_PLUS_8   8
#define UTC_PLUS_9   9
#define UTC_PLUS_10  10
#define UTC_PLUS_11  11
#define UTC_PLUS_12  12

char* getTime();



#endif //RTCDRIVER_H
