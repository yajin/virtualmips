# Compile VirtualMIPS With JIT Support #

JIT is supported since version 0.06. Only x86 host is supported. AMD64 will be supported in the future.

JIT can be used in pavo emulation. ADM5120 is not supported.

When compiling VritualMIPS, scons script will check your host automatically. If scons thinks your host is x86, it builds VirtualMIPS with JIT support. Otherwise, it builds VritualMIPS without JIT support.

# Set configure file #

In order to use JIT in pavo emulation, jit\_use must be set to 1 in pavo.conf.
```
jit_use = 1
```

If you do not want use JIT in pavo emulation, set jit\_use = 0.

jit\_use can only be set to 1 when building VirtualMIPS with JIT support. If you set jit\_use=1 when building VirtualMIPS without JIT support, an error message will be given and VirtualMIPS will exit.
```
yajin@kill-bill:/media/disk/develop/release/trunk/build$ sudo ./pavo 
VirtualMIPS (version 0.06)
Copyright (c) 2008 yajin.
Build date: May 28 2008 20:31:22

You must compile with JIT Support to use jit. 
pavo: /media/disk/develop/release/trunk/emulator/system/jz/pavo/pavo.c:335: pavo_parse_configure: Assertion `(0==1)' failed.
Aborted
```
