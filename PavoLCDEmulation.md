In the following,${version}=0.06.

# Introduction #

Since version 0.04, VirtualMIPS emulates LCD controller and touch screen for JZ4740. You can test and run your GUI application(QT/GTK for example) in VirtualMIPS.

# Download the following files #

The following files are needed.

  * [u-boot-nand.bin.bz2](http://virtualmips.googlecode.com/files/u-boot-nand.bin.bz2): uboot image for JZ4740 pavo board with LCD support.
  * [uImage-2.4.bz2](http://virtualmips.googlecode.com/files/uImage-2.4.bz2): Linux 2.4 kernel image with LCD support.
  * [uImage-2.6.bz2](http://virtualmips.googlecode.com/files/uImage-2.6.bz2): Linux 2.6.23 kernel image with LCD support.
  * [yaffs2.tar.bz2](http://virtualmips.googlecode.com/files/yaffs2.tar.bz2): yaffs2 utils for making yaffs2 image.
  * [rootfs-20080409.tgz](http://prdownloads.sourceforge.net/virtualmips/rootfs-20080409.tgz?download): rootfs for JZ4740 pavo board from [JZ](http://www.ingenic.cn/eng/default.aspx). [Also can download from here](ftp://ftp.ingenic.cn/3sw/01linux/03root/rootfs.tgz).


# Build VirtualMIPS #

Build VirtualMIPS with lcd support. LibSDL is needed in LCD emulation. Please install it before building VirtualMIPS.

```
#cd virtualmips-${version}/build
#scons pavo
```

# Run qtopia in 2.4 kernel #

Compress and copy uImage-2.4 and uboot image into VirtualMIPS.

```
bzip2 -d uImage-2.4.bz2
bzip2 -d u-boot-nand.bin.bz2
cp u-boot-nand.bin  virtualmips-${version}/build
cp uImage-2.4  virtualmips-${version}/build
```

Make yaffs2 root filesystem. You need to download rootfs first.

```
tar zxvf rootfs-20080409.tgz
cd rootfs-20080409
mkyaffs2image 1 root24 root.yaffs2
```

Make nand falsh image with uboot/kernel/rootfs.

```
cp rootfs-20080409/root.yaffs2  virtualmips-${version}/build
cd virtualmips-${version}/build
./mknandflash
```

Run pavo.

```
virtualmips-${version}/build
./pavo
```

When you enter linux 2.4 shell. Type 'runqpe'.

```
# runqpe
```

![http://virtualmips.googlecode.com/svn/wiki/img/system-info.jpg](http://virtualmips.googlecode.com/svn/wiki/img/system-info.jpg)

# Run qtopia in 2.6 kernel #

Run qtopia in 2.6 is similiar with in 2.4 kernel. The difference is that JZ does not provide qtopia for linux 2.6 kernel. But do not worry. Just copy the qtopia for linux 2.4 rootfs to linux 2.6 rootfs.
```
cd rootfs-20080409
cp -rf root24/opt/* root26/opt/
mkyaffs2image 1 root26 root.yaffs2
```

Copy it to VirtualMIPS

```
cp rootfs-20080409/root.yaffs2  virtualmips-${version}/build
```

Chage the nandflash.conf in virtualmips-${version}/build and make nandflash image.

```
kernel_startaddress=0x400000
kernel_file="uImage-2.6"  ##Makesure this value is your linux 2.6 kernel.
kernel_has_spare=0
```

```
cd virtualmips-${version}/build
./mknandflash
```

Run pavo.

```
virtualmips-${version}/build
./pavo
```

When you enter linux 2.6 shell. Type 'runqpe'.

```
# runqpe
```

![http://virtualmips.googlecode.com/svn/wiki/img/system-info26.jpg](http://virtualmips.googlecode.com/svn/wiki/img/system-info26.jpg)

# Calibrate touchscreen in qtopia #

Do not forget to calibrate touchscreen in qtopia before playing with it.
Settings->recalibrate

![http://virtualmips.googlecode.com/svn/wiki/img/calibrate.jpg](http://virtualmips.googlecode.com/svn/wiki/img/calibrate.jpg)


# Links #

  * [How to build VirtualMIPS](UserManual.md)
  * [How to use network in pavo emulation](pavonetwork.md)