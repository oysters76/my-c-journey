#include <stdio.h>

/*
 * The value of the mathematical constant e can be expressed via an infinite series: 
 * e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n! 
 *
 **/

long factorial(int n)
{
 long sum = 1; 
 for (int i = 1; i <= n; i++)
 {
   sum *= i; 
 }
 return sum; 
}

int main(void)
{
 int n = 0; 
 double e = 1; 

 printf("Enter number of times to approximate e : "); 
 scanf("%d", &n); 

 for (int i = 1; i <= n; i++)
 {
  e += 1.0/factorial(i); 
  printf("Approximation of e (%d) times: %lf\n", i, e); 
 } 

 return 0; 
}
