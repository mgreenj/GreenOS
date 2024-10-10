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

#define REG_ADDRESS(page, offset) ((page << PAGE_SHIFT) | (offset * sizeof(uint16_t)))              /* Calculate Register Address */
#define MMD_DEVICE_ADDRESS(dev, offset) ((device) << DEV_SHIFT) + offset))                          /* Calculate MMD Register Address */
#define REG_ISLH(u32) (((u32) & 0x00000080) ? 1 : 0)                                                /* Check if bit 7 is set */
#define REG_BIT_RANGE(reg, mask) ((reg) & mask)                                                     /* Apply Bitmask for PHYID2 */
#define REG_SC_SET 1                                                                                /* Activate function, set to 1 */

// Macros to set, clear, and check specific bits
#define SET_BIT(reg, bit)    ((reg) |= (1U << (bit)))                                               /* Set register bit */
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1U << (bit)))                                              /* Clear register bit */
#define IS_BIT_SET(reg, bit) (((reg) >> (bit)) & 1U)                                                /* Check if register bit is set */

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

/* MMD REgister Mappings */
#define PCIR_MMD_REG    MMD_DEVICE_ADDRESS(3, 0)    /* PCS Control 1 Register */
#define PSIR_MMD_REG    MMD_DEVICE_ADDRESS(3, 1)    /* PCS Status 1 Register */
#define EEECR_MMD_REG   MMD_DEVICE_ADDRESS(3, 20)   /* EEE Capability Register */
#define EEEWER_MMD_REG  MMD_DEVICE_ADDRESS(3, 22)   /* EEE Wake Error Register */
#define EEEAR_MMD_REG   MMD_DEVICE_ADDRESS(7, 60)   /* EEE Advertisement Register */
#define EEELPAR_MMD_REG MMD_DEVICE_ADDRESS(7, 61)   /* EEE Link Partner Ability Register */

/* Structure for Register Mappings */
struct eth_regmap {
    uint16 bmcr;        /* Basic Mode Control Register */
    uint16 bmsr;        /* Basic Mode Status Register */
    uint16 phyid1;      /* PHY Identifier Register 1 */
    uint16 phyid2;      /* PHY Identifier Register 2 */
    uint16 anar;        /* Auto-Negotiation Advertising Register */
    uint16 anlpar;      /* Auto-Negotation Link Parner Ability Reg. */
    uint16 aner;        /* Auto-Negotiation Expansion Register */
    uint16 annptr;      /* Auto-Negotiation Next Page Transmit Reg.*/
    uint16 annprr;      /* Auto-Negotiation Next Page Receive Reg. */
    uint16 gbcr;        /* 1000Base-T Control Register */
    uint16 gbsr;        /* 1000Base-T Status Register */
    uint16 rsvd[2];     /* Skipping Reserved Registers */
    uint16 macr;        /* MMD Access Control Register */
    uint16 maadr;       /* MMD Access Address Data Register */
    uint16 gbesr;       /* 1000Base-T Status Register */
    uint16 rsvd2[2];    /* Skipping Reserved Registers */
    uint16 iner;        /* Interupt Enable Register */
    uint16 rsvd3[5];    /* Skipping Reserved Registers */
    uint16 phycr1;      /* PHY Specific Control Register 1 */
    uint16 physr;       /* PHY Specific Status Register */
    uint16 rsvd[2];     /* Skipping Reserved Addresses */
    uint16 insr;        /* Interrupt Status Register */
    uint16 rsvd;        /* Skipping Reserved Addresses */
    uint16 pagsr;       /* PAGSR Page Select Register */
    uint16 phycr2;      /* PHY Specific Control Register 2 */
    uint16 physcr;      /* PHY Special Config Register */
    uint16 physr2;      /* PHY Specific Status Register 2 */
    uint16 lcr;         /* LED Control Register */
    uint16 eeelcr;      /* EEE LED Control Register */
    uint16 miicr1;      /* MII Control Register 1 */
    uint16 miicr2;      /* MII Control Register 2 */
    uint16 intbcr;      /* INTB Pin Control Register */                     
};

/* Structure for MMD Registers */
struct eth_mmdmap {
    uint16 pcir;        /* PCS Control 1 Register */
    uint16 psir;        /* PCS Status 1 Register */
    uint16 eecr;        /* EEE Capability Register */
    uint16 eeewer;      /* EEE Wake Error Register */
    uint16 eeear;       /* EEE Advertisment Register */
    uint16 eeelpar;     /* EEE Link Partner Ability Register */
};

