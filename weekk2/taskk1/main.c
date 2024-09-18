/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */
#define PORTA   *((u8*)0x3B)
#define DDRA   *((u8*)0x3A)
#define PINA   *((volatile u8*)0x39)

#define DDRB *((u8*)0x37)
#define PORTB *((u8*)0x38)
#define PINB   *((volatile u8*)0x36)

#define DDRC *((u8*)0x34)
#define PORTC *((u8*)0x35)
#define PINC *((volatile u8*)0x33)

#define DDRD *((u8*)0x31)
#define PORTD *((u8*)0x32)
#define PIND *((volatile u8*)0x30)
#include <util/delay.h>
typedef unsigned char u8;

int main(void)
{
	//led 1&2 output
	DDRA |=(1<<0);
	DDRA |=(1<<1);

	//switches input
	DDRB &=~(1<<0);
	DDRB &=~(1<<1);
	DDRB &=~(1<<2);

	PORTA &=~(1<<0);
	PORTA &=~(1<<1);

	PORTB |=(1<<0);
	PORTB |=(1<<1);
	PORTB |=(1<<2);

	while(1)
	{
		if(((PINB>>0)&1) == 0)
		{
			PORTA |=(1<<0);
		}
		else if(((PINB>>1)&1) == 0)
		{
			PORTA |=(1<<1);
		}
		else if(((PINB>>2)&1) == 0)
		{
			PORTA |=(1<<0);
			PORTA |=(1<<1);
		}
		else
		{
			PORTA &=~(1<<0);
			PORTA &=~(1<<1);
		}
	}



	return 0;
}
