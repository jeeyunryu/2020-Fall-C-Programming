/*
    This program reads a text from the user, and the retrives all words from the text.
    Complete this program following the instructions.

    A word is defined as a sequence of characters
    separated by the whitespace characters or the null character.

    Hints)
    - The start of a word can be detected by a non-whitespace character not preceded by a non-whitespace character.
    - The end of a word can be detected by a whitespace character not preceded by a whitespace character.
    - Use isspace() to decide whether a charcter is a whitespace character.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXT_LEN 512
#define WORD_LEN 32
#define MAX_WORD 100

void GetSubstring(char text[], int from, int to, char word[]);

int main()
{
    char text[TEXT_LEN] = "";
    char word[MAX_WORD][WORD_LEN];
    int no_word = 0;

    printf("Input a text line: ");
    fgets(text, TEXT_LEN - 1, stdin);
    int len = strlen(text);
    text[--len] = 0;                // trim '\n'

    int from = 0;
    int i = 0;
    for(i = 0; i < len; i++){
        if(isspace(text[i])){
            // TO DO: Check if text[i] is the end of a word.
            //        If so, make a new word in word[no_word] out of the characters in range [from, i) using GetSubstring(),
            //        and then, store it in word[no_word] and increase no_word
            
            GetSubstring(text, from, i, word[no_word]);
    
            no_word++;
        
            
        } else {
            // TO DO: check if text[i] is the start of a word.
            //        If so, mark the start of a word by saving i in the variable from.
            if (i == 0 || isspace(text[i-1]))
                from = i;


        }
    } 

    if(isspace(text[len]) == 0){
        // TO DO: Check if the last word terminates by the null character.
        //        If so, make a new word in word[no_word] out of the characters in range [from, i) using GetSubstring(),
        //        and then, store it in word[no_word] and increase no_word
        
        GetSubstring(text, from, i, word[no_word]);
        no_word++;
    }

    for(i = 0; i < no_word; i++)
        printf("word[%d] = [%s]\n", i, word[i]);

    return 0;
}

void GetSubstring(char text[], int from, int to, char word[])
{
    // TO DO: Retrieve a substring in word that is composed of the characters from text[from] to text[to-1]
    // e.g., a function call to GetSubstring("hello", 2, 4, word); stores "ll" into word
   
    char str[512] = {};
    int j = 0;

    for(int i = from; i < to; i++){

        str[j] = text[i];
        j++;
        
    }

    strcpy(word, str);
    

    return;
}
