#include <string.h> 
#include <assert.h>
#include <stdio.h>

#define MAX_WORD_SIZE 200 

int get_spacings(char * sample){
    int n = strlen(sample); 
    int count = 0; 
    for (int i = 0; i < n; i++){
        char c = sample[i]; 
        if (c == ' ') count++; 
    }
    return (count+1);
}

void split(int n, int m, char words[n][m], char * text){
    int size = strlen(text); 
    int p = 0; 
    char str[m];
    int sind = 0;  
    for (int i = 0; i < size; i++){
        char c = text[i]; 
        if (c == ' '){
            //dump old word
            assert((sind+1) < m); 
            assert((p+1) < n);
            str[sind++] = '\0'; 
            strcpy(words[p++], str); 

            //reset word 
            sind = 0;
            str[sind] = '\0'; 
            continue; 
        } 
        assert((sind+1) < m);
        str[sind++] = c; 
    }
    //if there are any remaining word in memory, add it as well
    if (sind > 0){
        assert((sind+1) < m); 
        str[sind++] = '\0'; 
        assert((p) < n);
        strcpy(words[p], str);
    }
}  

int main(void){
    char * sample = "booo pali"; 
    int n = get_spacings(sample); 
    char words[n][MAX_WORD_SIZE]; 
    split(n, MAX_WORD_SIZE, words, sample);
    
    //let's print the words.
    for (int i = 0; i < n; i++){
        printf("%d.) %s\n", i+1, words[i]); 
    }

    /*output:
        1.) list
        2.) of
        3.) words
    */
    return 0; 
}