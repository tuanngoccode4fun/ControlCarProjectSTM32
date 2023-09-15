#include "Car.h"
#include "Motor.h"
#include "main.h"
extern TIM_HandleTypeDef htim1;
Motor_t motor_left;
Motor_t motor_right;

void car_init()
{
  motor_init(&motor_left,
			 &htim1,
			 TIM_CHANNEL_1,
			 GPIOA,
			 GPIO_PIN_10
			 );
  motor_init(&motor_right,
			 &htim1,
			 TIM_CHANNEL_2,
			 GPIOA,
			 GPIO_PIN_11
			 );
}
void car_control(uint8_t dir, uint8_t speed)
{
	switch (dir) {
		case CAR_DIR_FORDWARD:
			motor_control(&motor_left, MOTOR_DIR_CCW, speed);
			motor_control(&motor_right, MOTOR_DIR_CCW, speed);
			break;
		case CAR_DIR_BACKWARD:
			motor_control(&motor_left, MOTOR_DIR_CW, speed);
			motor_control(&motor_right, MOTOR_DIR_CW, speed);
			break;
		case CAR_DIR_LEFT:
			motor_control(&motor_left, MOTOR_DIR_CCW, speed);
			motor_control(&motor_right, MOTOR_DIR_CCW, 0);
			break;
		case CAR_DIR_RIGHT:
			motor_control(&motor_left, MOTOR_DIR_CCW, 0);
			motor_control(&motor_right, MOTOR_DIR_CCW, speed);
			break;
		default:
			break;
	}
}
