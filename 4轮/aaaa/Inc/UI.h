#ifndef __UI_H
#define __UI_H

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "oled.h"
#include "tim.h"
	 
extern uint32_t PWM_MOTOR_L;
extern uint32_t PWM_MOTOR_R;
extern uint32_t PWM_Duoji;

uint8_t Main_UI_Con(void);
uint8_t Fun1_UI_Con(void);
uint8_t Fun2_UI_Con(void);
uint8_t Fun3_UI_Con(void);
uint8_t Fun4_UI_Con(void);
#endif
