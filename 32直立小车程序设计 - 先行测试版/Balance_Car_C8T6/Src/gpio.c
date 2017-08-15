/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
uint8_t Key_Press = 0;
/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|OLED_D1_Pin|OLED_RST_Pin|OLED_DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RGB_1_Pin|RGB_2_Pin|RGB_3_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OLED_D0_GPIO_Port, OLED_D0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = KEY_Right_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY_Right_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB2 PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = GPIO_PIN_2|OLED_D1_Pin|OLED_RST_Pin|OLED_DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = RGB_1_Pin|RGB_2_Pin|RGB_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = OLED_D0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OLED_D0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = KEY_Up_Pin|KEY_Down_Pin|KEY_Mid_Pin|KEY_Left_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
/*************************************************************************
*函 数 名：Get_Key()
*函数功能：按键检测，识别哪个按键被按下
*入口参数：无
*返 回 值：无
*作    者：康滢
*时    间：2017.7.23
*备    注：无传入参数，但在之前要定义一个全局变量Key_Press，用于标记是哪个
					 按键被按下，并在每次进入该函数时，该标记都会清零。
**************************************************************************/
void Get_Key(void)
{
	Key_Press = 0;
	
	if(0 == HAL_GPIO_ReadPin(KEY_Up_GPIO_Port, KEY_Up_Pin))
	{
		HAL_Delay(70);
		if(0 == HAL_GPIO_ReadPin(KEY_Up_GPIO_Port, KEY_Up_Pin))
		{
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_SET);
			Key_Press = Press_Up;
		}

		return;
	}
	
	else if(0 == HAL_GPIO_ReadPin(KEY_Down_GPIO_Port, KEY_Down_Pin))
	{
		HAL_Delay(70);
		if(0 == HAL_GPIO_ReadPin(KEY_Down_GPIO_Port, KEY_Down_Pin))
		{
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_SET);
			Key_Press = Press_Down;
		}
		return;
	}
	
	else if(0 == HAL_GPIO_ReadPin(KEY_Mid_GPIO_Port, KEY_Mid_Pin))
	{
		HAL_Delay(70);
		if(0 == HAL_GPIO_ReadPin(KEY_Mid_GPIO_Port, KEY_Mid_Pin))
		{
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_SET);
			Key_Press = Press_Mid;
		}
		return;
	}
	
	else if(0 == HAL_GPIO_ReadPin(KEY_Left_GPIO_Port, KEY_Left_Pin))
	{
		HAL_Delay(70);
		if(0 == HAL_GPIO_ReadPin(KEY_Left_GPIO_Port, KEY_Left_Pin))
		{
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_SET);
			Key_Press = Press_Left;
		}
		return;
	}
	
	else if(0 == HAL_GPIO_ReadPin(KEY_Right_GPIO_Port, KEY_Right_Pin))
	{
		HAL_Delay(70);
		if(0 == HAL_GPIO_ReadPin(KEY_Right_GPIO_Port, KEY_Right_Pin))
		{
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(RGB_1_GPIO_Port, RGB_1_Pin, GPIO_PIN_SET);
			Key_Press = Press_Right;
		}
		return;
	}
	
}
/* USER CODE END 2 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
