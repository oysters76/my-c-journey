#include <stdio.h> 

int main(void)
{
	char array[8][8];
	for (int i = 0; i < 8; i++)
	{
	  for(int j = 0; j < 8; j++)
	  {
		int is_even = ((i+j) % 2) == 0; 
		array[i][j] = is_even == 1 ? 'B' : 'R'; 
		printf("%c", array[i][j]);   
	  }
	  printf("\n");
	}
	return 0; 
}
