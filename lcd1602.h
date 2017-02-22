/*
 * lcd1602.h
 *
 *  Created on: 2017Äê2ÔÂ22ÈÕ
 *      Author: Aeroman
 */

#ifndef LCD1602_H_
#define LCD1602_H_
#include<msp430.h>

extern void init1602();
extern void writeData(unsigned char Ch);
extern void writeCmd(unsigned char Cmd1);
extern void disStr1602(unsigned char x,unsigned char y,unsigned char *str);
extern void disChar1602(unsigned char x,unsigned char y,unsigned char ch);
extern void clear1602();
#endif /* LCD1602_H_ */
