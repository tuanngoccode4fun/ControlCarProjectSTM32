#ifndef __MOTOR_H_
#define __MOTOR_H_
#include "main.h"
#define MOTOR_LEFT  1
#define MOTOR_RIGHT 2

#define MOTOR_DIR_CW 1
#define MOTOR_DIR_CCW 2
typedef struct 
{
	TIM_HandleTypeDef *htim;
	uint32_t Channel;
	GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
    uint8_t speed;
    uint8_t dir;
}Motor_t;
void motor_control(Motor_t *motor, uint8_t dir, uint8_t speed);
void motor_init(Motor_t *motor,
                TIM_HandleTypeDef *htim,
                uint32_t Channel,
                GPIO_TypeDef * GPIOx,
                uint16_t GPIO_Pin);
#endif
