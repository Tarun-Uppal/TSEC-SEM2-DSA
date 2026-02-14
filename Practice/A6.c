#include <stdio.h>
# include <ctype.h>
# include <string.h>
# define SIZE 20
struct Stack{
    int top;
    int arr[SIZE];
};
void display(struct Stack *a) {
    for (int i = 0;i<=a->top; i++){
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

void init(struct Stack *a){
    a->top = -1;
}

int push(struct Stack *a, int c){
    if (a->top + 1 == SIZE){
        return 0;
    }
    a->arr[++a->top] = c;
    return 1;
}

int pop(struct Stack *a, int *c) {
    if (a->top == -1){
        return 0;
    }
    *c = a->arr[a->top--];
    return 1;
}

struct Stack1{
    int top;
    char arr[SIZE];
};
void display(struct Stack1 *a) {
    for (int i = 0;i<=a->top; i++){
        printf("%c ", a->arr[i]);
    }
    printf("\n");
}

void init(struct Stack1 *a){
    a->top = -1;
}

int push(struct Stack1 *a, char c){
    if (a->top + 1 == SIZE){
        return 0;
    }
    a->arr[++a->top] = c;
    return 1;
}

int pop(struct Stack1 *a, char *c) {
    if (a->top == -1){
        return 0;
    }
    *c = a->arr[a->top--];
    return 1;
}



void main() {
    struct Stack num;
    struct Stack1 func;
    init(&num);
    printf("Enter the postfix: ");
    char q[SIZE];
    scanf("%s", &q);

    for(int i = 0; q[i] != '\0'; i--) {
        if(isdigit(q[i])) {
            push(&num, q[i] - '0');
        } else {
        }
    }
}
