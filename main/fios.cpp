#include "fios.h"

#include "pinos.h"
#include "seeds.h"
#include "modulos.h"

bool fiosConcluidos = false;

bool roxoDesligado = false;
bool laranjaDesligado = false;
bool amareloDesligado = false;
bool brancoDesligado = false;
bool azulDesligado = false;
bool pretoDesligado = false;

bool verificarFios(int seed){
    if (fiosConcluidos){
      return true;
    }

    Serial.println(seed);
    int estadoDoFioRoxo = digitalRead(fioRoxo);
    int estadoDoFioLaranja = digitalRead(fioLaranja);
    int estadoDoFioBranco = digitalRead(fioBranco);
    int estadoDoFioAzul = digitalRead(fioAzul);
    int estadoDoFioAmarelo = digitalRead(fioAmarelo);
    int estadoDoFioPreto = digitalRead(fioPreto);

    if (seed == 90){
      if (!estadoDoFioLaranja || laranjaDesligado){
        laranjaDesligado = true;
        fiosConcluidos = true;
        return true;
      }

      if (!estadoDoFioPreto || !estadoDoFioAmarelo || !estadoDoFioBranco || !estadoDoFioRoxo || !estadoDoFioAzul){
        modulos_resolvidos = -100;
      }
    }
    else if (seed >= 80){
      if (!estadoDoFioRoxo || roxoDesligado){
        roxoDesligado = true;
        fiosConcluidos = true;
        return true;
      }


      if (!estadoDoFioPreto || !estadoDoFioAmarelo || !estadoDoFioBranco || !estadoDoFioLaranja || !estadoDoFioAzul){
        modulos_resolvidos = -100;
      }
    }
    else if (seed >= 70){
      if (!estadoDoFioAzul || azulDesligado){
        azulDesligado = true;
        fiosConcluidos = true;
        return true;
      }


      if (!estadoDoFioPreto || !estadoDoFioAmarelo || !estadoDoFioBranco || !estadoDoFioLaranja || !estadoDoFioRoxo){
        modulos_resolvidos = -100;
      }
    }
    else if (seed >= 60){
      if (!estadoDoFioAmarelo || amareloDesligado){
        amareloDesligado = true;
        fiosConcluidos = true;
        return true;
      }


      if (!estadoDoFioPreto || !estadoDoFioBranco || !estadoDoFioLaranja || !estadoDoFioRoxo || !estadoDoFioAzul){
        modulos_resolvidos = -100;
      }
    }
    else if (seed >= 50){
      if (!estadoDoFioBranco || brancoDesligado){
        brancoDesligado = true;
        fiosConcluidos = true;
        return true;
      }


      if (!estadoDoFioPreto || !estadoDoFioAmarelo || !estadoDoFioLaranja || !estadoDoFioRoxo || !estadoDoFioAzul){
        modulos_resolvidos = -100;
      }
    }
    else if (seed >= 40){
      if (!estadoDoFioPreto || pretoDesligado){
        pretoDesligado = true;
        fiosConcluidos = true;
        return true;
      }


      if (!estadoDoFioAmarelo || !estadoDoFioBranco || !estadoDoFioLaranja || !estadoDoFioRoxo || !estadoDoFioAzul){
        modulos_resolvidos = -100;
      }
    }
    else if (seed >= 30){
      if (!estadoDoFioLaranja || laranjaDesligado){
        fiosConcluidos = true;
        return true;
      }
    }
    else if (seed >= 20){
      if (!estadoDoFioAmarelo || amareloDesligado){
        fiosConcluidos = true;
        return true;
      }

      
      if (!estadoDoFioPreto || !estadoDoFioBranco || !estadoDoFioLaranja || !estadoDoFioRoxo || !estadoDoFioAzul){
        modulos_resolvidos = -100;
      }
    }
    else{
      if (!estadoDoFioAzul || azulDesligado){
        fiosConcluidos = true;
        return true;
      }


      if (!estadoDoFioPreto || !estadoDoFioAmarelo || !estadoDoFioBranco || !estadoDoFioLaranja || !estadoDoFioRoxo){
        modulos_resolvidos = -100;
      }
    }

    return false;
}