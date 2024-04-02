
/*
 Solve primes numbers: Sieve of Eratosthenes
 https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes 
*/

#include <stdio.h> 
#include <stdbool.h>
#define M 1000000

void populate(bool * stat, int size){
    for (int i = 0; i < size; i++) 
      stat[i] = false;
}

bool seiveByN(bool * stat, int start, int n, int size){
    bool didEdits = ((start+n)<size); 
    for (int i = start+n; i < size; i += n){
        stat[i] = true;
    }
    return didEdits; 
}

int main(void){ 
    bool stat[M];  
    populate(stat, M);
    bool editsMade = true; 
    int seiveBy = 2; 
    while (editsMade){
        editsMade = seiveByN(stat, seiveBy, seiveBy, M); 
        int nextIndex = seiveBy+1; 
        while (nextIndex < M){
            if (!stat[nextIndex]){
                seiveBy = nextIndex;
                break; 
            }
            nextIndex++; 
        }
    }
    for(int i = 2; i < M; i++){
        if (!stat[i]){
            printf("%d is a prime\n", i); 
        }
    }
    return 0; 
}