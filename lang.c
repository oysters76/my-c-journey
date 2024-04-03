// #include <stdio.h> 

// #define ENGLISH 
// #define FRENCH  
// #define SPANISH

void printMessage(){
    #ifdef ENGLISH
    printf("Insert Disk 1\n"); 
    #endif
    #ifdef FRENCH 
    printf("Inserez Le Disque 1\n"); 
    #endif 
    #ifdef SPANISH
    printf("Inserte El Disco 1\n");
    #endif 
}


#define IDENT(x) PRAGMA(ident #x) 
#define PRAGMA(x) _Pragma(#x) 

int main(void){
    IDENT(foo)
    printMessage(); 
}

