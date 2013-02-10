#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wiringPi.h>
#include <wiringShift.h>

int dataPin  = 0; // DIO
int clockPin = 3; // SCK
int latchPin = 4; // RCK

int pattn[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff};

void dispdigit(int pos, int d, int dot) {
  printf("%x\n", d);
  // write to the shift register with the correct bit set high:
  digitalWrite(latchPin, LOW);
  // shift the bits out:
  shiftOut(dataPin, clockPin, LSBFIRST, pow(2, pos));
  shiftOut(dataPin, clockPin, MSBFIRST, d);
  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
}

void dispdata(unsigned long datat) {
  unsigned long dketa = 10000000;
  int dpos;
  int zero_f = 0;
  int dnum;
  for(dpos = 7; dpos>=0 ; dpos--) {
    dnum  = datat / dketa;
    datat = datat % dketa;
    dketa = dketa / 10;
    if (dnum > 0 || zero_f == 1) {
      zero_f = 1;
      dispdigit(dpos, pattn[dnum], 0);
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
  // for(;;) dispdata(y);
  int i;
  for(i=0;i<0x200;i++) {
    // dispdigit(128, i);
    // delay(1000);
  }
  char *c = "-./0123456789:;<=>?@aBcdefghijklmnopqrstuvwxyz";

  int len = strlen(c);
  // printf("%d\n", len);
  for(i=0;i<len;i++) {
    int cd = toupper(c[i]) - 45;
    // printf("%d\n", cd);
  }
  dispdigit(7, 0x7f + 0x80 - 0x67, 0);
  return 0;
}

