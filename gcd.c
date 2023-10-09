#include <stdio.h>


/*
 * The classical algorithm to compute the gcd, goes as follows:
 * It is known as the Euclid Algorithm, 
 * 
 * let m and n be two integers (numbers) 
 * if n is 0, then stop, m contains the gcd 
 * otherwise, 
 * compute the remainder when m is divided by n. Copy n into m
 * and copy the remainder into n. 
 * Then repeat the process, starting with testing whether n is 0. 
 */

int calc_gcd(int n1, int n2)
{
 int n = n1; 
 int m = n2;  
 
 while (n != 0)
 {
   int r = m % n;
   m = n; 
   n = r; 
 }

 return m; 
}

int main(void)
{
 int n1, n2; 
 printf("Enter two integers: "); 
 scanf("%d %d", &n1, &n2); 
 printf("Greatest common divisor: %d\n", calc_gcd(n1,n2)); 
 return 0; 
}
