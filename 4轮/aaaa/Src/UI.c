#include "UI.h"

uint8_t Main_UI_Con(void)
{
			PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
			PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, 0);
			PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, 0);
			PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
			
			uint8_t UI_Case = 1;
			
			OLED_Clear();
			OLED_ShowString_Toggle(0,  0, "         MAIN        ", 12);
			OLED_ShowString_Normal(0, 13, "         GO          ", 12);
			OLED_ShowString_Normal(0, 26, "         MT-C        ", 12);
			OLED_ShowString_Normal(0, 39, "         DJ-C        ", 12);
			OLED_ShowString_Normal(0, 52, "         4444        ", 12);
			while (1)
			{
				uint8_t Case_Temp = UI_Case;
				Get_Key();
				switch (Key_Press)
				{
					case	KEY_U:	
									{
										if(--UI_Case < 1)
											UI_Case = 4;
										Key_Press = 0;
										break;
									}
									
					case KEY_D:
									{
										if(++UI_Case > 4)
											UI_Case = 1;
										Key_Press = 0;
										break;
									}
									
					case KEY_M:
									{
										switch(UI_Case)
										{
											case 1:		return 1;
											case 2:		return 2;
											case 3:		return 3;
											case 4:		return 4;

											default:	return 0;
										}
									}
									
					case KEY_L:
									{
										break;
									}
									
					case KEY_R:
									{
										break;
									}
					
					default:						break;
				}
				if(Case_Temp != UI_Case)
				{
					OLED_ShowString_Toggle(0,  0, "         MAIN        ", 12);
					OLED_ShowString_Normal(0, 13, "         GO          ", 12);
					OLED_ShowString_Normal(0, 26, "         MT-C        ", 12);
					OLED_ShowString_Normal(0, 39, "         DJ-C        ", 12);
					OLED_ShowString_Normal(0, 52, "         4444        ", 12);
				}
				switch (UI_Case)
				{
					case 1:	//菜单1
							{
								OLED_ShowString_Normal(0, 13, "       >  GO         ", 12);
								OLED_ShowChar(38,13,'>',12,1);
								break;
							}
					case 2: //菜单2
							{
								OLED_ShowString_Normal(0, 26, "       >  MT-C       ", 12);
								OLED_ShowChar(38,26,'>',12,1);
								break;
							}
					case 3: //菜单3
							{
								OLED_ShowString_Normal(0, 39, "       >  DJ-C       ", 12);
								OLED_ShowChar(38,39,'>',12,1);
								break;
							}
					case 4: //菜单4
							{
								OLED_ShowString_Normal(0, 52, "       >  4444       ", 12);
								OLED_ShowChar(38,52,'>',12,1);
								break;
							}
					
					default:		break;
				}
				OLED_Refresh_Gram();
			}
}
uint8_t Fun1_UI_Con(void)
{
	uint8_t time = 2;
	for(uint8_t i=time; i!=0; i--)
	{
		OLED_Clear();
		OLED_ShowNum(20, 20, i, 1, 24);
		OLED_Refresh_Gram();
		
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		HAL_Delay(50);
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		HAL_Delay(950);
	}
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
	
	uint8_t Turn = 5;
	while(1)
	{
		uint8_t Turn_Lost = 3;
		Get_Key();
		switch (Key_Press)
		{
			case	KEY_U:	return 0;
			case	KEY_D:	return 0;
			case	KEY_M:	break;
			case	KEY_L:	return 0;
			case	KEY_R:	return 0;
		}
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 10000);
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, 10000);
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, 10000);
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 10000);
		
		switch(((uint16_t)GPIOC->IDR&0x1F))
		{
			case 27://11011
								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji);//10
								
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, PWM_MOTOR_L);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, PWM_MOTOR_R);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
								Turn = 3;
								break;
			case 25:	case 29: //11001 11101
								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji-80);//10
								
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, PWM_MOTOR_L*0.9);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, PWM_MOTOR_R*1.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
								Turn = 2;
								break;
			case 19:	case 23:	//10011 10111
								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji+80);//2
								
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, (int)PWM_MOTOR_L*1.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, (int)PWM_MOTOR_R*0.9);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
								Turn = 4;
								break;
			case 30:	case 28:	case 24:
								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji-120);//2
								
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, (int)PWM_MOTOR_L*0.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, (int)PWM_MOTOR_R*1.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
								Turn = 1;
								break;
			case 15:	case 7:	case 3:
								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji+120);//2
								
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, (int)PWM_MOTOR_L*1.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, (int)PWM_MOTOR_R*0.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
								Turn = 5;
								break;
			case 31://11111丢线
								if(Turn == 1)
								{
								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji-120);//2
								
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, (int)PWM_MOTOR_L*0.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, (int)PWM_MOTOR_R*1.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
								Turn_Lost = 1;
								}
								else if(Turn == 5)
								{
								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji+120);//2
								
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, (int)PWM_MOTOR_L*1.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, (int)PWM_MOTOR_R*0.8);
								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
								Turn_Lost = 5;
								}
