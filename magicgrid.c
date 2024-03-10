#include <stdio.h> 

#define TEST_MODE 0

int isComplete(int n, int grid[n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == -1) return 0; 
        }
    }
    return 1; 
}

void initGrid(int n, int grid[n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            grid[i][j] = -1; 
        }
    }
}

int wrapNumber(int n, int d){
    if (n < 0) return (d-1); 
    if (n >= d) return 0; 
    return n; 
}

void printGrid(int d, int grid[][d]){
    int width = d; 
    printf("\n");
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            printf("%*d", width, grid[i][j]); 
        }
        printf("\n");
    }
}

void buildMagicSquare(int d, int grid[d][d]){
    initGrid(d, grid); 

    int x = (d-1)/2; 
    int y = 0; 
    int num = 1; 
    while(!isComplete(d, grid)){
        grid[y][x] = num; 

        int ny = y - 1; 
        int nx = x + 1;  

        ny = wrapNumber(ny, d); 
        nx = wrapNumber(nx, d); 

        int val = grid[ny][nx]; 
        if (val != -1){
            ny = y + 1;
            nx = x; 
            ny = wrapNumber(ny, d); 
            nx = wrapNumber(nx, d); 
        }
        x = nx; 
        y = ny;
        num += 1; 
    }
}

int assertMagicSquare(){
    if (TEST_MODE == 0) return 0;
    int d = 5; 
    int expected[5][5] = {
        {17,24,1,8,15},{23,5,7,14,16},{4,6,13,20,22},
        {10,12,19,21,3},
        {11,18,25,2,9}
    };
    int actual[d][d]; 
    buildMagicSquare(5, actual); 
    int isError = 0; 
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (actual[i][j] != expected[i][j]){
                printf("[Assert Error]: value at position (%d,%d) doesn't match.\n\tExpected:%d, Actual %d\n", 
                i, j, expected[i][j], actual[i][j]);
                isError = 1;                 
            }
        }
    }
    if (isError > 0){
        printf("Test failed!\n");
        return 1;
    }else{
        printf("Test passed!\n");
        return 0;
    }
}

int main(void){
    if(assertMagicSquare() > 0) return 1; 

    int d = 0; 
    printf("The size must be an odd number between 0 and 99: "); 
    scanf("%d", &d); 

    if (d % 2 == 0){
        printf("Error: %d isn't an odd number!\n", d);
        return 1;
    }

    int grid[d][d]; 
    buildMagicSquare(d, grid);
    printGrid(d, grid); 
    return 0; 
}