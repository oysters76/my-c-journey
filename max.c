#include <stdio.h>

int main(void)
{
  float max = 0; 
  float cnum = 0;
  for(;;)
  {
    printf("Enter a number: "); 
    scanf("%f", &cnum); 
    if (cnum <= 0)
      break; 
    if (max < cnum)
      max = cnum;	    
  }
  printf("The largest number entered was : %.2f\n", max); 
}
