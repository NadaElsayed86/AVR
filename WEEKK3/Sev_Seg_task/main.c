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
#include "Sev_int.h"
int main(void)
{
	Sev_Seg_enuInit();

	while(1)
	{
		u8 i=0;
		for(i-0;i<10;i++)
		{
			Sev_Seg_enuDisplayNum(i);
			_delay_ms(500);
		}

	}

	return 0;
}
