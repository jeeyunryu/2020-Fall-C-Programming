/*

    Write a C program as follows:
        1. Read two numbers, k and limit.
            두 수 k와 limit을 입력받는다.

        2. Print all positive multilples of k that is less than or equal to limit as the following examples.
            limit 이하의 양수 중 k의 배수를 모두 출력한다.

        3. Print the sum of the multiples of k printed in step 2 as the following examples.
            2단계에서 출력한 limit 이하 k의 배수의 합을 출력하시오.

    Example)
        Input k: 3
        Input limit: 60
        3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57 60 
        The sum of multiples of 3 in [1, 60] = 630

    Example)
        Input k: 6
        Input limit: 100
        6 12 18 24 30 36 42 48 54 60 66 72 78 84 90 96 
        The sum of multiples of 6 in [1, 100] = 816

    Name your file as <student_id>_<name>_sum_of_multiples.c.

*/

#include <stdio.h>

int main()
{

    int k = 0;
    int limit = 0;
    int i = 0;
    int end = 0;
    int count = 0;

    printf("Input k: ");
    scanf("%d", &k);

    printf("Input limit: ");
    scanf("%d", &limit);

    end = limit / k;

    for (i = 0; i< end; i++){
    
        
        printf("%d ", (i+1)*k);
        count+= (i+1)*k;
    }
        printf("\n");
        printf("The sum of multiples of %d in [1, %d] = %d\n", k, limit, count);


    return 0;

}