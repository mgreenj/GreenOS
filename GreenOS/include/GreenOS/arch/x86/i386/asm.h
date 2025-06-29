/* asm.h - x86 tool dependent headers */

#ifndef GREENOS_INCLUDE_ARCH_X86_I386_ASM_H
#define GREENOS_INCLUDE_ARCH_X86_I386_ASM_H

#include <greenos/toolchain.h>
#include <greenos/linker/sections.h>

#if defined(_ASSEMBLYLANG)

#ifdef CONFIG_X86_KPTI
GTEXT(g_x86_trampoline_to_user)
GTEXT(g_x86_trampoline_to_kernel)

#define KPTI_IRET       jmp z_x86_trampoline_to_user
#define KPTI_IRET_USER	jmp z_x86_trampoline_to_user_always
#else
#define KPTI_IRET	    iret
#define KPTI_IRET_USER	iret
#endif  /* CONFIG_X86_KPTI */

#endif /* _ASSEMBLYLANG */

#endif /* GREENOS_INCLUDE_ARCH_X86_I386_ASM_H */