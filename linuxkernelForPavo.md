# Introduction #

This page describes how to build linux 2.4 and 2.6 kernel for pavo demo board.


# Build the toolchain #

Linux 2.4 and 2.6 kernel uses different toolchain.

Linux 2.4:
> gcc-3.3.1 with glibc 2.3.2
Linux 2.6
> gcc-4.1.2 with glibc 2.3.5

Follow [mipsel toolchain guide](ftp://ftp.ingenic.cn/3sw/01linux/08doc/mips_toolchain_guide.pdf) to build the gcc-4.1.2 toolchain. Add it to $PATH.
In ubuntu system, you need to change the default shell program to build the toolchain.
```
sudo dpkg-reconfigure dash
```
See [DashAsBinSh](https://wiki.ubuntu.com/DashAsBinSh) for more information.

For gcc-3.3.1 toolchain, download from jz website. [for linux](ftp://ftp.ingenic.cn/3sw/01linux/00toolchain/mipseltools-gcc-3.3.1.tar.gz).

DO NOT forget to add toolchain path to your system's PATH.

# Download and patch linux 2.6 kernel #

Down [linux 2.6.24 kernel](ftp://ftp.ingenic.cn/3sw/01linux/02kernel/linux-2.6.24/linux-2.6.24.3.tar.bz2) and [patch](http://virtualmips.googlecode.com/files/linux-2.6.24.3-jz-20080409.patch.gz).

```
tar jxvf linux-2.6.24.3.tar.bz2
cd linux-2.6.24.3
gzip -cd ../linux-2.6.24.3-jz-20080304.patch.gz | patch -p1
```

# Configure linux 2.6 kernel #

You can config the kernel by yourself or download the [config file](http://virtualmips.googlecode.com/files/config.linux2.6.24.pavo).
```
cp config.linux2.6.24.pavo linux-2.6.24.3/.config
make
```

Configure the kernel by yourself.

```
make pavo_defconfig
make menuconfig
```

~~1. **Exclude** the LCD support because VirtualMIPS does not emulate LCD controller.~~

~~Device Drivers  ->Graphics support   ->Support for frame buffer devices    ->< >   JZSOC LCD controller support~~
(Since version 0.04, VirtualMIPS support touchscreen emulation)

~~2. **Exclude** the touch screen support.~~

~~Device Drivers ->Character device  -> JZSOC char device support ->< > JzSOC touchpanel driver support~~
(Since version 0.04, VirtualMIPS support LCD emulation)

~~3. **Exclude** the JZ CS8900A Ethernet support.~~

~~Device Driver -> Network device suppor -> Ethernet (10 or 100Mbit) ->< >   JZ CS8900A Ethernet support~~
(Since version 0.03, VirtualMIPS support cs8900a network card emulation)

4. Change the nand config.

Device Drivers ->Memory Technology Device (MTD) support ->NAND Device Support -> (63)  which page inside a block will store the badblock mark

5. **Exclude** the USB support.

Device Drivers ->[ ] USB support

6. **Exclude** the MMC/SD card support support.

Device Drivers -> < > MMC/SD card support

7. **Exclude** the ac97 support.

Device Drivers ->Sound ->Advanced Linux Sound Architecture ->System on Chip audio support->< > SoC Audio for Ingenic jz4740 chip

8. Modify 8250 driver otherwise emulator always has the following warning message.

```
serial8250: too much work for irq9
```
QEMU also has the same problem.
http://kerneltrap.org/mailarchive/linux-kernel/2008/2/7/769924

Just comment line 1502 and 1503 in drivers/serial/8250.c.

```
1500                 if (l == i->head && pass_counter++ > PASS_LIMIT) {
1501                         /* If we hit this, we're dead. */
1502                 //        printk(KERN_ERR "serial8250: too much work for "
1503                 //                "irq%d\n", irq);
1504                         break;
1505                 }

```


Saving the config option and make linux kernel. Type 'make' to make linux kernel or 'make uImage' to generate linux image for u-boot.
```
make
make uImage
```

uImage will be created in arch/mips/boot/ directory.


# Download and patch linux 2.4 kernel #

Down [celinux-040503.tar.bz2](ftp://ftp.ingenic.cn/3sw/01linux/02kernel/celinux/celinux-040503.tar.bz2) and [patch](http://virtualmips.googlecode.com/files/celinux-040503-jz-20080409.patch.gz).

```
tar jxvf celinux-040503.tar.bz2
cd celinux-040503
gzip -cd ../celinux-040503-jz-20080409.patch.gz | patch -p1
```

# Configure linux 2.4 kernel #

You can config the kernel by yourself or download the [config file](http://virtualmips.googlecode.com/files/config.linux2.4.20.pavo).
```
cp config.linux2.4.20.pavo celinux-040503/.config
make
```

Type 'make' to make linux kernel or 'make uImage' to generate linux image for u-boot.
```
make
make uImage
```

uImage will be created in arch/mips/uboot/ directory.

# Links #
  * [How to build and run VirtualMIPS](UserManual.md)
  * [How to build u-boot for pavo](ubootForPavo.md)
  * http://www.ingenic.cn/pfwebplus/productServ/kfyd/linux/pfFixedPage.aspx