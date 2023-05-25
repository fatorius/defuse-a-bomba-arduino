#include "beeps.h"
#include "pinos.h"

void beep(int tempo){
  tone (buzzer, 524, (tempo / 9) * 10);
}
