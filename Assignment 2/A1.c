#include <stdio.h>

# define SIZE 25
struct Stack {
    int top;
    int arr[SIZE];
};

void push(struct Stack *s);
void pop(struct Stack *s);
void display(struct Stack *s);

void main()
{
    struct Stack s;
    s.top = 0;
    int a = 1;
    while (a > 0) {
        int i;
        printf("1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                push(&s);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                return;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
}

/***
Adds elements to the top of the stack
***/
void push(struct Stack *s)
{
    int num;
    // Checks if the stack is full
    if (s->top < SIZE)
    {
        printf("Please enter the number: ");
        scanf("%d", &num);
        s->arr[s->top] = num;
        s->top++;
    }
    else
    {
        printf("STACK IS FULL\n");
    }
}

/***
Remove the last element from the stack
***/
void pop(struct Stack *s)
{
    //Checks if the stack is not empty
    if (s->top > 0)
    {
        s->top--;
        s->arr[s->top] = 0;
    }
    else
    {
        printf("NO ELEMENTS IN STACK\n");
    }
}
/***
Prints all the elements in the stack
***/
void display(struct Stack *s)
{
    // Checks if the stack is empty
    if (s-> top == 0)
    {
        printf("NO ELEMENTS IN STACK\n");
        return;
    }
    for (int j = 0; j<s->top; j++)
    {
        printf("%d, " , s->arr[j]);
    }
    printf("\n");
}
