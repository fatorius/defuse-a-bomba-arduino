#include "beeps.h"
#include "pinos.h"

void beep(){
  tone (buzzer, 524,100);
  delay(500);
}

void beep2(){
  tone (buzzer, 524,100);
  delay(500);
  tone(buzzer, 524, 100);
}

void beep3(){
  tone (buzzer, 524,50);
  delay(333);
  tone(buzzer, 524, 50);
  delay(333);
  tone(buzzer, 524, 50);
}