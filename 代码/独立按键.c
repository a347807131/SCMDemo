#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;
sbit led=P0^0;
sbit k1=P1^0;

//毫秒级延时
void delay(u16 x){
  u16 t;
  while(x--) for(t=0;t<120;t++);
}
void keyPros(){
  if(k1==0){
    delay(10);
    if(k1==0){
      led=!led;
    }
    while(!k1);
  }
}
void main(){
  led=0;
  while(1){
    keyPros();
  }
}
