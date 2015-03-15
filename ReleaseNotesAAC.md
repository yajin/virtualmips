I am glad to release VirtualMIPS version 0.02. Changes and improvements include:
  * add 'reboot' support of jz4740
  * add interrupt controller emulation of jz4740
  * add DMA controller emulation of jz4740
  * fix the bug of uart emulation of jz4740
  * update mknandflash tool to generate flash file of linux kernel and rootfs

Supported SOC:
  * ADM5120
  * JZ4740 (pavo board)

Supported OS and bootloader:
  * u-boot: JZ4740
  * Linux 2.6.24 :JZ4740
  * Linux 2.6.22 :JZ4740
  * Linux 2.6.12 : ADM5120
  * ADM boot : ADM5120