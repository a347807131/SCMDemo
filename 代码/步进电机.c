#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;
sbit motorA=P1^0;
sbit motorB=P1^1;
sbit motorC=P1^2;
sbit motorD=P1^3;
u8 t=20;

void delay(u16 x){
  u8 t;
  while(x--) for(t=0;t<120;t++);
}
void main(){
  P1=0x00;//清零
  while(1){
    motorA=1;
    motorB=0;
    motorC=1;
    motorD=1;
    delay(t);

  }
}
