#include <stdint.h>
#include "./include/speaker.h"

extern uint8_t inb(uint16_t port);
extern void outb(uint16_t port, uint8_t value);

// Reproduce un sonido en el altavoz incorporado
static void play_sound(uint32_t frequency) {
    uint32_t divisor = 1193180 / frequency;

    // Configura el PIT para la frecuencia deseada
    outb(0x43, 0xb6); // Configura el PIT
    outb(0x42, (uint8_t)(divisor)); // Baja parte del divisor
    outb(0x42, (uint8_t)(divisor >> 8)); // Alta parte del divisor

    // Activa el altavoz incorporado
    uint8_t tmp = inb(0x61);
    if ((tmp & 3) != 3) {
        outb(0x61, tmp | 3);
    }
}

// Silencia el altavoz incorporado
static void nosound() {
    uint8_t tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

// Hace un beep en el altavoz incorporado
void beep(int frequency, int duration) {
    play_sound(frequency);
    //falta una funcion para usar la duracion. un sleep
    nosound();
}
