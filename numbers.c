#include <stdio.h> 
#define N 10000 

int is_even(int n)
{
 return n % 2 == 0; 
}

int is_odd(int n)
{
 return n % 2 != 0; 
}


void print_numbers_based_on_condition(int n, int condition_func(int))
{
 for (int i = 1; i <= n; i++)
 {
   if (condition_func(i))
   {
     printf("%d", i);
   if (i != n)
     {
       if (i == (n-1) && condition_func(n) == 0)
	 break;
       printf(" , ");	
     }
   }
 }
 printf("\n");
}

int main(void)
{
 print_numbers_based_on_condition(N, is_even);  
 return 0; 
}
