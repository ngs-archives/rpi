#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <wiringShift.h>

int dataPin  = 0; // DIO
int clockPin = 3; // SCK
int latchPin = 4; // RCK

int pattn[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff};

void dispdata(unsigned long datat) {
  unsigned long dketa = 10000000;
  int dpos;
  int zero_f = 0;
  int dnum;
  for(dpos = 128; dpos>0 ; dpos=dpos /2) {
    dnum  = datat / dketa;
    datat = datat % dketa;
    dketa = dketa / 10;
    if (dnum > 0 || zero_f == 1) {
      zero_f = 1;
      // write to the shift register with the correct bit set high:
      digitalWrite(latchPin, LOW);
      // shift the bits out:
      shiftOut(dataPin, clockPin, LSBFIRST, dpos);
      shiftOut(dataPin, clockPin, MSBFIRST, pattn[dnum]);
      // turn on the output so the LEDs can light up:
      digitalWrite(latchPin, HIGH);
      delay(1);
    }
  }
}

int main (int argc, char *argv []) {
  wiringPiSetup();
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);
  const char* x = argv[1];
  int y = atoi(x);
  for(;;) dispdata(y);
  return 0;
}

