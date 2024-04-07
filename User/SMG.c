#include "reg52.h"

void Set_HC573(unsigned char channel, unsigned char dat)
{
  P0 = dat;
  switch(channel)
  {
    case 4:
      P2 = (P2 & 0x1f) | 0x80;  //LED����
    break;
    case 5:
      P2 = (P2 & 0x1f) | 0xa0;  //�������ͼ̵�������
    break;
    case 6:
      P2 = (P2 & 0x1f) | 0xc0;  //�����λѡ
    break;
    case 7:
      P2 = (P2 & 0x1f) | 0xe0;  //����ܶ���
    break;
    case 0:
      P2 = (P2 & 0x1f) | 0x00;  //��ѡ��
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
  Set_HC573(6, 0x01 << pos);    //����ܵĶ�λ
  Set_HC573(7, value);          //�������ʾ����
  DelaySMG(500);                //����ܵ���ʱ��
  Set_HC573(6, 0x01 << pos);        
  Set_HC573(7, 0xff);            //����
}