//								else
//								{
//								PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, 870);//2
//								
//								PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, 0);
//								PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, (int)PWM_MOTOR_L*1.8);
//								PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, (int)PWM_MOTOR_R*0.8);
//								PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, 0);
//								}
								break;
		}
		OLED_Clear();
		switch(Turn)
		{
			case 1:
						OLED_ShowString_Normal(0,  0, "  ********        ", 12);
						OLED_ShowString_Normal(0, 13, "  ********        ", 12);
						OLED_ShowString_Normal(0, 26, "        **        ", 12);
						OLED_ShowString_Normal(0, 39, "        **        ", 12);
						OLED_ShowString_Normal(0, 52, "        **        ", 12);
						if(Turn_Lost == 1)
							OLED_ShowString_Normal(0, 38, " ??", 24);
						break;
			case 2:
						OLED_ShowString_Normal(0,  0, "      **          ", 12);
						OLED_ShowString_Normal(0, 13, "       **         ", 12);
						OLED_ShowString_Normal(0, 26, "        **        ", 12);
						OLED_ShowString_Normal(0, 39, "        **        ", 12);
						OLED_ShowString_Normal(0, 52, "        **        ", 12);
						break;
			case 3:
						OLED_ShowString_Normal(0,  0, "        **        ", 12);
						OLED_ShowString_Normal(0, 13, "        **        ", 12);
						OLED_ShowString_Normal(0, 26, "        **        ", 12);
						OLED_ShowString_Normal(0, 39, "        **        ", 12);
						OLED_ShowString_Normal(0, 52, "        **        ", 12);
						break;
			case 4:
						OLED_ShowString_Normal(0,  0, "          **      ", 12);
						OLED_ShowString_Normal(0, 13, "         **       ", 12);
						OLED_ShowString_Normal(0, 26, "        **        ", 12);
						OLED_ShowString_Normal(0, 39, "        **        ", 12);
						OLED_ShowString_Normal(0, 52, "        **        ", 12);
						break;
			case 5:
						OLED_ShowString_Normal(0,  0, "        ********  ", 12);
						OLED_ShowString_Normal(0, 13, "        ********  ", 12);
						OLED_ShowString_Normal(0, 26, "        **        ", 12);
						OLED_ShowString_Normal(0, 39, "        **        ", 12);
						OLED_ShowString_Normal(0, 52, "        **        ", 12);
						if(Turn_Lost == 5)
							OLED_ShowString_Normal(72, 38, "??", 24);
						break;
		}
		OLED_Refresh_Gram();
	}
}

