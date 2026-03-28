#include <stdio.h>

void main(){
    int c1=3, c2=4;
    int arr1[] = {2, 1,4};
    int arr2[] = {5,7,9,3};

    int ans[c1+c2];
    for(int i=0;i<c1; i++){
        ans[i] = arr1[i];
    }
    for(int i=0;i<c2; i++){
        ans[c1+i] = arr2[i];
    }
    printf("Merged Array: ");
    for(int i=0;i<c1+c2; i++){
        printf("%d ", ans[i]);
    }
}
