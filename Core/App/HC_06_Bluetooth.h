/*
 * HC_06_Bluetooth.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Admin
 */

#ifndef APP_HC_06_BLUETOOTH_H_
#define APP_HC_06_BLUETOOTH_H_
#include "main.h"
#include "stdint.h"
#include "stdio.h"
#define MAX_SIZE_UART 128
typedef struct
{;
	UART_HandleTypeDef *huart;
}bluetooth_t;
void bluetooth_init(bluetooth_t * bluetooth, UART_HandleTypeDef *huart);
void bluetooth_handler(bluetooth_t * bluetooth,uint8_t len);
#endif /* APP_HC_06_BLUETOOTH_H_ */
