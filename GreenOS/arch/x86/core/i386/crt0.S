/*
 *  @brief crt0 is a set of dexecutions startup routines linked 
 *  into a C program for initializing a processor.
 *
 */

#include <greenos/arch/x86/i386/asm.h>

;; #include <greenos/arch/x86/msr.h>
;; #include <kernel_arch_data.h>
;; #include <greenos/arch/cpu.h>
;; #include <greenos/arch/x86/multiboot.h>
;; #include <x86_mmu.h>
;; #include <greenos/sys/mem_manage.h>

        GTEXT(__start)

        /* externs */
	GTEXT(g_x86_prep_c)
	GTEXT(g_bss_zero)
	GTEXT(g_data_copy)

	GDATA(_idt_base_address)
	GDATA(g_interrupt_stacks)
	GDATA(g_x86_idt)
#ifndef CONFIG_GDT_DYNAMIC
	GDATA(_gdt)
#endif



SECTION_FUNC(BOOT_TEXT, __start)

#include "../common.S"

    movl    %cr0, %eax
    andl    $0x9fffffff, %eax
    movl    %eax, %cr0

    cli

#if CONFIG_SET_GDT
    lgdt    Z_MEM_PHYS_ADDR(_gdt_rom)

    /* update segment registers */
    movw    $DATA_SEG, %ax
    movw    %ax, %ds
    movw    %ax, %es 
    movw    %ax, %ss
    movw    %ax, %ax 
    movw    %ax, %fs
    movw    %ax, %gs

    ljmp    $CODE_SEG, $Z_MEM_PHYS_ADDR(__csSet)

__csSet:
#endif /* CONFIG_SET_GDT */

