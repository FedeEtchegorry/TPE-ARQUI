//  randlib.c

#include <mtwister.h>
#include <randlib.h>

static unsigned long seed = 1234;

static void srand(int newseed) {
    
    seed = (unsigned int)newseed & 0x7fffffff;
}

static void randomize() {
    ;

// seed = getMiliSeconds // la idea es que cambie la seed segun la hora

}

unsigned long rand()    {

    MTRand mtrand = seedRand((pow(1103515245, seed) + 12345) & 0x7fffffff);
    return genRandLong(&mtrand);
}
