#include <LiquidCrystal.h>

#include "ctimer.h"
#include "beeps.h"
#include "pinos.h"
#include "seeds.h"
#include "tempo.h"
#include "fios.h"
#include "rickroll.h"

// objetos
LiquidCrystal lcd(12,11,5,4,3,2);

cTimer tempoTimer(true);
cTimer beepTimer(true);
cTimer fiosTimer(true);

void explodir(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Terrorist win");

  while (true){
    nevergonnagiveyouup();
  }
}

void printNoLCD(){
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(obterMinutos(tempoRestante));

  lcd.setCursor(1, 0);
  lcd.print(":");

  lcd.setCursor(2, 0);
  lcd.print(obterSegundos(tempoRestante));
}

void setup(){
  tempoRestante = 10;

  gerarSeeds();

  tempoTimer.SetTimeOut(SEGUNDO);
  beepTimer.SetTimeOut(SEGUNDO);
  fiosTimer.SetTimeOut(0.25 * SEGUNDO);

  pinMode(buzzer, OUTPUT);

  pinMode(fioPreto, INPUT);
  pinMode(fioAzul, INPUT);
  pinMode(fioAmarelo, INPUT);
  pinMode(fioLaranja, INPUT);
  pinMode(fioBranco, INPUT);
  pinMode(fioRoxo, INPUT);

  lcd.begin(16,2);

  Serial.begin(9600);
}

void loop(){
  if (tempoRestante == 0){
    explodir();
  }

  if (tempoTimer.IsTimeOut(true)){
    atualizarTempo();
    printNoLCD();
  }

  if (beepTimer.IsTimeOut(true)){
    beep(tempoRestante);
    beepTimer.SetTimeOut((tempoRestante / 9) * 100);
  }

  if (fiosTimer.IsTimeOut(true)){
    verificarFios();
  }
}