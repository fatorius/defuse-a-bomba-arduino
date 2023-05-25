#include "leds.h"

#include "pinos.h"

void acenderLeds(int seed, int infra){
    if (infra == 1){
      digitalWrite(ledInfra, HIGH);
    }

    if (seed >= 90){
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledBranco, HIGH);
    }
    else if (seed >= 80){
      digitalWrite(ledAmarelo, HIGH);
    }
    else if (seed >= 70){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, HIGH);
    }
    else if (seed >= 60){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, HIGH);
    }
    else if (seed >= 50){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledBranco, HIGH);
    }
    else if (seed >= 40){
      digitalWrite(ledVermelho, HIGH);
    }
    else if (seed >= 30){
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, HIGH);
    }
    else if (seed >= 20){
      digitalWrite(ledVerde, HIGH);
    }
    else{
      digitalWrite(ledBranco, HIGH);
    }
}