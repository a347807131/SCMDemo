#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;
sbit motor=P1^0;

void delay(u16 x){
  u8 t;
  while(x--) for(t=0;t<120;t++);
}
void main(){
  motor=0;
  while(1){
    motor=1;
    delay(5000);
    motor=0;
    delay(1000);
  }
}
