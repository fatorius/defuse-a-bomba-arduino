#include "lcd.h"

LiquidCrystal lcd(12,11,5,4,3,2);

void exibirMensagemNoLCD(int seed){
  lcd.setCursor(0, 10);

  if (seed >= 90){
      lcd.print("4729486768452233");
    }
    else if (seed >= 80){
      lcd.print("6338557790473045");
    }
    else if (seed >= 70){
      lcd.print("8955787369071799");
    }
    else if (seed >= 60){
      lcd.print("9716899577690808");
    }
    else if (seed >= 50){
      lcd.print("4729486768452233");
    }
    else if (seed >= 40){
      lcd.print("1686828862435477");
    }
    else if (seed >= 30){
      lcd.print("9378545885191826");
    }
    else if (seed >= 20){
      lcd.print("9670644332148059");
    }
    else{
      lcd.print("6368034340907517");
    }
}