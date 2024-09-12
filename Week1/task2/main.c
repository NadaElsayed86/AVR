/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#define PORTA   *((u8*)0x3B)
#define DDRA   *((u8*)0x3A)
#define PINA   *((volatile u8*)0x39)
#include <util/delay.h>
typedef unsigned char u8;

int main(void)
{

	DDRA |=(1<<0);
	DDRA |=(1<<1);
	DDRA |=(1<<2);
	DDRA |=(1<<3);
	DDRA |=(1<<4);

	while(1)
	{
		PORTA |=(1<<0);
		_delay_ms(200);
		PORTA |=(1<<1);
		_delay_ms(200);
		PORTA |=(1<<2);
		_delay_ms(200);
		PORTA |=(1<<3);
		_delay_ms(200);
		PORTA |=(1<<4);
		_delay_ms(200);


		PORTA &=~(1<<0);
		_delay_ms(200);
		PORTA &=~(1<<1);
		_delay_ms(200);
		PORTA &=~(1<<2);
		_delay_ms(200);
		PORTA &=~(1<<3);
		_delay_ms(200);
		PORTA &=~(1<<4);
		_delay_ms(200);


	}

	return 0;
}

