#ifndef BEEPS
#define BEEPS

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include "beeps.h"

void beep();
void beep2();
void beep3();

#endif