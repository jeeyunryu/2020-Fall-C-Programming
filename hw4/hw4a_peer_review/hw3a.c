#include <stdio.h>

int main()
{
  int num1 = 0, num2 = 0;
  int near = 0;
  int smaller = 0, larger = 0;
  int result = 0;
  
  printf("Input two integers: \n");
  scanf("%d %d", &num1, &num2);


  if ( num1 % num2 == 0)
  {
    printf("%d is a multiple of %d\n", num1, num2);
  }
  else
  {
    printf("%d is not a multiple of %d\n", num1, num2);
    
    result = num1 / num2;

    smaller = result * num2;
    larger = (result + 1) * num2;
    
    if ((num1 - smaller) < (larger -  num1) || ((num1 - smaller) == (larger - num1)))
    {
      near = smaller;
    }
    if ((num1 - smaller) > (larger - num1))
    {
      near = larger;
    }

    
    printf("The multiple of %d nearest from %d is %d\n", num2, num1, near);
    
  }
  
  
  
  
  
  
  
  return 0;
  
}