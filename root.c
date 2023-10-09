#include <stdio.h> 
#include <math.h> 

int main(void)
{
 double   x   = 0.0f; 
 double   y   = 1.0f;  
 double avg   = 0.0f; 
 double old_y = 0.0f; 
 const float eps = 0.00001;

 printf("Enter number to find square-root: "); 
 scanf("%lf", &x);  
 while (1)
 {
   avg = (y + (x/y))/2; 
   old_y = y; 
   y = avg; 

   if (fabs(old_y - y) <= eps)
    break;	   
 }

 printf("Square root of %f is %f\n", x, y); 

 return 0; 
}
