#ifndef ARM_BOOT_H
#define ARM_BOOT_H

#include <stdint.h>

#if defined(__arm__) && (((__ARM_ARCH7S__) || (__ARM_ARCH7A__)) || (__ARM_ARCH__ <= 8))
        /* ARM 32-bit */
#elif defined(__aarch64__) || (__ARM_ARCH_ISA_A64)

#endif // ARM_BOOT_H