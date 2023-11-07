#include <stdint.h>
#include "./include/speaker.h"

extern uint8_t inb(uint16_t port);
extern void outb(uint16_t port, uint8_t value);

// Reproduce un sonido en el altavoz incorporado
static void play_sound(uint32_t frequency) {
    uint32_t divisor = 1193180 / frequency;

    // Configura el PIT para la frecuencia deseada
    write_port(0x43, 0xb6); // Configura el PIT
    write_port(0x42, (uint8_t)(divisor)); // Baja parte del divisor
    write_port(0x42, (uint8_t)(divisor >> 8)); // Alta parte del divisor

    // Activa el altavoz incorporado
    uint8_t tmp = read_port(0x61);
    if ((tmp & 3) != 3) {
        write_port(0x61, tmp | 3);
    }
}

// Silencia el altavoz incorporado
static void nosound() {
    uint8_t tmp = read_port(0x61) & 0xFC;
    write_port(0x61, tmp);
}

// Hace un beep en el altavoz incorporado
void beep(int frequency, int duration) {
    play_sound(frequency);
    //falta una funcion para usar la duracion. un sleep
    nosound();
}

#include <time.h>

#define DO  262
#define RE  294
#define MI  330
#define FA  349
#define SOL  392
#define SI 494
#define LA 440

#define DO2  523
#define RE2  587
#define MI2  659
#define FA2  698
#define SOL2  784
#define LA2  880

uint16_t jingleBells[] = {MI, MI, MI, MI, MI, MI, MI, SOL, DO, RE, MI,
                          FA, FA, FA,  MI, MI, MI, RE, RE, RE, MI, RE, SOL};
uint16_t timeJB[]={1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 2};
uint32_t tetrisSong[]={MI2, SI, DO2, RE2, DO2, SI, LA, LA, DO2, MI2, RE2, DO2, SI, SI, DO2, RE2, MI2, DO2, LA, LA,
                       10000, RE2, FA2, LA2, SOL2, FA2, MI2, DO2, MI2, RE2, DO2, SI, SI, DO2, RE2, MI2, DO2, LA, LA, 10000};
double timeTetris[]={1, 0.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 0.5,
                1, 0.5, 1, 0.5, 0.5, 1.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 0.5};
uint32_t death2[]={SI, FA2, FA2, FA2, MI2, RE2, DO2, MI, SOL, MI, DO} ;
double tiempo[]={0.5, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 0.5, 0.5, 2};

static int initFreq=1000;
static double defaultTime=0.00005;
void playFrecuency(double time, unsigned int frequency) {
    play_sound(frequency);
    uint64_t i=(time)*250000000;
    while(i!=0){
        i--;
    }
    nosound();
}
void playDefault(){
    play_sound(initFreq);
    nosound();
}

void playTetris(){
    for (int index = 0; index < 40; index++) {
        playFrecuency(0.4*timeTetris[index], tetrisSong[index]*2);
    }
    nosound();
}
void playJingleBells(){
    for (int index = 0; index < 23; index++){
        playFrecuency(0.3*timeJB[index], jingleBells[index]*2);
    }
    nosound();
}
void playMario(){
    for (int index = 0; index < 10; index++) {
        playFrecuency(0.35*tiempo[index], death2[index]);
    }
    nosound();
}

void beep(){
    play_sound(initFreq);
    nosound();
}