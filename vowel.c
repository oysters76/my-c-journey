#include <stdio.h>

int is_vowel(char c)
{
	if (c <= 'Z' && c >= 'A') 
		c += 32;  
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

int main(void)
{
 int v_count = 0; 
 printf("Enter a phrase: ");
 char ch = ' '; 
 while ((ch = getchar()) != '\n')
 {
	v_count += (is_vowel(ch) ? 1 : 0); 
 }
 char * vowel_suffix = v_count <= 1 ? "" : "s"; 
 printf("Your phrase contains %d vowel%s\n", v_count, vowel_suffix); 
 return 0; 
}
