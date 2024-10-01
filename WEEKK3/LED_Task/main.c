/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "errorStates.h"
#include "stdTypes.h"
#include "DIO_int.h"
#include <util/delay.h>
#include "Led_int.h"
#include "Led_config.h"

extern LED_t LED_AstrLedConfig[LED_NUM];
int main(void)
{
	LED_enuInit(LED_AstrLedConfig);

	while(1)
	{
		LED_enuTurnON(&LED_AstrLedConfig[1]);
		_delay_ms(500);
		LED_enuTurnOFF(&LED_AstrLedConfig[1]);
		_delay_ms(500);
	}

	return 0;
}
