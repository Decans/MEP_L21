#include "bsp.h"
#include "stm32f4xx.h"

static uint32_t volatile l_tickCtr;

void SysTick_Handler(void)
{
    l_tickCtr++;
}

void BSP_SysInit(void)
{
    SystemCoreClockUpdate();
	SysTick_Config( SystemCoreClock / BSP_TICKS_PER_SEC);

	__enable_irq(); // QUESTION: Is this needed?

	// Enable the GPIOD Peripheral
	RCC->AHB1ENR = RCC_AHB1ENR_GPIODEN;

	// Configure LD4 pin
	GPIOD->MODER &= ~GPIO_MODER_MODER12;
	GPIOD->MODER |= GPIO_MODER_MODER12_0;

	// Configure LD3 pin
	GPIOD->MODER &= ~GPIO_MODER_MODER13;
	GPIOD->MODER |= GPIO_MODER_MODER13_0;

	// Configure LD5 pin
	GPIOD->MODER &= ~GPIO_MODER_MODER14;
	GPIOD->MODER |= GPIO_MODER_MODER14_0;

	// Configure LD6 pin
	GPIOD->MODER &= ~GPIO_MODER_MODER15;
	GPIOD->MODER |= GPIO_MODER_MODER15_0;
}

uint32_t BSP_tickCtr(void)
{
    uint32_t tickCtr;

    __disable_irq();
    tickCtr = l_tickCtr;
    __enable_irq();

    return tickCtr;
}

void BSP_delay(uint32_t ticks)
{
    uint32_t start = BSP_tickCtr();

    while ((BSP_tickCtr() - start) < ticks)
    {
        /* Do nothing */
    }
}

void BusFault_Handler(void)
{
    while (1)
    {
        /* Infinite Loop */
    }
}

void HardFault_Handler(void)
{
    while (1)
    {
        /* Infinite Loop */
    }
}