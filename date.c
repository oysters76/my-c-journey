#include <stdio.h>

typedef struct {
 int day;
 int month;
 int year;
} Date; 

void print_date(Date);

Date get_date(void)
{
 Date d; 
 printf("Enter a date (mm/dd/yy): ");
 scanf("%2d/%2d/%2d", &d.month, &d.day, &d.year);
 return d; 
}

int convert_date_to_ints(Date d)
{
 return d.day + (d.month * 1000) + (d.year * 10000); 
}

int check_min_date(Date d1, Date d2)
{
 int d1_i = convert_date_to_ints(d1); 
 int d2_i = convert_date_to_ints(d2);

 return d1_i < d2_i; 
}

int should_stop(Date d)
{
 return (d.day == 0 && d.month == 0 && d.year == 0); 
}

void print_date(Date d)
{
 printf("%2d/%2d/%2d", d.day, d.month, d.year);  
}

Date init_date(int val)
{
  Date bigDate; 
  bigDate.day   = val; 
  bigDate.month = val; 
  bigDate.year  = val;
  return bigDate; 
}

int main(void)
{
 Date minDate     = init_date(10000);
 Date currentDate = init_date(10000);
 int doStop = 0; 
 while (!doStop)
 {
   currentDate = get_date();  
   doStop = should_stop(currentDate); 
   if (!doStop)
     minDate = check_min_date(minDate, currentDate) ? minDate : currentDate; 
 }
 print_date(minDate);
 printf(" is the earliest date.\n"); 
 return 0; 
}
