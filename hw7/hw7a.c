/*

    This program reads words and insert them at the beginning of a text.
    Complete this program by writing two functions ShiftString() and PasteString().

    Algorithm:
        initialize a string text by an empty string

        repeat until the user types "quit"
            read a word
            shift text in right direction
            paste the input word from text
    
*/

#include <stdio.h>
#include <string.h>

#define MAX_TEXT 512
#define MAX_WORD 32

void ShiftString(char string[], int from, int n);
void PasteString(char string[], int from, char substring[]);

int main()
{
    char text[MAX_TEXT] = "";
    char word[MAX_WORD] = "";

    printf("text = [%s]\n\n", text);

    while(1){
        printf("Input word to insert: ");
        scanf("%s", word);
        
        if(strcmp(word, "quit") == 0)
            break;

        int word_len = strlen(word);

        ShiftString(text, 0, ((text[ 0] == 0) ? word_len : word_len + 1));
        printf("text after shift = [%s]\n", text);        

        PasteString(text, 0, word);
        printf("text after overwriting = [%s]\n\n", text);
    }

    printf("Bye!\n");

    return 0;
}

void ShiftString(char string[], int from, int n)
{
    // TO DO: complete this function

    char new_str[512] = {};

    
    for (int i = from; i < n; i++){
        strcat(new_str, " ");
    }

    strcat(new_str, string);
    strcpy(string, new_str);





}

void PasteString(char string[], int from, char substring[])
{
    // TO DO: complete this function
    //substring[strlen(substring)] = 0;
    for (int i = 0; i < strlen(substring); i++){
        string[from+i] = substring[i];
    }

    //string[strlen(string)-1] = 0;

    

    //if (string[0] != 0)
        //strcat(substring, " ");

    //strcat(substring, string);

    //strcpy(string, substring);


}
