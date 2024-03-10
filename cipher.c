#include <stdio.h> 
#include <ctype.h> 

#define MAX_SIZE     80 
#define LETTER_COUNT 26

char encode(char c, int n){
    if (!isalpha(c)) return c; 
    char p = isupper(c) ? 'A' : 'a'; 
    return (((c - p) + n) % LETTER_COUNT) + p;  
}

int main(void){ 
    int shift = 1; 
    printf("Enter shift amount: "); 
    scanf("%d", &shift); 
    printf("Enter message to be encrypted: "); 
    int size = 0; 
    char encoded[MAX_SIZE+1]; 
    for (int i = 0; i < MAX_SIZE; i++){
        char c = getchar(); 
        if (c == '\n' && i != 0){
            break; 
        }
        encoded[i] = encode(c, shift); 
        size += 1; 
    }
    encoded[size] = '\0'; 
    printf("Encoded message: %s\n", encoded); 
    return 0; 
}