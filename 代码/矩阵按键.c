//行列扫描来检测
#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;
#define GPIO_LED P0
#define GPIO_KEY P1
//共阴数码管
u8 code table[4][4]={
  {0x3f,0x06,0x5b,0x4f},// 0 1 2 3
  {0x66,0x6d,0x7d,0x07},// 4 5 6 7
  {0x7f,0x6f,0x77,0x7c},// 8 9 A B
  {0x39,0x5e,0x79,0x71} // C D E F
};
u8 line,row;

void delay(u16 x){
  u8 t;
  while(x--) for(t=0;t<120;t++);
}
void keyDown(){
  //高四位输出高电平
  char a=0;
  GPIO_KEY=0xf0;
  if(GPIO_KEY!=0xf0){
    delay(50);
    if(GPIO_KEY=0xf0){
      //列
      switch (GPIO_KEY) {
        case 0x70:row=3;break;
        case 0xb0:row=2;break;
        case 0xd0:row=1;break;
        case 0xe0:row=0;break;
      }
      //低四位输出低电平
      GPIO_KEY=0x0f;
      //line
      switch (GPIO_KEY) {
        case 0x07:line=3;break;
        case 0x0b:line=2;break;
        case 0x0d:line=1;break;
        case 0x0e:line=0;break;
      }
    }
  }
}
void main(){
  while (1) {
    keyDown();
    GPIO_LED=table[line][row];
  }
}
