/* x86/arch.h contains architecture definitions for x86 */

#ifndef GREENOS_INCLUDE_ARCHX86_ARCH_H_
#define GREENOS_INCLUDE_ARCHX86_ARCH_H_

#include <greenos/devicetree.h>

#define G_X86_OOPS_VECTOR       32

#if !defined(_ASSEMBLYLANG)

#include <stddef.h>
#include <stdbool.h>
#include <greenos/irq.h>
// #include <greenos/arch/x86/mmustructs.h>
// #include <greenos/arch/x86/thread_stack.h>
#include <greenos/linker/sections.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_PCIE_MSI

struct x86_msi_vector {
    unsigned int irq;
    uint8_t vector;
#ifdef CONFIG_INTEL_VTD_ICTL
    bool remap;
    uint8_t irte;
#endif
};

typedef struct x86_msi_vector arch_msi_vector_t;

#endif /* CONFIG_PCIE_MSI */

#endif /* _ASSEMBLYLANG */

#ifdef __cplusplus
}
#endif

// #include <greenos/drivers/interrupt_controller/sysapic.h>

#ifdef CONFIG_X86_64
#include <greenos/arch/x86/x86_64/arch.h>
#else
#include <greenos/arch/x86/i386/arch.h>
#endif

// TODO

#endif /* GREENOS_INCLUDE_ARCHX86_ARCH_H_ */