/*
 * Command.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Admin
 */

#include "Command.h"
#include "Car.h"

void process_data(uint8_t *data, uint8_t len)
{
	printf("data[0] = 0x%02X \r\n", data[0]);
	switch (data[0]) {
		case CAR_COMMAND_STOP:
			    printf("process_data : CAR_COMMAND_STOP \r\n");
				car_control(CAR_DIR_FORDWARD,0);

			break;
		case CAR_COMMAND_FORWARD:
			 printf("process_data : CAR_COMMAND_FORWARD \r\n");
				car_control(CAR_DIR_FORDWARD,data[1]);

			break;
		case CAR_COMMAND_BACKWARD:
			 printf("process_data : CAR_COMMAND_BACKWARD \r\n");
				car_control(CAR_DIR_BACKWARD,data[1]);

			break;
		case CAR_COMMAND_LEFT:
			 printf("process_data : CAR_COMMAND_LEFT \r\n");
				car_control(CAR_DIR_LEFT,data[1]);

			break;
		case CAR_COMMAND_RIGHT:
			 printf("process_data : CAR_COMMAND_RIGHT \r\n");
				car_control(CAR_DIR_RIGHT,data[1]);

			break;
		default:
			break;
	}
}
