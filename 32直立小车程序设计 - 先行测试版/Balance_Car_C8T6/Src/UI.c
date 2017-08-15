#include "UI.h"



/*----------------------------------------------------------------------------------*/
/*--------------------------------------主菜单---------------------------------------*/
/*----------------------------------------------------------------------------------*/
uint8_t Main_UI_Con(void)
{
	uint8_t UI_Case = 1;
	
	OLED_ShowString_Toggle(0,  0, "         MAIN        ", 12);
	OLED_ShowString_Normal(0, 13, "         1111        ", 12);
	OLED_ShowString_Normal(0, 26, "         Plan        ", 12);
	OLED_ShowString_Normal(0, 39, "         Device      ", 12);
	OLED_ShowString_Normal(0, 52, "         4444        ", 12);
	
	while (1)
	{
		uint8_t Case_Temp = UI_Case;
		Get_Key();
		switch (Key_Press)
		{
			case	Press_Up:	
							{
								if(--UI_Case < 1)
									UI_Case = 4;
								Key_Press = 0;
								break;
							}
							
			case Press_Down:
							{
								if(++UI_Case > 4)
									UI_Case = 1;
								Key_Press = 0;
								break;
							}
							
			case Press_Mid:
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
							
			case Press_Left:
							{
								break;
							}
							
			case Press_Right:
							{
								break;
							}
			
			default:						break;
		}
		if(Case_Temp != UI_Case)
		{
			OLED_ShowString_Toggle(0,  0, "         MAIN        ", 12);
			OLED_ShowString_Normal(0, 13, "         1111        ", 12);
			OLED_ShowString_Normal(0, 26, "         Plan        ", 12);
			OLED_ShowString_Normal(0, 39, "         Device      ", 12);
			OLED_ShowString_Normal(0, 52, "         4444        ", 12);
		}
		switch (UI_Case)
		{
			case 1:	//菜单1
					{
						OLED_ShowString_Normal(0, 13, "       >  1111       ", 12);
						OLED_ShowChar(38,13,'>',12,1);
						break;
					}
			case 2: //菜单2
					{
						OLED_ShowString_Normal(0, 26, "       >  Plan       ", 12);
						OLED_ShowChar(38,26,'>',12,1);
						break;
					}
			case 3: //菜单3
					{
						OLED_ShowString_Normal(0, 39, "       >  Device       ", 12);
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
/*----------------------------------------------------------------------------------*/
/*--------------------------------------菜单1---------------------------------------*/
/*----------------------------------------------------------------------------------*/
uint8_t Fun1_UI_Con(void)
{
	uint8_t UI_Case = 1;
	
	OLED_ShowString_Toggle(0,  0, "         1111        ", 12);
	OLED_ShowString_Normal(0, 13, "         1111        ", 12);
	OLED_ShowString_Normal(0, 26, "         2222        ", 12);
	OLED_ShowString_Normal(0, 39, "         3333        ", 12);
	OLED_ShowString_Normal(0, 52, "         4444        ", 12);
	
	while (1)
	{
		uint8_t Case_Temp = UI_Case;
		Get_Key();
		switch (Key_Press)
		{
			case	Press_Up:	
							{
								if(--UI_Case < 1)
									UI_Case = 4;
								Key_Press = 0;
								break;
							}
							
			case Press_Down:
							{
								if(++UI_Case > 4)
									UI_Case = 1;
								Key_Press = 0;
								break;
							}
							
			case Press_Mid:
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
							
			case Press_Left:
							{
								return 0;
							}
							
			case Press_Right:
							{
								break;
							}
			
			default:						break;
		}
		if(Case_Temp != UI_Case)
		{
			OLED_ShowString_Toggle(0,  0, "         1111        ", 12);
			OLED_ShowString_Normal(0, 13, "         1111        ", 12);
			OLED_ShowString_Normal(0, 26, "         2222        ", 12);
			OLED_ShowString_Normal(0, 39, "         3333      ", 12);
			OLED_ShowString_Normal(0, 52, "         4444        ", 12);
		}
		switch (UI_Case)
		{
			case 1:	//菜单1
					{
						OLED_ShowString_Normal(0, 13, "       >  1111       ", 12);
						OLED_ShowChar(38,13,'>',12,1);
						break;
					}
			case 2: //菜单2
					{
						OLED_ShowString_Normal(0, 26, "       >  2222       ", 12);
						OLED_ShowChar(38,26,'>',12,1);
						break;
					}
			case 3: //菜单3
					{
						OLED_ShowString_Normal(0, 39, "       >  3333       ", 12);
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
/*----------------------------------------------------------------------------------*/
/*--------------------------------------菜单2---------------------------------------*/
/*----------------------------------------------------------------------------------*/
uint8_t Fun2_UI_Con(void)
{
	uint8_t UI_Case = 1;
	
	OLED_ShowString_Toggle(0,  0, "         Plan        ", 12);
	OLED_ShowString_Normal(0, 13, "         1111        ", 12);
	OLED_ShowString_Normal(0, 26, "         2222        ", 12);
	OLED_ShowString_Normal(0, 39, "         3333        ", 12);
	OLED_ShowString_Normal(0, 52, "         4444        ", 12);
	
	while (1)
	{
		uint8_t Case_Temp = UI_Case;
		Get_Key();
		switch (Key_Press)
		{
			case	Press_Up:	
							{
								if(--UI_Case < 1)
									UI_Case = 4;
								Key_Press = 0;
								break;
							}
							
			case Press_Down:
							{
								if(++UI_Case > 4)
									UI_Case = 1;
								Key_Press = 0;
								break;
							}
							
			case Press_Mid:
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
							
			case Press_Left:
							{
								return 0;
							}
							
			case Press_Right:
							{
								break;
							}
			
			default:						break;
		}
		if(Case_Temp != UI_Case)
		{
			OLED_ShowString_Toggle(0,  0, "         Plan        ", 12);
			OLED_ShowString_Normal(0, 13, "         1111        ", 12);
			OLED_ShowString_Normal(0, 26, "         2222        ", 12);
			OLED_ShowString_Normal(0, 39, "         3333        ", 12);
			OLED_ShowString_Normal(0, 52, "         4444        ", 12);
		}
		switch (UI_Case)
		{
			case 1:	//菜单1
					{
						OLED_ShowString_Normal(0, 13, "       >  1111       ", 12);
						OLED_ShowChar(38,13,'>',12,1);
						break;
					}
			case 2: //菜单2
					{
						OLED_ShowString_Normal(0, 26, "       >  2222       ", 12);
						OLED_ShowChar(38,26,'>',12,1);
						break;
					}
			case 3: //菜单3
					{
						OLED_ShowString_Normal(0, 39, "       >  3333       ", 12);
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
/*----------------------------------------------------------------------------------*/
/*--------------------------------------菜单3---------------------------------------*/
/*----------------------------------------------------------------------------------*/
uint8_t Fun3_UI_Con(void)
{
	uint8_t UI_Case = 1;
	
	OLED_ShowString_Toggle(0,  0, "        Device       ", 12);
	OLED_ShowString_Normal(0, 13, "         1111        ", 12);
	OLED_ShowString_Normal(0, 26, "         2222        ", 12);
	OLED_ShowString_Normal(0, 39, "         3333        ", 12);
	OLED_ShowString_Normal(0, 52, "         4444        ", 12);
	
	while (1)
	{
		uint8_t Case_Temp = UI_Case;
		Get_Key();
		switch (Key_Press)
		{
			case	Press_Up:	
							{
								if(--UI_Case < 1)
									UI_Case = 4;
								Key_Press = 0;
								break;
							}
							
			case Press_Down:
							{
								if(++UI_Case > 4)
									UI_Case = 1;
								Key_Press = 0;
								break;
							}
							
			case Press_Mid:
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
							
			case Press_Left:
							{
								return 0;
							}
							
			case Press_Right:
							{
								break;
							}
			
			default:						break;
		}
		if(Case_Temp != UI_Case)
		{
			OLED_ShowString_Toggle(0,  0, "        Device       ", 12);
			OLED_ShowString_Normal(0, 13, "         1111        ", 12);
			OLED_ShowString_Normal(0, 26, "         2222        ", 12);
			OLED_ShowString_Normal(0, 39, "         3333        ", 12);
			OLED_ShowString_Normal(0, 52, "         4444        ", 12);
		}
		switch (UI_Case)
		{
			case 1:	//菜单1
					{
						OLED_ShowString_Normal(0, 13, "       >  1111       ", 12);
						OLED_ShowChar(38,13,'>',12,1);
						break;
					}
			case 2: //菜单2
					{
						OLED_ShowString_Normal(0, 26, "       >  2222       ", 12);
						OLED_ShowChar(38,26,'>',12,1);
						break;
					}
			case 3: //菜单3
					{
						OLED_ShowString_Normal(0, 39, "       >  3333       ", 12);
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
/*----------------------------------------------------------------------------------*/
/*--------------------------------------菜单4---------------------------------------*/
/*----------------------------------------------------------------------------------*/
uint8_t Fun4_UI_Con(void)
{
	uint8_t UI_Case = 1;
	
	OLED_ShowString_Toggle(0,  0, "         4444        ", 12);
	OLED_ShowString_Normal(0, 13, "         1111        ", 12);
	OLED_ShowString_Normal(0, 26, "         2222        ", 12);
	OLED_ShowString_Normal(0, 39, "         3333        ", 12);
	OLED_ShowString_Normal(0, 52, "         4444        ", 12);
	
	while (1)
	{
		uint8_t Case_Temp = UI_Case;
		Get_Key();
		switch (Key_Press)
		{
			case	Press_Up:	
							{
								if(--UI_Case < 1)
									UI_Case = 4;
								Key_Press = 0;
								break;
							}
							
			case Press_Down:
							{
								if(++UI_Case > 4)
									UI_Case = 1;
								Key_Press = 0;
								break;
							}
							
			case Press_Mid:
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
							
			case Press_Left:
							{
								return 0;
							}
							
			case Press_Right:
							{
								break;
							}
			
			default:						break;
		}
		if(Case_Temp != UI_Case)
		{
			OLED_ShowString_Toggle(0,  0, "         4444        ", 12);
			OLED_ShowString_Normal(0, 13, "         1111        ", 12);
			OLED_ShowString_Normal(0, 26, "         2222        ", 12);
			OLED_ShowString_Normal(0, 39, "         3333      ", 12);
			OLED_ShowString_Normal(0, 52, "         4444        ", 12);
		}
		switch (UI_Case)
		{
			case 1:	//菜单1
					{
						OLED_ShowString_Normal(0, 13, "      =>  1111       ", 12);
						break;
					}
			case 2: //菜单2
					{
						OLED_ShowString_Normal(0, 26, "      =>  2222       ", 12);
						break;
					}
			case 3: //菜单3
					{
						OLED_ShowString_Normal(0, 39, "      =>  3333       ", 12);
						break;
					}
			case 4: //菜单4
					{
						OLED_ShowString_Normal(0, 52, "      =>  4444       ", 12);
						break;
					}
			
			default:		break;
		}
		OLED_Refresh_Gram();
	}
}