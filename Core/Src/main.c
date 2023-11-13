#include "main.h"
#include "stm32f407xx.h"
#include "bsp.h"



int main(void)
{

	BSP_SysInit();

	while(1)
	{
		BSP_LED_SET(LD4 | LD3 | LD5 | LD6);

		BSP_delay(100U);

		BSP_LED_RESET(LD4 | LD3 | LD5 | LD6);

		BSP_delay(100U);

	}
	
}
