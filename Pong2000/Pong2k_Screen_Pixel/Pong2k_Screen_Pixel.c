#include<stdlib.h>
#include"Pong2k_Screen_Pixel.h"

#define IS_NULL_PIXEL_PTR(P) (!(P))

struct Pong2k_Screen_Pixel
{
	int m_length;
	int m_width;
	unsigned char m_value;
};

void P2K_Screen_Pixel_Init(Pong2k_Screen_Pixel* _screenPixel,int _length, int _width, unsigned char _initValue)
{
    if(IS_NULL_PIXEL_PTR(_screenPixel))
    {
        return;
    }
    _screenPixel->m_length = _length;
    _screenPixel->m_width = _width;
    _screenPixel->m_value = _initValue;
}

Pong2k_Screen_Pixel* P2K_Screen_Pixel_Create(int _length, int _width, unsigned char _initValue)
{
    Pong2k_Screen_Pixel* screenPixel;
    if (!(screenPixel = malloc(sizeof(Pong2k_Screen_Pixel))))
    {
        return NULL;
    }
    /*screenPixel->m_length = _length;
    screenPixel->m_width = _width;
    screenPixel->m_value = _initValue;*/
    P2K_Screen_Pixel_Init(screenPixel, _length, _width, _initValue);
    return screenPixel;
}

void P2K_Screen_Pixel_Destroy(Pong2k_Screen_Pixel** _screenPixel)
{
    if (IS_NULL_PIXEL_PTR(_screenPixel) || IS_NULL_PIXEL_PTR(*_screenPixel))
    {
        return;
    }
    free(*_screenPixel);
}

int P2K_Screen_Pixel_GetLength(Pong2k_Screen_Pixel* _screenPixel)
{
    if(IS_NULL_PIXEL_PTR(_screenPixel))
    {
        return -1;
    }
    return _screenPixel->m_length;
}

void P2K_Screen_Pixel_SetLength(Pong2k_Screen_Pixel* _screenPixel, int _length)
{
    if(IS_NULL_PIXEL_PTR(_screenPixel))
    {
        return;
    }
    _screenPixel->m_length = _length;
}

int P2K_Screen_Pixel_GetWidth(Pong2k_Screen_Pixel* _screenPixel)
{
    if(IS_NULL_PIXEL_PTR(_screenPixel))
    {
        return -1;
    }
    return _screenPixel->m_width;
}

void P2K_Screen_Pixel_SetWidth(Pong2k_Screen_Pixel* _screenPixel, int _width)
{
    if(IS_NULL_PIXEL_PTR(_screenPixel))
    {
        return;
    }
    _screenPixel->m_width = _width;
}

unsigned char P2K_Screen_Pixel_GetValue(Pong2k_Screen_Pixel* _screenPixel)
{
    if(IS_NULL_PIXEL_PTR(_screenPixel))
    {
        return 0;
    }
    return _screenPixel->m_value;
}

void P2K_Screen_Pixel_SetValue(Pong2k_Screen_Pixel* _screenPixel, unsigned char _value)
{
    if(IS_NULL_PIXEL_PTR(_screenPixel))
    {
        return;
    }
    _screenPixel->m_value = _value;
}

