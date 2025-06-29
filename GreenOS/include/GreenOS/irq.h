/* irq.h definitions for the irq interface to handle interrupts  */

#ifndef GREENOS_INCLUDE_IRQ_H
#define GREENOS_INCLUDE_IRQ_H

#include <greenos/arch/cpu.h>

#ifndef _ASSEMBLYLANG
#include <greenos/toolchain.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup isr_apis Interrupt Service Routine APIs
 * @ingroup kernel_apis
 * 
 */

/**
 * @brief Initialize an Interrupt handler.
 * 
 * This routine initialized interrupt handlers for IRQ.  See later
 * section for FIQ.
 * 
 * @warning
 * Interrupt routines are invoked during runtime; however, their 
 * arguments must be known at compile time.  Think `constexpr`
 * 
 * @param irq_p IRQ line number
 * @param priority_p Interrupt Prioritiy
 * @param isr_p Address of interupt service routine
 * @param isr_param_p Parameter passed to interrupt service routine
 * @param flags_p Architecture-specific IRQ configuration flasgs
 */

#define IRQ_CONNECT(irq_p, priority_p, isr_p, isr_param_p, flags_p) \
        ARCH_IRQ_CONNECT(irq_p, priority_p, isr_p, isr_param_p, flags_p)

#ifdef __cplusplus
}
#endif


#endif /* ASSEMBLYLANG */
#endif /* GREENOS_INCLUDE_IRQ_H */