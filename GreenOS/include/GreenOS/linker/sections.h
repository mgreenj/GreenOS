/*  
 * sections.h Linker section definitions
 *
 * See GNU Assembler directives:
 *  - https://ftp.gnu.org/old-gnu/Manuals/gas-2.9.1/html_node/as_toc.html
 * 
 */


#ifndef GREENOS_INCLUDE_LINKSECTIONS_H_
#define GREENOS_INCLUDE_LINKSECTIONS_H_


/* Linker sections */
                                                    /* If using XIP to ROM an application (i.e., running
                                                        from read-only memory), see the Texas Instruments
                                                        guide (XIP Programming Guide) */
#define _TEXT_SECTION   text
#define _DATA_SECTION   data                                
#define _BSS_SECTION    bss
#define _RODATA_SECTION rodata

#define _APPLICATION_DATA   adata
#define _APPLICATION_BSS    abss


/* Interrupts */
#define _IRQ_VECTOR_TABLE_SECTION       .gnu.linkonce.irq_vector_table
#define _IRQ_VECTOR_TABLE_SECTION_SYMS  .gnu.linkonce.irq_vector_table*

#ifdef CONFIG_NOCACHE_MEMORY
#define _NOCACHE_SECTION    nocache
#endif

#if defined(CONFIG_LINKER_USE_BOOT_SECTION)
#define BOOT_TEXT_SECTION   btext
#define BOOT_DATA_SECTION   bdata
#define BOOT_BSS_SECTION    bbss
#define BOOT_RODATA_SECTION brodata
#endif

#if defined(_ASSEMBLYLANG)

#define TEXT    text
#define DATA    data
#define BSS     bss
#define RODATA  rodata

#if defined(CONFIG_LINKER_USE_BOOT_SECTION)
#define BOOT_TEXT   BOOT_TEXT_SECTION
#define BOOT_DATA   BOOT_DATA_SECTION
#define BOOT_BSS    BOOT_BSS_SECTION
#define BOOT_RODATA BOOT_RODATA_SECTION
#else
#define BOOT_TEXT   TEXT
#define BOOT_DATA   DATA
#define BOOT_BSS    BSS
#define BOOT_RODATA RODATA
#endif /* CONFIG_LINKER_USE_BOOT_SECTION */

#endif /* _ASSEMBLYLANG */


#endif /* GREENOS_INCLUDE_LINKSECTIONS_H_ */