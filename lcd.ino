#include <LiquidCrystal.h>

#include "ctimer.h"
#include "beeps.h"
#include "pinos.h"
#include "seeds.h"
#include "tempo.h"
#include "fios.h"

// objetos
LiquidCrystal lcd(12,11,5,4,3,2);

cTimer tempoTimer(true);
cTimer beepTimer(true);
cTimer fiosTimer(true);

void explodir(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cabummmmm");

  while (true){
    tone(buzzer, 700);
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
  tempoRestante = 180;

  gerarSeeds();

  tempoTimer.SetTimeOut(SEGUNDO);
  beepTimer.SetTimeOut(SEGUNDO);
  fiosTimer.SetTimeOut(5 * SEGUNDO);

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
    if (tempoRestante > 60){
      beep();
    }
    else if (tempoRestante > 30){
      beep2();
    }
    else{
      beep3();
    }
  }

  if (fiosTimer.IsTimeOut(true)){
    verificarFios();

    Serial.print("Azul: ");
    Serial.println(digitalRead(fioAzul));
    Serial.print("Preto: ");
    Serial.println(digitalRead(fioPreto));
    Serial.print("Laranja: ");
    Serial.println(digitalRead(fioLaranja));
    Serial.print("Amarelo: ");
    Serial.println(digitalRead(fioAmarelo));
    Serial.print("Branco: ");
    Serial.println(digitalRead(fioBranco));
    Serial.print("Roxo: ");
    Serial.println(digitalRead(fioRoxo));
    Serial.println("=============================");
    Serial.flush();
  }
}