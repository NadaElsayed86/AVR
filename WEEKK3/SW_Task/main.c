/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "errorStates.h"
#include "stdTypes.h"
#include "DIO_int.h"
#include "SW_config.h"
#include "SW_int.h"
#include <util/delay.h>

extern SW_t SW_AstrSwitchConfug[Switch_NUM];
int main(void)
{
	DIO_enuInit();
	SW_enuInit(SW_AstrSwitchConfug);

	u8 pinstate=0;
	while(1)
	{
		SW_enuGetSwitchState(&SW_AstrSwitchConfug[0],&pinstate);

		if(pinstate==0)
		{
			DIO_enuSetPinValue(DIO_PORTB,PIN1,DIO_HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_PORTB,PIN1,DIO_LOW);
		}
	}

	return 0;
}
