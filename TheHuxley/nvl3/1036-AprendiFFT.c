#include <stdio.h>

void multPolinomio(int pol1[], int pol2[], int x, int y) {
    
    int arr[x][y], i, j, count = 0;
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            arr[i][j] = pol1[i]*pol2[j];
            //printf("I: %d J: %d arr: %d\n", i,  j, arr[i][j]);
        }
        
    }
   
    for(i = 0; i < x-1; i++) {
        for(j = 1; j < y; j++) {
           arr[i+1][j-1] = arr[i][j] + arr[i+1][j-1];
           //printf("I: %d J: %d arr: %d arrF: %d\n", i, j, arr[i][j], arr[i+1][j-1]);
           arr[i][j] = 0;
           //printf("dps da soma arrF: %d\n", arr[i+1][j-1]);
        }
        
    }
    
    for(i = 0; i < x; i++) {
        
        for(j = 0; j < y-1; j++) {
            if(arr[i][j] == 0) continue;
            printf("%d ", arr[i][j]);
        }
        
    }
    printf("%d", arr[x-1][y-1]);
    
    
    printf("\n");
    
    
}


int main() {
    
    int x, y, i, count = 1;

    while(scanf("%d %d", &x, &y) != EOF) {
        x++;
        y++;
        int pol1[x], pol2[y];
        //printf("X: %d Y: %d\n", x, y);
        for(i = 0; i < x; i++) scanf("%d", &pol1[i]);
        for(i = 0; i < y; i++) scanf("%d", &pol2[i]); 
        printf("Caso #%d: ", count);
        multPolinomio(pol1, pol2, x, y);
        count++;
        
    }
    
    return 0;
}