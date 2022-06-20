/*

    Write a C Program as follows:
        1. Read a number as a string from the user.
            사용자로부터 숫자를 string 형태로 입력 받는다.

        2. Read a base from the user.
            사용자로부터 base를 입력받는다.
            The base is an arbitrary integer between 2 and 10. But, you don't have to check whether the input value is in range [2, 10].
            base는 2 ~ 10 범위의 임의의 정수이다.

        3. Decide whether the number is a valid number in the numeral system of the base.
            입력 숫자(string)가 base 진법의 수인지 판별하라.
            e.g.) Binary numbers are numeral system of base 2.            
                  Octal numbers are numeral system of base 8.
                  Decimal numbers are numeral system of base 10.
                  
            If the input number (string) is a valid number of base, print "<number> is a base-<base> number".
            입력 숫자가 base 진법의 수이면 "<number> is a base-<base> number"라는 문자를 출력하라.            
            Otherwise, print "<number> is NOT a base-<base> number"
            그렇지 않으면 "<number> is NOT a base-<base> number"이라는 메시지를 출력하라.
            
            <number> and <base> should be replaced by the input number and base.
            단, <number>, <base>는 실제 입력 숫자와 base로 치환


        Guideline)
            All valid numbers in a numeral system of a base B is composed of digits in [0, B-1].
            B진법의 각 자리수는 [0, B-1]의 범위를 갖는다.
            e.g.) A binary number is composed of 0 and 1
                  An octal number is composed of digits in [0, 7]
                  A decimal number is composed of digits from [0, 9]

            If the input number (string) contains other characters, it is NOT a valid nummber of bases B.
            입력 숫자가 다른 문자를 포함할 경우 B진법 숫자가 아니다.
            Otherwise, decide it is a valid nummber of bases B.
            그렇지 않을 경우 B진법 숫자로 판정하라.

        Example)
            Input a number: 325262
            Input base (0 ~ 10): 8
            325262 is a base-8 number.          // 325262 is a valid octal number composed of digits in range [0, 7]

        Example)
            Input a number: 123*452
            Input base (0 ~ 10): 9
            123*452 is NOT a base-9 number.    // '*' is not a digit

        Example)
            Input a number: 81726
            Input base (0 ~ 10): 6
            81726 is NOT a base-6 number.      // '8', '7' and '6' are not in the valid range [0, 5]


    Name your file as <student_id>_<name>_check_base.c.

*/

#include <stdio.h>

int GetStringLength(char string[]);

int main()
{
    char num[256] = "";
    int base = 0;
    int i = 0;
    int is_true = 1;

    printf("Input a number: ");
    fgets(num, 255, stdin);
    int len = GetStringLength(num);
    num[--len] = 0;

    printf("Input base (0 ~ 10): ");
    scanf("%d", &base);


    // TO DO: complete this code.
    //        Do not use string manipulation functions not covered in this course yet.
    for (i = 0; i < len; i++){
        
        if (!( (num[i] - '0') >= 0 && (num[i] - '0') < base ) ) {
        //  num[i] - '0' is another way to change the character type of variable into an integer type
        
        //if (!((int)num[i] >= 48 && (int)num[i] <= 48+base-1)){
            printf("%s is NOT a base-%d number", num, base);
            is_true = 0;
            break;
        }
    }
    if (is_true == 1)
        printf("%s is a base-%d number", num, base);


    return 0;
}

int GetStringLength(char string[])
{
    int n = 0;

    while(string[n] != 0)
        n++;

    return n;
}
