<p align="center"><a href="https://0x0m03ii.github.io/GreenOS" target="_blank"><img src="Docs/img/GreenOS.png" width="400" alt="GreenOS Logo"></a></p>

<p align="center">
<a href="#"><img src="https://github.com/#" alt="Build Status"></a>
<a href="#"><img src="https://img.shields.io/packagist/#" alt="Total Downloads"></a>
<a href="#"><img src="https://img.shields.io/packagist/#" alt="Latest Stable Version"></a>
<a href="#"><img src="https://img.shields.io/packagist/#" alt="License"></a>
</p>

#  The GreenOS Operating System
The GreenOS operating System is a minimal operating system developed as a part of my [tutorial series]().  GreenOS is a bare-metal OS that will run on the [Rasberry Pi 5](https://www.raspberrypi.com/products/raspberry-pi-5/), using the ARMv8.2-A Instruction Set.  I may add support for additional architectures; however, I am busy and this is a hobby.


## Target Development Board
- [Rasberry Pi 5](https://www.raspberrypi.com/products/raspberry-pi-5/)


## RISC-V Toolchain for Cross-Compiling
When developing an operating system, you'll most liklely want your OS to run on several different architectures (e.g., ARM, RISC-V, i386/x86, x86_64, etc.).  Unless you plan on purchasing hardware to test functionality for each architecture, you'll need to familiarize yourself with the process of Cross-Compiling.

Cross-Compiling can be a headache; nevertheless, it's a vital skill for OS Development.  As mentioned above, this tutorial will use the Rasperry Pi 5 board, which uses the ARMv8.2-A Instruction Set.  This Instruction Set will run on a Broadcom bcm2712 machine, so we must build a cross-compile environment with a toolchain that can.

> [!TIP]
> It may be worth it to learn more about toolchains and cross-compiling before
> beginning.  Athough not necessary, it may save you some time.  Listed below
> are a few optional resources.

The [ARM GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) includes all that is necessary for an ARM target. 

Cross compiling can present unique challengiFor additional information on cross-compiling read the following:
	-  [cross-compiling guide on OSDev Wiki](https://wiki.osdev.org/GCC_Cross-Compiler)

## General Operating Systems Development
If you're not already familiar with the [OSDev Wiki](https://wiki.osdev.org), you should bookmark it and familiarize yourself with its content.  It's not a replacement for manuals and texts, but a very helpful resource when developing an operating system.

Another cool guide is [Operating Systems: From 0 to 1](https://tuhdo.github.io/os01/).  The book author has graciously made the book [available to download](https://github.com/tuhdo/os01/blob/master/Operating_Systems_From_0_to_1.pdf) for free; this resource is especially helpful if you're less familiar with Bare-metal OS.  Most books focus on OS concepts and skip hardware interaction, which is essential to developing an OS.

The [BrokenThorn OS Development series](http://www.brokenthorn.com/Resources/OSDevIndex.html) is older, but still relevant.  It includes many interesting tutorials such as DMA programming, using Programmable Interrupt Controllers (PIC), etc.


## Rasperry Pi 5

Please visit my [documentation reference page](Docs/rpi/README.md) for Raspberry Pi.


## Additional Resources

### Build Systems
The build system that you choose will depend on the Language selected to develop your operating system.  ***GreenOS*** will be developed mostly in C.

- [GNU Make](https://www.gnu.org/software/make/) (C/C++)

- [GNU CMake](https://cmake.org/) (C/C++, C#, CUDA, Objective-C/C++, Swift)

- [Meson](https://mesonbuild.com/Quick-guide.html) (C/C++, D, Fortran, Java, and Rust)

- [Ninja](https://ninja-build.org/manual.html) (C++, C with some work)

- [Gradle](https://gradle.org/) (C/C++, Java, JavaScript)

### Additional Tools
GNU [Binutils](https://www.gnu.org/software/binutils/)

GNU [Recommended Tools for Compilation](https://www.gnu.org/software/libc/manual/html_node/Tools-for-Compilation.html "Tools For Compiling")

## License

GreenOS - lightweight, secure OS

Copyright (C) 2024 Maurice Green

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.