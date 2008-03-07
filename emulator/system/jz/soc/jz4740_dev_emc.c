
/*EMC. */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


#include "device.h"
#include "mips64_memory.h"
#include "cpu.h"
#include "jz4740.h"



 m_uint32_t jz4740_emc_table[JZ4740_EMC_INDEX_MAX];

struct jz4740_emc_data {
   struct vdevice *dev;
   m_uint8_t *jz4740_emc_ptr;
   m_uint32_t jz4740_emc_size;
};

void *dev_jz4740_emc_access(cpu_mips_t *cpu,struct vdevice *dev,
                     m_uint32_t offset,u_int op_size,u_int op_type,
                     m_reg_t *data,m_uint8_t *has_set_value)
{

	struct jz4740_emc_data *d = dev->priv_data;
   //cpu_log(cpu,"","emc offset %x\n",offset);
	if (offset >= d->jz4740_emc_size) {
      *data = 0;
      return NULL;
   }
  /*FIXME:
  currently we do not support nand flash rc check. just set 
  EMC_NFINTS_DECF(bit 3) and EMC_NFINTS_ENCF(bit 2). to tell uboot and decoding and Encoding finished 
  set EMC_NFINTS_ERR(bit 0)=0 : no error*/
  if (offset==EMC_NFINTS)
    {
      jz4740_emc_table[EMC_NFINTS/4] |= 0xc;
    }
  return((void *)(d->jz4740_emc_ptr + offset));

}

void dev_jz4740_emc_init_defaultvalue()
{

#ifdef SIM_PAVO
    /*EMC BCR(31:30):Boot sel
    11:2k page nand flash*/
    jz4740_emc_table[EMC_BCR/4] |= 0xc0000000;
#endif
    
}
int dev_jz4740_emc_init(vm_instance_t *vm,char *name,m_pa_t paddr,m_uint32_t len)
{
 	struct jz4740_emc_data *d;

   /* allocate the private data structure */
   if (!(d = malloc(sizeof(*d)))) {
      fprintf(stderr,"jz4740_emc: unable to create device.\n");
      return  (-1);
   }

   memset(d,0,sizeof(*d));
   if (!(d->dev = dev_create(name)))
     goto err_dev_create;
   d->dev->priv_data = d;
   d->dev->phys_addr = paddr;
   d->dev->phys_len = len;
   d->jz4740_emc_ptr = (m_uint8_t*)(&jz4740_emc_table[0]);
   d->jz4740_emc_size = len;
   d->dev->handler   = dev_jz4740_emc_access;
   d->dev->flags     = VDEVICE_FLAG_NO_MTS_MMAP;
   
	vm_bind_device(vm,d->dev);
	dev_jz4740_emc_init_defaultvalue();
	
	return  (0);

   err_dev_create:
   		free(d);
   		return  (-1);
}


   


   

