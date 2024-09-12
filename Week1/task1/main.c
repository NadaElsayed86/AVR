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

	while(1)
	{
		PORTA |=(1<<0);
		_delay_ms(1000);
		PORTA &=~(1<<0);
		_delay_ms(1000);

	}

	return 0;
}
