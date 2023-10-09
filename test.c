#include <stdio.h>

void enforce_rule(char c, char lower, char upper,char map, char * res)
{
 if (c >= lower && c <= upper)
   *res = map; 
}

char ch_to_num(char c)
{
  enforce_rule(c, 'A', 'C', '2', &c); 
  enforce_rule(c, 'D', 'F', '3', &c); 
  enforce_rule(c, 'G', 'I', '4', &c); 
  enforce_rule(c, 'J', 'L', '5', &c); 
  enforce_rule(c, 'M', 'O', '6', &c); 
  enforce_rule(c, 'P', 'S', '7', &c); 
  enforce_rule(c, 'T', 'V', '8', &c); 
  enforce_rule(c, 'W', 'Z', '9', &c); 
  return c; 
}

int main(void)
{
 char ch = ' '; 
 printf("Enter phone number: "); 
 while ((ch = getchar()) != '\n')
 {
   putchar(ch_to_num(ch));
 }
 putchar('\n');
 return 0; 
}
