#ifndef _IIC_H
#define _IIC_H

#include "reg52.h"
#include "intrins.h"

typedef enum {
	Pres = 0x01,
	res = 0x03
}pcf8591_channel;

void IIC_Start(void); 
void IIC_Stop(void);  
bit IIC_WaitAck(void);  
void IIC_SendAck(bit ackbit); 
void IIC_SendByte(unsigned char byt); 
unsigned char IIC_RecByte(void);
void at24c02_write(unsigned char addr,dat);
unsigned char at24c02_read(unsigned char addr);
unsigned char pcf8591_read(pcf8591_channel mode);
void DA_change(unsigned char dat);

#endif