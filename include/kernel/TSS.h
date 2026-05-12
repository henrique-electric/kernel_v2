#ifndef TSS_HEADER
#define TSS_HEADER

#include <stdint.h>

/**
 * @file TSS.h
 * @brief Task State Segment (TSS) definitions.
 *
 * The Task State Segment is a special structure on x86 processors that holds information
 * about a task. It's used by the OS kernel for hardware context switching and for storing
 * ring 0 stack pointers (esp0, ss0) to handle privilege level transitions (e.g., syscalls).
 */

/**
 * @struct tss_table
 * @brief Represents the x86 Task State Segment structure.
 *
 * Uses the packed attribute to ensure it maps exactly to the hardware specification.
 */
struct tss_table {
  uint32_t linked; /**< Previous Task Link Field and reserved 16 bits */
  uint32_t esp0;   /**< Ring 0 stack pointer */
  uint32_t ss0;    /**< Ring 0 stack segment (contains 16 bits reserved on high bits) */
  uint32_t esp1;   /**< Ring 1 stack pointer */
  uint32_t ss1;    /**< Ring 1 stack segment (contains 16 bits reserved on high bits) */
  uint32_t esp2;   /**< Ring 2 stack pointer */
  uint32_t ss2;    /**< Ring 2 stack segment (contains 16 bits reserved on high bits) */
  
  uint32_t cr3;    /**< Page directory base register */
  uint32_t eip;    /**< Instruction pointer */
  uint32_t eflags; /**< EFLAGS register */
  uint32_t eax;    /**< EAX register */
  uint32_t ecx;    /**< ECX register */
  uint32_t edx;    /**< EDX register */
  uint32_t ebx;    /**< EBX register */
  uint32_t esp;    /**< ESP register */
  uint32_t ebp;    /**< EBP register */
  uint32_t esi;    /**< ESI register */
  uint32_t edi;    /**< EDI register */
  
  // Segments registers
  // All contains 16 bit reserved, so we are using 32 bit type
  uint32_t es;     /**< ES segment register */
  uint32_t cs;     /**< CS segment register */
  uint32_t ss;     /**< SS segment register */
  uint32_t ds;     /**< DS segment register */
  uint32_t fs;     /**< FS segment register */
  uint32_t gs;     /**< GS segment register */
  //
  
  uint32_t ldtr;   /**< Local Descriptor Table Register (contains 16 bits reserved on high bits) */
  uint32_t iopb;   /**< I/O Map Base Address (contains 16 bits reserved on low bits) */
  uint32_t ssp;    /**< Shadow Stack Pointer (if used/supported) */
} __attribute__((packed));

#endif
