

#ifndef GREENOS_INCLUDE_TOOLCHAIN_H
#define GREENOS_INCLUDE_TOOLCHAIN_H

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#ifdef _ASSEMBLYLANG
    #define REQUIRES(sym) .set sym ## _Requires, sym
#else
    #define REQUIRES(sym) __asm__ (".set " # sym "_Requires, " # sym "\n\t");
#endif

#ifdef _ASSEMBLYLANG
    #define SECTION .section
#endif

#if !defined(_ASSEMBLYLANG)
    #ifdef CONFIG_COVERAGE
        /*
         * Using always_inline attribute forces inlining.  This can
         * cause the object file to become artificially inflated
         * because of duplication.  Thus, use this when needed.
         * 
         * Note that using `__attribute__((always_inline))` overrides
         * the compiler flag -fno-inline.
        */
        #define __inline inline
    #else
        #define __inline                            \
            inline __attribute__((always_inline))
    #endif  /* CONFIG_COVERAGE */
#endif  /* _ASSEMBLYLANG */


#endif /* GREENOS_INCLUDE_TOOLCHAIN_H */