#include <stdio.h>

#define SIZE 4
struct Queue{
    int start;
    int end;
    int arr[SIZE];
};

void init(struct Queue *a){
    a->start = -1;
    a->end = -1;
}

int push(struct Queue *a, int val){
    if (a->end - a->start == SIZE){
        return 0;
    }
    a->end = (a->end+1) % SIZE;
    a->arr[a->end] = val;
    return 1;
}

int pop(struct Queue *a, int *val){
    if (a->end - a->start == 0) {
        return 0;
    }
    a->start = (a->start + 1) % SIZE;
    *val = a->arr[a->start];
    return 1;
}

void display(struct Queue *a){
    if (a->end - a->start == 0){
        printf("Empty Array\n");
        return;
    }
    printf("START = %d, END = %d", a->start, a->end);
    int i = a->end;
    while (i!= a->start){
        printf("%d ", a->arr[i]);
        i = (i-1) % SIZE;
    }
    printf("\n");
}

void main(){
    struct Queue a;
    init(&a);
    push(&a, 121);
    push(&a, 121);
    push(&a, 121);
    push(&a, 121);
    push(&a, 122);
    display(&a);
    int cal;
    pop(&a, &cal);
    display(&a);
    push(&a, 222);
    push(&a, 111);
    display(&a);
}
