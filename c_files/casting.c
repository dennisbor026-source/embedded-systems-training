#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *arr;
arr = (int *)malloc(5 * sizeof(int));
if (arr == NULL){
    printf("memory allocation failed\n");
    return 1;
}
for(int i = 0, i<5, i++){
    arr[i] = i*10;
}
free(arr);