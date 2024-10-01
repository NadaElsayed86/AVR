/*
 * DIO_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

ES_t DIO_enuInit(void);
ES_t DIO_enuSetPortDirection(u8 copy_u8PortID,u8 copy_u8PortValue);
ES_t DIO_enuSetPortValue(u8 copy_u8PortID,u8 copy_u8PortValue);
ES_t DIO_enuTogPort(u8 copy_u8PortID);
ES_t DIO_enuGetPortValue(u8 copy_u8PortID,u8 copy_u8PortValue,u8 * copy_pu8PortValue);

ES_t DIO_enuSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8PinVal);
ES_t DIO_enuSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8PinVal);
ES_t DIO_enuTogPin(u8 copy_u8PortID,u8 copy_u8PinID);
ES_t DIO_enuGetPinValue(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8PinVal,u8 * copy_pu8PinVal);

#define DIO_INPUT          0
#define DIO_OUTPUT         1

#define DIO_HIGH           1
#define DIO_LOW            0
#define DIO_FLOAT          0
#define DIO_PULLUP         1

#define DIO_PORTA              0
#define DIO_PORTB              1
#define DIO_PORTC              2
#define DIO_PORTD              3

#define PIN0  			   0
#define PIN1  			   1
#define PIN2  			   2
#define PIN3  			   3
#define PIN4  			   4
#define PIN5  			   5
#define PIN6  			   6
#define PIN7  			   7
#endif /* DIO_INT_H_ */
