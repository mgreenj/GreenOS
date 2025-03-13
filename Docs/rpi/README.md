# ATMEGA328P Board Documentation

## Raspberry Pi 5 Documentation 

- The [official documentation page](https://www.raspberrypi.com/documentation/) provides useful information about the Raspberry Pi in General.

- Raspberry Pi [datasheets](https://datasheets.raspberrypi.com/)

## Broadcom BCM2712

- The BCM2712 is the successor to BCM2711, and, according to Rasberry Pi, it shares many common architectural features.  The [BCM2711 ARM Peripherals](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf) datasheet will be a very helpful references.  Notable differences between the two boards are specified on the [documentation page](https://www.raspberrypi.com/documentation/computers/processors.html#bcm2712).

- The [Device Tree](https://www.devicetree.org/specifications/) files for BCM2712 (and other versions) are available in the [Linux GitHub repository](https://github.com/raspberrypi/linux/tree/rpi-6.6.y/arch/arm64/boot/dts/broadcom).

## ARM Cortex A-76

- The [reference manual for ARM Cortex-A76](https://developer.arm.com/documentation/100798/0401/giq1479805174793) is nicely organized and available on the ARM developer website.  (Note: There is a tab that includes [links to additional resources](https://developer.arm.com/documentation/100798/0401/Introduction/Useful-resources); although, many of these are beyond the scope of this project.)

## ARMv8.2-A

- The [ARMv8.2-A programmers guide](https://cs140e.sergio.bz/docs/ARMv8-A-Programmer-Guide.pdf) includes a lot of useful information for ARM development, including writing a bootloader.

- The [instruction set pdf](https://developer.arm.com/-/media/Arm%20Developer%20Community/PDF/Learn%20the%20Architecture/Armv8-A%20Instruction%20Set%20Architecture.pdf) will include all ISA information for ARMv8-A.  [Feature extensions for 8.2](https://developer.arm.com/documentation/109697/2024_12/Feature-descriptions/The-Armv8-2-architecture-extension) are also available.

- If you're interested in writing a bare-metal bootloader for ARMv8-A (cortext A), the [following guide for ARMv8-A](https://developer.arm.com/documentation/dai0527/latest/) combined with a [general guide for ARM](https://developer.arm.com/documentation/den0042/a/Boot-Code/Booting-a-bare-metal-system) will help for 32- and 64-bit mode.