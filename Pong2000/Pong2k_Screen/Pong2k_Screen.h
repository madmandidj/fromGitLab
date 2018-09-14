#ifndef __PONG2000_SCREEN_H__
#define __PONG2000_SCREEN_H__
#include<stddef.h>
#include "../Pong2k_Screen_Pixel/Pong2k_Screen_Pixel.h"

typedef struct Pong2k_Screen Pong2k_Screen;

/*
typedef struct Pong2k_Screen;
{
    Pong2k_Screen_Pixel** m_screen;
}Pong2k_Screen;
*/
typedef int (*ScreenPixelActionFunc)(void* _element, void* _context);

Pong2k_Screen* P2K_Screen_Create(size_t _length, size_t _width);
void P2K_Screen_Destroy(Pong2k_Screen** _screen);
void P2K_Screen_Print(Pong2k_Screen* _screen);
unsigned char GetPixelValue(Pong2k_Screen* _screen, size_t _length, size_t _width);
void SetPixelValue(Pong2k_Screen* _screen, size_t _length, size_t _width, unsigned char _pixelVal);
void ForAllPixels(Pong2k_Screen* _screen, ScreenPixelActionFunc _screenPixelActionFunc, void* _context);

#endif /*#ifndef __PONG2000_SCREEN_H__*/
