#include <ncurses.h>
#include <unistd.h>
#define TICKRATE 100
#define WINDOW_WIDTH 150 
#define WINDOW_HEIGHT 40 
#define PLAY_AREA_WIDTH 150
#define PLAY_AREA_HEIGHT 35

#define BRICK_WIDTH 1 
#define BRICK_HEIGHT 5
#define BALL_WIDTH 1
#define BALL_HEIGHT 1

typedef struct coordinate
{
    int x;
    int y;
}coordinate;

int main() 
{
    WINDOW* gameAreaWindow;
    WINDOW* playAreaWindow;
    int offsetx, offsety;

    initscr();
    noecho();
    cbreak();
    timeout(TICKRATE);
    keypad(stdscr, TRUE);
    printw("PieceOfCakeSnake v. 1.0  -  Press x to quit...");
    refresh();
    offsetx = (COLS - WINDOW_WIDTH) / 2;
    offsety = (LINES - WINDOW_HEIGHT) / 2;
    gameAreaWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, offsety, offsetx);
    box(gameAreaWindow, 0 , 0);
    playAreaWindow = newwin(PLAY_AREA_HEIGHT, PLAY_AREA_WIDTH, offsety, offsetx);
    box(playAreaWindow, 0 , 0);
    curs_set(0);
    for (int i=0; i < PLAY_AREA_WIDTH; ++i)
    {
        wclear(playAreaWindow);
        box(playAreaWindow, 0 , 0);
        wrefresh(gameAreaWindow);
        mvwaddch(playAreaWindow, 2, i, '*');
        mvwaddch(playAreaWindow, 3, i, '*');
        wrefresh(playAreaWindow);
        usleep(50000);
    }
    
    
    // sleep(3);
    delwin(gameAreaWindow);
    delwin(playAreaWindow);

    endwin();

    return 0;
}	



/*
typedef enum
{
    MASTER_WIN,
    PLAY_WIN,
    MENU_WIN
}Window_ID;

typedef enum
{
    BRICK_L,
    BRICK_R,
    BALL
}Object_ID;

class GraphicsEngine
{
public:
    GraphicsEngine
    ~GraphicsEngine
    AddWindow
    RemoveWindow
    RefreshWindow
    
protected:

private:
    WindowContainer m_winContainer;
};

class Window
{
public:
    Window(unsigned int _width, unsigned int _height)
    ~Window
    GetWindowWidth
    GetWindowHeight
    GetPixel
    SetPixel
protected:

private:
    unsigned int m_width;
    unsigned int m_height;
    PixelContainer m_pixelContainer;
    Window_ID m_windowID;
};

class Pixel
{
public:
    Pixel()
    ~Pixel
    GetCharacter
    SetCharacter
    operator==(unsigned char _pixelChar)
    operator==(unsigned int _x, _y);
    operator<(unsigned int _x, _y);
protected:

private:
    unsigned char m_pixelChar;
    Coordinate m_coordinate;
};

class Coordinate
{
public:
    Coordinate(unsigned int _x, unsigned int _y)
    ~Coordinate
    GetCoordinateX
    SetCoordinateX
    GetCoordinateY
    SetCoordinateY
    operator==
    operator<
protected:

private:
    unsigned int m_x;
    unsigned int m_y;
};

*/

