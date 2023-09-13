#ifndef __ULTRASONIC_H
#define __ULTRASONIC_H
#include "main.h"
#include "stdbool.h"
#include "stdio.h"
typedef enum
{
    ULTRASONIC_IDLE_STATE,
    ULTRASONIC_GEN_PULSE_STATE,
    ULTRASONIC_START_STATE,
    ULTRASONIC_DONE_STATE,
}ULTRASONIC_State_t;

typedef struct
{
	TIM_HandleTypeDef *htim;
	GPIO_TypeDef *GPIOx_Trigger;
	uint16_t GPIO_Pin_Trigger;
	GPIO_TypeDef *GPIOx_Echo;
  uint16_t GPIO_Pin_Echo;
	float distance;
	ULTRASONIC_State_t ULTRA_state;
	bool ULTRA_error;
	uint32_t time_start;
  uint32_t time_loop;
}Ultrasonic_t;
void Ultra_init(Ultrasonic_t *Ultrasonic, TIM_HandleTypeDef *htim, 
                                         GPIO_TypeDef *_GPIOx_Trigger,uint16_t _GPIO_Pin_Trigger,
                                         GPIO_TypeDef *_GPIOx_Echo,uint16_t    _GPIO_Pin_Echo);
void Ultrasonic_Ext_isr(Ultrasonic_t *Ultrasonic, uint16_t pin);
void Ultra_handle(Ultrasonic_t *Ultrasonic);
#endif
