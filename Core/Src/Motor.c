#include "Motor.h"
#include "stdio.h"
void motor_init(Motor_t *motor,
                TIM_HandleTypeDef *htim,
                uint32_t Channel,
                GPIO_TypeDef * GPIOx,
                uint16_t GPIO_Pin)
{
    motor->htim = htim;
    motor->Channel = Channel;
    motor->GPIO_Pin = GPIO_Pin;
    motor->GPIOx = GPIOx;
    motor->speed = 0;
    motor->dir = MOTOR_DIR_CW;
    HAL_TIM_PWM_Start(htim, Channel);
}
void motor_control(Motor_t *motor, uint8_t dir, uint8_t speed)
{
    printf("htim1.Instance->ARR = %u\r\n", motor->htim->Instance->ARR);
    motor->speed = speed;
    motor->dir = dir;
    uint16_t ccr = speed * (motor->htim->Instance->ARR) / 100;
	switch (dir)
	{
		case MOTOR_DIR_CW:
			__HAL_TIM_SetCompare(motor->htim, motor->Channel, ccr);
			HAL_GPIO_WritePin(motor->GPIOx, motor->GPIO_Pin, GPIO_PIN_RESET);
			break;
		case MOTOR_DIR_CCW:
			__HAL_TIM_SetCompare(motor->htim,  motor->Channel, motor->htim->Instance->ARR - ccr);
			HAL_GPIO_WritePin(motor->GPIOx, motor->GPIO_Pin, GPIO_PIN_SET);
			break;
	}
}
