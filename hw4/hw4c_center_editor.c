/*            
    Mission: complete this program by following the guidelines

    Compile instruction:
        Put Console.c and Console.h into the current directory, and run the following commands:

            gcc hw4c_center_editor.c Console.c -D_WINDOWS  // on Windows
            gcc hw4c_center_editor.c Console.c -D_MAC      // on MacOS

*/

#include <stdio.h>
#include <string.h>

#include "Console.h"

void PrintCenter(char text[], int cx, int cy);
// Displays a text at the center of the screen

void Erase(int len);
// Erases a text from the screen given its length

void EraseCenter(int len, int cx, int cy);
// Erases the previous message at the center of the screen given the length of the previous message

int main()
{
    int screen_width = getWindowWidth();            // get width of current console window
    int screen_height = getWindowHeight() - 3;      // get width of current console window
    int cx = screen_width / 2, cy = screen_height / 2;   // center of the screen

    char text[256] = "";
    int len = 0;				// the length of text
    int oldlen = 0;

    clrscr();
    gotoxy(1, 1);
    printf("Press ESC to quit.\n");

    char key = 0;
    while(key != 27){
        //int oldlen = len;			// save the length of the current text

        key = getch();				// reads a key from the user
        switch(key){
            case 27:    // ESC key
            	// if key == ESC, do nothing
                break;

            case 8:     // backspace key
                // TO DO: erase the last character of text and decrease len.
                EraseCenter(len, cx, cy);
                if (len != 0)
                    text[--len] = '\0'; 
            
                //      Then, reprint the text at the center of the screen
                PrintCenter(text, cx, cy);
                break;

            case 13:     // Enter key
				// TO DO: print current text at (1, 2). (erase previous text at (1, 2))
                gotoxy(1, 2);
                Erase(oldlen);
                oldlen = len;

                gotoxy(1, 2);
                printf("%s", text);

                // TO DO: Erase the center text
                EraseCenter(len, cx, cy);

                // TO DO: clear text (fill text[0] by zero), and reset len to zero
                text[0] = '\0'; 
                len = 0;

                break;

            default:	// all other keys
                // TO DO: append key at the end of text, and increase len
                text[len++] = key;
                text[len] = '\0';
                
                // TO DO: display new text at the center of the screen
                PrintCenter(text, cx, cy);

                break;
        }               
    }

    // print a goodbye message at (1, 3)
    gotoxy(1, 3);
    printf("Bye!\n");
    
    return 0;
}

void PrintCenter(char text[], int cx, int cy)
// Displays a text at the center of the screen
{
    int len = strlen(text);         // returns the length of text. declared in string.h
    gotoxy(cx - len / 2, cy);
    printf("%s", text);
}

void Erase(int len)
// Erases a text from the screen given its length
{
    // TO DO: print space character len times (use the for statement)
    int i = 0;

    for (i = 0; i < len; i++)
        printf(" ");
}

void EraseCenter(int len, int cx, int cy)
// Erases the previous message at the center of the screen given the length of the previous message
{
	// TO DO: implement this function
    gotoxy(cx-len/2, cy);
    
    int i = 0;

    for (i = 0; i <len; i++)
        printf(" ");
   
}
