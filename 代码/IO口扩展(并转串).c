#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;
#define GIOP_LED P0
sbit IN_PL=P1^6;
sbit IN_Data=P1^7;
sbit SCK=P3^6;

u8 Read74HC165(){
  u8 indata,i;
  IN_PL=0;
  _nop_();
  IN_PL=1;
  _nop_();

  indata=0;
  for (i = 0; i <8; i++) {
    indata=indata<<1;
    SCK=0;
    _nop_();

    indata|=IN_Data;
    SCK=1;
  }
  return indata;
}
void delay(u16 x){
  u8 t;
  while(x--) for(t=0;t<120;t++);
}
void main(){
  u8 h165Value;
  while(1){
    h165Value=Read74HC165();
    if(h165Value!=0xff){
      GIOP_LED=~h165Value;
    }
  }
}
