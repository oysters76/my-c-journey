#include <stdio.h> 

char to_upper(char c)
{
 if (c >= 'a' && c <= 'z') 
   return (c - ('a' - 'A')); 
 return c; 
}

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

char space_to_map(char c)
{
 if (c == ' ')
   return '-'; 
 return c; 
}

int main(void)
{
 char ch = ' '; 
 printf("Enter text to encode: "); 
 while ((ch = getchar()) != '\n')
 {
  char out = ch_to_num(to_upper(ch)); 
  out      = space_to_map(out); 
  putchar(out); 
 }
 putchar('\n');
 return 0; 
}
