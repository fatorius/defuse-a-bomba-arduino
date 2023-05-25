#include "seeds.h"

int seedFios;
int seedInfra;
int seedLCD;

void gerarSeeds(){
  randomSeed(analogRead(A10));

  seedLCD = random(100);
  seedFios = random(16);
  seedInfra = random(100) % 2;
}