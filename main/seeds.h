#ifndef SEEDS
#define SEEDS

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

extern int seedFios;
extern int seedInfra;
extern int seedLCD;

void gerarSeeds();

#endif