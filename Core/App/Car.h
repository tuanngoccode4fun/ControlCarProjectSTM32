#ifndef __CAR_H_
#define __CAR_H_
#include "stdint.h"
#define CAR_DIR_FORDWARD 1
#define CAR_DIR_BACKWARD 2
#define CAR_DIR_LEFT	 3
#define CAR_DIR_RIGHT    4
void car_init();
void car_control(uint8_t dir, uint8_t speed);
#endif
