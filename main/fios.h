#ifndef FIOS
#define FIOS

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

bool verificarFios(int seed);

#endif