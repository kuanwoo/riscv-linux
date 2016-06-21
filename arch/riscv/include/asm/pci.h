#ifndef __ASM_RISCV_PCI_H
#define __ASM_RISCV_PCI_H
#ifdef __KERNEL__

#include <linux/types.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>

#include <asm/io.h>

#define PCIBIOS_MIN_IO		0x1000
#define PCIBIOS_MIN_MEM		0

/* RISC-V shim does not initialize PCI bus */
#define pcibios_assign_all_busses() 1

/* RISC-V TileLink and PCIe share the share address space */
#define PCI_DMA_BUS_IS_PHYS 1

extern int isa_dma_bridge_buggy;

#ifdef CONFIG_PCI
static inline int pci_get_legacy_ide_irq(struct pci_dev *dev, int channel)
{
	/* no legacy IRQ on risc-v */
	return -ENODEV;
}

static inline int pci_proc_domain(struct pci_bus *bus)
{
	/* always show the domain in /proc */
	return 1;
}
#endif  /* CONFIG_PCI */

#endif  /* __KERNEL__ */
#endif  /* __ASM_PCI_H */
