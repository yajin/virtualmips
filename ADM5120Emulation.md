# Download the files first #

  * [run.bin.bz2](http://downloads.sourceforge.net/virtualmips/run.bin.bz2): Linux 2.6 kernel image and rootfs for adm5120.
  * [vmlinux-adm5120.bz2](http://downloads.sourceforge.net/virtualmips/vmlinux-adm5120.bz2): Linux 2.6 kernel image for adm5120.

# How to run adm5120 emulation #

Type the following command to run ADM5120 emulation.(Make sure you have download and decompress the kernel image and copy it to VirtualMIPS directory.)

```
bzip2 -d run.bin.bz2
bzip2 -d vmlinux-adm5120.bz2
cp run.bin virtualmips-${version}/build
cp vmlinux-adm5120 virtualmips-${version}/build
cd virtualmips-${version}/build
./adm5120
```


```
VirtualMIPS (version 0.03)
Copyright (c) 2008 yajin.
Build date: Apr  1 2008 22:27:33

Using configure file: adm5120.conf
ram_size: 16M bytes 
boot_method: ELF 
flash_type: NOR FLASH 
flash_size: 4M bytes 
flash_file_name: run.bin 
flash_phy_address: 0x1fc00000 
kernel_file_name: vmlinux-adm5120 
Loading ELF file 'vmlinux-adm5120'...
ELF entry point: 0x80214000

ADM5120 'adm5120': starting simulation (CPU0 PC=0x80214000), JIT disabled.
Linux version 2.6.12-rc1-mipscvs-20050403 (root@kill-bill) (gcc version 3.4.2) #4 Mon Feb 25 21:08:49 CST 2008
CPU revision is: 0001800b
ADM5120 board setup
System has no PCI BIOS
Determined physical RAM map:
 memory: 00d2c000 @ 002d4000 (usable)
Built 1 zonelists
Kernel command line: 
Primary instruction cache 8kB, physically tagged, 2-way, linesize 32 bytes.
Primary data cache 8kB, 2-way, linesize 32 bytes.
Synthesized TLB refill handler (19 instructions).
Synthesized TLB load handler fastpath (31 instructions).
Synthesized TLB store handler fastpath (31 instructions).
Synthesized TLB modify handler fastpath (30 instructions).
PID hash table entries: 128 (order: 7, 2048 bytes)
CPU clock: 175MHz
Dentry cache hash table entries: 4096 (order: 2, 16384 bytes)
Inode-cache hash table entries: 2048 (order: 1, 8192 bytes)
Memory: 13312k/13488k available (1819k kernel code, 160k reserved, 297k data, 676k init, 0k highmem)
Mount-cache hash table entries: 512
Checking for 'wait' instruction...  available.
NET: Registered protocol family 16
Initializing Cryptographic API
ADM5120 LED & GPIO driver
ttyS0 at I/O 0x12600000 (irq = 1) is a ADM5120
ttyS1 at I/O 0x12800000 (irq = 2) is a ADM5120
io scheduler noop registered
RAMDISK driver initialized: 16 RAM disks of 4096K size 1024 blocksize
ADM5120 board flash (0x200000 at 0x1fc00000)
ADM5120: Found 1 x16 devices at 0x0 in 16-bit bank
 Amd/Fujitsu Extended Query Table at 0x0040
number of CFI chips: 1
cfi_cmdset_0002: Disabling erase-suspend-program due to code brokenness.
NET: Registered protocol family 2
IP: routing cache hash table of 512 buckets, 4Kbytes
TCP established hash table entries: 1024 (order: 1, 8192 bytes)
TCP bind hash table entries: 1024 (order: 0, 4096 bytes)
TCP: Hash tables configured (established 1024 bind 1024)
NET: Registered protocol family 17
Freeing unused kernel memory: 2099677k freed

Please press Enter to activate this console. 
Algorithmics/MIPS FPU Emulator v1.5


BusyBox v1.00 (2008.02.22-15:41+0000) Built-in shell (ash)
Enter 'help' for a list of built-in commands.

/ # cat /proc/cpuinfo 
system type		: ADM5120 Board
processor		: 0
cpu model		: MIPS 4Kc V0.11
BogoMIPS		: 0.00
wait instruction	: yes
microsecond timers	: yes
tlb_entries		: 32
extra interrupt vector	: yes
hardware watchpoint	: no
VCED exceptions		: not available
VCEI exceptions		: not available
/ # 


```