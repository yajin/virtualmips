# Introduction #

This article describles how to build u-boot for pavo board.


# Build the toolchain #

Follow [mipsel toolchain guide](ftp://ftp.ingenic.cn/3sw/01linux/08doc/mips_toolchain_guide.pdf) to build the toolchain. Add it to $PATH.

In ubuntu system, you need to change the default shell program to build the toolchain.
```
sudo dpkg-reconfigure dash
```
See [DashAsBinSh](https://wiki.ubuntu.com/DashAsBinSh) for more information.

# Build u-boot #

1. Download [u-boot source](ftp://ftp.ingenic.cn/3sw/01linux/01loader/u-boot/u-boot-1.1.6.tar.bz2) code and [patch](http://virtualmips.googlecode.com/files/u-boot-1.1.6-jz-20080226.patch.gz) first.

```
tar jxvf u-boot-1.1.6.tar.bz
cd u-boot-1.1.6
gzip -cd ../u-boot-1.1.6-jz-20080226.patch.gz | patch -p1
```

2. Modify u-boot source code.
```
- means delete the line
+ means add a line
```

2.1. u-boot-1.1.6/borad/pavo/u-boot-nand.lds

```
46 - __got_start = .; 
46 + __got_start = ALIGN(16);
```



Please refer http://blog.chinaunix.net/u/10695/showart_490721.html and http://www.mail-archive.com/qemu-devel@nongnu.org/msg12726.html for more information.

2.2.u-boot-1.1.6/lib\_mips/borad.c
```
37 - #define TOTAL_MALLOC_LEN        (CFG_MALLOC_LEN + CFG_ENV_SIZE)
37 + #define TOTAL_MALLOC_LEN        (CFG_MALLOC_LEN + CFG_ENV_SIZE*3)
```

Otherwise,the malloc space is not enough for function _env\_relocate\_spec_.

2.3.u-boot-1.1.6/include/configs/pavo.h
```
34 - #define CONFIG_LCD              /* LCD support */
```
Because VirtualMIPS do not emulate LCD controller in current release.

3. build u-boot
```
cd u-boot-1.1.6
make pavo_nand_config
make
```

If everything goes well, file _u-boot-nand.bin_ will be created and that is what we need.

# Links #
  * [How to build and run VirtualMIPS](UserManual.md)
  * [How to build linux kernel for pavo](linuxkernelForPavo.md)
  * http://www.ingenic.cn/pfwebplus/productServ/kfyd/linux/pfFixedPage.aspx