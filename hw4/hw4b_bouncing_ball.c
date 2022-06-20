/*
    Bouncing Ball:
        1. Copy this file to hw4b_bouncing_ball.c.
        
        2. Compile and run the following code.
            * Put Console.c and Console.h into the current directory, and run the following commands:

                gcc hw4b_bouncing_ball.c Console.c -D_WINDOWS  // on Windows
                gcc hw4b_bouncing_ball.c Console.c -D_MAC      // on MacOS

            * It is recommended to run on a terminal (or Dos Prompt).

        3. Read the code to fully understand.

        4. Modify this code so that the ball bounces at the top and bottom of the window.

*/

#include <stdio.h>

#include "Console.h"

int main()
{
    int screen_width = getWindowWidth();       // get width of current console window
    int screen_height = getWindowHeight() - 3;      // get height of current console window
    int x = screen_width / 2, y = screen_height / 2;           // set initial coordinate by center of the screen
    int dx = 1, dy = 1;
    int key = 0;

    clrscr();               // clear screen (defined in Console.c)
    gotoxy(1, screen_height + 1);
    printf("screen size = %d x %d. Press ESC to fisnish.\n", screen_width, screen_height);
    
    while (key != 27) {           // the ASCII code of ESC is 27.
        
        // save previous coordinate
        int oldx = x;
        int oldy = y;
        
        // move the coordinate of the ball
        x += dx;
        y += dy;
        
        if (y >= screen_height) {        // if the ball reaches the bottom, restart from the top
            y = screen_height;
            dy = -1;
        }
        if (y <= 1) {
            y = 1;
            dy = 1;
        }
        if (x >= screen_width) {
            x = screen_width;
            dx = -1;
        }
        if (x <= 1){
            x = 1;
            dx = 1;
        }
        // erase previous coordinate
        gotoxy(oldx, oldy);
        printf(" ");

        // draw star at tshe new object
        gotoxy(x, y);
        printf("*");

        // move the cursor to (1, 1) so that it does not blink
        gotoxy(1, 1);

        // flush screen (display all content in the output buffer and flush it)
        // this is to display all messages immediately.
        fflush(stdout);

        // the following routine detects and reads a key press. this is to stop when ESC key is pressed.
        if(kbhit())
            key = getch();

        // delay for 50 ms
        MySleep(50);      // defined in Console.c   
    }

    clrscr();
    gotoxy(1, 1);
    printf("Bye!\n");

    return 0;
}