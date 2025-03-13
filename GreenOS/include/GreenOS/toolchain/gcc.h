

#ifndef GREENOS_INCLUDE_TOOLCHAIN_GCC_H
#define GREENOS_INCLUDE_TOOLCHAIN_GCC_H

#define TOOLCHAIN_GCC_VERSION \
    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if !defined(TOOLCHAIN_HAS_PRAGMA_DIAGNOSTIC) && (TOOLCHAIN_GCC_VERSION >= 40600)
#define TOOLCHAIN_HAS_PRAGMA_DIAGNOSTIC 1
#endif

#if !defined(TOOLCHAIN_HAS_C_AUTO_TYPE) && (TOOLCHAIN_GCC_VERSION >= 40900)
#define TOOLCHAIN_HAS_C_AUTO_TYPE 1
#endif

#define TOOLCHAIN_HAS_ZLA 1


#ifndef _LINKER

#ifndef __ORDER_BIG_ENDIAN__
#define __ORDER_BIG_ENDIAN__            (1)
#endif

#ifndef __ORDER_LITTLE_ENDIAN__
#define __ORDER_LITTLE_ENDIAN__         (2)
#endif

#ifndef __BYTE_ORDER__
#if defined(__BIG_ENDIAN__) || defined(__ARMEB__) || \
    defined(__THUMBEB__) || defined(__AARCH64EB__) || \
    defined(__MIPSEB__) || defined(__TC32EB__)

#define __BYTE_ORDER__                  __ORDER_BIG_ENDIAN__

#elif defined(__LITTLE_ENDIAN__) || defined(__ARMEL__) || \
      defined(__THUMBEL__) || defined(__AARCH64EL__) || \
      defined(__MIPSEL__) || defined(__TC32EL__)

#define __BYTE_ORDER__                  __ORDER_LITTLE_ENDIAN__

#else
#error "__BYTE_ORDER__ is not defined and cannot be automatically resolved"
#endif
#endif

#include <GreenOS/toolchain/common.h>
#include <stdbool.h>

#define ALIAS_OF(of) __attribute__((alias(#of)))

#define FUNC_ALIAS(real_func, new_alias, return_type) \
    return_type new_alias() ALIAS_OF(real_func)


#ifndef __noininline
#define __noininline __attribute__((noinline))
#endif

#ifndef __packed
#define __packed        __attribute__((__packed__))
#endif

#ifndef __aligned
#define __aligned(x)	__attribute__((__aligned__(x)))
#endif

#define __used		__attribute__((__used__))
#define __unused	__attribute__((__unused__))
#define __maybe_unused	__attribute__((__unused__))

#define likely(x)   (__builtin_expect((bool)!!(x), true) != 0L)
#define unlikely(x) (__builtin_expect((bool)!!(x), false) != 0L)

#define likely(x)   (__builtin_expect((bool)!!(x), true) != 0L)
#define unlikely(x) (__builtin_expect((bool)!!(x), false) != 0L)

#if defined(_ASMLANGUAGE)

#if defined(CONFIG_ARM) || defined(CONFIG_NIOS2) || defined(CONFIG_RISCV) \
	|| defined(CONFIG_XTENSA) || defined(CONFIG_ARM64) \
	|| defined(CONFIG_MIPS)
#define GTEXT(sym) .global sym; .type sym, %function
#define GDATA(sym) .global sym; .type sym, %object
#define WTEXT(sym) .weak sym; .type sym, %function
#define WDATA(sym) .weak sym; .type sym, %object
#elif defined(CONFIG_ARC)
/*
 * Need to use assembly macros because ';' is interpreted as the start of
 * a single line comment in the ARC assembler.
 */

.macro glbl_text symbol
	.globl \symbol
	.type \symbol, %function
.endm

.macro glbl_data symbol
	.globl \symbol
	.type \symbol, %object
.endm

.macro weak_data symbol
	.weak \symbol
	.type \symbol, %object
.endm

#define GTEXT(sym) glbl_text sym
#define GDATA(sym) glbl_data sym
#define WDATA(sym) weak_data sym

#else  /* !CONFIG_ARM && !CONFIG_ARC */
#define GTEXT(sym) .globl sym; .type sym, @function
#define GDATA(sym) .globl sym; .type sym, @object
#endif // CONFIG_

#endif // _ASMLANGUAGE

#endif // _LINKER

/* from zephyr */
#define TOOLCHAIN_WARNING_ADDRESS_OF_PACKED_MEMBER "-Waddress-of-packed-member"
#define TOOLCHAIN_WARNING_ARRAY_BOUNDS             "-Warray-bounds"
#define TOOLCHAIN_WARNING_ATTRIBUTES               "-Wattributes"
#define TOOLCHAIN_WARNING_DELETE_NON_VIRTUAL_DTOR  "-Wdelete-non-virtual-dtor"
#define TOOLCHAIN_WARNING_EXTRA                    "-Wextra"
#define TOOLCHAIN_WARNING_NONNULL                  "-Wnonnull"
#define TOOLCHAIN_WARNING_SHADOW                   "-Wshadow"
#define TOOLCHAIN_WARNING_UNUSED_LABEL             "-Wunused-label"
#define TOOLCHAIN_WARNING_UNUSED_VARIABLE          "-Wunused-variable"

/* GCC-specific warnings that aren't in clang. */
#if defined(__GNUC__) && !defined(__clang__)
#define TOOLCHAIN_WARNING_POINTER_ARITH "-Wpointer-arith"
#endif

#define _TOOLCHAIN_DISABLE_WARNING(compiler, warning)                                              \
	TOOLCHAIN_PRAGMA(compiler diagnostic push)                                                 \
	TOOLCHAIN_PRAGMA(compiler diagnostic ignored warning)

#define _TOOLCHAIN_ENABLE_WARNING(compiler, warning) TOOLCHAIN_PRAGMA(compiler diagnostic pop)

#define TOOLCHAIN_DISABLE_WARNING(warning) _TOOLCHAIN_DISABLE_WARNING(GCC, warning)
#define TOOLCHAIN_ENABLE_WARNING(warning) _TOOLCHAIN_ENABLE_WARNING(GCC, warning)

#if defined(__GNUC__) && !defined(__clang__)
#define TOOLCHAIN_DISABLE_GCC_WARNING(warning) _TOOLCHAIN_DISABLE_WARNING(GCC, warning)
#define TOOLCHAIN_ENABLE_GCC_WARNING(warning)  _TOOLCHAIN_ENABLE_WARNING(GCC, warning)
#endif


#endif // GREENOS_INCLUDE_TOOLCHAIN_GCC_H