/*

    Write a C program that draws a vertical parallelogram.
        1. Read the width of the parallelogram.
            사용자로부터 평행사변형의 너비를 입력받는다.

        2. Draw a parallelogram whose left and right sides are vertical lines as the following examples.
            아래 예제들과 같이 좌우변이 수직선인 평행성을 그린다.
            - The parallelogram is compose of three parts (an upper triangle, a middle square, and a lower triangle).
                평행사변형은 세 부분 (상단 삼각형, 중단 정사각형, 하단 삼각형)으로 구성된다.

              The height of each part is the same as the width.
                각 파트의 높이는 너비와 같다.

            - You need to use the loop statements, such as the for-statement.
                
            - Do NOT user gotoxy() or other functions in Console.c and Console.h
                gotoxy()와 같은 Console.c, Console.h의 함수들은 사용하지 마시오.
        
        Example) 
            Input the width of vertical parallelogram: 5
            *    
            **   
            * *  
            *  * 
            *   *
            *   *
            *   *
            *   *
            *   *
            *   *
            *   *
             *  *
              * *
               **
                *

        Example)
            Input the width of vertical parallelogram: 8
            *
            **
            * *
            *  *
            *   *
            *    *
            *     *
            *      *
            *      *
            *      *
            *      *
            *      *
            *      *
            *      *
            *      *
            *      *
            *      *
             *     *
              *    *
               *   *
                *  *
                 * *
                  **
                   *

    Name your file as <student_id>_<name>_parallelogram.c.

*/

#include <stdio.h>

int main()
{
    int width = 0;
    int i = 0, j = 0;

    printf("Input the width of vertical parallelogram: ");
    scanf("%d", &width);

    // draw upper part

    for (i = 0; i< width ; i++){
        printf("*");

        for ( j = 0; j < i-1; j++){
            printf(" ");
        }
        
        if (i != 0)
            printf("*");

        printf("\n");


    }



    // draw middle part
    
    for (i = 0; i < width; i++){
       
        printf("*");
        for(j = 0; j < width-2; j++){
            printf(" ");
        }
        printf("*");

        printf("\n");
    }
    
    




    // draw lower part
    if (width != 1){
       for ( i = 0; i < width; i++){

        for (j = 0; j < i; j++){
            printf(" ");
        }
        
        if (i != width-1)
            printf("*");
        

        for (j = 0; j < width-2-i; j++){
            printf(" ");
        }

        printf("*");
        printf("\n");

        } 
    
    }

    else if(width == 1)
        printf(" *\n");
    



    return 0;
}
