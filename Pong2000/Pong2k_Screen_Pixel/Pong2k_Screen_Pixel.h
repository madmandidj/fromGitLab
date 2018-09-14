#ifndef __PONG2000_SCREEN_PIXEL_H__
#define __PONG2000_SCREEN_PIXEL_H__

typedef struct Pong2k_Screen_Pixel Pong2k_Screen_Pixel;

Pong2k_Screen_Pixel* P2K_Screen_Pixel_Create(int _length, int _width, unsigned char _initValue);
void P2K_Screen_Pixel_Init(Pong2k_Screen_Pixel* _screenPixel,int _length, int _width, unsigned char _initValue);
void P2K_Screen_Pixel_Destroy(Pong2k_Screen_Pixel** _screenPixel);
int P2K_Screen_Pixel_GetLength(Pong2k_Screen_Pixel* _screenPixel);
void P2K_Screen_Pixel_SetLength(Pong2k_Screen_Pixel* _screenPixel, int _length);
int P2K_Screen_Pixel_GetWidth(Pong2k_Screen_Pixel* _screenPixel);
void P2K_Screen_Pixel_SetWidth(Pong2k_Screen_Pixel* _screenPixel, int _width);
unsigned char P2K_Screen_Pixel_GetValue(Pong2k_Screen_Pixel* _screenPixel);
void P2K_Screen_Pixel_SetValue(Pong2k_Screen_Pixel* _screenPixel, unsigned char _value);

#endif /* #ifndef __PONG2000_SCREEN_PIXEL_H__ */
