/*
 * Sev_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "Sev_config.h"

#include "Sev_priv.h"

extern SEG_t SEG_AstrSegConfig[SEG_NUM];

ES_t Sev_Seg_enuInit(SEG_t *copy_SegConfig)
{
	ES_t Local_enuErrorState=ES_NOK;
	u8 Local_u8Iter=0;
	if(copy_SegConfig!=NULL)
	{
		for(Local_u8Iter=0;Local_u8Iter<SEG_NUM;Local_u8Iter++)
		{
			DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8APort,copy_SegConfig[Local_u8Iter].SEG_u8APin,DIO_OUTPUT);
			DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8BPort,copy_SegConfig[Local_u8Iter].SEG_u8BPin,DIO_OUTPUT);
			DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8CPort,copy_SegConfig[Local_u8Iter].SEG_u8CPin,DIO_OUTPUT);
			DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8DPort,copy_SegConfig[Local_u8Iter].SEG_u8DPin,DIO_OUTPUT);
			DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8EPort,copy_SegConfig[Local_u8Iter].SEG_u8EPin,DIO_OUTPUT);
			DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8FPort,copy_SegConfig[Local_u8Iter].SEG_u8FPin,DIO_OUTPUT);
			DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8GPort,copy_SegConfig[Local_u8Iter].SEG_u8GPin,DIO_OUTPUT);

			if(copy_SegConfig[Local_u8Iter].SEG_u8CMN_Port != NOT_CONNECTED && copy_SegConfig[Local_u8Iter].SEG_u8CMN_Pin!= NOT_CONNECTED)
			{
				DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8CMN_Port,copy_SegConfig[Local_u8Iter].SEG_u8CMN_Pin,DIO_OUTPUT);
			}
			if(copy_SegConfig[Local_u8Iter].SEG_u8DOT_Port != NOT_CONNECTED && copy_SegConfig[Local_u8Iter].SEG_u8DOT_Pin!= NOT_CONNECTED)
			{
				DIO_enuSetPinDirection(copy_SegConfig[Local_u8Iter].SEG_u8DOT_Port,copy_SegConfig[Local_u8Iter].SEG_u8DOT_Pin,DIO_OUTPUT);
			}
		}
		Local_enuErrorState = ES_OK;

	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_t Sev_Seg_enuDisplayNum(u8 copy_SegID,u8 copy_u8Num)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_u8Num<10)
	{
		if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type ==COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8APort,SEG_AstrSegConfig[copy_SegID].SEG_u8APin,(((SEG_u8AsSeg[copy_u8Num])>>0)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8BPort,SEG_AstrSegConfig[copy_SegID].SEG_u8BPin,(((SEG_u8AsSeg[copy_u8Num])>>1)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CPort,SEG_AstrSegConfig[copy_SegID].SEG_u8CPin,(((SEG_u8AsSeg[copy_u8Num])>>2)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DPort,SEG_AstrSegConfig[copy_SegID].SEG_u8DPin,(((SEG_u8AsSeg[copy_u8Num])>>3)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8EPort,SEG_AstrSegConfig[copy_SegID].SEG_u8EPin,(((SEG_u8AsSeg[copy_u8Num])>>4)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8FPort,SEG_AstrSegConfig[copy_SegID].SEG_u8FPin,(((SEG_u8AsSeg[copy_u8Num])>>5)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8GPort,SEG_AstrSegConfig[copy_SegID].SEG_u8GPin,(((SEG_u8AsSeg[copy_u8Num])>>6)&1));
		}
		else if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type ==COMMON_ANODE)
		{
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8APort,SEG_AstrSegConfig[copy_SegID].SEG_u8APin,!(((SEG_u8AsSeg[copy_u8Num])>>0)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8BPort,SEG_AstrSegConfig[copy_SegID].SEG_u8BPin,!(((SEG_u8AsSeg[copy_u8Num])>>1)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CPort,SEG_AstrSegConfig[copy_SegID].SEG_u8CPin,!(((SEG_u8AsSeg[copy_u8Num])>>2)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DPort,SEG_AstrSegConfig[copy_SegID].SEG_u8DPin,!(((SEG_u8AsSeg[copy_u8Num])>>3)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8EPort,SEG_AstrSegConfig[copy_SegID].SEG_u8EPin,!(((SEG_u8AsSeg[copy_u8Num])>>4)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8FPort,SEG_AstrSegConfig[copy_SegID].SEG_u8FPin,!(((SEG_u8AsSeg[copy_u8Num])>>5)&1));
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8GPort,SEG_AstrSegConfig[copy_SegID].SEG_u8GPin,!(((SEG_u8AsSeg[copy_u8Num])>>6)&1));
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

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuClearDisplay(u8 copy_SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type ==COMMON_CATHODE)
	{
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8APort,SEG_AstrSegConfig[copy_SegID].SEG_u8APin,DIO_LOW);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8BPort,SEG_AstrSegConfig[copy_SegID].SEG_u8BPin,DIO_LOW);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CPort,SEG_AstrSegConfig[copy_SegID].SEG_u8CPin,DIO_LOW);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DPort,SEG_AstrSegConfig[copy_SegID].SEG_u8DPin,DIO_LOW);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8EPort,SEG_AstrSegConfig[copy_SegID].SEG_u8EPin,DIO_LOW);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8FPort,SEG_AstrSegConfig[copy_SegID].SEG_u8FPin,DIO_LOW);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8GPort,SEG_AstrSegConfig[copy_SegID].SEG_u8GPin,DIO_LOW);
	}
	else if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type ==COMMON_ANODE)
	{
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8APort,SEG_AstrSegConfig[copy_SegID].SEG_u8APin,DIO_HIGH);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8BPort,SEG_AstrSegConfig[copy_SegID].SEG_u8BPin,DIO_HIGH);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CPort,SEG_AstrSegConfig[copy_SegID].SEG_u8CPin,DIO_HIGH);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DPort,SEG_AstrSegConfig[copy_SegID].SEG_u8DPin,DIO_HIGH);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8EPort,SEG_AstrSegConfig[copy_SegID].SEG_u8EPin,DIO_HIGH);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8FPort,SEG_AstrSegConfig[copy_SegID].SEG_u8FPin,DIO_HIGH);
		DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8GPort,SEG_AstrSegConfig[copy_SegID].SEG_u8GPin,DIO_HIGH);
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuEnableCommon(u8 copy_SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Port != NOT_CONNECTED && SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Pin!= NOT_CONNECTED)
	{
		if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Pin,DIO_HIGH);
		}
		else if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_ANODE)
		{
			DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Pin,DIO_LOW);
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	}

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuDisableCommon(u8 copy_SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Port != NOT_CONNECTED && SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Pin!= NOT_CONNECTED)
		{
			if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_CATHODE)
			{
				DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Pin,DIO_LOW);
			}
			else if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8CMN_Pin,DIO_HIGH);
			}
			else
			{
				Local_enuErrorState=ES_OUT_OF_RANGE;
			}
		}

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuEnableDOT(u8 copy_SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Port != NOT_CONNECTED && SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Pin!= NOT_CONNECTED)
		{
			if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_CATHODE)
			{
				DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Pin,DIO_HIGH);
			}
			else if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Pin,DIO_LOW);
			}
			else
			{
				Local_enuErrorState=ES_OUT_OF_RANGE;
			}
		}

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuDisableDOT(u8 copy_SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Port != NOT_CONNECTED && SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Pin!= NOT_CONNECTED)
		{
			if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_CATHODE)
			{
				DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Pin,DIO_LOW);
			}
			else if(SEG_AstrSegConfig[copy_SegID].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Port,SEG_AstrSegConfig[copy_SegID].SEG_u8DOT_Pin,DIO_HIGH);
			}
			else
			{
				Local_enuErrorState=ES_OUT_OF_RANGE;
			}
			}

	return Local_enuErrorState;
}
