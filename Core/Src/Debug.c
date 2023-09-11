#include "Debug.h"
int _write(int file, char *data, int len)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)data, len, HAL_MAX_DELAY);
	return len;
}
