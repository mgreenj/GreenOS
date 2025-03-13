
#include <asm/macro.h>

exception_entry:

    // initialize General-purpose registers
    stp     x27, x28, [sp, #-16]!
    stp     x25, x26, [sp, #-16]!
    stp     x23, x24, [sp, #-16]!
    stp     x21, x22, [sp, #-16]!
    stp     x19, x20, [sp, #-16]!
    stp     x17, x18, [sp, #-16]!
    stp     x15, x16, [sp, #-16]!
    stp     x13, x14, [sp, #-16]!
    stp     x11, x12, [sp, #-16]!
    stp     x9, x10, [sp, #-16]!
    stp     x7, x8, [sp, #-16]!
    stp     x5, x6, [sp, #-16]!
    stp     x3, x4, [sp, #-16]!
    stp     x1, x2, [sp, #-16]!
    b       _save_el_regs
    
    // x29 and x30 are typically use for stack unwinding, we 
        // want to save general-purpose registers values before
            // branching to ensure _save_el_regs doesn't overwrite values

    .align  7
    stp     x29, x30, [sp, #-16]!
    bl      exception_entry
    bl      handle_bad_irq
    b       excetion_exit


/*************************************************************************
 *
 * Save exception context for EL3, EL2, and EL1
 *
 *************************************************************************/

 _save_el_regs:
    switch