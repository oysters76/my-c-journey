#include <stdio.h> 
#include <string.h> 

#define RULE_SIZE 7

char toLower(char c)
{
 if (c >= 'A' && c <= 'Z')
   return (c + (('a' - 'A'))); 		 
 return c; 
}

typedef struct {
 char * letters; 
 int score; 
} Rule; 

Rule create_rule(char * letters, int score)
{
 Rule r; 
 r.letters = letters; 
 r.score = score; 
 return r; 
}

void print_rule(Rule rule)
{
 printf("\n-----------------\n"); 
 printf("Words Allowed : %s\n", rule.letters);
 printf("Score Given   : %d\n", rule.score);
 printf("-----------------\n"); 
}

int get_point_awarded(Rule * rules, int size, char letter)
{
 for (int i = 0; i < size; i++)
 {
   Rule r = rules[i]; 
   for (size_t j = 0; j < strlen(r.letters); j++)
   {
	if (toLower(letter) == toLower(r.letters[j]))
	  return r.score; 		
   }
 }
 return 0; 
}

int main(void)
{
 Rule rules [] = 
 {
   create_rule("AEILNORSTU", 1), 
   create_rule("DG", 2), 
   create_rule("BCMP", 3), 
   create_rule("FHVWY", 4), 
   create_rule("K", 5), 
   create_rule("JX", 6), 
   create_rule("QZ", 7)
 }; 

 int total_score = 0; 
 char ch = ' '; 
 while ((ch = getchar()) != '\n')
 {
  total_score += get_point_awarded(rules, RULE_SIZE, ch);   
 }
 printf("Scrabble value: %d\n", total_score);
 return 0; 
}
