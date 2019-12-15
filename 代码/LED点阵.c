#include "reg51.h"
typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 x){
  u8 t;
  while(x--) for(t=0;t<120;t++);
}
void main(){

}
