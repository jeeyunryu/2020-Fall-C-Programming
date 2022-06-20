/*

    Write a C program that computes the end time from the start time and elapsed time.
    시작 시간과 소요 시간을 입력받아 종료 시간을 계산하는 프로그램을 작성하시오.

        1. Read the hour of start time as an integer in range [1, 12].
            시작 시간의 시(hour)를 1~12 사이의 정수로 입력받는다.

        2. Read the elapsed time in hour, which is an arbitrary non-negative integer.
            소요시간을 시간(hour) 단위로 읽는다. 소요시간은 0, 또는 임의의 양수이다.

        3. Compute the hour of the end time from the sum of the start hour and the elapsed hour and print it.
            시작 시(hour)와 소요 시(hour)의 합으로부터 종료 시(hour)를 계산해 출력하라.
            - The end hour should be in range [1, 12].
            - Do not separate AM and PM.

        Example)
            Input the start hour (1~12): 5
            Input the elapsed time in hours: 20
            5 + 20 = 1                  // 5 + 20 = 25 = 1

        Example)
            Input the start hour (1~12): 12
            Input the elapsed time in hours: 0
            12 + 0 = 12

        Example)
            Input the start hour (1~12): 8
            Input the elapsed time in hours: 30
            8 + 30 = 2                  // 8 + 30 = 38 = 2

    Name your file as <student_id>_<name>_clock.c.

*/

#include <stdio.h>

int main()
{

    int start = 0;
    int elapsed = 0;
    int end = 0;

    while(start < 1 || start > 12){    // when user types value which is out of range, run while loop 
        printf("Input the start hour (1~12): ");
        scanf("%d", &start);
        if (start < 1 || start > 12)     // when input is out of range print out an error message
            printf("Input out of range.\n");

    }
   

    printf("Input the elapsed time in hours: ");
    scanf("%d", &elapsed);

    end = start +  elapsed;

    if(end % 12 != 0)
        printf("%d + %d = %d\n", start, elapsed, end%12);
    else if (end % 12 == 0)
        printf("%d + %d = %d\n", start, elapsed, 12);




    return 0;
}
