#include "miros.h"
#include "stm32f4xx.h"

void OS_init(void)
{   
    // Set PendSV to lowest priority
    NVIC_SetPriority(PendSV_IRQn, 7U);
}

void OSThread_start(
    OSThread_t *me,
    OSThreadHandler threadHandler,
    void *stkSto,
    uint32_t stkSize
)
{
    // Set sp to end of stack memory
    uint32_t *sp = (uint32_t *)((uint32_t)stkSto + stkSize);

	// The stack grows from high address to low address
    // Initialize stack (with FPU)
	*(--sp) = 0x00000000U; // FPSCR
	*(--sp) = 0x80003070U; // S15
	*(--sp) = 0x00000000U; // S14
	*(--sp) = 0x00000000U; // S13
	*(--sp) = 0x00201700U; // S12
	*(--sp) = 0xFF000020U; // S11
	*(--sp) = 0x000000F0U; // S10
	*(--sp) = 0x00000000U; // S9
	*(--sp) = 0x00000000U; // S8
	*(--sp) = 0x00000000U; // S7
	*(--sp) = 0x00000000U; // S6
	*(--sp) = 0x00000000U; // S5
	*(--sp) = 0x00000000U; // S4
	*(--sp) = 0x00000000U; // S3
	*(--sp) = 0x00000000U; // S2
	*(--sp) = 0x00000000U; // S1
	*(--sp) = 0x00000000U; // S0
	*(--sp) = (1U << 24U); // xPSR -> Thumb mode for function entry
	*(--sp) = (uint32_t)&threadHandler; // PC
	*(--sp) = 0x0000DEADU; // LR
	*(--sp) = 0x00000012U; // R12
	*(--sp) = 0x00000003U; // R3
	*(--sp) = 0x00000002U; // R2
	*(--sp) = 0x00000001U; // R1
	*(--sp) = 0x00000000U; // R0

    // Save the init top-of-stack in the thread's attribute
    me->sp = sp;

    // Top-of-stack
    uint32_t *stk_limit = (uint32_t *)stkSto;

    // Fill rest of stack if easily identifiable value for debug purposes
    for (sp = sp - 1U; sp >= stk_limit; --sp)
    {
        *sp = 0xDEADBEEFU;
    }

}

void PendSV_Handler(void)
{

}