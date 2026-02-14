#include <stdio.h>

# define SIZE 20
struct Stack{
    int top;
    char arr[SIZE];
};
void display(struct Stack *a) {
    for (int i = 0;i<=a->top; i++){
        printf("%c ", a->arr[i]);
    }
    printf("\n");
}

void init(struct Stack *a){
    a->top = -1;
}

int push(struct Stack *a, char c){
    if (a->top + 1 == SIZE){
        return 0;
    }
    a->arr[++a->top] = c;
    return 1;
}

int pop(struct Stack *a, char *c) {
    if (a->top == -1){
        return 0;
    }
    *c = a->arr[a->top--];
    return 1;
}



void main() {
    struct Stack a;
    init(&a);
    printf("Enter the String: ");
    char q[SIZE];
    scanf("%s", &q);
    for(int i = 0; q[i] != '\0'; i++){
        push(&a, q[i]);
    }
    for (int i = 0; a.top > -1; i++) {
        pop(&a, &q[i]);
    }
    for(int i = 0; q[i] != '\0'; i++){
        printf("%c", q[i]);
    }
}
