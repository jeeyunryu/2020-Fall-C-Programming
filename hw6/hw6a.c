//window

/*
    This program writes text on a frame buffer, and then displays the frame buffer in multiple ways.

        1. Initialize the frame buffer by filling it with space characters.
        2. Write a message on the frame buffer.        
        3. Fill the screen, and then show the frame buffer without any animation
        4. Fill the screen, and then show the frame from left.
        5. Fill the screen, and then show the frame from right.
        6. Fill the screen, and then show the frame from center.

    Mission: complete this program by writing the following functions:
        void WriteOnBuffer(char buffer[][MAX_WIDTH], int width, int height, int x, int y, char text[]);
        void ShowBufferFromRight(char buffer[][MAX_WIDTH], int width, int height);
        void ShowBufferFromCenter(char buffer[][MAX_WIDTH], int width, int height);
    
    gcc hw6a_frame_buffer.c Console.c -D_WINDOWS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Console.h"

#define MAX_WIDTH 200
#define MAX_HEIGHT 100

void FillScreen(int width, int height);
void FillBuffer(char buffer[][MAX_WIDTH], int width, int height, char c);
void WriteOnBuffer(char buffer[][MAX_WIDTH], int width, int height, int x, int y, char text[]);
void ShowBuffer(char buffer[][MAX_WIDTH], int width, int height);
void ShowBufferFromLeft(char buffer[][MAX_WIDTH], int width, int height);
void ShowBufferFromRight(char buffer[][MAX_WIDTH], int width, int height);
void ShowBufferFromCenter(char buffer[][MAX_WIDTH], int width, int height);

int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;
    char frame_buffer[MAX_HEIGHT][MAX_WIDTH];


    srand(time(NULL));

    clrscr();
    gotoxy(1, 1);   
    printf("screen size = %d x %d\n", screen_width, screen_height);

    FillBuffer(frame_buffer, screen_width, screen_height, ' ');

    char *text = "God loves you and has a wonderful plan for your life!";
    int sx = (screen_width - strlen(text)) / 2;
    int sy = screen_height / 2;
    WriteOnBuffer(frame_buffer, screen_width, screen_height, sx, sy, text);

    // display from top
    FillScreen(screen_width, screen_height);
    MyPause();

    ShowBuffer(frame_buffer, screen_width, screen_height);
    MyPause();


    // display from left
    FillScreen(screen_width, screen_height);
    MyPause();

    ShowBufferFromLeft(frame_buffer, screen_width, screen_height);
    MyPause();

    // display from right
    FillScreen(screen_width, screen_height);
    MyPause();

    ShowBufferFromRight(frame_buffer, screen_width, screen_height);
    gotoxy(1, screen_height + 1);
    MyPause();

    // display from center
    FillScreen(screen_width, screen_height);
    MyPause();

    ShowBufferFromCenter(frame_buffer, screen_width, screen_height);
    gotoxy(1, screen_height + 1);
    MyPause();



    clrscr();    
    gotoxy(1, 1);
    printf("Bye!\n");

    return 0;
}

void FillScreen(int width, int height)
{
    gotoxy(1, 1);
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= width; j++)
            putchar(rand() % 26 + 'A');
    }
}

void FillBuffer(char buffer[][MAX_WIDTH], int width, int height, char c)
{
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= width; j++)
            buffer[i][j] = c;
    }
}

void WriteOnBuffer(char buffer[][MAX_WIDTH], int width, int height, int x, int y, char text[])
{
    // TO DO: write this function
    int i = 0;
    gotoxy(x, y);
    for (i = 0; i < strlen(text); i++)
        buffer[y][x+i] = text[i];




}

void ShowBuffer(char buffer[][MAX_WIDTH], int width, int height)
{
    gotoxy(1, 1);

    for(int i = 1; i <= height; i++){
        gotoxy(1, i);
        for(int j = 1; j <= width; j++)
            putchar(buffer[i][j]);
    }
}

void ShowBufferFromLeft(char buffer[][MAX_WIDTH], int width, int height)
{
    for(int x = 1; x <= width; x++){
        for(int y = 1; y <= height; y++){
            gotoxy(x, y);
            putchar(buffer[y][x]);
        }

        MySleep(10);
    }
}

void ShowBufferFromRight(char buffer[][MAX_WIDTH], int width, int height)
{
    // TO DO: write this function
    for(int x = width; x >= 1; x--){
        for(int y = 1; y <= height; y++){
            gotoxy(x, y);
            putchar(buffer[y][x]);
        }

        MySleep(10);
    }

}

void ShowBufferFromCenter(char buffer[][MAX_WIDTH], int width, int height)
{
    // TO DO: write this function
    
    if (width % 2 != 0){
        int x = width/2+1;

        for (int y = 1; y <= height; y++){
            gotoxy(x, y);
            putchar(buffer[y][x]);
        }
        
        for (int i = 1; i <= width/2; i++){
            for(int y = 1; y <= height; y++)
            {
                gotoxy(x-i, y);
                putchar(buffer[y][x-i]);
                gotoxy(x+i, y);
                putchar(buffer[y][x+i]); 
            }
            
        }
    }
    

    else if (width % 2 == 0){
        int x = width/2;
        for (int i = 1; i <= width/2; i++){
            for(int y = 1; y <= height; y++){
                    gotoxy(x-i, y);
                    putchar(buffer[y][x-i]);
                    gotoxy(x+i, y);
                    putchar(buffer[y][x+i]); 
                }
        
        }

    }
/*
    int i = 0;
    
    if (width % 2 != 0){
        for (int x = width/2+1; x >= 1; x--){
            for (int y = 1; y <= height; y++){
                gotoxy(x, y);
                putchar(buffer[y][x]);
                gotoxy(x+2*i, y);
                putchar(buffer[y][x+2*i]);
                i++;    
            
                
            }
        }    
    }

    else if{
        for (int x = width/2; x >= 1; x--){
            for (int y = 1; y <= height; y++){
                gotoxy(x, y);
                putchar(buffer[y][x]);
                gotoxy(x+(2*i)+1, y);
                putchar(buffer[y][x+(2*i)+1]);
                i++;    
            
                
            }
        }    

    }
    */
    
    
}
