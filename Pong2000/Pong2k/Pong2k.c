#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"Pong2k.h"
#include"../Pong2k_Screen/Pong2k_Screen.h"

#define SCREEN_LENGTH	35
#define SCREEN_WIDTH	160
#define GAME_AREA_LENGTH 30
#define GAME_AREA_WIDTH 140
#define MENU_AREA_LENGTH 5
#define MENU_AREA_WIDTH 140
#define IS_NULL_PTR(P) (!(P))
#define FRAME_REFRESH_RATE_USEC 10000

int main()
{
	size_t screenLength = SCREEN_LENGTH;
	size_t screenWidth = SCREEN_WIDTH;
	size_t curLength;
	size_t curWidth;

	Pong2k_Screen* screen;
	screen = P2K_Screen_Create(screenLength, screenWidth);
	P2K_Screen_Print(screen);

	for (curWidth = 1; curWidth < screenWidth; ++curWidth)
	{
		SetPixelValue(screen, 0,curWidth-1, ' ');
		SetPixelValue(screen, 0,curWidth, '*');
		P2K_Screen_Print(screen);
		usleep(FRAME_REFRESH_RATE_USEC);
	}
	P2K_Screen_Destroy(&screen);
	
	return 0;
}