/* BMCR Register Table */
#define BMCR_RESET_BIT          REG_BIT_RANGE(BMSR_REG, 0x8000)
#define BMCR_LOOPBACK_BIT       REG_BIT_RANGE(BMSR_REG, 0x4000)
#define BMCR_SELECT_SPEED_BIT   REG_BIT_RANGE(BMSR_REG, 0x2000)
#define BMCR_AUTONEG_ENABLE_BIT REG_BIT_RANGE(BMSR_REG, 0x1000)
#define BMCR_POWERDOWN_BIT      REG_BIT_RANGE(BMSR_REG, 0x0800)
#define BMCR_ISOLATE_BIT        REG_BIT_RANGE(BMSR_REG, 0x0400)
#define BMCR_RST_AUTONEG_BIT    REG_BIT_RANGE(BMSR_REG, 0x0200)
#define BMCR_DUPLEX_BIT         REG_BIT_RANGE(BMSR_REG, 0x0100)
#define BMCR_COL_TEST           REG_BIT_RANGE(BMSR_REG, 0x0080)
#define BMCR_SELECT_SPEED_BIT   REG_BIT_RANGE(BMSR_REG, 0x0040)
#define BMCR_UNIDIR_ENABLE_BIT  REG_BIT_RANGE(BMSR_REG, 0x0020)
#define BMCR_RSVD_BIT           REG_BIT_RANGE(BMCR_REG, 0x001F)

/* BMSR Register Table */       /* Foreach, 1 = Able/Full-Duplex, 0 = Unable/Full-Duplex, Read-only */
#define BMSR_100Base_T4_BIT     REG_BIT_RANGE(BMSR_REG, 0x8000)
#define BMSR_100Base_TX_F_BIT   REG_BIT_RANGE(BMSR_REG, 0x4000)
#define BMSR_100Base_TX_H_BIT   REG_BIT_RANGE(BMSR_REG, 0x2000)
#define BMSR_10Base_T_F_BIT     REG_BIT_RANGE(BMSR_REG, 0x1000)
#define BMSR_10Base_T_H_BIT     REG_BIT_RANGE(BMSR_REG, 0x0800)
#define BMSR_100Base_T2_F_BIT   REG_BIT_RANGE(BMSR_REG, 0x0400)
#define BMSR_100Base_T2_H_BIT   REG_BIT_RANGE(BMSR_REG, 0x0200)
#define BMSR_1000Base_T_EX_BIT  REG_BIT_RANGE(BMSR_REG, 0x0100)
#define BMSR_UNIDIR_BIT         REG_BIT_RANGE(BMSR_REG, 0x0080)
#define BMSR_SUPP_PRE_BIT       REG_BIT_RANGE(BMSR_REG, 0x0040)
#define BMSR_AUTONEG_COMPL_BIT  REG_BIT_RANGE(BMSR_REG, 0x0020)
#define BMSR_REMOTE_FAULT_BIT   REG_BIT_RANGE(BMSR_REG, 0x0010)
#define BMSR_AUTONEG_BIT        REG_BIT_RANGE(BMSR_REG, 0x0008)
#define BMSR_LINK_STATUS_BIT    REG_BIT_RANGE(BMSR_REG, 0x0004)
#define BMSR_JABBER_DETECT_BIT  REG_BIT_RANGE(BMSR_REG, 0x0002)
#define BMSR_EXTENDED_CAP_BIT   REG_BIT_RANGE(BMSR_REG, 0x0000)

/* PHYID1 Register Table */         /* Read-Only -- NEVER Change */
#define PHYID1_OUI_MSB_BIT          REG_BIT_RANGE(PHYID1_REG, 0x001C)

/* PHYID2 Register Table */         /* Read-Only Values */
#define PHYID2_OUI_LSB_BIT          REG_BIT_RANGE(PHYID2_REG, 0xFC00)
#define PHYID2_MODEL_NUM_BIT        REG_BIT_RANGE(PHYID2_REG, 0x0210)  
#define PHYID2_SAMPLE_CLASS_BIT     REG_BIT_RANGE(PHYID2_REG, 0x0008)
#define PHYID2_REVISION_NO_BIT      REG_BIT_RANGE(PHYID2_REG, 0x0007)

