#include <stdio.h>

#define SIZE 10
struct Queue{
    int top;
    int arr[SIZE];
};

void init(struct Queue *a){
    a->top = -1;
}

int push(struct Queue *a, int val){
    if (a->top+1 == SIZE){
        return 0;
    }
    a->arr[++a->top] = val;
    return 1;
}

int pop(struct Queue *a, int *val){
    if (a->top == -1) {
        return 0;
    }
    *val = a->arr[a->top--];
    return 1;
}

void display(struct Queue *a){
    if (a->top == -1){
        printf("Empty Array");
        return;
    }
    for (int i = 0;i<=a->top;i++){
        printf("%d ", a->arr[i]);
    }
}

void main(){
    struct Queue a;
    init(&a);
    push(&a, 121);
    int cal;
    pop(&a, &cal);
    display(&a);
    push(&a, 222);
    printf("%d", cal);
}
