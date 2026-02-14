#include <stdio.h>

#define SIZE 10
struct Stack{
    int top;
    char arr[SIZE];
};

void init(struct Stack *a){
    a->top = -1;
}

int push(struct Stack *a, char val){
    if (a->top+1 == SIZE){
        return 0;
    }
    a->arr[++a->top] = val;
    return 1;
}

int pop(struct Stack *a, char *val){
    if (a->top == -1) {
        return 0;
    }
    *val = a->arr[a->top--];
    return 1;
}

void display(struct Stack *a){
    if (a->top == -1){
        printf("Empty Array");
        return;
    }
    for (int i = 0;i<=a->top;i++){
        printf("%c ", a->arr[i]);
    }
}

void main(){
    struct Stack a;
    init(&a);
    char q[SIZE];
    printf("Enter expression: ");
    scanf("%s", &q);
    for(int i = 0; q[i] != '\0'; i++){
        if (q[i] == '(' || q[i] == '[' || q[i] == '{') {
                push(&a, q[i]);
        } else if (q[i] == ')' || q[i] == ']' || q[i] == '}') {
            char temp;
            int t = pop(&a, &temp);
            if (t == 0) {
                printf("Not balanced");
                return;
            }
            if ((q[i] == ']' && temp == '[') || (q[i] == ')' && temp == '(') || (q[i] == '}' && temp == '{')){
                continue;
            } else {
                printf("NOT BALANCED");
                return;
            }
        }

    }
    if (a.top == -1){
        printf("BALANCED BRACKETS");
    } else {
        printf("UNBALANCED");
    }
}
