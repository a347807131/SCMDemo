#include "reg51.h"
typedef unsigned char u8;
typedef unsigned int u16;
//??????? ??
void delay(u16 x){
  u8 t;
  while(x--) for(t=0;t<120;t++);
}
//共阴
u8 code table[16]={
  0x3f,0x06,0x5b,0x4f,// 0 1 2 3
  0x66,0x6d,0x7d,0x07,// 4 5 6 7
  0x7f,0x6f,0x77,0x7c,// 8 9 A B
  0x39,0x5e,0x79,0x71 // C D E F
};
void main(){
  while(1){
		int i;
    for(i=0;i<=16;i++){
      P0=~table[i];//????????????
      delay(1000);
  }
  }
}
