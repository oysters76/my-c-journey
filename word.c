#include <stdio.h> 

int main(void)
{
 char ch = ' ';
 float word_len = 0; 
 float sentence_len = 0; 
 while ((ch = getchar()) != '\n')
 {
  if (ch == ' ')
  {
	word_len += 1; 
  }else
  {
	sentence_len += 1; 
  }
 }
 word_len += 1;
 float avg_word_len = sentence_len/word_len; 
 printf("Words size : %f\n", word_len); 
 printf("Total characters: %f\n", sentence_len); 
 printf("Average word len is %f\n", avg_word_len);
 return 0; 
}
