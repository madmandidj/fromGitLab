#ifndef __BITOPS_H__
#define __BITOPS_H__
#define INT_BIT 32

typedef unsigned char Byte;

/* Byte functions */
int BitOn(Byte* _src, int _bitInd);
int BitOff(Byte* _src, int _bitInd);
int IsBitOn(const Byte _src, int bitInd);
int InvertByte(const Byte _src, Byte* _srcInv);
int RotateByteRight(const Byte _src, Byte* _srcRot, int _nPlaces);
void PrintByte(const Byte _byte);

/* Int functions */
int BitOnInt(unsigned int* _src, int _bitInd);
int BitOffInt(unsigned int* _src, int _bitInd);
int IsBitOnInt(const unsigned int _src, int _bitInd);
void PrintInt(const unsigned int _int);

/* Additional functions */
int setBitsNP(Byte* _x, const Byte* _y, int _n, int _p);
int setBitsIJ(unsigned int* _w, int _i, int _j, int value);

#endif /* #ifndef __BITOPS_H__ */
