/*
 * Led_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "errorStates.h"
#include "stdTypes.h"
#include "Led_priv.h"
#include "Led_config.h"

#include "DIO_int.h"

LED_t LED_AstrLedConfig[LED_NUM]={
		{DIO_PORTA,PIN0,SINK,LED_ON},
		{DIO_PORTB,PIN0,SOURCE,LED_OFF}
};
