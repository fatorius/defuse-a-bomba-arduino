#ifndef LCD
#define LCD

#include <LiquidCrystal.h>

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

extern int seedFios;
extern int seedInfra;

extern LiquidCrystal lcd;

void exibirMensagemNoLCD(int seed);

#endif