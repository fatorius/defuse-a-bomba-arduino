#include "seeds.h"

int seed = 0;

void gerarSeeds(){
  randomSeed(analogRead(A10));

  seed = random(100);
}