#include <stdio.h>
#define LEN 50

int main(void){

  char statement[LEN];
  char* p = statement;
  int n = 0; 
  for (int i = 0; i < LEN; i++){
    char c = getchar();
    if (c == '\n')
      break;
    *p = c; 
    p++;
    n++;
  }
  p--;
  printf("\n"); 
  printf("Your statement reversed: "); 
  for (int i = n-1; i >= 0; i--){
    printf("%c", *p);
    p--;
  }
  printf("\n");

}
