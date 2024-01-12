#include <stdio.h> 
#include <string.h> 

char digit_to_hex(int i){
    return "0123456789ABCEDF"[i]; 
}

int get_count(const char s[], char c){
    int count = 0; 
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == c)
            count++; 
    }
    return count;
}

int main(void){ 
    // printf("if there is a fork in the road, take it.\n");
    // printf("When you come to a fork in the road, take it.    "
    //         "\n-- Yogi Bear"
    //         " the bear that cares"
    //         "wears!");  
    // char * p = "harry potter is the dumb goat head"; 
    // char c = 'h'; 
    // printf("the number of '%c's in \"%s\"is: %d ",c, p, get_count(p,  c)); 
    printf("string compare 'a' with 'a' = %d\n", strcmp("chirath", "vhirath")); 
    return 0; 
}