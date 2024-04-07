#include "reg52.h"
#include "keyscan.h"

sbit R1 = P3^0;
sbit R2 = P3^1;
sbit R3 = P3^2;
sbit R4 = P3^3;

sbit C1 = P4^4;
sbit C2 = P4^2;
sbit C3 = P3^5;
sbit C4 = P3^4;

void Delay_ms()		//@12.000MHz
{
	unsigned char data i, j;

	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
}

unsigned char ScanKeys(){
	unsigned char keyNum = 0;
	R1 = 0;
	R2 = R3 = R4 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0){
		Delay_ms();
		if(C1 == 0)
			keyNum = 1;
	}
	else if(C2 == 0){
		Delay_ms();
		if(C2 == 0)
			keyNum = 2;
	}
	else if(C3 == 0){
		Delay_ms();
		if(C3 == 0)
			keyNum = 3;
	}
	else if(C4 == 0){
		Delay_ms();
		if(C4 == 0)
			keyNum = 4;
	}
	R2 = 0;
	R1 = R3 = R4 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0){
		Delay_ms();
		if(C1 == 0)
			keyNum = 5;
	}
	else if(C2 == 0){
		Delay_ms();
		if(C2 == 0)
			keyNum = 6;
	}
	else if(C3 == 0){
		Delay_ms();
		if(C3 == 0)
			keyNum = 7;
	}
	else if(C4 == 0){
		Delay_ms();
		if(C4 == 0)
			keyNum = 8;
	}
	R3 = 0;
	R2 = R1 = R4 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0){
		Delay_ms();
		if(C1 == 0)
			keyNum = 9;
	}
	else if(C2 == 0){
		Delay_ms();
		if(C2 == 0)
			keyNum = 10;
	}
	else if(C3 == 0){
		Delay_ms();
		if(C3 == 0)
			keyNum = 11;
	}
	else if(C4 == 0){
		Delay_ms();
		if(C4 == 0)
			keyNum = 12;
	}
	R4 = 0;
	R2 = R3 = R1 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0){
		Delay_ms();
		if(C1 == 0)
			keyNum = 13;
	}
	else if(C2 == 0){
		Delay_ms();
		if(C2 == 0)
			keyNum = 14;
	}
	else if(C3 == 0){
		Delay_ms();
		if(C3 == 0)
			keyNum = 15;
	}
	else if(C4 == 0){
		Delay_ms();
		if(C4 == 0)
			keyNum = 16;
	}
	return keyNum;
}
