
#ifndef __ASM_ARM_MACRO_H__
#define __ASM_ARM_MACRO_H__

#ifdef CONFIG_ARM64
#include <asm/system.h>
#endif

#ifdef __ASSEMBLY__

/* Cononveniently  write 8, 16 and 32 bit data to any address. */

// writing machros
 .macro	write32, addr, data
 ldr	r4, =\addr
 ldr	r5, =\data
 str	r5, [r4]
.endm

.macro	write16, addr, data
 ldr	r4, =\addr
 ldrh	r5, =\data
 strh	r5, [r4]
.endm

.macro	write8, addr, data
 ldr	r4, =\addr
 ldrb	r5, =\data
 strb	r5, [r4]
.endm

// end writing macros


.macro	switch_el, xreg, el3_label, el2_label, el1_label
	mrs	\xreg, CurrentEL
	cmp	\xreg, #0x8
	b.gt	\el3_label
	b.eq	\el2_label
	b.lt	\el1_label
.endm

#endif // __ASSEMBLY__