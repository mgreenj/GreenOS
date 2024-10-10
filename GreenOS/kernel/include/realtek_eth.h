/*
 * realtek_eth.h created on Thu Oct 10 2024
 *
 * GreenOS - lightweight, secure OS
 * Copyright (C) 2024  Maurice Green
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#define REG_ADDRESS(page, offset) ((page << PAGE_SHIFT) | (offset * sizeof(uint32_t)))              /* Calculate Register Address */
#define REG_ISLH(u32) (((u32) & 0x00000080) ? 1 : 0)                                                /* Check if bit 7 is set */
#define REG_SC_SET 1                                                                                /* Activate function, set to 1 */

/** 
 * Accessing the IEEE Standard Registers 0 - 15, the Page Select Register (PAGSR, register 31)
 * should be set as 0 or the default, 0xa42.
 * 
 * Example: To switch to Page 0xd04, set PAGSR (register 31) Data = 0x0d04, which effectively
 * changes to Page 0xd04.  After LED setting, switch back to the PHY's IEEE Stardard registers
 * by setting PAGSR to page 0 or the default, page 0xa42.
 * 
 */

/* Register Mappings Page 0 */
#define BMCR_REG    REG_ADDRESS(0x0000, 0)  /* Basic Mode Control Register */
#define BMSR_REG    REG_ADDRESS(0x0000, 1)  /* Basic Mode Status Register */
#define PHYID1_REG  REG_ADDRESS(0x0000, 2)  /* PHY Identifier Register 1 */
#define PHYID2_REG  REG_ADDRESS(0x0000, 3)  /* PHY Identifier Register 2 */
#define ANAR_REG    REG_ADDRESS(0x0000, 4)  /* Auto-Negotiation Advertising Register */
#define ANLPAR_REG  REG_ADDRESS(0x0000, 5)  /* Auto-Negotation Link Parner Ability Reg. */
#define ANER_REG    REG_ADDRESS(0x0000, 6)  /* Auto-Negotiation Expansion Register */
#define ANNPTR_REG  REG_ADDRESS(0x0000, 7)  /* Auto-Negotiation Next Page Transmit Reg.*/
#define ANNPRR_REG  REG_ADDRESS(0x0000, 8)  /* Auto-Negotiation Next Page Receive Reg. */
#define GBCR_REG    REG_ADDRESS(0x0000, 9)  /* 1000Base-T Control Register */
#define GBSR_REG    REG_ADDRESS(0x0000, 10) /* 1000Base-T Status Register */
#define MACR_REG    REG_ADDRESS(0x0000, 13) /* MMD Access Control Register */
#define MAADR_REG   REG_ADDRESS(0x0000, 14) /* MMD Access Address Data Register */
#define GBESR_REG   REG_ADDRESS(0x0000, 15) /* 1000Base-T Status Register */

/* Register Mappings Page 0xa42 */
#define INER_REG    REG_ADDRESS(0xa42, 18)  /* Interupt Enable Register */
#define PHYCR1_REG  REG_ADDRESS(0xa43, 24)  /* PHY Specific Control Register 1 */
#define PHYSR_REG   REG_ADDRESS(0xa43, 26)  /* PHY Specific Status Register */
#define INSR_REG    REG_ADDRESS(0xa43, 29)  /* Interrupt Status Register */
#define PAGSR_REG   REG_ADDRESS(0xa43, 31)                                              /* PAGSR Page Select Register */
#define PHYCR2_REG  REG_ADDRESS(0xa44, 17)  /* PHY Specific Control Register 2 */
#define PHYSCR_REG  REG_ADDRESS(0xa46, 20)  /* PHY Special Config Register */
#define PHYSR2_REG  REG_ADDRESS(0xa4b, 16)  /* PHY Specific Status Register 2 */
#define LCR_REG     REG_ADDRESS(0xd04, 16)  /* LED Control Register */
#define EEELCR_REG  REG_ADDRESS(0xd04, 17)  /* EEE LED Control Register */
#define MIICR1_REG  REG_ADDRESS(0xd08, 17)  /* MII Control Register 1 */
#define MIICR2_REG  REG_ADDRESS(0xd08, 21)  /* MII Control Register 2 */
#define INTBCR_REG  REG_ADDRESS(0xd40, 22)  /* INTB Pin Control Register */
                 

struct eth_regmap {
    uint32 bmcr;        /* Basic Mode Control Register */
    uint32 bmsr;        /* Basic Mode Status Register */
    uint32 phyid1;      /* PHY Identifier Register 1 */
    uint32 phyid2;      /* PHY Identifier Register 2 */
    uint32 anar;        /* Auto-Negotiation Advertising Register */
    uint32 anlpar;      /* Auto-Negotation Link Parner Ability Reg. */
    uint32 aner;        /* Auto-Negotiation Expansion Register */
    uint32 annptr;      /* Auto-Negotiation Next Page Transmit Reg.*/
    uint32 annprr;      /* Auto-Negotiation Next Page Receive Reg. */
    uint32 gbcr;        /* 1000Base-T Control Register */
    uint32 gbsr;        /* 1000Base-T Status Register */
    uint32 macr;        /* MMD Access Control Register */
    uint32 maadr;       /* MMD Access Address Data Register */
    uint32 gbesr;       /* 1000Base-T Status Register */
    uint32 iner;        /* Interupt Enable Register */
    uint32 phycr1;      /* PHY Specific Control Register 1 */
    uint32 physr;       /* PHY Specific Status Register */
    uint32 insr;        /* Interrupt Status Register */
    uint32 pagsr;       /* PAGSR Page Select Register */
    uint32 phycr2;      /* PHY Specific Control Register 2 */
    uint32 physcr;      /* PHY Special Config Register */
    uint32 physr2;      /* PHY Specific Status Register 2 */
    uint32 lcr;         /* LED Control Register */
    uint32 eeelcr;      /* EEE LED Control Register */
    uint32 miicr1;      /* MII Control Register 1 */
    uint32 miicr2;      /* MII Control Register 2 */
    uint32 intbcr;      /* INTB Pin Control Register */                     
};