uint8_t Fun2_UI_Con(void)
{
	int8_t UI_Case = 1;
	
	OLED_Clear();
	OLED_ShowString_Normal( 0, 20, "L:99", 24);
	OLED_ShowString_Normal(65, 20, "R:99", 24);
	while(1)
	{	
		int8_t Case_Temp = UI_Case;
		Get_Key();
				switch (Key_Press)
				{
					case	KEY_U:	
									{
										switch(UI_Case)
										{
											case  1: UI_Case = 2; break;
											case  2: UI_Case = 1; break;
											case 12: UI_Case = 1; break;
										}
										break;
									}
									
					case KEY_D:
									{
										switch(UI_Case)
										{
											case  1: UI_Case = 2; break;
											case  2: UI_Case = 1; break;
											case 12: UI_Case = 1; break;
										}
										break;
									}
									
					case KEY_M:
									{
										switch(UI_Case)
										{
											case 1:		return 0;//回主菜单
											case 2:		
											{
												uint8_t ch[20] = "";
												sprintf(ch, "%2d", (int)PWM_MOTOR_L/100);
												OLED_ShowString_Toggle(24, 20, ch, 24);
												
												uint32_t temp_PWM = PWM_MOTOR_L;
												uint8_t value_ok_flag = 0;
												while(1)
												{
													Get_Key();
													switch(Key_Press)
													{
														case KEY_U:	
																				temp_PWM = temp_PWM==9900?9800:temp_PWM;
																				temp_PWM += 100;
																				sprintf(ch, "%2d", (int)temp_PWM/100);
																				OLED_ShowString_Toggle(24, 20, ch, 24);
																				break;
														
														case KEY_D:	
																				temp_PWM = temp_PWM==100?200:temp_PWM;
																				temp_PWM -= 100;

																				sprintf(ch, "%2d", (int)temp_PWM/100);
																				OLED_ShowString_Toggle(24, 20, ch, 24);
																				break;
														
														case KEY_M: PWM_MOTOR_L = temp_PWM;
																				value_ok_flag = 1;
																				break;
														
														default : 											break;
													}
													if(value_ok_flag == 1)
													{
														sprintf(ch, "%2d", (int)PWM_MOTOR_L/100);
														OLED_ShowString_Normal(24, 20, ch, 24);
														break;//结束选修改while
													}
														
													OLED_Refresh_Gram();
												}
												break;//结束选值switch
											}
											case 12:
											{
												uint8_t ch[20] = "";
												sprintf(ch, "%2d", (int)PWM_MOTOR_R/100);
												OLED_ShowString_Toggle(89, 20, ch, 24);
												
												uint32_t temp_PWM = PWM_MOTOR_R;
												uint8_t value_ok_flag = 0;
												while(1)
												{
													Get_Key();
													switch(Key_Press)
													{
														case KEY_U:	temp_PWM += 100;
																				temp_PWM = temp_PWM==10000?9900:temp_PWM;
																				sprintf(ch, "%2d", (int)temp_PWM/100);
																				OLED_ShowString_Toggle(89, 20, ch, 24);
																				break;
														
														case KEY_D:	temp_PWM -= 100;
																				temp_PWM = temp_PWM==0?100:temp_PWM;
																				sprintf(ch, "%2d", (int)temp_PWM/100);
																				OLED_ShowString_Toggle(89, 20, ch, 24);
																				break;
														
														case KEY_M: PWM_MOTOR_R = temp_PWM;
																				value_ok_flag = 1;
																				break;
														
														default : 											break;
													}
													if(value_ok_flag == 1)
													{
														sprintf(ch, "%2d", (int)PWM_MOTOR_R/100);
														OLED_ShowString_Normal(89, 20, ch, 24);
														break;//结束选修改while
													}
														
													OLED_Refresh_Gram();
												}
											break;//结束选修switch
											}
											default:		break;
										}
										break;//结束选完值后的switch按键检测
									}
									
					case KEY_L:
									{
										switch(UI_Case)
										{
											case  2: UI_Case = 12; break;
											case 12: UI_Case = 2;  break;
										}
										break;
									}
									
					case KEY_R:
									{
										switch(UI_Case)
										{
											case  2: UI_Case = 12; break;
											case 12: UI_Case = 2;  break;
										}
										break;
									}
					
					default:						break;
				}
				if(Case_Temp != UI_Case)
				{
					OLED_Fill(0, 13, 36, 13, 0);
					OLED_Fill(24, 44, 48, 44, 0);
					OLED_Fill(89, 44, 113, 44, 0);
				}
				{
					uint8_t ch[20] = "";
					sprintf(ch, "%2d", (int)PWM_MOTOR_L/100);
					OLED_ShowString_Normal(24, 20, ch, 24);
					sprintf(ch, "%2d", (int)PWM_MOTOR_R/100);
					OLED_ShowString_Normal(89, 20, ch, 24);
				}
				switch (UI_Case)
				{
					case 1:	//菜单1
							{
								OLED_ShowString_Normal( 0, 0, "< BACK", 12);
								OLED_Fill(0, 13, 36, 13, 1);
								break;
							}
					case 2: //菜单2
							{
								OLED_Fill(24, 44, 48, 44, 1);
								break;
							}
					case 12: //菜单3
							{
								OLED_Fill(89, 44, 113, 44, 1);
								break;
							}
					
					default:		break;
				}
		OLED_Refresh_Gram();
				
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_1, PWM_MOTOR_L);
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_2, PWM_MOTOR_L);
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_3, PWM_MOTOR_R);
//		PWM_Ratio_Set(&htim1, TIM_CHANNEL_4, PWM_MOTOR_R);
	}
}
uint8_t Fun3_UI_Con(void)
{
	int8_t UI_Case = 1;
	
	OLED_Clear();
	OLED_ShowString_Normal(37, 20, "T: ", 24);
	
	while(1)
	{	
		int8_t Case_Temp = UI_Case;
		Get_Key();
		uint8_t turn;
		
		switch(PWM_Duoji)
		{
			case 600:	turn =  0;	break;
			case 615:	turn =  1;	break;
			case 630:	turn =  2;	break;
			case 645:	turn =  3;	break;
			case 660:	turn =  4;	break;
			case 675:	turn =  5;	break;
			case 690:	turn =  6;	break;
			case 705:	turn =  7;	break;
			case 720:	turn =  8;	break;
			case 735:	turn =  9;	break;
			case 750:	turn = 10;	break;
			case 765:	turn = 11;	break;
			case 780:	turn = 12;	break;
			case 795:	turn = 13;	break;
			case 810:	turn = 14;	break;
			case 825:	turn = 15;	break;
			case 840:	turn = 16;	break;
			case 855:	turn = 17;	break;
			case 870:	turn = 18;	break;
			case 885:	turn = 19;	break;
			case 900:	turn = 20;	break;
		}
		uint8_t ch[20] = "";
		sprintf(ch, "%2d", turn);
		OLED_ShowString_Normal(60, 20, ch, 24);
		
		switch (Key_Press)
		{
			case	KEY_U:	
									switch(UI_Case)
									{
										case 1:	UI_Case = 2;	break;
										case 2: UI_Case = 1;	break;
									}
									break;
			case KEY_D:
									switch(UI_Case )
									{
										case 1:	UI_Case = 2;	break;
										case 2: UI_Case = 1;	break;
									}
									break;
			case KEY_M:
									switch(UI_Case)
									{
										case 1:		return 0;//回主菜单
										case 2:		
										{
											
												int8_t temp_turn = turn;
												uint8_t value_ok_flag = 0;
											
												sprintf(ch, "%2d", turn);
												OLED_ShowString_Toggle(60, 20, ch, 24);
											
												while(1)
												{
													Get_Key();
													switch(Key_Press)
													{
														case KEY_U:	
																				temp_turn = temp_turn>=20?19:temp_turn;
																				temp_turn ++;
																				
																				sprintf(ch, "%2d", temp_turn);
																				OLED_ShowString_Toggle(60, 20, ch, 24);

																				break;
														
														case KEY_D:	
																				temp_turn = temp_turn==0?1:temp_turn;
																				temp_turn --;
																				
																				sprintf(ch, "%2d", temp_turn);
																				OLED_ShowString_Toggle(60, 20, ch, 24);

																				break;
														
														case KEY_M: turn = temp_turn;
																				switch(turn)
																				{
																					case  0:	PWM_Duoji = 600;	break;
																					case  1:	PWM_Duoji = 615;	break;
																					case  2:	PWM_Duoji = 630;	break;
																					case  3:	PWM_Duoji = 645;	break;
																					case  4:	PWM_Duoji = 660;	break;
																					case  5:	PWM_Duoji = 675;	break;
																					case  6:	PWM_Duoji = 690;	break;
																					case  7:	PWM_Duoji = 705;	break;
																					case  8:	PWM_Duoji = 720;	break;
																					case  9:	PWM_Duoji = 735;	break;
																					case 10:	PWM_Duoji = 750;	break;
																					case 11:	PWM_Duoji = 765;	break;
																					case 12:	PWM_Duoji = 780;	break;
																					case 13:	PWM_Duoji = 795;	break;
																					case 14:	PWM_Duoji = 810;	break;
																					case 15:	PWM_Duoji = 825;	break;
																					case 16:	PWM_Duoji = 840;	break;
																					case 17:	PWM_Duoji = 855;	break;
																					case 18:	PWM_Duoji = 870;	break;
																					case 19:	PWM_Duoji = 885;	break;
																					case 20:	PWM_Duoji = 900;	break;
																				}
																				value_ok_flag = 1;
																				break;
														
														default : 											break;
													}
													if(value_ok_flag == 1)
													{
														sprintf(ch, "%2d", turn);
														OLED_ShowString_Toggle(60, 20, ch, 24);

														break;//结束选修改while
													}
														
													OLED_Refresh_Gram();
												}
												break;//结束选值switch
											}
									
									}
		}
		if(Case_Temp != UI_Case)
		{
			OLED_Fill(0, 13, 36, 13, 0);
			OLED_Fill(60, 44, 82, 44, 0);
		}

		switch (UI_Case)
		{
			case 1:	//菜单1
					{
						OLED_ShowString_Normal( 0, 0, "< BACK", 12);
						OLED_Fill(0, 13, 36, 13, 1);
						break;
					}
			case 2: //菜单2
					{
						OLED_Fill(60, 43, 82, 43, 1);
						break;
					}
			
			default:		break;
		}
		OLED_Refresh_Gram();

		PWM_Ratio_Set(&htim3, TIM_CHANNEL_1, PWM_Duoji);
	}
}
uint8_t Fun4_UI_Con(void)
{
	
}
