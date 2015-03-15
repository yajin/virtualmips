| **[Document](http://code.google.com/p/virtualmips/wiki/document?tm=6)** | **[TODO List](todolist.md)** | **[Screenshot](screenshot.md)** | **[Status](status.md)** |
|:------------------------------------------------------------------------|:-----------------------------|:--------------------------------|:------------------------|


## Introduction ##

VirtualMIPS is an emulator of MIPS Soc and systems. It is available under the terms of GPL.

If you have any problem of VirtualMIPS, please post on [issue page](http://code.google.com/p/virtualmips/issues/list).

## News ##
2008-10-16 Many days before last release. Maybe the todo list will be "todo" forever!

2008-07-29 The jit part of pavo emulation is not mature, aka it has some critical bugs. Please set jit\_use = 0 to disable JIT in pavo.conf.

2008-07-29 I found someone has tried virtualmips for adm5120 based router emulation and complained that the bootloader worked on router does not work on virtualmips. That is true. Virtualmips is just an emulator and it does **NOT** emulate all the devices of adm5120. If the error message is like this "no device!cpu->pc 9fc0081c vaddr a1022000 paddr 1022000 ", that means the devices on virtual address 0xa1022000 is not emulated. You can dig into it and fix it.

2008-05-28 [VirtualMIPS V0.06](http://virtualmips.googlecode.com/files/virtualmips-0.06.tar.bz2) released.JIT of x86 host is supported in this release of pavo emulation. View the [release notes](ReleaseNotesAAG.md) for more information.

2008-05-12 [VirtualMIPS V0.05](http://virtualmips.googlecode.com/files/virtualmips-0.05.tar.bz2) released.View the [release notes](ReleaseNotesAAF.md) for more information.

2008-04-25 [VirtualMIPS V0.04](http://virtualmips.googlecode.com/files/virtualmips-0.04.tar.bz2) released. LCD and touchscreen emulation is supported in this release.View the [release notes](ReleaseNotesAAE.md) for more information.

2008-04-01 VirtualMIPS V0.03 released. View the [release notes](ReleaseNotesAAD.md) for more information.

2008-03-21 VirtualMIPS V0.02 released. View the [release notes](ReleaseNotesAAC.md) for more information. Thanks for binchen and panjet's help.

2008-03-11 VirtualMIPS V0.02 RC1 released. It adds support of [JZ pavo board](http://www.ingenic.cn/pfwebplus/productServ/kfyd/Hardware/pffaqQuestionContent.aspx?Category=2&Question=3)([JZ 4740 soc](http://www.ingenic.cn/pfwebplus/productServ/App/JZ4740/pfCustomPage.aspx)) **WITHOUT** LCD controller. Currently u-boot can run successfully.(Linux kernel support is on developing). Thanks for peter and panjet's help.

2008-02-25 VirtualMIPS V0.01 released.


---


Copyright © 2008-2009 [yajin](http://vm-kernel.org)