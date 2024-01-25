#include <stdio.h> 

char * months [] = {
 "Jan", 
 "Feb",
 "Mar",
 "Apr",
 "May",
 "June",
 "July",
 "Aug",
 "Sept",
 "Oct",
 "Nov",
 "Dec"
};

char * errors [] = {
    "Invalid month", 
    "Invalid day",
    "Invalid year"
};

int formatDate(int, int, int); 
char * getErrorMessage(int); 

int main(void){

    int day,month,year; 

    scanf("%d/%d/%d", &day, &month, &year); 

    int error = formatDate(day,month,year); 
    if (error < 0){
        printf("Invalid date! Error: %s\n", getErrorMessage(error)); 
        return 1; 
    }

    return 0; 
}

char * getErrorMessage(int error){
    if (error < -3 || error > 0){
        return "Undefined error!"; 
    }
    error = (error*-1)-1; 
    return errors[error]; 
}

int formatDate(int day, int month, int year){
    month -= 1;
    if (month < 0 || month >= 12){
       return -1; 
    }
    if (day <= 0) return -2; 
    if (year <= 0) return -3; 
    printf("%s %02d, %d\n", months[month], day, year);    
    return 0;
} 