#include <stdio.h>

int main() {
    
    int n, i;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for(i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    
    for(i = 0; i < n; i++) {
        printf("%d\n", arr1[i]);
        printf("%d\n", arr2[i]);
    }
    
    return 0;
}