
---


You need to download VirtualMIPS first. The [latest version](http://virtualmips.googlecode.com/files/virtualmips-0.06.tar.bz2) is v0.06. In the following, ${version} means the latest version number.

Supported systems:
  * JZ [Pavo demo borad](http://www.ingenic.cn/pfwebplus/productServ/kfyd/Hardware/pffaqQuestionContent.aspx?Category=2&Question=3)(with LCD controller).
  * ADM5120

# Library dependence #

Library dependence:
  * libelf
  * libconfuse
  * libSDL

  * Debian etch / ubuntu hardy
```
sudo apt-get install build-essential
sudo apt-get install libelf-dev
sudo apt-get install libconfuse-dev
sudo apt-get install  libsdl1.2-dev
```

  * Archlinux
```
sudo pacman -S libelf
sudo pacman -S confuse
sudo pacman -S libsdl
```



# Build VirtualMIPS #

Build VirtualMIPS is very easy. VirtualMIPS uses [scons](http://www.scons.org) to build the system instead of make. Please install scons in your system first.

  * Debian etch / ubuntu hardy
```
sudo apt-get install scons
```
  * Archlinux
```
sudo pacman -S scons
```


```
tar -jxvf virtualmips-${version}.tar.bz2
cd virtualmips-${version}/build
```

Use scons-h to see the build options of VirtualMIPS.

```
# scons -h

scons: Reading SConscript files ...
scons: done reading SConscript files.

Usage:
        scons [target] [compile options]
Targets:
        adm5120:                Build VirtualMIPS for adm5120 emulation
        pavo:                   Build VirtualMIPS for pavo emulation
        mknandflash:            Build mknandflash tool

Compile Options:
        jit:                    Set to 0 to compile VirtualMIPS *without* JIT support(pavo only). Default 1.
        lcd:                    Set to 0 to compile VirtualMIPS *without* LCD support(pavo only). Default 1.
        mhz:                    Set to 1 to test emulator's speed. Default 0.
        debug:                  Set to 1 to compile with -g. Default 0.
        o:                      Set optimization level.Default 3.
        cc:                     Set compiler.Default "gcc". You can set cc=gcc-3.4 to use gcc 3.4.

```

```
#scons pavo
#scons mknandflash
#scons adm5120 
```
If everything goes well, file 'adm5120'/'pavo'/'mknandflash' will be created in virtualmips-${version}/build.

Other build options example:
```
# scons pavo jit=1              <--build VirtualMIPS for pavo emulation *with* JIT support
# scons pavo jit=0              <--build VirtualMIPS for pavo emulation *without* JIT support
# scons pavo lcd=1   		<--build VirtualMIPS for pavo emulation *with* LCD support
# scons pavo lcd=0   		<--build VirtualMIPS for pavo emulation *without* LCD support
# scons adm5120      		<--build VirtualMIPS for adm5120 emulation.
# scons mknandflash  		<--build mknandflash tool.
# scons pavo -c      		<--clean the build of VirtualMIPS for pavo.
# scons adm5120 -c   		<--clean the build of VirtualMIPS for adm5120.
# scons mknandflash -c	        <--clean the build of mknandflash tool.
# scons pavo o=3                <--build VirtualMIPS with O3 optimization.
# scons pavo cc=gcc-3.4         <--build VirtualMIPS with gcc-3.4
```


# Links #
  * [How to run pavo emulation](PavoEmulation.md)
  * [How to run adm5120 emulation](ADM5120Emulation.md)
  * [Build linux kernel for ADM5120](KernelForADM5120.md)
  * [how to use gdb to debug kernel](gdbinterface.md)
  * [How to build u-boot for pavo borad](ubootForPavo.md)
  * [How to build linux kernel for pavo borad](linuxkernelForPavo.md)
  * [How to use network in pavo emulation](pavonetwork.md)