## high priority ##

  * ~~add support of [JZ](http://www.ingenic.cn) 4740 Soc.~~ (finished in 2008-04-24)

  * Loogson host support.

  * dynamic binary translation(JIT)
    * In order to improve the performance of emulator, jit is used to translate the guest code into host code, mips to x86 for example, on the fly. QEMU has an excellent architectural of JIT. However, it relays on the specific version of gcc(gcc-3). We want to design and implement a framework of JIT which **DOES NOT** relay on the version of compiler and host architectural.
    * Similiar architectural JIT optimization. Both loogson and JZ-4740/PSP?? are MIPS based. JIT can be optimized in loogson.

  * add support of PSP??.

## middle priority ##

  * OKL4 porting
    * porting [OKL4](http://www.ok-labs.com/products/okl4) to jz4740. OKL4 is a good virtualization platform and it is very cool to see two operating system running on VirutalMIPS at the same time.

  * Windows host os support.

## low priority ##

  * add support of swarm board (BCM1250)
  * add support of [fulong](http://www.linux-mips.org/wiki/Fulong)
  * ~~add support of au1200 (low priority)~~ ([Skyeye](http://www.skyeye.org) is working on this)