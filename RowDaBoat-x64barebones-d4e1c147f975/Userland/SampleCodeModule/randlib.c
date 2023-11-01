//  randlib.c

#include <randlib.h>

unsigned int randInt(unsigned int izq, unsigned int der)    {

    if ( izq > der) {
        int aux = izq;
        izq = der;
        der = aux;
    }
    
    return (unsigned int)rand() % (der - izq + 1)  + izq;

}

// Creditos: Marcelo Garberoglio 