#include "main.h"
#include "stm32f407xx.h"
#include "bsp.h"
#include "miros.h"

#define THREAD_STACK_SIZE	60

uint32_t stack_blinky01[THREAD_STACK_SIZE] = {0};
OSThread_t sp_blinky01;

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

uint32_t stack_blinky02[THREAD_STACK_SIZE] = {0};
OSThread_t sp_blinky02;

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
	// Initialize
	BSP_SysInit();
	OS_init();

	// Start blinky01 thread
	OSThread_start(	&sp_blinky01,
					&main_blinky01,
					stack_blinky01,
					sizeof(stack_blinky01));

	// Start blinky02 thread
	OSThread_start(	&sp_blinky02,
					&main_blinky02,
					stack_blinky02,
					sizeof(stack_blinky02));

	for(;;);
	
}
