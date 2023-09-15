/*
 * Command.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Admin
 */

#ifndef APP_COMMAND_H_
#define APP_COMMAND_H_
#include "stdint.h"
typedef enum
{
	CAR_COMMAND_STOP = 0x01,
	CAR_COMMAND_FORWARD,
	CAR_COMMAND_BACKWARD,
	CAR_COMMAND_LEFT,
	CAR_COMMAND_RIGHT,
}CarCommand_t;
void process_data(uint8_t *data, uint8_t len);
#endif /* APP_COMMAND_H_ */
