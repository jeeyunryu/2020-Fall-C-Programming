//window

/*
    This program displays a puzzle and let the user move numbers by the following keys:
        'i': up (the hole moves down)
        'l': right (the hole moves left)
        'k': down (the hole moves up)
        'j': left (the home moves right)

    Mission: complete this program following the instructions below.

    gcc hw6b_puzzle.c Console.c -D_WINDOWS

*/

#include <stdio.h>

#include "Console.h"

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3


void InitPuzzle(int puzzle[][MAX_WIDTH], int width, int height);
void DisplayPuzzle(int puz[][MAX_WIDTH], int width, int height, int sx, int sy);


int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    int puzzle[MAX_HEIGHT][MAX_WIDTH];

    int width = 0, height = 0;

    clrscr();
    printf("Input width and height of puzzle: ");
    scanf("%d %d", &width, &height);
    printf("Move the numbers by i(up), l(right), k(down), or j(left) keys.\n");
    printf("Press ESC to finish.\n");

    InitPuzzle(puzzle, width, height);

    int hx = width - 1;
    int hy = height - 1;

    int sx = (screen_width - width * 4) / 2;
    int sy = (screen_height - height) / 2;


    DisplayPuzzle(puzzle, width, height, sx, sy);

    char key = 0;
    while((key = getch()) != 27){
        // Move the numbers according to the key. The hole should move in the opposite direction.
        // TO DO: complete the code for right, down, and left movement
        switch(key){
        case 'i':           // up
            if(hy < height - 1){
                puzzle[hy][hx] = puzzle[hy + 1][hx];    // fill the hole with the number at the lower coordinate
                hy++;                                   // update the coordinate of the hole
                puzzle[hy][hx] = 0;                     // fill the element at the new coordinate with zero
            }
            break;

        case 'l':           // right
            // TO DO: write your code here.
            if (hx > 0){
                puzzle[hy][hx] = puzzle[hy][hx-1];
                hx--;
                puzzle[hy][hx] = 0;
            }


            break;

        case 'k':           // down
            // TO DO: write your code here.
            if (hy > 0){
                puzzle[hy][hx] = puzzle[hy-1][hx];
                hy--;
                puzzle[hy][hx] = 0;
            }


            break;

        case 'j':           // left
            // TO DO: write your code here.
            if (hx < width - 1){
                puzzle[hy][hx] = puzzle[hy][hx+1];
                hx++;
                puzzle[hy][hx] = 0;
            }


            break;
        }

        DisplayPuzzle(puzzle, width, height, sx, sy);
        gotoxy(width, 1);
    }

    clrscr();
    gotoxy(1, 1);
    printf("Bye!\n");

    return 0;
}

void InitPuzzle(int puzzle[][MAX_WIDTH], int width, int height)
{
    // TO DO: fill the puzzle with numbers from 1 to (width * heigth - 1).
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            puzzle[i][j] = (width*i) + j+1;
        }
    }
    //      set the last element puzzle[height - 1][width - 1] by zero.
    puzzle[height-1][width-1] = 0;

    // e.g. when width = 4, height = 3, puzzle should be as follows:
    //      1  2  3  4
    //      5  6  7  8
    //      9 10 11  0
}

void DisplayPuzzle(int puzzle[][MAX_WIDTH], int width, int height, int sx, int sy)
{
    for(int i = 0; i < height; i++){
        gotoxy(sx, sy + i);
        for(int j = 0; j < width; j++){
            if(puzzle[i][j] == 0)
                printf("    ");                 // 0 represents the hole
            else    
                printf("%3d ", puzzle[i][j]);

        }
    }
}
