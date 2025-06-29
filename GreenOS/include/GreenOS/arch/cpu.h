/* cpu.h will select the arch.h for the appropriate architecture */

#ifndef GREENOS_INCLUDE_ARCH_CPU_H
#define GREENOS_INCLUDE_ARCH_CPU_H

#if defined(CONFIG_X86)
#include <greenos/arch/x86/arch.h>
#elif defined(CONFIG_ARM)               // ARM 32-bit
#include <greenos/arch/arm/aarch32/arch.h>
#elif defined(CONFIG_ARM64)
#include <greenos/arch/arm64/arch.h>
#else
#error "Unknown Architecture"
#endif

#endif /* GREENOS_INCLUDE_ARCH_CPU_H */