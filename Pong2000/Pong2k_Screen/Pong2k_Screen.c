#include "Pong2k_Screen.h"
#include <stdlib.h>
#include <stdio.h>

#define IS_NULL_SCREEN_PTR(P) (!(P))

#include "../Pong2k_Screen_Pixel/Pong2k_Screen_Pixel.h"

typedef struct PixelArray
{
    size_t m_size;
    Pong2k_Screen_Pixel* m_array;
}PixelArray;

struct Pong2k_Screen
{
    size_t m_length;
    size_t m_width;
    Pong2k_Screen_Pixel** m_screen;
};

Pong2k_Screen* P2K_Screen_Create(size_t _length, size_t _width)
{
    int curWidth = 0;
	int curLength = 0;
    int curPixelNum;
    Pong2k_Screen* screen;
    unsigned char initChar = ' ';
    int dummy = 0;
	if (0 == _length || 0 == _width)
	{
		return NULL;
	}
    if (!(screen = malloc(sizeof(Pong2k_Screen))))
    {
        return NULL;
    }
    if (!((screen->m_screen) = malloc(_length * _width * sizeof(Pong2k_Screen_Pixel*))))
    {
        free(screen);
        return NULL;
    }
    screen->m_length = _length;
    screen->m_width = _width;

	for (curLength = 0; curLength < _length; ++curLength)
	{
		for (curWidth = 0; curWidth < _width; ++curWidth)
		{
            curPixelNum = (curLength*(screen)->m_width) + curWidth;
            screen->m_screen[curPixelNum] = P2K_Screen_Pixel_Create(curLength, curWidth, initChar);
            if (!screen->m_screen[curPixelNum])
            {
                ++dummy;
            }
            /*TODO: Handle faile to create pixels*/
		}
	}
    return screen;
}

void P2K_Screen_Destroy(Pong2k_Screen** _screen)
{
    size_t curLength;
    size_t curWidth;

    if(IS_NULL_SCREEN_PTR(_screen))
    {
        return;
    }

    for (curLength = 0; curLength < (*_screen)->m_length; ++curLength)
    {
        for (curWidth = 0; curWidth < (*_screen)->m_width; ++curWidth)
        {
           P2K_Screen_Pixel_Destroy(&(*_screen)->m_screen[(curLength*(*_screen)->m_width) + curWidth]);
        }
    }

    free((*_screen)->m_screen);
    free(*_screen);
}

void P2K_Screen_Print(Pong2k_Screen* _screen)
{
	size_t curWidth = 0;
	size_t curLength = 0;
    size_t curPixelNum;
    unsigned char  curPixelValue;

	if (IS_NULL_SCREEN_PTR(_screen))
	{
		return;
	}

	/*printf("\n");*/
	for (curLength = 0; curLength < _screen->m_length; ++curLength)
	{
		printf("\n");
		for (curWidth = 0; curWidth < _screen->m_width; ++curWidth)
		{
            curPixelNum = (curLength*(_screen)->m_width) + curWidth;
            curPixelValue = P2K_Screen_Pixel_GetValue(_screen->m_screen[curPixelNum]);
			printf("%c", curPixelValue);
		}
	}
    printf("\n");
	/*printf("\n");*/
}


void ForAllPixels(Pong2k_Screen* _screen, ScreenPixelActionFunc _screenPixelActionFunc, void* _context)
{
	size_t curWidth = 0;
	size_t curLength = 0;
	/*Pong2k_Screen_Pixel* curPixel;*/

	if (IS_NULL_SCREEN_PTR(_screen) || IS_NULL_SCREEN_PTR(_screenPixelActionFunc))
	{
		return;
	}

	for (curLength = 0; curLength < _screen->m_length; ++curLength)
	{
		for (curWidth = 0; curWidth < _screen->m_width; ++curWidth)
		{
            _screenPixelActionFunc(_screen->m_screen[(curLength*(_screen)->m_width) + curWidth], _context);
		}
	}
}

void SetPixelValue(Pong2k_Screen* _screen, size_t _length, size_t _width, unsigned char _pixelVal)
{
    size_t curPixelNum;
    if (IS_NULL_SCREEN_PTR(_screen))
	{
		return;
	}
    curPixelNum = (_length*(_screen)->m_width) + _width;
    P2K_Screen_Pixel_SetValue(_screen->m_screen[curPixelNum], _pixelVal);
}