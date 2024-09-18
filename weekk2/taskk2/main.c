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
	u8 seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

	//switches input
	DDRA &=~(1<<0);
	DDRA &=~(1<<1);

	PORTA |=(1<<0);
	PORTA |=(1<<1);

	DDRB =0xFF;
	PORTB =seg[0];


	u8 i=0;
	while(1)
	{

		if(((PINA>>0)&1) == 0)
		{
			i++;
			if(i>9)
			{
				i=0;
			}
			PORTB =seg[i];
			_delay_ms(500);
		}
		else if(((PINA>>1)&1) == 0)
		{
			if(i==0)
			{
				i=9;
			}
			else
			{
				i--;
			}
			PORTB =seg[i];
			_delay_ms(500);
		}

	}



	return 0;
}
