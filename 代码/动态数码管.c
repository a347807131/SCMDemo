#include "reg51.h"
typedef unsigned char u8;
typedef unsigned int u16;

//定义38译码器的3个控制端
sbit LSA=P2^2;
sbit LSB=P2^1;
sbit LSC=P2^0;

void delay(u16 x){
  /*
  u16 t;
  while(x--) for(t=0;t<120;t++);
  */
  while(x--);
}
//共阴
u8 code table[16]={
  0x3f,0x06,0x5b,0x4f,// 0 1 2 3
  0x66,0x6d,0x7d,0x07,// 4 5 6 7
  0x7f,0x6f,0x77,0x7c,// 8 9 A B
  0x39,0x5e,0x79,0x71 // C D E F
};
void display(int n){
  u8 i;
  for(i=0;i<8;i++){
    switch (i) {
      case 0:LSA=0;LSB=0;LSC=0;break;
      case 1:LSA=1;LSB=0;LSC=0;break;
      case 2:LSA=0;LSB=1;LSC=0;break;
      case 3:LSA=1;LSB=1;LSC=0;break;
      case 4:LSA=0;LSB=0;LSC=1;break;
      case 5:LSA=1;LSB=0;LSC=1;break;
      case 6:LSA=0;LSB=1;LSC=1;break;
      case 7:LSA=1;LSB=1;LSC=1;break;
    }
    P0=table[i+n];
    delay(100);
    P0=0x00;
  }
}
void main(){
  u16 dey=0;
  int n=0
  while(1){
    display(n);
    dey=dey%1000+1;
    if(dey==500) n=n%8+1;
  }
}
