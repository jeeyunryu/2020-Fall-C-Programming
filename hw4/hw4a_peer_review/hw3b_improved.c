#include <stdio.h>
#include <string.h>

int GetStringLength(char str[]);

void RotateRight(char str[]);
void RotateLeft(char str[]);

int main()
{
    char str[256];

    printf("Input a text line: ");
    
    // The following three lines read a text line beyond space.
    fgets(str, 255, stdin);
    int str_len = strlen(str) - 1;
    str[str_len] = '\0';

    int len = GetStringLength(str);

    for(int i = 0; i < len; i++){
        printf("%s\n", str);
        RotateRight(str);
    }
     
    for(int i = 0; i < len; i++){
        printf("%s\n", str);
        RotateLeft(str);
    }

    return 0;
}

int GetStringLength(char str[])
{
    int len = 0;

    for(int i = 0; str[i] != 0; i++)
        len++;

    return len;
}

void RotateRight(char str[])
// TO DO: Read this function carefully.
{
    int len = GetStringLength(str);

    char temp = str[len - 1];
    for(int i = len - 1; i > 0; i--)
        str[i] = str[i-1];
    str[0] = temp;
}

void RotateLeft(char str[])
// TO DO: Implement this function.
{
  
  int len = GetStringLength(str);
  
  char temp = str[0];
  
  for (int i = 0; i < len-1; i++)
    str[i] = str[i+1];
  str[len -1] = temp;
  



}
