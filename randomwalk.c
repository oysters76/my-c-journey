#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define N 10 

const int letter_min = 65; 
const int letter_max = 90; 

int get_x(int x, int path)
{
  if (path == 1)
    x += 1; 
  if (path == 3)
    x -= 1; 
  return x;
}

int get_y(int y, int path)
{
 if (path == 0)
   y -= 1; 
 if (path == 2)
   y += 1; 	
 return y;
}

int check_valid(int x, int y, int path)
{
  int x1 = get_x(x, path); 
  int y1 = get_y(y, path); 

  int is_x_valid = x1 >= 0 && x1 < N; 
  int is_y_valid = y1 >= 0 && y1 < N; 

  return is_x_valid == 1 && is_y_valid == 1; 
}

void print_grid(char grid[N][N])
{
 printf("\n");
 for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  time_t t;
  srand((unsigned) time(&t)); 	
  char grid[N][N]; 
  char letter = letter_min; 
   
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      grid[i][j] = '.'; 
    }
  }

  int x = 0; 
  int y = 0; 
  grid[x][y] = letter; 
  letter += 1; 
  while (1){
    if (letter > letter_max)
	break;
    int path = rand()%4;
    int is_valid = check_valid(x,y,path); 
    
    int x1 = get_x(x, path);
    int y1 = get_y(y, path); 

    if (is_valid == 1 && grid[x1][y1] == '.')
    {
 	x = get_x(x,path); 
	y = get_y(y,path);
	
    }else
    {
	int is_blocked = 1; 
	for (int i = 0; i < 4; i++)
    	{
	   if (i == path)
	    continue; 
	   is_valid = check_valid(x,y,i);
	   if (is_valid)
	   {
	      x1 = get_x(x,i); 
	      y1 = get_y(y,i); 
	      is_blocked &= (grid[x1][y1] != '.');
	      if (is_blocked == 0)
		 break;      
	   }
    	}
	if (is_blocked == 1)
	   break; 	
	x = x1;
	y = y1;
    }
    grid[x][y] = letter;
    letter += 1;
    print_grid(grid);
  }
  print_grid(grid);
}
