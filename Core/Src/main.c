#include "main.h"
#include "stm32f407xx.h"
#include "bsp.h"

uint32_t stack_blinky01[60] = {0};
uint32_t* sp_blinky01 = &stack_blinky01[60];

void main_blinky01(void)
{
	while (1)
	{
		BSP_LED_SET(LD4 | LD3);

		BSP_delay(100U);

		BSP_LED_RESET(LD4 | LD3);

		BSP_delay(100U);
	}
	
}

uint32_t stack_blinky02[60] = {0};
uint32_t* sp_blinky02 = &stack_blinky02[60];

void main_blinky02(void)
{
	while (1)
	{
		BSP_LED_SET(LD5 | LD6);

		BSP_delay(50U);

		BSP_LED_RESET(LD5 | LD6);

		BSP_delay(50U);
	}
	
}

int main(void)
{

	BSP_SysInit();

	*(--sp_blinky01) = 0x00000000U; // FPSCR
	*(--sp_blinky01) = 0x80003070U; // S15
	*(--sp_blinky01) = 0x00000000U; // S14
	*(--sp_blinky01) = 0x00000000U; // S13
	*(--sp_blinky01) = 0x00201700U; // S12
	*(--sp_blinky01) = 0xFF000020U; // S11
	*(--sp_blinky01) = 0x000000F0U; // S10
	*(--sp_blinky01) = 0x00000000U; // S9
	*(--sp_blinky01) = 0x00000000U; // S8
	*(--sp_blinky01) = 0x00000000U; // S7
	*(--sp_blinky01) = 0x00000000U; // S6
	*(--sp_blinky01) = 0x00000000U; // S5
	*(--sp_blinky01) = 0x00000000U; // S4
	*(--sp_blinky01) = 0x00000000U; // S3
	*(--sp_blinky01) = 0x00000000U; // S2
	*(--sp_blinky01) = 0x00000000U; // S1
	*(--sp_blinky01) = 0x00000000U; // S0
	*(--sp_blinky01) = (1U << 24U); // xPSR -> Thumb mode for function entery
	*(--sp_blinky01) = (uint32_t)&main_blinky01; // PC
	*(--sp_blinky01) = 0x0000DEADU; // LR
	*(--sp_blinky01) = 0x00000012U; // R12
	*(--sp_blinky01) = 0x00000003U; // R3
	*(--sp_blinky01) = 0x00000002U; // R2
	*(--sp_blinky01) = 0x00000001U; // R1
	*(--sp_blinky01) = 0x00000000U; // R0

	*(--sp_blinky02) = 0x00000000U; // FPSCR
	*(--sp_blinky02) = 0x80003070U; // S15
	*(--sp_blinky02) = 0x00000000U; // S14
	*(--sp_blinky02) = 0x00000000U; // S13
	*(--sp_blinky02) = 0x00201700U; // S12
	*(--sp_blinky02) = 0xFF000020U; // S11
	*(--sp_blinky02) = 0x000000F0U; // S10
	*(--sp_blinky02) = 0x00000000U; // S9
	*(--sp_blinky02) = 0x00000000U; // S8
	*(--sp_blinky02) = 0x00000000U; // S7
	*(--sp_blinky02) = 0x00000000U; // S6
	*(--sp_blinky02) = 0x00000000U; // S5
	*(--sp_blinky02) = 0x00000000U; // S4
	*(--sp_blinky02) = 0x00000000U; // S3
	*(--sp_blinky02) = 0x00000000U; // S2
	*(--sp_blinky02) = 0x00000000U; // S1
	*(--sp_blinky02) = 0x00000000U; // S0
	*(--sp_blinky02) = (1U << 24U); // xPSR -> Thumb mode for function entery
	*(--sp_blinky02) = (uint32_t)&main_blinky02; // PC
	*(--sp_blinky02) = 0x0000DEADU; // LR
	*(--sp_blinky02) = 0x00000012U; // R12
	*(--sp_blinky02) = 0x00000003U; // R3
	*(--sp_blinky02) = 0x00000002U; // R2
	*(--sp_blinky02) = 0x00000001U; // R1
	*(--sp_blinky02) = 0x00000000U; // R0


	for(;;);




	// volatile int8_t run = 0;

	// if(run)
	// {
	// 	main_blinky01();
	// }
	// else
	// {
	// 	main_blinky02();
	// }

	// while(1)
	// {
	// 	BSP_LED_SET(LD4 | LD3 | LD5 | LD6);

	// 	BSP_delay(100U);

	// 	BSP_LED_RESET(LD4 | LD3 | LD5 | LD6);

	// 	BSP_delay(100U);

	// }
	
}
