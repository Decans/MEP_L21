#ifndef BSP_H
#define BSP_H

#include "stdint.h"

/* system clock tick [Hz] */
#define BSP_TICKS_PER_SEC 100U

#define LD4 GPIO_ODR_OD12
#define LD3 GPIO_ODR_OD13
#define LD5 GPIO_ODR_OD14
#define LD6 GPIO_ODR_OD15

#define BSP_LED_SET(LED_MSK)        (GPIOD->ODR |= (LED_MSK))
#define BSP_LED_RESET(LED_MSK)      (GPIOD->ODR &= ~(LED_MSK))

// void BSP_LED_On(uint32_t LED_Msk);
// void BSP_LED_Off(uint32_t LED_Msk);

/// @brief Application initializer
/// @param  None
void BSP_SysInit(void);

/// @brief Get SysTick counter Var
/// @param  None
/// @return SysTick counter value
uint32_t BSP_tickCtr(void);

/// @brief Blocking delay for "ticks" amount of time
/// @param ticks Ticks to wait
void BSP_delay(uint32_t ticks);

#endif // BSP_H