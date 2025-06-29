/* i386/arch.h the architecture definitions for 32-bit x86 ISA */


#ifndef GREENOS_INCLUDE_ARCH_X86_I386_ARCH_H
#define GREENOS_INCLUDE_ARCH_X86_I386_ARCH_H

#include <stdbool.h>
/*
TODO: Other includes
*/

#ifndef _ASSEMBLYLANG
#include <stddef.h>

#include <greenos/arch/x86/i386/segmentation.h>
 
// TODO: More includes

#endif /* _ASSEMBLYLANG */

/* GDT (see: https://wiki.osdev.org/Global_Descriptor_Table) */
#define CODE_SEG	0x08
#define DATA_SEG	0x10
#define MAIN_TSS	0x18
#define DF_TSS		0x20

#ifndef _ASSEMBLYLANG

#ifdef __cplusplus
extern "C" {
#endif

#define _VECTOR_ARG(irq_p)      (-1)

#define ARCH_IRQ_CONNECT(irq_p, priority_p, isr_p, isr_param_p, flags_p) \
{ \
    __asm__ __volatile__(                                                   \
            ".pushsection .intList\n\t" \
            ".long %c[isr]_irq%c[irq]_stub\n\t"             \
            ".long %c[irq]\n\t"                             \
            ".long %c[priority]\n\t"                        \
            ".long %c[vector]\n\t"                          \
            ".long 0\n\t"                                   \
            ".long 0\n\t"                                   \
            ".popsection\n\t"                               \
            ".pushsection " IRQSTUBS_TEXT_SECTION "\n\t"    \
            ".global %c[isr]_irq%c[irq]_stub\n\t"           \
            "%c[isr]_irq%c[irq]_stub:\n\t"                  \
            "pushl %[isr_param]\n\t"                        \
            "pushl %[isr]\n\t"                              \
            "jmp _interrupt_enter\n\t"                      \
            ".popsection\n\t"                               \
            :                                               \
            : [isr] "i" (isr_p),                            \
              [isr_param] "i" (isr_param_p),                \
              [priority] "i" (priority_p),                  \
              [vector] "i" _VECTOR_ARG(irq_p),              \
              [irq] "i" (irq_p));                           \
    z_irq_controller_irq_config(Z_IRQ_TO_INTERRUPT_VECTOR(irq_p), (irq_p),   \
                                (flags_p));                 \

    )
}

#ifdef __cplusplus
}
#endif


#endif /* _ASSEMBLYLANG */

#endif /* GREENOS_INCLUDE_ARCH_X86_I386_ARCH_H */