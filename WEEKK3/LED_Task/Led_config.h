/*
 * Led_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM          2
typedef struct
{
	u8 Led_u8PortID;
	u8 Led_u8PinID;
	u8 Led_u8Connection;
	u8 Led_u8InitalState;
}LED_t;

#endif /* LED_CONFIG_H_ */
