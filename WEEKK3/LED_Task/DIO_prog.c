/*
 * DIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "errorStates.h"
#include "DIO_config.h"
#include "DIO_priv.h"
#include "stdTypes.h"



ES_t DIO_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	DDRA=CONC(PA_PIN7_DIR,PA_PIN6_DIR,PA_PIN5_DIR,PA_PIN4_DIR,PA_PIN3_DIR,PA_PIN2_DIR,PA_PIN1_DIR,PA_PIN0_DIR);
	DDRB=CONC(PB_PIN7_DIR,PB_PIN6_DIR,PB_PIN5_DIR,PB_PIN4_DIR,PB_PIN3_DIR,PB_PIN2_DIR,PB_PIN1_DIR,PB_PIN0_DIR);
	DDRC=CONC(PC_PIN7_DIR,PC_PIN6_DIR,PC_PIN5_DIR,PC_PIN4_DIR,PC_PIN3_DIR,PC_PIN2_DIR,PC_PIN1_DIR,PC_PIN0_DIR);
	DDRD=CONC(PD_PIN7_DIR,PD_PIN6_DIR,PD_PIN5_DIR,PD_PIN4_DIR,PD_PIN3_DIR,PD_PIN2_DIR,PD_PIN1_DIR,PD_PIN0_DIR);

	PORTA=CONC(PA_PIN7_VAL,PA_PIN6_VAL,PA_PIN5_VAL,PA_PIN4_VAL,PA_PIN3_VAL,PA_PIN2_VAL,PA_PIN1_VAL,PA_PIN0_VAL);
	PORTB=CONC(PB_PIN7_VAL,PB_PIN6_VAL,PB_PIN5_VAL,PB_PIN4_VAL,PB_PIN3_VAL,PB_PIN2_VAL,PB_PIN1_VAL,PB_PIN0_VAL);
	PORTC=CONC(PC_PIN7_VAL,PC_PIN6_VAL,PC_PIN5_VAL,PC_PIN4_VAL,PC_PIN3_VAL,PC_PIN2_VAL,PC_PIN1_VAL,PC_PIN0_VAL);
	PORTD=CONC(PD_PIN7_VAL,PD_PIN6_VAL,PD_PIN5_VAL,PD_PIN4_VAL,PD_PIN3_VAL,PD_PIN2_VAL,PD_PIN1_VAL,PD_PIN0_VAL);

	return Local_enuErrorState;
}
ES_t DIO_enuSetPortDirection(u8 copy_u8PortID,u8 copy_u8PortValue)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_u8PortID<=DIO_PORTD)
	{
		switch(copy_u8PortID)
		{
		case DIO_PORTA:
			DDRA=copy_u8PortValue;
			break;
		case DIO_PORTB:
			DDRB=copy_u8PortValue;
			break;
		case DIO_PORTC:
			DDRC=copy_u8PortValue;
			break;
		case DIO_PORTD:
			DDRD=copy_u8PortValue;
			break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
ES_t DIO_enuSetPortValue(u8 copy_u8PortID,u8 copy_u8PortValue)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(copy_u8PortID<=DIO_PORTD)
	{
		switch(copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA=copy_u8PortValue;
			break;
		case DIO_PORTB:
			PORTB=copy_u8PortValue;
			break;
		case DIO_PORTC:
			PORTC=copy_u8PortValue;
			break;
		case DIO_PORTD:
			PORTD=copy_u8PortValue;
			break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
ES_t DIO_enuTogPort(u8 copy_u8PortID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(copy_u8PortID<=DIO_PORTD)
	{
		switch(copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA=~PORTA;
			break;
		case DIO_PORTB:
			PORTB=~PORTB;
			break;
		case DIO_PORTC:
			PORTC=~PORTC;
			break;
		case DIO_PORTD:
			PORTD=~PORTD;
			break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}
ES_t DIO_enuGetPortValue(u8 copy_u8PortID,u8 copy_u8PortValue,u8 * copy_pu8PortValue)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_pu8PortValue!=NULL)
	{
		if(copy_u8PortID<=DIO_PORTD)
		{
			switch(copy_u8PortID)
			{
			case DIO_PORTA:
				*copy_pu8PortValue=PINA;
				break;
			case DIO_PORTB:
				*copy_pu8PortValue=PINB;
				break;
			case DIO_PORTC:
				*copy_pu8PortValue=PINC;
				break;
			case DIO_PORTD:
				*copy_pu8PortValue=PIND;
				break;
			}
			Local_enuErrorState=ES_OK;
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

ES_t DIO_enuSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8PinVal)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_u8PortID<=DIO_PORTD && copy_u8PinID<=PIN7 && copy_u8PinVal<=DIO_OUTPUT)
	{
		switch(copy_u8PortID)
		{
		case DIO_PORTA:
			DDRA &=~(1<<copy_u8PinID);
			DDRA |=(copy_u8PinVal<<copy_u8PinID);
			break;
		case DIO_PORTB:
			DDRB &=~(1<<copy_u8PinID);
			DDRB |=(copy_u8PinVal<<copy_u8PinID);
			break;
		case DIO_PORTC:
			DDRC &=~(1<<copy_u8PinID);
			DDRC |=(copy_u8PinVal<<copy_u8PinID);
			break;
		case DIO_PORTD:
			DDRD &=~(1<<copy_u8PinID);
			DDRD |=(copy_u8PinVal<<copy_u8PinID);
			break;
		}
		Local_enuErrorState=ES_OK;

	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}
ES_t DIO_enuSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8PinVal)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(copy_u8PortID<=DIO_PORTD && copy_u8PinID<=PIN7 && copy_u8PinVal<=DIO_OUTPUT)
		{
		switch(copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA &=~(1<<copy_u8PinID);
			PORTA |=(copy_u8PinVal<<copy_u8PinID);
			break;
		case DIO_PORTB:
			PORTB &=~(1<<copy_u8PinID);
			PORTB |=(copy_u8PinVal<<copy_u8PinID);
			break;
		case DIO_PORTC:
			PORTC &=~(1<<copy_u8PinID);
			PORTC |=(copy_u8PinVal<<copy_u8PinID);
			break;
		case DIO_PORTD:
			PORTD &=~(1<<copy_u8PinID);
			PORTD |=(copy_u8PinVal<<copy_u8PinID);
			break;
		}
		Local_enuErrorState=ES_OK;
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}
ES_t DIO_enuTogPin(u8 copy_u8PortID,u8 copy_u8PinID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_u8PortID<=DIO_PORTD && copy_u8PinID<=PIN7)
	{
		switch(copy_u8PortID)
		{
		case DIO_PORTA:
			PORTA^=(1<<copy_u8PinID);
			break;
		case DIO_PORTB:
			PORTB^=(1<<copy_u8PinID);
			break;
		case DIO_PORTC:
			PORTC^=(1<<copy_u8PinID);
			break;
		case DIO_PORTD:
			PORTD^=(1<<copy_u8PinID);
			break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}
ES_t DIO_enuGetPinValue(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8PinVal,u8 *copy_pu8PinVal)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_pu8PinVal !=NULL)
	{
		if(copy_u8PortID<=DIO_PORTD && copy_u8PinID<=PIN7 && copy_u8PinVal<=DIO_OUTPUT)
		{
			switch(copy_u8PortID)
			{
			case DIO_PORTA:
				*copy_pu8PinVal=((PINA>>copy_u8PinID)&1);
				break;
			case DIO_PORTB:
				*copy_pu8PinVal=((PINB>>copy_u8PinID)&1);
				break;
			case DIO_PORTC:
				*copy_pu8PinVal=((PINC>>copy_u8PinID)&1);
				break;
			case DIO_PORTD:
				*copy_pu8PinVal=((PIND>>copy_u8PinID)&1);
				break;
			}
			Local_enuErrorState=ES_OK;
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
