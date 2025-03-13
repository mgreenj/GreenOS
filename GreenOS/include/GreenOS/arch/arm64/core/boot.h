
#ifndef _BOOT_H
#define _BOOT_H

#ifndef _ASMLANGUAGE

extern void *_vector_table[];
extern void _start(void);

#endif __ASMLANGUAGE

#define BOOT_PARAM_MPID_OFFSET      0
#define BOOT_PARAM_SP_OFFSET        8
#define BOOT_PARAM_VOTING_OFFSET    16

#endif // _BOOT_H