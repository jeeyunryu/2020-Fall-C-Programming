/*
    Mission: complete this program by writing MoveChar().
        This program should run as flying_characters.mp4.

	Compile instruction:
		Put Console.c and Console.h into the current directory, and run the following commands:

			gcc hw5a_flying_characters.c Console.c -D_WINDOWS  // on Windows
			gcc hw5a_flying_characters.c Console.c -D_MAC      // on MacOS

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "Console.h"

#define FROM_TOP 0
#define FROM_RIGHT 1
#define FROM_BOTTOM 2
#define FROM_LEFT 3

void MoveChar(char c, int tx, int ty, int screen_width, int screen_height, int dir);

int main()
{
    int screen_width = getWindowWidth();       // get width of current console window
    int screen_height = getWindowHeight() - 3;      // get height of current console window
    int cx = screen_width / 2, cy = screen_height / 2;           // set initial coordinate by center of the screen

    char text[512] = "";

    clrscr();
    printf("Input a text line: ");
    fgets(text, 511, stdin);
    int len = strlen(text);
    text[--len] = 0;

    int sx = cx - len / 2;
    for(int i = 0; i < len; i++){
        if(isspace(text[i]))
            continue;

        // move the i-th character of text
        int dir = i % 4;
        MoveChar(text[i], sx + i, cy, screen_width, screen_height, dir);

        // redraw previous characters
        gotoxy(sx, cy);        
        for(int j = 0; j <= i; j++)
            putchar(text[j]);

        // if ESC is pressed, terminate
        if(kbhit() && getch() == 27)
            break;
    }

    gotoxy(1, screen_height);
    printf("Bye!\n");

    return 0;
}

void MoveChar(char c, int tx, int ty, int screen_width, int screen_height, int dir)
{
    int x = 0, y = 0;
    int dx = 0, dy = 0;

    // TO DO: set initial coordinate (x, y) and movement vector (dx, dy) according to dir
    switch(dir % 4){
    case FROM_TOP:                     // from top
        // initial coordinate is (tx, 1)
        x = tx;
        y = 1;

        // movement vector of LOWER direction is (0, 1) 
        dx = 0;
        dy = 1;
        break;

    case FROM_RIGHT:                   // from right
        // TO DO: set initial coordinate and movement vector for movement from right
        x = screen_width;
        y = ty;

        dx = -1;
        dy = 0;

        break;

    case FROM_BOTTOM:                  // from bottom
        // TO DO: set initial coordinate and movement vector for movement from bottom
        x = tx;
        y = screen_height;

        dx = 0;
        dy = -1;
        break;

    case FROM_LEFT:                    // from up
        // TO DO: set initial coordinate and movement vector for movement from left
        x = 1;
        y = ty;

        dx = 1;
        dy = 0;

        break;
    }

    gotoxy(x, y);
    putchar(c);

    // TO DO: move character from (x, y) to (tx, ty) using (dx, dy)
    while(x != tx || y != ty){
        // TO DO: write your code here.

        //      erase previous coordinate
                gotoxy(x, y);
                printf(" ");
        //      update coordinate (x, y) using (dx, dy)
                x += dx;
                y += dy;

        //      draw character at the new coordinate
                gotoxy(x, y);
                putchar(c);


        fflush(stdout);             // flush output buffer for immediate display        
        if(dir % 2 == 1)
            MySleep(25);            // horizontal movement should be faster than vertical movement
        else
            MySleep(50);
    }
}
