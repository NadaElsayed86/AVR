/*
 * Led_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#include "Led_config.h"
ES_t LED_enuInit(LED_t *copy_AstrLedNum);
ES_t LED_enuTurnON(LED_t *copy_strPortID);
ES_t LED_enuTurnOFF(LED_t *copy_strPortID);

#endif /* LED_INT_H_ */
