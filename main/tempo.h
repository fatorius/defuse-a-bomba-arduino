#ifndef TEMPO
#define TEMPO

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define SEGUNDO 1000

extern int tempoRestante;

void atualizarTempo();

#endif