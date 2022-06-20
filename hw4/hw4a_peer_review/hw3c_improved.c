#include <stdio.h>
#include <ctype.h>
#include <string.h>

int GetStringLength(char str[]);
// TO DO: declare CountULDS()

void CountULDS(char str[], int* no_upper, int* no_lower, int* no_digit, int* no_space);



int main()
{
    char str[256] = "";
    int no_upper = 0;
    int no_lower = 0;
    int no_digit = 0;
    int no_space = 0;

    printf("Input a text line: ");
    
    // The following three lines read a text line beyond space.
    fgets(str, 255, stdin); 
    int len = strlen(str) - 1;
    str[len] = '\0';

    printf("length of string \"%s\" = %d\n", str, GetStringLength(str));

    // TO DO: get no_upper, no_lower, no_digit, and no_space by calling CountULDS()
    CountULDS(str, &no_upper, &no_lower, &no_digit, &no_space);
    

    printf("%d upper, %d lower, %d digit, and %d space characters\n", no_upper, no_lower, no_digit, no_space);

    return 0;
}

int GetStringLength(char str[])
{
    int len = 0;

    for(int i = 0; str[i] != '\0'; i++)
        len++;

    return len;
}

// TO DO: define CountULDS() here
  void CountULDS(char str[], int *no_upper, int *no_lower, int *no_digit, int *no_space)
  {
    
    int i = 0;
    
    for (int i = 0; i < GetStringLength(str); i++)
    {
      if (isupper(str[i]))
      {
        *no_upper += 1;
      }
      
      if (islower(str[i]))
      {
        *no_lower += 1;
      }
      
      if (isdigit(str[i]))
      {
        *no_digit +=  1;
      }
      
      if (isspace(str[i]))
      {
        *no_space += 1;
      }
    }
    
    return;
  }

