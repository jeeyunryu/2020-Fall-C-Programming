/*
	This program displays The Matrix Screen animation. (You can compile and run the code as it is.)

	It represents character bars using four arrays: y, delay, length, and prevLength.

 	Mission: 
	1) Read the code carefully and fully understand the techniques used in the program.
	2) Replace the four arrays by a single structure array
	 
		- Declare a structure Bar.
		- Erase the four arrays, y, delay, length, and prevLength.
		- Declare a Bar type array.
		- Modify the other part using the Bar array.
			e.g., The expressions such as y[col], delay[col], length[col], prevLength[col] should be removed.

	Compile command:
		gcc hw8a_matrix_screen.c Console.c -D_WINDOWS         // on Windows
		gcc hw8a_matrix_screen.c Console.c -D_MAC         	// on Mac

*/

#include <stdio.h>
#include <time.h>

#include "Console.h"

#define MAX_WIDTH 200

char GetRandomChar();		// a function that returns a random alpha-numeric character

void clrscr(void);			// clear the screen
void gotoxy(int x, int y);	// move cursor to (x, y)


//	TO DO: declare a strucure Bar containing four integer fields: y, delay, length, prevLength
struct Sample{
    int y;
    int delay;
    int length;
    int prevlength;
};


int main()
{

    struct Sample arr[MAX_WIDTH] = {0};
    
	int screenWidth = getWindowWidth();
	int screenHeight = getWindowHeight() - 3;

	if(screenWidth > MAX_WIDTH)			// for safety
		screenWidth = MAX_WIDTH;

	// TO DO: erase the following four arrays and declare an array of Bars instead.
	// 		Then, modify the code accordingly.

	int y[MAX_WIDTH];					// y coordinates for each screenWidth
	int delay[MAX_WIDTH];				// inverse of speed of each screenWidth
	int length[MAX_WIDTH];				// length of each screenWidth
	int prevLength[MAX_WIDTH];			// length of each screenWidth in the previous turn

	int t = 0;							// the master clock
	int col = 0;
	
	clrscr();

	printf("This program shows something interesting.\n");
	printf("If you want to finish, press ESC.\n");
	printf("Press Enter to start: ");
	getchar();

	clrscr();

	srand(time(NULL));
	
	// initialize each screenWidths
	for(col = 0; col < screenWidth; col++){
		//y[col] = 1;
        arr[col].y = 1;
		//delay[col] = rand() % 10 + 1;	// initialize delay and length
        arr[col].delay = rand() % 10 + 1;
		//length[col] = rand() % 5 + 3;
        arr[col].length = rand() % 5 + 3;
		//prevLength[col] = length[col];
        arr[col].prevlength = arr[col].length;
	}

	while(1){
		if(kbhit() && getch() == 27)	// if ESC is pressed, terminate the loop (You may ignore this line.)
				break;

		for(col = 0; col < screenWidth; col++){
			if(t % arr[col].delay == 0){
				// print a random character at current position
				gotoxy(col + 1, arr[col].y);
				putchar(GetRandomChar());

				// erase previous location
				if(arr[col].y - length[col] >= 1){
					gotoxy(col + 1, arr[col].y - arr[col].length);
					putchar(' ');
				}
				
				if(arr[col].y <= arr[col].prevlength){
					gotoxy(col + 1, screenHeight + arr[col].y - arr[col].prevlength);	// wrapped
					putchar(' ');
				}

				// increase current y coordinate
				arr[col].y++;

				// check if y reached the last screenHeight
				if(arr[col].y > screenHeight){
					arr[col].y = 1;
					arr[col].delay = rand() % 10 + 1;	// reset delay and length
					
					arr[col].prevlength = arr[col].length;
					arr[col].length = rand() % 5 + 3;
				}
			}
		}
		
		Sleep(50);
		t++;				// master clock
	}

	clrscr();
	
	gotoxy(1, 1);
	printf("Good bye!\n");

	system("PAUSE");

	return 0;	
}

char GetRandomChar()
{
	const int noUpperCase = 26;
	const int noLowerCase = 26;
	const int noDigits = 10;

	int x = rand() % (noUpperCase + noLowerCase + noDigits);
	if(x < noUpperCase)
		return 'A' + x;
	else if(x < noUpperCase + noLowerCase)
		return 'a' + x - noUpperCase;
	else
		return '0' + x - (noUpperCase + noLowerCase);
}
