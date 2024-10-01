/*
 * SW_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "errorStates.h"
#include "stdTypes.h"
#include "SW_config.h"
#include "SW_priv.h"
#include "DIO_int.h"

SW_t SW_AstrSwitchConfug[Switch_NUM]={
		{DIO_PORTA,PIN0,DIO_PULLUP},
		{DIO_PORTB,PIN0,DIO_PULLUP},
		{DIO_PORTC,PIN0,DIO_FLOAT}
};
