#ifndef LEDS
#define LEDS

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

void acenderLeds(int seed, int infra);

#endif