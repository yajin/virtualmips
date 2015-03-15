# How to use the gdb interface #
Gdb is an useful tool for debugging kernel. VirtualMIPS has a gdb interface and you can debug your program without gdb stub in you program. To use gdb interface in VirtualMIPS, modify the configure file of VirtualMIPS(adm5120.conf for ADM5120 emulation for example).

```
#set to 1 to enable gdb debug
gdb_debug = 1
#the port for remote gdb connection
gdb_port = 5555
```
Run VirtualMIPS.
```
KILL-BILL:/home/root/develop/virtualmips/emulator# ./adm5120
VirtualMIPS (version 0.01)
Copyright (c) 2008 yajin.
Build date: Feb 27 2008 11:09:30

Using configure file: adm5120.conf
ram_size: 16M bytes
boot_method: ELF
flash_size: 4M bytes
flash_file_name: flash.bin
flash_phy_address: 0x1fc00000
kernel_file_name: vmlinux
GDB debug enable
GDB port: 5555
Loading ELF file 'vmlinux'...
ELF entry point: 0x80214000

ADM5120 'adm5120': starting simulation (CPU0 PC=0x80214000), JIT disabled.
Waiting for gdb on port 5555.
```

Open other terminal and connect to gdb on port 5555.

```
KILL-BILL:/home/root/develop/buildroot/linux# mipsel-linux-gdb
GNU gdb 6.3
Copyright 2004 Free Software Foundation, Inc.
GDB is free software, covered by the GNU General Public License, and you are
welcome to change it and/or distribute copies of it under certain conditions.
Type "show copying" to see the conditions.
There is absolutely no warranty for GDB.  Type "show warranty" for details.
This GDB was configured as "--host=i386-pc-linux-gnu --target=mipsel-linux-uclibc".
(gdb) add-symbol-file vmlinux   
add symbol table from file "vmlinux" at
(y or n) y
Reading symbols from /home/root/develop/buildroot/linux/vmlinux...done.
(gdb) target remote localhost:5555    <-- connect to VirtualMIPS
Remote debugging using localhost:5555
0xffffffff80214000 in kernel_entry () at kernel/timer.c:1162
1162    }
(gdb) b start_kernel   <-- add a breakpoint at start_kernel
Breakpoint 1 at 0x802145e8: file init/main.c, line 434.
(gdb) c
Continuing.

Breakpoint 1, start_kernel () at init/main.c:434
434             printk(KERN_NOTICE);
(gdb)
```