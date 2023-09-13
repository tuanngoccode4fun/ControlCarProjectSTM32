#include "Ultrasonic.h"
static void Ultrasonic_start(Ultrasonic_t *Ultrasonic);
__weak void Ultrasonic_complete_callback(Ultrasonic_t *Ultrasonic)
{
	
}

/// @brief This function you must use in this file.
/// @param Ultrasonic 
static void Ultrasonic_start(Ultrasonic_t *Ultrasonic)
{
    if(Ultrasonic->ULTRA_state == ULTRASONIC_IDLE_STATE)
    {
     // my_printf("pin = %d \r\n",Ultrasonic->GPIO_Pin_Trigger );
      HAL_GPIO_WritePin(Ultrasonic->GPIOx_Trigger, Ultrasonic->GPIO_Pin_Trigger, GPIO_PIN_SET);
      Ultrasonic->ULTRA_state = ULTRASONIC_GEN_PULSE_STATE;
      Ultrasonic->time_start =  HAL_GetTick();
    }
}
/// @brief We will take this function in interrupt call back.
/// @param Ultrasonic 
/// @param pin 
void Ultrasonic_Ext_isr(Ultrasonic_t *Ultrasonic, uint16_t pin)
{
  if(Ultrasonic->ULTRA_state == ULTRASONIC_START_STATE)
  {
       if(pin == Ultrasonic->GPIO_Pin_Echo)
      {
            if(HAL_GPIO_ReadPin(Ultrasonic->GPIOx_Echo, Ultrasonic->GPIO_Pin_Echo) == 1) // Rising interrupt
            {
                //Set CNT
                Ultrasonic->htim->Instance->CNT = 0;
                HAL_TIM_Base_Start(Ultrasonic->htim);
            }
            else // Falling interrupt
            {
                Ultrasonic->distance = 0.017*Ultrasonic->htim->Instance->CNT;// S = v*t = v*T/2= 340 (van toc anh sang)*100/10^6*(T/2) = 0.017*T(cm)
                HAL_TIM_Base_Stop(Ultrasonic->htim);
                Ultrasonic->ULTRA_state = ULTRASONIC_DONE_STATE;
                Ultrasonic_complete_callback(Ultrasonic);
            }
        }
  }

}
/// @brief We will take this function in while(1)
/// @param Ultrasonic 
void Ultra_handle(Ultrasonic_t *Ultrasonic)
{
    switch (Ultrasonic->ULTRA_state)
    {
    case ULTRASONIC_IDLE_STATE:
			if(HAL_GetTick() - Ultrasonic->time_loop >=100)
			{
					Ultrasonic_start(Ultrasonic);
					Ultrasonic->time_loop = HAL_GetTick();
			}
      break;
     case ULTRASONIC_GEN_PULSE_STATE:
      if(HAL_GetTick() - Ultrasonic->time_start >1)
      {
            HAL_GPIO_WritePin(Ultrasonic->GPIOx_Trigger, Ultrasonic->GPIO_Pin_Trigger, GPIO_PIN_RESET);
            Ultrasonic->time_start =  HAL_GetTick();
            Ultrasonic->ULTRA_state = ULTRASONIC_START_STATE;
      }
     break; 
    case ULTRASONIC_START_STATE:
      /* code */
      if(HAL_GetTick() - Ultrasonic->time_start >1000)
      {
        printf("Your sensor is broken.... \r\n");
        Ultrasonic->ULTRA_state = ULTRASONIC_IDLE_STATE;
        Ultrasonic->ULTRA_error =true;
      }
    break;
    case ULTRASONIC_DONE_STATE:
      /* code */
      Ultrasonic->ULTRA_error =false;
       Ultrasonic->ULTRA_state = ULTRASONIC_IDLE_STATE;
    break;
    
    default:
      break;
    }
}
/// @brief This is the function we have to init all value.
/// @param Ultrasonic 
/// @param htim 
/// @param _GPIOx_Trigger 
/// @param _GPIO_Pin_Trigger 
/// @param _GPIOx_Echo 
/// @param _GPIO_Pin_Echo 
void Ultra_init(Ultrasonic_t *Ultrasonic, TIM_HandleTypeDef *htim, GPIO_TypeDef *_GPIOx_Trigger,uint16_t _GPIO_Pin_Trigger,GPIO_TypeDef *_GPIOx_Echo,uint16_t _GPIO_Pin_Echo)
{
    Ultrasonic->htim =htim;
    Ultrasonic->GPIOx_Trigger = _GPIOx_Trigger;
    Ultrasonic->GPIO_Pin_Trigger = _GPIO_Pin_Trigger;
    Ultrasonic->GPIOx_Echo= _GPIOx_Echo;
    Ultrasonic->GPIO_Pin_Echo = _GPIO_Pin_Echo;
    Ultrasonic->distance = 0;
    Ultrasonic->time_start =0;
    Ultrasonic->time_loop =0;
    Ultrasonic->ULTRA_state = ULTRASONIC_IDLE_STATE;
    Ultrasonic->ULTRA_error = false;	  
}
