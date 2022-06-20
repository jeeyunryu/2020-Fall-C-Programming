/*

    Mission: Write a program that retrieves the words in a text, shuffles the characters in each word, and then, restores the text using the saved words. (40 points)

        1) Retrieves all words in a text into an array of structures saving the starting position of each word.
           And then, shuffle the characters in each word.
        2) Print the words retrieved.
        3) Print the text in which the characters in each word ares shuffled.
        4) Rewrite the retrieved words on text at their saved positions.
        5) Print the restored text.

    Ex)
        Input a text: Hello!         WORLD!!!
        word 0: (0, Hello!)
        word 1: (15, WORLD!!!)
        text (word shuffled) = ollHe!         DLRW!!!O
        text (restored) =      Hello!         WORLD!!!

    Ex)
        Input a text: Regist the temptation to code!
        word 0: (0, Regist)
        word 1: (7, the)
        word 2: (11, temptation)
        word 3: (22, to)
        word 4: (25, code!)
        text (word shuffled) = esiRtg teh natitpoetm to oec!d
        text (restored) =      Regist the temptation to code!

    Ex)
        Input a text: HGU CSEE is a higher educational institution that cultivates excellent and honest professionals who will serve God and people by playing a role as salt and light in the darkening world.
        word 0: (0, HGU)
        word 1: (4, CSEE)
        word 2: (9, is)
        word 3: (12, a)
        word 4: (14, higher)
        word 5: (21, educational)
        word 6: (33, institution)
        word 7: (45, that)
        word 8: (50, cultivates)
        word 9: (61, excellent)
        word 10: (71, and)
        word 11: (75, honest)
        word 12: (82, professionals)
        word 13: (96, who)
        word 14: (100, will)
        word 15: (105, serve)
        word 16: (111, God)
        word 17: (115, and)
        word 18: (119, people)
        word 19: (126, by)
        word 20: (129, playing)
        word 21: (137, a)
        word 22: (139, role)
        word 23: (144, as)
        word 24: (147, salt)
        word 25: (152, and)
        word 26: (156, light)
        word 27: (162, in)
        word 28: (165, the)
        word 29: (169, darkening)
        word 30: (179, world.)
        text (word shuffled) = UGH SEEC is a ehhigr uoactedlani sntiinttoui htat lituecsvat enxectell dna onshte opinsssfrolae owh wlil eersv oGd dna lopeep by aygnlpi a oelr sa lats adn tlgih in eth aerikndgn odw.lr
        text (restored) =      HGU CSEE is a higher educational institution that cultivates excellent and honest professionals who will serve God and people by playing a role as salt and light in the darkening world.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD 1024

typedef struct {
    int position;           // the starting position of the word in the text
    char word[64];          // word string
} Subword;

void RetrieveWord(char text[], int from, int to, Subword *pword, int no_word);
void ShuffleWord(char text[], int from, int to, int no_word);
void RewriteWord(char text[], Subword *pword);

int main()
{
    srand(time(NULL));

    Subword word[MAX_WORD];
    int no_word = 0;

    char text[256] = "";

    printf("Input a text: ");
    // TO DO: Read a text line. (Use fgets() to read a text line beyond whitespace characters.)
    fgets(text, 256, stdin);
    
    


    int len = strlen(text);
    int from = 0;
    for(int i = 0; i < len; i++){
        // TO DO: If text[i] is the end of a word (a whitespace character preceded by a non-space character),
        //        - Retrieve a word using the characters from text[from] to text[i-1]. (call RetrieveWord())
        //        - Shuffle the characters from text[from] to text[i-1]. (call ShuffleWord())
        if(isspace(text[i]) && !(isspace(text[i-1]))){
            RetrieveWord(text, from, i, word, no_word);
            ShuffleWord(text, from, i, no_word);
            no_word++;
        }

        // TO DO: If text[i] is the start of a word (a non-space character not preceded by a non-space character),
        //        mark i as the start of a word by setting 'from' to i.
        if((!(isspace(text[i])) && isspace(text[i-1])) || i == 0){
            from = i;
        }
    }

    // TO DO: if there is a remaining word at the end of text, retrieve the word and shuffle the word in text.
    

    // display saved words
    for(int i = 0; i < no_word; i++)
        printf("word %d: (%d, %s)\n", i, word[i].position, word[i].word);

    // display shuffled text
    printf("text (word shuffled) = %s\n", text);

    // restore words
    for(int i = 0; i < no_word; i++)
        RewriteWord(text, &word[i]);

    printf("text (restored) =      %s\n", text);

    return 0;
}

void RetrieveWord(char text[], int from, int to, Subword *pword, int no_word)
{
    // TO DO: Build a string in the 'word' field using the characters from text[from] to text[to-1].
    //        Then, save 'from' in the 'position' field.
    
    Subword word[MAX_WORD];
    
    char new_c[MAX_WORD] = "";
    int i = 0;
    
    for(int j = from; i < to; i++){
        new_c[i] = text[j];
        i++;
    }

    
    strcpy(word[no_word].word, new_c);
    
    
    word[no_word].position = from;
    i++;

}

void ShuffleWord(char text[], int from, int to, int no_word)
{
    // TO DO: Randomly shuffle the characters from text[from] to text[to-1].
    //        Hint) Swap text[i] with text[j] for all i in [from, to-1], where j is a random number in [from, to-1].
    int d = 0;
    int i = 0;
    
    
    Subword word[MAX_WORD];
    
    char new_c[MAX_WORD] = "";

    if (from == 0){
        for (int i = 0; i < to+1; i++);
            d = rand()/(to+1) + from;
            if((isspace(text[d]))){
                new_c[i] = text[d];
            }
            else
                i--;                       

    }
    else{
        for(int i = 0; i < to-from+1; i++);
            d = rand()/(to-from+1) + from;
            new_c[i] = text[d];

    }
    
    strcpy(word[no_word].word, new_c);
    
    
    word[no_word].position = from;



}

void RewriteWord(char text[], Subword *pword)
{
    int len = strlen(pword->word);
    for(int i = 0; i < len; i++)
        text[pword->position + i] = pword->word[i];
}
