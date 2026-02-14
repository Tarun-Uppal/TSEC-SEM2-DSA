#include <stdio.h>

#define SIZE 20

int end = 0;
int arr[SIZE];

void push(int a);
void pop();

void main(){
    push(100);
    push(121);
    pop();
    push(111);
    for (int i = 0; i<end; i++){
        printf("%d ", arr[i]);
    }
}
void push(int a){
    if (end+1 == SIZE){
        printf("ERROR\n");
        return;
    }
    arr[end] = a;
    end++;
}
void pop(){
    if (end == 0){
        printf("ERROR");
        return;
    }
    end--;
}
