#include <time.h>
#include <videoDriver.h>

static unsigned long ticks = 0;
static int snakeIsOn=0;

void timer_handler() {
	ticks++;
    blink();
}
void snakeIsOff(){

}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 19;
}

int alarmAt(int at)	{
	return seconds_elapsed() % at == 0 && ticks % 19 == 0 && seconds_elapsed()!=0 ; 
}
int alarmAtTicks(int at){
    return ticks%at==0;
}

int alarmAtDecimal(double at){
    int target_ticks = (int)(at * 19);
    return alarmAtTicks(target_ticks);
}
void waitTime(double at){
    int ticks_now=ticks;
    while(ticks<(ticks_now+at*19)){
        ;
    }
}