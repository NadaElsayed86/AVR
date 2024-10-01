/*
 * SW_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "errorStates.h"
#include "stdTypes.h"
#include "SW_config.h"
#include "SW_priv.h"
#include "DIO_int.h"

ES_t SW_enuInit(SW_t *copy_AstrSwitches)
{
	ES_t Local_enuErrorState=ES_NOK;
	u8 Local_u8Iter=0;
	if(copy_AstrSwitches !=NULL)
	{
		for(Local_u8Iter=0;Local_u8Iter<Switch_NUM;Local_u8Iter++)
		{
			Local_enuErrorState=DIO_enuSetPinDirection(copy_AstrSwitches[Local_u8Iter].SW_u8PortID,copy_AstrSwitches[Local_u8Iter].SW_u8PinID,DIO_INPUT);
			Local_enuErrorState=DIO_enuSetPinValue(copy_AstrSwitches[Local_u8Iter].SW_u8PortID,copy_AstrSwitches[Local_u8Iter].SW_u8PinID,copy_AstrSwitches[Local_u8Iter].SW_u8status);
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
ES_t SW_enuGetSwitchState(SW_t *copy_strPortID,SW_t *copy_strValue)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_strPortID!=NULL && copy_strValue!=NULL)
	{
		Local_enuErrorState=DIO_enuGetPinValue(copy_strPortID->SW_u8PortID,copy_strPortID->SW_u8PinID,copy_strValue);
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
