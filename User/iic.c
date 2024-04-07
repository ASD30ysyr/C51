#include "iic.h"

#define DELAY_TIME 5

sbit IIC_SDA = P2^1;
sbit IIC_SCL = P2^0;

void IIC_Delay_ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);
	}
}

//I2C总线内部延时函数
void IIC_Delay(unsigned char i)
{
    do{_nop_();}
    while(i--);        
}

//I2C总线启动信号
void IIC_Start(void)
{
    IIC_SDA = 1;
    IIC_SCL = 1;
    IIC_Delay(DELAY_TIME);
    IIC_SDA = 0;
    IIC_Delay(DELAY_TIME);
    IIC_SCL = 0;	
}

//I2C总线停止信号
void IIC_Stop(void)
{
    IIC_SDA = 0;
    IIC_SCL = 1;
    IIC_Delay(DELAY_TIME);
    IIC_SDA = 1;
    IIC_Delay(DELAY_TIME);
}

//发送应答或非应答信号
void IIC_SendAck(bit ackbit)
{
    IIC_SCL = 0;
    IIC_SDA = ackbit;  					
    IIC_Delay(DELAY_TIME);
    IIC_SCL = 1;
    IIC_Delay(DELAY_TIME);
    IIC_SCL = 0; 
    IIC_SDA = 1;
    IIC_Delay(DELAY_TIME);
}

//等待应答
bit IIC_WaitAck(void)
{
    bit ackbit;
	
    IIC_SCL  = 1;
    IIC_Delay(DELAY_TIME);
    ackbit = IIC_SDA;
    IIC_SCL = 0;
    IIC_Delay(DELAY_TIME);
    return ackbit;
}

//I2C总线发送一个字节数据
void IIC_SendByte(unsigned char byt)
{
    unsigned char i;

    for(i=0; i<8; i++)
    {
        IIC_SCL  = 0;
        IIC_Delay(DELAY_TIME);
        if(byt & 0x80) IIC_SDA  = 1;
        else IIC_SDA  = 0;
        IIC_Delay(DELAY_TIME);
        IIC_SCL = 1;
        byt <<= 1;
        IIC_Delay(DELAY_TIME);
    }
    IIC_SCL  = 0;  
}

//I2C总线接收一个字节数据
unsigned char IIC_RecByte(void)
{
    unsigned char i, da;
    for(i=0; i<8; i++)
    {   
    	IIC_SCL = 1;
	IIC_Delay(DELAY_TIME);
	da <<= 1;
	if(IIC_SDA) da |= 1;
	IIC_SCL = 0;
	IIC_Delay(DELAY_TIME);
    }
    return da;    
}

void at24c02_write(unsigned char addr,dat){
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	IIC_SendByte(dat);
	IIC_WaitAck();
	IIC_Stop();
	IIC_Delay_ms(10);
}

unsigned char at24c02_read(unsigned char addr){
	unsigned char temp;
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	IIC_Start();
	IIC_SendByte(0xa1);
	IIC_WaitAck();
	temp = IIC_RecByte();
	IIC_SendAck(1);
	IIC_Stop();
	return temp;
}

unsigned char pcf8591_read(pcf8591_channel mode){
	unsigned char temp;
	float value;
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();
	IIC_SendByte(mode);
	IIC_WaitAck();
	IIC_Start();
	IIC_SendByte(0x91);
	IIC_WaitAck();
	value = IIC_RecByte();
	temp = (value / 255) * 50;
	IIC_SendAck(1);
	IIC_Stop();
	return temp;
}

void DA_change(unsigned char dat){
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();
	IIC_SendByte(0x40);
	IIC_WaitAck();
	IIC_SendByte(0x40);
	IIC_WaitAck();
	IIC_Stop();
}
