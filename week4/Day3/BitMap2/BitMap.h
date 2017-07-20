#ifndef __BITMAP_H__
#define __BITMAP_H__
#define CHAR_BIT_NUM 8

typedef struct
{
	char* m_bits;
	int m_nof;
}BitMap;

typedef int(*BitOps)(BitMap* _bM, int _bNum);

BitMap* CreateBitMap(int _nof);
void 	DestroyBitMap(BitMap* _bM);
void	PrintBitMap(BitMap* _bM, int _nof);
int 	BitOn(BitMap* _bM, int _bNum);
int 	BitOff(BitMap* _bM, int _bNum);
int 	IsBitOn(BitMap* _bM, int _bNum);

#endif /* #ifndef __BITMAP_H__ */
