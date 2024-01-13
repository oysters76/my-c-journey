#include <stdio.h> 
#include <string.h> 

#define WORD_SIZE 50 

int read_line(char [], int);

int main(void){
    char smallest_word[WORD_SIZE+1] = "zzz"; 
    char largest_word[WORD_SIZE+1] = "aaa";  
    char word[WORD_SIZE + 1]; 
    while (1){
        printf("Enter a word: "); 
        read_line(word, WORD_SIZE);
        if (strlen(word) == 4){
            break; 
        }
        if (strcmp(smallest_word, word) > 0)
            strcpy(smallest_word, word); 
        if (strcmp(largest_word, word) < 0) 
            strcpy(largest_word, word);
    }

    printf("\nSmallest word: %s\n", smallest_word); 
    printf("Largest word: %s\n", largest_word);

    return 0; 
}

int read_line(char str[], int n){
    int ch, i = 0; 
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;         
    }
    str[i] = '\0'; 
    return i; 
}