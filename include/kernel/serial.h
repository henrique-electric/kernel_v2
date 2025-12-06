#ifndef SERIAL_H

enum COM1_registers {
  THR_RBR = 0x3F8,
  IER = 0x3F9,
  IIR_FCR = 0x3FA,
  LCR = 0x3FB,
  MCR = 0x3FC
};

extern void init_serial(void);
extern void write_serial(unsigned char data);
extern unsigned char read_serial(void);

#endif // !SERIAL_H
