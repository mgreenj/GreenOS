#include "asm.h"
#include <GreenOS/toolchain/toolchain.h>
#include <asm/macro.h>
#include <asm/armv8/mmu.h>


/*************************************************************************
 *
 * Startup Code (sleep non-primary cores, reset vector)
 *
 *************************************************************************/

.section ".text.boot"
.global _start

_start:

/*************************************************************************
*
* Only the processor with CPUID = 0 performs the initialization.  Other CPU processors 
* go into WFI.  To implement, we must determine which CPU this is.  This is the first 
* initialization step.
*
 *************************************************************************/

    mrc     p15, 0, r1, c0, c0, 5               // Read Multiprocessor Affinity register
    and     r1, r1, #0x3                        // Extract CPUID bits
    cbz     x1, 2f                              // if CPUID==0, jump to start

    // Sleep slave Processors (CPUID neq 0) until break

1:  wfe                                         // wait for event (sleep until event)
    b       1b                                  // jump back to 1, infinite loop

    // Continue boot process
2:                                              // CPUID == 0, continue booting

    ldr     x1, =_start
    mov     sp, x1
                                                // Zero out BSS section
    ldr     x1, =_bss_start
    ldr     w2, =_bss_size

3:  cbz     w2, 4f                              // jump to 4 if zero, else
    str     xzr, [x1], #8                       // store zero at address x1, increment by 8
    sub     w2, w2, #1                          // degrement bss size
    cbnz    w2, 3b                              // repeat until bss_size == 0

/* When the ARM processor is reset, it commences execution at the location of the reset vector in the execption 
 vector table.  For this reason, setting up the vector table is one of the first steps.  On a multi-core system, 
 it is necessary to put  non-primary cores to sleep. */

    // Initialize vector tables - Processor starts in EL3

    ldr     x1, =Vector_table_el3              // EL3
    msr     vbar_el3, x1

    ldr     x1, =Vector_table_el2              // EL2
    msr     vbar_el2, x1

    ldr     x1, =Vector_table_el1              // EL1
    msr     vbar_el1, x1



.global enable_irq
enable_irq:
    mrs     x0, scr_el3
    orr     x0, x0, #(1<<3)                     // EA bit
    orr     x0, x0, #(1<<1)                     // IRQ bit
    orr     x0, x0, #(1<<2)                     // FIQ bit
    msr     scr_el3, x0

    // PSTATE.{AIF}, the immediate is a mask that is applied 
        // to the DAIF register. if PSTATE.{AIF} exception is masked

    msr     daifclr, #0x7                        // 0x7 == 0111 -> enable SError, IRQ, and FIQ
    ret

.global rteception_el2
rteception_el2:
    mrs     x0, hcr_el2
    orr     x0, x0, #(1<<5)                     // AMO bit
    orr     x0, x0, #(1<<4)                     // IMO bit
    orr     x0, x0, #(1<<3)                     // FMO bit
    msr     hcr_el2, x0
    ret


/* in AArch64, each execution level has its own vector table, interrupts must be initialized for each */

4:  bl      main
    b       1b


/* ***************************************************************************************************** *
 *       ***********************************************************************************************
 *
 *                                      ARMv8-A Vector Table Structure
 *
 *       ***********************************************************************************************
 * ***************************************************************************************************** *
 *       |-----------------------------------------------------------------------------------------------|
 * 0x780 | SError / vSError                              |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x700 | FIQ / vFIQ                                    |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x680 | IRQ / vIRQ                                    |               Lower EL using AArch32          |
 *       | --------------------------------------------- |                                               |
 * 0x600 | Synchronous                                   |                                               |
 *       |-----------------------------------------------------------------------------------------------|
 * 0x580 | SError / vSError                              |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x500 | FIQ / vFIQ                                    |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x480 | IRQ / vIRQ                                    |               Lower EL using AArch64          |
 *       | --------------------------------------------- |                                               |
 * 0x400 | Synchronous                                   |                                               |
 *       |-----------------------------------------------------------------------------------------------|
 * 0x380 | SError / vSError                              |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x300 | FIQ / vFIQ                                    |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x280 | IRQ / vIRQ                                    |               Current EL with SPx             |
 *       | --------------------------------------------- |                                               |
 * 0x200 | Synchronous                                   |                                               |
 *       |-----------------------------------------------------------------------------------------------|
 * 0x180 | SError / vSError                              |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x100 | FIQ / vFIQ                                    |                                               |
 *       | --------------------------------------------- |                                               |
 * 0x080 | IRQ / vIRQ                                    |               Current EL with SP0             |
 *       | --------------------------------------------- |                                               |
 * 0x000 | Synchronous                                   |                                               |
 *       |-----------------------------------------------------------------------------------------------|
 * ***************************************************************************************************** *
*/





// Initialize vector exceptions
.global Vector_table_el3
.balign 0x800
Vector_table_el3:
curr_el_sp0_sync:
    
    // branch here

.balign 0x80
curr_el_sp0_irq:


.balign 0x80
curr_el_sp0_fiq:


.balign 0x80
curr_el_sp0_serror:


.balign 0x80
curr_el_spx_sync:


.balign 0x80
curr_el_spx_irq:


.balign 0x80
curr_el_spx_fiq:


.balign 0x80
curr_el_spx_serror:


.balign 0x80
lower_el_aarch64_sync:


.balign 0x80
lower_el_aarch64_irq:


.balign 0x80
lower_el_aarch64_fiq:


.balign 0x80
lower_el_aarch64_serror:


.balign 0x80
lower_el_aarch32_irq:


.balign 0x80
lower_el_aarch32_fiq:


.balign 0x80
lower_el_aarch32_serror:


