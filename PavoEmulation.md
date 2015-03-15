In the following,${version}=0.06.
# Download the following files #

The following files are needed.

  * [u-boot-nand.bin.bz2](http://virtualmips.googlecode.com/files/u-boot-nand.bin.bz2): uboot image for JZ4740 pavo board with LCD support.
  * [uImage-2.4.bz2](http://virtualmips.googlecode.com/files/uImage-2.4.bz2): Linux 2.4 kernel image with LCD support.
  * [uImage-2.6.bz2](http://virtualmips.googlecode.com/files/uImage-2.6.bz2): Linux 2.6.23 kernel image with LCD support.
  * [yaffs2.tar.bz2](http://virtualmips.googlecode.com/files/yaffs2.tar.bz2): yaffs2 utils for making yaffs2 image.
  * [rootfs-20080409.tgz](http://prdownloads.sourceforge.net/virtualmips/rootfs-20080409.tgz?download): rootfs for JZ4740 pavo board from [JZ](http://www.ingenic.cn/eng/default.aspx). [Also can download from here](ftp://ftp.ingenic.cn/3sw/01linux/03root/rootfs.tgz).

# Compile yaffs2 utils #

We need mkyaffs2image tool to convert the rootfs into yaffs2 format. You CAN NOT use the tool from www.yaffs.net directly. Please use the utils from jz's linux patch. I strip the source code from jz's linux patch. Please download it first.

```
tar jxvf yaffs2.tar.bz2
cd yaffs2/utils
make
```

'mkyaffs2image' will be created. Please copy it to /bin or /usr/bin or just put the yaffs2/utils into your system's $PATH.

# Make nand flash image for pavo #

```
tar zxvf rootfs-20080409.tgz
cd rootfs-20080409
mkyaffs2image 1 root24 root.yaffs2
```

It will create the yaffs2 root file system root.yaffs2. Copy it to VirtualMIPS directory.

```
cp rootfs-20080409/root.yaffs2  virtualmips-${version}/build
```

Decompress and copy u-boot image and linux kernel image to VirtualMIPS.

```
bzip2 -d uImage-2.4.bz2
bzip2 -d uImage-2.6.bz2
bzip2 -d u-boot-nand.bin.bz2
cp u-boot-nand.bin  virtualmips-${version}/build
cp uImage-2.4  virtualmips-${version}/build
cp uImage-2.6  virtualmips-${version}/build
```

VirtualMIPS provides a tool "mknandflash" to create the nand flash file(Source code is tool/mknandflash.c). Make sure you have setten the right u-boot/kernel image file name and root filesytem file name/startaddress in the configure file of mknandflash(nandflash.conf in directory virtualmips-${version}/build).See nandflash.conf for more information.

```
cd virtualmips-${version}/build
./mknandflash 
```

It will create a directory nandflash1GB containning nand flash file(One file one block).

# Create TAP device (optional) #

Since version 0.03, VirtualMIPS supports network card(cs8900a) emulation. Before using network card emulation, you need to create a tap device first.

```
tunctl
```

It will create a tap device 'tap0'.
```
[root@kill-bill /]# tunctl 
Set 'tap0' persistent and owned by uid 0
```

If tunctl command is not found in your computer, please install uml\_utilities first.

**Debian etch
```
sudo apt-get install uml-utilities
```**

**Archlinux
```
sudo pacman -S user-mode-linux
sudo pacman -S uml_utilities
modprobe tun
```**

Change the pavo.conf in virtualmips-${version}/build to enable network card emulation.

```
cs8900_enable = 1
cs8900_iotype = "tap:tap0"  <- tap name can be changed according to your system. 
```

Read [this document](pavonetwork.md) for how to use network in VirtualMIPS.


# Run pavo emulation #

```
cd virtualmips-${version}/build
./pavo
```


```
yajin@kill-bill:/media/disk/develop/release/trunk/build$ sudo ./pavo 
VirtualMIPS (version 0.06)
Copyright (c) 2008 yajin.
Build date: May 28 2008 19:58:16

Using configure file: pavo.conf
ram_size: 64M bytes 
boot_method: Binary 
flash_type: NAND FLASH 
flash_size: 1024M bytes 
boot_from: NAND FLASH 
CS8900 net card enabled
CS8900 iotype tap:tap0 
CPU0: carved JIT exec zone of 64 Mb into 2048 pages of 32 Kb.

loaded 926 nand flash file from directory "nandflash1GB". 
VM 'pavo': starting simulation (CPU0 PC=0x80000004), JIT enabled.


NAND Secondary Program Loader

Starting U-Boot ...


U-Boot 1.1.6 (Apr 18 2008 - 16:24:45)

Board: Ingenic PAVO (CPU Speed 336 MHz)
DRAM:  64 MB
Top of RAM usable for U-Boot at: 84000000
LCD panel info: 480 x 272, 32 bit/pix
Reserving 512k for LCD Framebuffer at: 83f80000
Reserving 458k for U-Boot at: 83f0c000
Reserving 896k for malloc() at: 83e2c000
Reserving 44 Bytes for Board Info at: 83e2bfd4
Reserving 60 Bytes for Global Data at: 83e2bf98
Reserving 128k for boot params() at: 83e0bf98
Stack Pointer at: 83e0bf78
Now running in RAM - U-Boot at: 83f0c000
Flash:  0 kB
NAND:1024 MiB
*** Warning - bad CRC or NAND, using default environment

[LCD] Initializing LCD frambuffer at 83f80000
vid->vl_row = 0x00000110   vid->vl_col 0x000001e0 NBITS (vid->vl_bpix) vid->vl_col 0x00000020
palette_mem_size = 0x00000200
lcdbase = 0x83f80000
fb_size = 0x0007f800
fbi->palette = 0x84000600
fbi = 0x83f428a8
[LCD] Drawing the logo...
Logo: width 160  height 96  colors 31  cmap 62
In:    serial
Out:   lcd
Err:   lcd
### main_loop entered: bootdelay=3

### main_loop: bootcmd="nand read 0x80600000 0x400000 0x300000;bootm"
Hit any key to stop autoboot:  0 

NAND read: device 0 offset 0x400000, size 0x300000
 3145728 bytes read: OK
## Booting image at 80600000 ...
   Image Name:   Linux-2.6.24.3
   Image Type:   MIPS Linux Kernel Image (gzip compressed)
   Data Size:    1808433 Bytes =  1.7 MB
   Load Address: 80010000
   Entry Point:  802f92c0
   Verifying Checksum ... OK
   Uncompressing Kernel Image ... OK
No initrd
## Transferring control to Linux (at address 802f92c0) ...
## Giving linux memsize in MB, 64

Starting kernel ...

Linux version 2.6.24.3 (root@KILL-BILL) (gcc version 4.1.2) #1 PREEMPT Thu Apr 24 19:08:53 CST 2008
CPU revision is: 0ad0024f (Ingenic JZRISC)
CPU clock: 336MHz, System clock: 112MHz, Peripheral clock: 112MHz, Memory clock: 112MHz
JZ4740 PAVO board setup
Determined physical RAM map:
 memory: 04000000 @ 00000000 (usable)
User-defined physical RAM map:
 memory: 04000000 @ 00000000 (usable)
Zone PFN ranges:
  Normal          0 ->    16384
Movable zone start PFN for each node
early_node_map[1] active PFN ranges
    0:        0 ->    16384
Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 16256
Kernel command line: mem=64M console=ttyS0,57600n8 ip=off rootfstype=yaffs2 root=/dev/mtdblock2 rw
Primary instruction cache 16kB, VIPT, 4-way, linesize 32 bytes.
Primary data cache 16kB, 4-way, VIPT, no aliases, linesize 32 bytes
Synthesized clear page handler (25 instructions).
Synthesized copy page handler (44 instructions).
Synthesized TLB refill handler (20 instructions).
Synthesized TLB load handler fastpath (32 instructions).
Synthesized TLB store handler fastpath (32 instructions).
Synthesized TLB modify handler fastpath (31 instructions).
PID hash table entries: 256 (order: 8, 1024 bytes)
Console: colour dummy device 80x25
console [ttyS0] enabled
Dentry cache hash table entries: 8192 (order: 3, 32768 bytes)
Inode-cache hash table entries: 4096 (order: 2, 16384 bytes)
Memory: 60640k/65536k available (3001k kernel code, 4828k reserved, 906k data, 172k init, 0k highmem)
Mount-cache hash table entries: 512
net_namespace: 64 bytes
NET: Registered protocol family 16
Linux Plug and Play Support v0.97 (c) Adam Belay
SCSI subsystem initialized
NET: Registered protocol family 2
IP route cache hash table entries: 1024 (order: 0, 4096 bytes)
TCP established hash table entries: 2048 (order: 2, 16384 bytes)
TCP bind hash table entries: 2048 (order: 1, 8192 bytes)
TCP: Hash tables configured (established 2048 bind 2048)
TCP reno registered
Total 4MB memory at 0x3400000 was reserved for IPU
Power Management for JZ
yaffs Apr 24 2008 19:04:47 Installing. 
io scheduler noop registered
io scheduler anticipatory registered (default)
io scheduler deadline registered
io scheduler cfq registered
jzlcd use 1 framebuffer:
jzlcd fb[0] phys addr =0x03d00000
LCDC: PixClock:9081081 LcdClock:25846153
Console: switching to colour frame buffer device 60x34
fb0: jz-lcd frame buffer device, using 512K of video memory
JzSOC onchip RTC installed !!!
JzSOC: char device family.
Jz generic touch screen driver registered
JZ4740 SAR-ADC driver registered
JZ UDC hotplug driver registered
Serial: 8250/16550 driver $Revision: 1.1.1.1 $ 2 ports, IRQ sharing disabled
UDC starting monitor thread
serial8250: ttyS0 at MMIO 0x0 (irq = 9) is a 16450
serial8250: ttyS1 at MMIO 0x0 (irq = 8) is a 16450
RAMDISK driver initialized: 2 RAM disks of 4096K size 1024 blocksize
loop: module loaded
Jz CS8900A driver for Linux (V0.02)
eth%d: CS8900A rev ; detected
Linux video capture interface: v2.00
JzSOC Camera Interface Module (CIM) driver registered
Ingenic CMOS camera sensor driver registered
Driver 'sd' needs updating - please use bus_type methods
block2mtd: version $Revision: 1.30 $
NAND device: Manufacturer ID: 0xec, Chip ID: 0xd3 (Samsung NAND 1GiB 3,3V 8-bit)
Scanning device for bad blocks
Creating 6 MTD partitions on "NAND 1GiB 3,3V 8-bit":
0x00000000-0x00400000 : "NAND BOOT partition"
0x00400000-0x00800000 : "NAND KERNEL partition"
0x00800000-0x08000000 : "NAND ROOTFS partition"
0x08000000-0x10000000 : "NAND DATA1 partition"
0x10000000-0x20000000 : "NAND DATA2 partition"
0x20000000-0x40000000 : "NAND VFAT partition"
mice: PS/2 mouse device common for all mice
JzSOC Watchdog Timer: timer margin 60 sec
TCP cubic registered
NET: Registered protocol family 1
NET: Registered protocol family 17
RPC: Registered udp transport module.
RPC: Registered tcp transport module.
yaffs: dev is 32505858 name is "mtdblock2"
yaffs: Attempting MTD mount on 31.2, "mtdblock2"
VFS: Mounted root (yaffs2 filesystem).
Freeing unused kernel memory: 172k freed
Algorithmics/MIPS FPU Emulator v1.5
#


```

![http://virtualmips.googlecode.com/svn/wiki/img/system-info.jpg](http://virtualmips.googlecode.com/svn/wiki/img/system-info.jpg)

# How to stop emulation #

press **CTRL+\** to stop emulation. CTRL+C is sent to guest.

# Links #

  * [How to run pavo LCD emulation](PavoLCDEmulation.md)
  * [How to use network in pavo emulation](pavonetwork.md)
