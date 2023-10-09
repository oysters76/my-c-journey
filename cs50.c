#include <stdio.h> 

typedef struct {
  char o[10]; 
} output; 


output get_string(char * str)
{
 printf("%s :", str); 
 output s; 
 scanf("%s :", s.o); 
 return s; 
}

int main(void)
{
 output o1 = get_string("what is your name?"); 
 printf("Your name is %s\n", o1.o); 
 return 0; 
}
