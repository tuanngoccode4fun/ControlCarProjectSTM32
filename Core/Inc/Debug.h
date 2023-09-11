#ifndef __DEBUG_H_
#define __DEBUG_H_
#include "main.h"
extern UART_HandleTypeDef huart1; 
int _write(int file, char *data, int len);
#endif
