// Palindome implementation in c via a stack!

#include <stdio.h> 
#include <string.h> 

int push(char * stack, char c, int count){
    stack[count] = c; 
    return count+1;
}

int pop(char * stack, int count){
    stack[count-1] = ' '; 
    return count-1;
}

char peek(char * stack, int count){
    if (strlen(stack) == 0)
        return ' ';
    return stack[count-1];
}

int is_palindrome(char * text, int size){
    char stack[size];
    int count = 0; 
    for (int i = 0; i < size; i++){
        char p = peek(stack, count); 
        if (p == text[i]){
            count = pop(stack, count); 
        }else{
            count = push(stack, text[i], count);
        }
    }
    return count == 0;
}

int main(int argc, char * argv[]){ 
    if (argc == 1){
        printf("Error! Need one argument!\n");
        return 1; 
    }
    char * outcome = is_palindrome(argv[1], strlen(argv[1])) ? "Yes!" : "No :("; 
    printf("Result: %s\n", outcome);
    return 0; 
}