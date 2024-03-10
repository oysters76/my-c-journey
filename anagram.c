#include <stdio.h> 
#include <ctype.h> 

#define WORD_SIZE 26
#define MIN_UPPER 65 
#define MIN_LOWER 97
 
void updateWord(int * word, char * statement, int mult){
    printf("%s: ", statement); 
    char c = getchar();
    while (c != '\n'){
        int ind = -1; 
        if (isalpha(c)){
            if (isupper(c)){
                ind = c - MIN_UPPER; 
            }else{
                ind = c - MIN_LOWER; 
            }
        }
        if (ind != -1){
            word[ind] += (mult * 1); 
        }
        c = getchar();
    }
} 

int isAnagram(int * word){
    for (int i = 0; i < WORD_SIZE; i++){
        if (word[i] != 0){
            return 0; 
        }
    }
    return 1;
}

int main(void){
    int word[WORD_SIZE]; 
    updateWord(word, "Enter first word", 1); //Add occurences
    updateWord(word, "Enter second word", -1); //Sub occurences 
    if (isAnagram(word)){
        printf("The words are anagrams!\n"); 
    }else{
        printf("The words aren't anagrams!\n");
    }
    return 0; 
}