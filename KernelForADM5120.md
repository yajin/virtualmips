# Build linux 2.6 kernel for ADM5120 #

Tom gives us [an excellent article](http://www.student.tue.nl/Q/t.f.a.wilms/adm5120/) of how to build linux 2.6 kernel for ADM5120. Just follow it. However, there are some mirror changes.

1. commit the switch core initiation code because VirtualMIPS does not emulate switch core of ADM5120.

```
drivers/net/adm5120sw.c.

Line501 //module_init(adm5120_sw_init);
Line502 //module_exit(adm5120_sw_exit);
```

2. When configuring the kernel, do NOT include USB Support.
```
    Device Drivers  --->
      USB support  --->       
         < > Support for Host-side USB
```

3. (Optional)Modify the prom\_meminit function.
```

#define ADM5120_MEMCTRL_SDRAM1_MASK	0x20  
void __init prom_meminit(void)
{
	unsigned long base=CPHYSADDR(PFN_ALIGN(&_end));
	unsigned long size;

	u32 memctrl = *(u32*)KSEG1ADDR(ADM5120_MEMCTRL);
	size = adm_sdramsize[memctrl & ADM5120_MEMCTRL_SDRAM_MASK]; 
	if (memctrl & ADM5120_MEMCTRL_SDRAM1_MASK)                  //by yajin
		size *= 2;                                          //by yajin
	add_memory_region(base, size-base, BOOT_MEM_RAM);
}

```