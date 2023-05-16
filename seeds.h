#ifndef SEEDS
#define SEEDS

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

extern int seed;

void gerarSeeds();

#endif