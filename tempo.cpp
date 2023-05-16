#include "tempo.h"

int tempoRestante = 180;

void atualizarTempo(){
  tempoRestante--;
}

int obterMinutos(int tempo){
  return tempo / 60;
}

String obterSegundos(int tempo){
  int tempoReal = tempo % 60;

  String tempoString;

  tempoString = String(tempoReal);

  if (tempoReal < 10){
    return "0" + tempoString;
  }
  else{
    return tempoString;
  }
}