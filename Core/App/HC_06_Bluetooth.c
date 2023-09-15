/*
 * HC_06_Bluetooth.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Admin
 */

#include "HC_06_Bluetooth.h"
uint8_t pData[MAX_SIZE_UART];
__weak void Receive_data_from_bluetooth_callback(uint8_t *data, uint8_t len);
void bluetooth_init(bluetooth_t * bluetooth, UART_HandleTypeDef *huart)
{
	bluetooth->huart = huart;
	HAL_UARTEx_ReceiveToIdle_IT(bluetooth->huart, pData, MAX_SIZE_UART);
}

void bluetooth_handler(bluetooth_t * bluetooth,uint8_t len)
{
	printf("bluetooth_handler= %s [len] = %d  \r\n", pData,len);
	Receive_data_from_bluetooth_callback(pData,len);
	HAL_UARTEx_ReceiveToIdle_IT(bluetooth->huart, pData, MAX_SIZE_UART);
}
