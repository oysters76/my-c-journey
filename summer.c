#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main(int argc, char * argv[]){
    int sum = 0; 
    char result [argc * 4]; 
    for (int i = 1; i < argc; i++){
        char * argument = argv[i]; 
        sum += atoi(argument); 
        strcat(result, argument); 
        if (i != (argc-1)) 
            strcat(result, "+");
    }
    printf("%s = %d\n", result, sum);
}