I am glad to release VirtualMIPS version 0.04. The most important change in this release is LCD and touch screen emulation. Now qtopia 1.6.1 can run successfully although the emulation speed need to be improved.

Changes and improvements include:
  * add LCD emulation of JZ4740 Soc
  * add touchscreen support of JZ4740 Soc
  * support rtc emulation of JZ4740 Soc
  * fix cs8900a network card emulation bug.
  * use scons building system instead of make

Supported SOC:
  * ADM5120
  * JZ4740 (pavo board)

Supported Devices:
  * 4M Bytes nor-flash
  * 1G Bytes Nand-flash (Samsung K9F8G08 1GB)
  * LCD and touchscreen

Supported GUI:
  * Qtopia 1.6.1

Supported OS and bootloader:
  * u-boot: JZ4740
  * Linux 2.6.24 :JZ4740
  * Linux 2.6.22 :JZ4740
  * Linux 2.4.20 :JZ4740
  * Linux 2.6.12 : ADM5120
  * ADM boot : ADM5120