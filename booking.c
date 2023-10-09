#include <stdio.h> 

typedef struct 
{
  char code[10];
  int owner; 
} Seat; 

typedef struct 
{
  char name[100]; 
  int seats[10]; 
} Owner; 

Seat seats[100]; 
Owner owners[10]; 

Owner init_owner(char name[100])
{

}

int main(void)
{
 
 return 0; 
}
