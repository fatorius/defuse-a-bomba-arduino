#include "ctimer.h"
#include "beeps.h"
#include "pinos.h"
#include "seeds.h"
#include "tempo.h"
#include "fios.h"
#include "rickroll.h"
#include "leds.h"
#include "modulos.h"
#include "lcd.h"

cTimer tempoTimer(true);
cTimer beepTimer(true);
cTimer fiosTimer(true);
cTimer desarmeTimer(true);

void desarmar(){
  tone (buzzer, 600, 100);
  delay(100);
  tone (buzzer, 600, 100);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bomba desarmada");

  while (true){

  }
}

void setup(){
  tempoRestante = 120;

  gerarSeeds();

  tempoTimer.SetTimeOut(SEGUNDO);
  beepTimer.SetTimeOut(SEGUNDO);
  desarmeTimer.SetTimeOut(SEGUNDO);
  fiosTimer.SetTimeOut(0.25 * SEGUNDO);

  pinMode(buzzer, OUTPUT);

  pinMode(fioPreto, INPUT);
  pinMode(fioAzul, INPUT);
  pinMode(fioAmarelo, INPUT);
  pinMode(fioLaranja, INPUT);
  pinMode(fioBranco, INPUT);
  pinMode(fioRoxo, INPUT);

  pinMode(ledInfra, OUTPUT);
  pinMode(ledBranco, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);


  lcd.begin(16,2);

  Serial.begin(9600);

  acenderLeds(seedFios, seedInfra);
  exibirMensagemNoLCD(seedLCD);

  Serial.print("Seed fios: ");
  Serial.println(seedFios);


  Serial.print("Seed infra: ");
  Serial.println(seedInfra);


  Serial.print("Seed LCD: ");
  Serial.println(seedLCD);
}

void loop(){
  if (modulos_resolvidos == -100){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bomba explodiu...");

    tone (buzzer, 700, 5000);
    delay(5000);

    while(true){
      nevergonnagiveyouup();
    }
  }

  if (tempoTimer.IsTimeOut(true)){
    atualizarTempo();

    if (tempoRestante <= 8){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Bomba explodiu...");

      digitalWrite(ledAmarelo,LOW);
      digitalWrite(ledVermelho,LOW);
      digitalWrite(ledVerde,LOW);
      digitalWrite(ledBranco,LOW);
      
      if (tempoRestante <= 0){
        while (true){
          nevergonnagiveyouup();
        }
      }
    }
  }

  if (beepTimer.IsTimeOut(true)){
    beep(tempoRestante);
    beepTimer.SetTimeOut((tempoRestante / 9) * 100);
  }

  if (fiosTimer.IsTimeOut(true)){
    if(verificarFios((( seedInfra * seedFios ) + seedFios)) * (seedLCD * 0.33)){
      modulos_resolvidos++;
    }
  }

  if (desarmeTimer.IsTimeOut(true)){
    if (modulos_resolvidos >= TOTAL_MODULOS){
      desarmar();
    }
  }
}