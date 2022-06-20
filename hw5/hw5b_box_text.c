/*
    Mission: complete this program by writing DrawBoxText(), DuplicateText(), and RotateLeft().
        This program should run as box_text.mp4.

	Compile instruction:
		Put Console.c and Console.h into the current directory, and run the following commands:

			gcc hw5b_box_text.c Console.c -D_WINDOWS  // on Windows
			gcc box_text.c Console.c -D_MAC      // on MacOS

*/

#include <stdio.h>
#include <string.h>

#include "Console.h"

void DrawBoxText(char text[], int sx, int sy, int width, int height);
void DuplicateText(char text[], int min_len);
void RotateLeft(char text[]);

int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    gotoxy(1, 1);
    printf("screen size = %d x %d\n", screen_width, screen_height);

    char text[512] = "God loves you and has a wonderful plan for your life!";
    int box_width = 0, box_height = 0;

    clrscr();

    printf("Input text: ");
    fgets(text, 511, stdin);
    text[strlen(text) - 1] = 0;

    printf("Input box_width and box_height: ");
    scanf("%d %d", &box_width, &box_height);

    printf("Press ESC to stop.\n");

    if(box_width > screen_width)
        box_width = screen_width;
    if(box_height > screen_height)
        box_height = screen_height;

    int sx = (screen_width - box_width) / 2; 
    int sy = (screen_height - box_height) / 2; 

    DuplicateText(text, box_width * 2 + box_height * 2 - 4);

    while(1){
        DrawBoxText(text, sx, sy, box_width, box_height);
        RotateLeft(text);

        gotoxy(screen_width, 1);
        MySleep(100);

        if(kbhit() && getch() == 27)
            break;
    }

    gotoxy(1, screen_height);
    printf("Bye!\n");

    return 0;
}

void DrawBoxText(char text[], int sx, int sy, int width, int height)
{
    //int i = 0;
    
    int j = 0;
    int n = 0;
    int len = strlen(text);

    // TO DO: display characters along the top side (this is example)
    for (j = 0; n < len && j < width - 1; j++){
        gotoxy(sx + j, sy);
        putchar(text[n++]);
    }



    // display characters along the right side (this is an example.)
    for(j = 0; n < len && j < height - 1; j++){
        gotoxy(sx + width - 1, sy + j);
        putchar(text[n++]);
    }    

    // TO DO: display characters along the bottom side

    for ( j = 0; n < len && j < width - 1; j++){
        gotoxy(sx + width - 1 - j, sy + height - 1);
        putchar(text[n++]);
    }
    

    // TO DO: display characters along the left side

    for (j = 0; n < len && j < height - 1; j++){
        gotoxy(sx , sy + height - 1 - j);
        putchar(text[n++]);
    }


}

void DuplicateText(char text[], int min_len)
{
    int len = strlen(text);
    if(text[len - 1] != ' ')
        text[len++] = ' ';
    
    // TO DO: duplicate text multiple times until the length >= min_len
    int i = 0;
    int temp = 0;
    temp = len;

    while(1){
        if (len >= min_len)
            break;
        else
            for (i = 0; i < temp; i++)
                text[len++] = text[i];
    }
    
    text[len-1] = '\0';



    
        
    //      ex) when min_len = 25, "hello "(lenth = 6) ==> "hello hello hello hello hello "(length = 30)



    // Hint: don't forget to put the null character at the end of the string    
}

void RotateLeft(char text[])
{
    int len = strlen(text);         // the length of text
    int i = 0;

    int temp;

    temp = text[0];

    // TO DO: rotate text one step left
    for (i = 0; i < len - 1; i++){
        text[i] = text[i+1];
    }

    text[len - 1] = temp;

    
    
    //      eg) "Hello " ==> "ello H"

}