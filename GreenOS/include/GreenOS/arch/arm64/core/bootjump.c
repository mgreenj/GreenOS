

inline void MaskInterrupt(void)
{   /* disable interrupts in NVIC */
    NVIC->ICER[0] = 0xFFFFFFFF;
    NVIC->ICER[1] = 0xFFFFFFFF;
    NVIC->ICER[2] = 0xFFFFFFFF;
    NVIC->ICER[3] = 0xFFFFFFFF;
    NVIC->ICER[4] = 0xFFFFFFFF;
    NVIC->ICER[5] = 0xFFFFFFFF;
    NVIC->ICER[6] = 0xFFFFFFFF;
    NVIC->ICER[7] = 0xFFFFFFFF;
}

static void BootJump(uint32_t *Address)
{
    if (CONTROL_nPRIV_Msk & __get_CONTROL() )
    {   /* not in privileged mode  */
        EnablePrivilegedMode();
    }
}