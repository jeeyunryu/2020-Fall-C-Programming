/*

    Write a C program that reads a text and convert the first character of each word into a capital letter.
        - A word is a sequence of characters between whitespace characters.
        - If the first character of a word is not an alphabet, leave it as it is.
        - Output the result as the format of the following examples.

    Ex)
        Input a text: god loves you and has a wonderful plan for your life.
        text before conversion: god loves you and has a wonderful plan for your life.
        text after conversion: God Loves You And Has A Wonderful Plan For Your Life. 

    Ex)
        Input a text: Everything is gonna be okay!
        text before conversion: Everything is gonna be okay!
        text after conversion: Everything Is Gonna Be Okay!

    Ex)
        Input a text: I was born in 2000.
        text before conversion: I was born in 2000.
        text after conversion: I Was Born In 2000.

*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[256] = " ";

    printf("Input a text: ");
    
    // TO DO: Read a text line. (Use fgets() to read a text line beyond whitespace characters.)
    fgets(text, 256, stdin);



    printf("text before conversion: %s\n", text);

    // TO DO: Convert the first character of each word into uppercase.
    int len = strlen(text);

    for(int i = 0; i < len; i++){

        if (!(isspace(text[i]))){
            if(isspace(text[i-1]) || i == 0){
                if(isalpha(text[i]) && islower(text[i])){
                    char c = text[i];
                    text[i] = c - 32;
                }
            }
        }

        else
            continue;
        

    }
    


    printf("text after conversion: %s\n", text);

    return 0;
}