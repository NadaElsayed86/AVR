/*
 * Led_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */
#include "errorStates.h"
#include "stdTypes.h"

#include "Led_config.h"
#include "Led_priv.h"
#include "DIO_int.h"

ES_t LED_enuInit(LED_t *copy_AstrLedNum)
{
	ES_t Local_enuErrorState=ES_NOK;
	u8 Local_u8Iter=0;
	if(copy_AstrLedNum!=NULL)
	{
		for(Local_u8Iter=0;Local_u8Iter<LED_NUM;Local_u8Iter++)
		{
			Local_enuErrorState=DIO_enuSetPinDirection(copy_AstrLedNum[Local_u8Iter].Led_u8PortID,copy_AstrLedNum[Local_u8Iter].Led_u8PinID,DIO_OUTPUT);
			if(copy_AstrLedNum[Local_u8Iter].Led_u8Connection == SINK)
					{
						if(copy_AstrLedNum[Local_u8Iter].Led_u8InitalState == LED_ON)
						{
							DIO_enuSetPinValue(copy_AstrLedNum[Local_u8Iter].Led_u8PortID,copy_AstrLedNum[Local_u8Iter].Led_u8PinID,DIO_LOW);
						}
						else if(copy_AstrLedNum[Local_u8Iter].Led_u8InitalState == LED_OFF)
						{
							DIO_enuSetPinValue(copy_AstrLedNum[Local_u8Iter].Led_u8PortID,copy_AstrLedNum[Local_u8Iter].Led_u8PinID,DIO_HIGH);
						}
						else
						{
							Local_enuErrorState=ES_OUT_OF_RANGE;
						}

					}
			else if(copy_AstrLedNum[Local_u8Iter].Led_u8Connection == SOURCE)
			{
				if(copy_AstrLedNum[Local_u8Iter].Led_u8InitalState == LED_ON)
						{
							DIO_enuSetPinValue(copy_AstrLedNum[Local_u8Iter].Led_u8PortID,copy_AstrLedNum[Local_u8Iter].Led_u8PinID,DIO_HIGH);
						}
						else if(copy_AstrLedNum[Local_u8Iter].Led_u8InitalState == LED_OFF)
						{
							DIO_enuSetPinValue(copy_AstrLedNum[Local_u8Iter].Led_u8PortID,copy_AstrLedNum[Local_u8Iter].Led_u8PinID,DIO_LOW);
						}
						else
						{
							Local_enuErrorState=ES_OUT_OF_RANGE;
						}
			}
			else
			{
				Local_enuErrorState=ES_OUT_OF_RANGE;
			}

		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
ES_t LED_enuTurnON(LED_t *copy_strPortID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_strPortID != NULL)
	{
		if(copy_strPortID->Led_u8Connection == SINK)
		{
			DIO_enuSetPinValue(copy_strPortID->Led_u8PortID,copy_strPortID->Led_u8PinID,DIO_LOW);
		}
		else if(copy_strPortID->Led_u8Connection == SOURCE)
		{
			DIO_enuSetPinValue(copy_strPortID->Led_u8PortID,copy_strPortID->Led_u8PinID,DIO_HIGH);
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
ES_t LED_enuTurnOFF(LED_t *copy_strPortID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_strPortID != NULL)
		{
			if(copy_strPortID->Led_u8Connection == SINK)
			{
				DIO_enuSetPinValue(copy_strPortID->Led_u8PortID,copy_strPortID->Led_u8PinID,DIO_HIGH);
			}
			else if(copy_strPortID->Led_u8Connection == SOURCE)
			{
				DIO_enuSetPinValue(copy_strPortID->Led_u8PortID,copy_strPortID->Led_u8PinID,DIO_LOW);
			}
			else
			{
				Local_enuErrorState=ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState=ES_NULL_POINTER;
		}

	return Local_enuErrorState;
}
