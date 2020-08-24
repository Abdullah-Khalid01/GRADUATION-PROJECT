#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

#define Set_bit(byte,bit) (byte|=(1<<bit))
#define Clr_bit(byte,bit) (byte&=~(1<<bit))
#define toggle_bit(byte,bit) (byte^=(1<<bit))
#define Get_bit(byte,bit) ((byte>>bit)&1)

#endif // BIT_MATH_H_INCLUDED
