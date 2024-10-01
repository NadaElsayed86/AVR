/*
 * Sev_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "Sev_priv.h"
#include "Sev_config.h"


ES_t Sev_Seg_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32check=0;

	Local_u32check |=(DIO_enuSetPinDirection(SEG_APORT,SEG_APIN,DIO_OUTPUT)<<0);
	Local_u32check |=(DIO_enuSetPinDirection(SEG_BPORT,SEG_BPIN,DIO_OUTPUT)<<3);
	Local_u32check |=(DIO_enuSetPinDirection(SEG_CPORT,SEG_CPIN,DIO_OUTPUT)<<6);
	Local_u32check |=(DIO_enuSetPinDirection(SEG_DPORT,SEG_DPIN,DIO_OUTPUT)<<9);
	Local_u32check |=(DIO_enuSetPinDirection(SEG_EPORT,SEG_EPIN,DIO_OUTPUT)<<12);
	Local_u32check |=(DIO_enuSetPinDirection(SEG_FPORT,SEG_FPIN,DIO_OUTPUT)<<15);
	Local_u32check |=(DIO_enuSetPinDirection(SEG_GPORT,SEG_GPIN,DIO_OUTPUT)<<18);

#if SEG_CMN_PORT<=DIO_PORTD && SEG_CMN_PIN<=PIN7
	DIO_enuSetPinDirection(SEG_CMN_PORT,SEG_CMN_PIN,DIO_OUTPUT);
#elif SEG_CMN_PORT ==NOT_CONNECTED || SEG_CMN_PIN ==NOT_CONNECTED
#else
#error"SEG common has wrong Selection"
#endif

#if SEG_DOT_PORT<=DIO_PORTD && SEG_DOT_PIN<=PIN7
	DIO_enuSetPinDirection(SEG_DOT_PORT,SEG_DOT_PIN,DIO_OUTPUT);
#elif SEG_DOT_PORT ==NOT_CONNECTED || SEG_DOT_PIN ==NOT_CONNECTED
#else
#error"SEG DOT has wrong Selection"
#endif

	u8 Local_u8Iter=0;
	for(Local_u8Iter=0;Local_u8Iter<21;Local_u8Iter+=3)
	{
		if((((Local_u32check)>>Local_u8Iter)&7)!=ES_OK)
		{
			return Local_enuErrorState;
		}
	}
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuDisplayNum(u8 copy_u8Num)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(copy_u8Num<10)
	{
#if SEG_TYPE == COMMON_CATHODE
		DIO_enuSetPinValue(SEG_APORT,SEG_APIN,((SEG_u8ASeg[copy_u8Num]>>0)&1));
		DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,((SEG_u8ASeg[copy_u8Num]>>1)&1));
		DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,((SEG_u8ASeg[copy_u8Num]>>2)&1));
		DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,((SEG_u8ASeg[copy_u8Num]>>3)&1));
		DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,((SEG_u8ASeg[copy_u8Num]>>4)&1));
		DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,((SEG_u8ASeg[copy_u8Num]>>5)&1));
		DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,((SEG_u8ASeg[copy_u8Num]>>6)&1));
#elif SEG_TYPE == COMMON_ANODE
		DIO_enuSetPinValue(SEG_APORT,SEG_APIN,!((SEG_u8ASeg[copy_u8Num]>>0)&1));
		DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,!((SEG_u8ASeg[copy_u8Num]>>1)&1));
		DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,!((SEG_u8ASeg[copy_u8Num]>>2)&1));
		DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,!((SEG_u8ASeg[copy_u8Num]>>3)&1));
		DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,!((SEG_u8ASeg[copy_u8Num]>>4)&1));
		DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,!((SEG_u8ASeg[copy_u8Num]>>5)&1));
		DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,!((SEG_u8ASeg[copy_u8Num]>>6)&1));
#else
#error"SEG type has wrong Selection"
#endif
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}
ES_t Sev_Seg_enuClearDisplay()
{
	ES_t Local_enuErrorState=ES_NOK;

#if SEG_TYPE == COMMON_ANODE
		DIO_enuSetPinValue(SEG_APORT,SEG_APIN,DIO_HIGH);
		DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,DIO_HIGH);
		DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,DIO_HIGH);
		DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,DIO_HIGH);
		DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,DIO_HIGH);
		DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,DIO_HIGH);
		DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,DIO_HIGH);
#elif SEG_TYPE == COMMON_CATHODE
		DIO_enuSetPinValue(SEG_APORT,SEG_APIN,DIO_LOW);
		DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,DIO_LOW);
		DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,DIO_LOW);
		DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,DIO_LOW);
		DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,DIO_LOW);
		DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,DIO_LOW);
		DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,DIO_LOW);
#else
#error"SEG type has wrong Selection"
#endif




	return Local_enuErrorState;
}
ES_t Sev_Seg_enuEnableCommon()
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_CMN_PORT<=DIO_PORTD && SEG_CMN_PIN<=PIN7
  #if SEG_TYPE == COMMON_ANODE
	DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN_PIN,DIO_HIGH);
  #elif SEG_TYPE == COMMON_CATHODE
	DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN_PIN,DIO_LOW);
  #else
  #error"SEG type has wrong Selection"
  #endif
#elif SEG_CMN_PORT ==NOT_CONNECTED || SEG_CMN_PIN ==NOT_CONNECTED
#else
#error"SEG common has wrong Selection"
#endif

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuDisableCommon()
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_CMN_PORT<=DIO_PORTD && SEG_CMN_PIN<=PIN7
  #if SEG_TYPE == COMMON_ANODE
	DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN_PIN,DIO_LOW);
  #elif SEG_TYPE == COMMON_CATHODE
	DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN_PIN,DIO_HIGH);
  #else
  #error"SEG type has wrong Selection"
  #endif
#elif SEG_CMN_PORT ==NOT_CONNECTED || SEG_CMN_PIN ==NOT_CONNECTED
#else
#error"SEG common has wrong Selection"
#endif

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuEnableDOT()
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_DOT_PORT<=DIO_PORTD && SEG_DOT_PIN<=PIN7
  #if SEG_TYPE == COMMON_ANODE
	DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT_PIN,DIO_LOW);
  #elif SEG_TYPE == COMMON_CATHODE
	DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT_PIN,DIO_HIGH);
  #else
  #error"SEG type has wrong Selection"
  #endif
#elif SEG_CMN_PORT ==NOT_CONNECTED || SEG_CMN_PIN ==NOT_CONNECTED
#else
#error"SEG DOT has wrong Selection"
#endif

	return Local_enuErrorState;
}
ES_t Sev_Seg_enuDisableDOT()
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_DOT_PORT<=DIO_PORTD && SEG_DOT_PIN<=PIN7
  #if SEG_TYPE == COMMON_ANODE
	DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT_PIN,DIO_HIGH);
  #elif SEG_TYPE == COMMON_CATHODE
	DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT_PIN,DIO_LOW);
  #else
  #error"SEG type has wrong Selection"
  #endif
#elif SEG_CMN_PORT ==NOT_CONNECTED || SEG_CMN_PIN ==NOT_CONNECTED
#else
#error"SEG DOT has wrong Selection"
#endif

	return Local_enuErrorState;
}
