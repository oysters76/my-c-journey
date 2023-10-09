#include <stdio.h>

char pieces [] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p'};
void add_main_pieces(char * row, int i, int is_upper)
{
  for (int j = 0; j < 8; j++)
  {
	row[j] = is_upper == 1 ? (pieces[j]-32) : pieces[j]; 
  }	
}

void add_pawns(char * row, int i, int is_upper)
{
 for (int j = 0; j < 8; j++)
 {
 	row[j] = is_upper == 1 ? (pieces[8]-32) : pieces[8];  
 }
}

void add_space(char * row, int i, int is_even)
{
 char s = is_even == 1 ? ' ' : '*'; 
 char p = is_even == 1 ? '*' : ' '; 
 for (int j = 0; j < 8; j++)
 {
     row[j] = (((j+1)%2) == 0) ? p : s; 
 }
}

int main(void)
{
	char grid[8][8]; 
	for (int i = 0; i < 8; i++)
	{
	   if (i == 0 || i == 7)
	   {
		add_main_pieces(grid[i], i, i == 7);
		continue; 
	   }
	   if (i == 1 || i == 6)
	   {
		add_pawns(grid[i], i, i == 6); 
	   	continue;
	   }
	   add_space(grid[i], i, ((i % 2)==0));
	}

	for (int i = 0; i < 8; i++)
	{
          for (int j = 0; j < 8; j++)
	  {
	     printf("%c", grid[i][j]); 
	  }
	  printf("\n");
	}
	int size = sizeof(grid[0])/sizeof(grid[0][0]); 
	printf("size: %d\n", size);	
}
