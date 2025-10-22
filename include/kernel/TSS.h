#ifndef TSS_HEADER
#define TSS_HEADER

#include <stdint.h>

struct tss_table {
  uint32_t linked; // Previous Task Link Field and reserved 16 bits
  uint32_t esp0;
  uint32_t ss0; // contains 16 bits reserved on high bits
  uint32_t esp1;
  uint32_t ss1; // contains 16 bit reserved on high bits
  uint32_t esp2;
  uint32_t ss2; // contains 16 bit reserved on high bits
  
  uint32_t cr3;
  uint32_t eip;
  uint32_t eflags;
  uint32_t eax;
  uint32_t ecx;
  uint32_t edx;
  uint32_t ebx;
  uint32_t esp;
  uint32_t ebp;
  uint32_t esi;
  uint32_t edi;
  
  

  // Segments registers
  // All contains 16 bit reserved, so we are using 32 bit type
  uint32_t es; 
  uint32_t cs; 
  uint32_t ss;
  uint32_t ds;
  uint32_t fs;
  uint32_t gs;
  //
  
  uint32_t ldtr; // Contains 16 bits reserved on high bits
  uint32_t iopb; // Contains 16 bits reserved on low bits
  uint32_t ssp;
} __attribute__((packed));

#endif
