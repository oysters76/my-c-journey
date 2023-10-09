#include <stdio.h>

const int SUN = 0; 
const int MON = 1; 
const int TUE = 2; 
const int WED = 3; 
const int THU = 4; 
const int FRI = 5; 
const int SAT = 6; 
const int SIZE = 7; 
const char * WEEK_STRS [] = {"SU", "MO", "TU", "WE", "TH", "FR", "SA"};

void print_calendar_headers()
{
 for (int i = 0; i < SIZE; i++)
 {
   printf(" %s ", WEEK_STRS[i]); 
 }
 printf("\n");
}

void print_start_trail(int start)
{
 if (start <= SUN || start > SAT) 
   return; 
 for (int i = 0; i < start-1; i++) 
   printf("    "); 
}

int is_last_day(int n)
{
 return n % 7 == SUN; 
}

void print_calendar(int n, int start)
{
  print_calendar_headers(); 
  print_start_trail(start); 
  for (int i = 1; i <= n; i++)
  {
    printf(" %02d ", i); 
    if (is_last_day(start))
      printf("\n"); 
    start += 1;
  }
  printf("\n");
}

int main(void)
{
 int n = 0; 
 int start = 0; 
 printf("Enter number of days: "); 
 scanf("%d", &n); 
 printf("Enter starting day of week (1=SUN, 6=SAT): "); 
 scanf("%d", &start); 
 print_calendar(n, start); 
 return 0; 
}
