/*
 * lcd1602.c
 *
 *  Created on: 2017-2-22
 *      Author: Aeroman
 */
#include"lcd1602.h"


/*<Ctrl pins>*/
//RS
#define Cmd P2OUT&=~BIT0
#define Data P2OUT|=BIT0
//RW
#define write P2OUT&=~BIT1
#define read P2OUT|=BIT1
//EN
#define en P2OUT|=BIT2
#define execute P2OUT&=~BIT2
/*</Ctrl pins>*/

/*<Data pins>*/
#define D0 BIT0
#define D1 BIT1
#define D2 BIT2
#define D3 BIT3
#define D4 BIT4
#define D5 BIT5
#define D6 BIT6
#define D7 BIT7
/*</Data pins>*/

#define delay(x) _delay_cycles((long)(16000000.000*(double)x/1000.000))
void initPin1602(void)
{
	P2DIR|=BIT0|BIT1|BIT2;
	P1DIR|=D0|D1|D2|D3|D4|D5|D6|D7;
}
//void busy()
//{
//
//}
void writeCmd(unsigned char Cmd1)//,unsigned char busy
{
	//if(busy) busy();
	Cmd;
	delay(5);
	write;
	P1OUT&=0X00;
	P1OUT|=Cmd1;
	en;
	delay(5);
	execute;
}
void writeData(unsigned char Ch)
{
	Data;
	delay(5);
	write;
	P1OUT&=0X00;
	P1OUT|=Ch;
	en;
	delay(5);
	execute;
}
void init1602(void)
{
	initPin1602();
	writeCmd(0x38);
	delay(1);
	writeCmd(0x0c);
	delay(1);
	writeCmd(0x06);
	delay(1);
	writeCmd(0x01);
	delay(1);
}
void writePos(unsigned char x,unsigned char y)
{
	if(y==1)
		writeCmd(0x80+x);
	else
		writeCmd(0x40+0x80+x);
}
void disChar1602(unsigned char x,unsigned char y,unsigned char ch)
{
	writePos(x,y);
	delay(0.1);
	writeData(ch);
}
void disStr1602(unsigned char x,unsigned char y,unsigned char *str)
{
	while(*str!='\0')
	{
		if(x<16)
			disChar1602(x++,y,*(str++));
		else
		{
			disChar1602(x-15,y+1,*(str++));
			x++;
		}
	}
}
void clear1602()
{
	writeCmd(0x01);
}
