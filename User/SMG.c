#include "reg52.h"

void Set_HC573(unsigned char channel, unsigned char dat)
{
  P0 = dat;
  switch(channel)
  {
    case 4:
      P2 = (P2 & 0x1f) | 0x80;  //LED控制
    break;
    case 5:
      P2 = (P2 & 0x1f) | 0xa0;  //蜂鸣器和继电器控制
    break;
    case 6:
      P2 = (P2 & 0x1f) | 0xc0;  //数码管位选
    break;
    case 7:
      P2 = (P2 & 0x1f) | 0xe0;  //数码管段码
    break;
    case 0:
      P2 = (P2 & 0x1f) | 0x00;  //不选择
    break;
  }
  P2 = (P2 & 0x1f) | 0x00;
}

void DelaySMG(unsigned int xms)
{
	while(xms--);
}

void DisplaySMG(unsigned char pos, unsigned char value)//pos:0 1 2 3 4 5 6 7
{
  Set_HC573(6, 0x01 << pos);    //数码管的段位
  Set_HC573(7, value);          //数码管显示内容
  DelaySMG(500);                //数码管点亮时长
  Set_HC573(6, 0x01 << pos);        
  Set_HC573(7, 0xff);            //消隐
}