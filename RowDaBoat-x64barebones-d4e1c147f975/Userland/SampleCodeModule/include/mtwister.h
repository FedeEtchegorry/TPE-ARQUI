#ifndef __MTWISTER_H
#define __MTWISTER_H

#define STATE_VECTOR_LENGTH 624
#define STATE_VECTOR_M      397 /* changes to STATE_VECTOR_LENGTH also require changes to this */

typedef struct tagMTRand {
  unsigned long mt[STATE_VECTOR_LENGTH];
  int index;
} MTRand;

MTRand seedRand(unsigned long seed);

unsigned long genRandLong(MTRand* rand);

double genRand(MTRand* rand);

#endif /* #ifndef __MTWISTER_H */

// The following code will create a new random generator seeded at 1337 and print 
// out one thousand random doubles between 0 and 1.

// #include <stdio.h>
// #include "mtwister.h"

// int main() {
//   MTRand r = seedRand(1337);
//   int i;
//   for(i=0; i<1000; i++) {
//     printf("%f\n", genRand(&r));
//   }
//   return 0;
// }

// Source: https://github.com/ESultanik/mtwister
