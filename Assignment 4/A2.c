#include <stdio.h>
#include <string.h>

# define SIZE 100
struct Stack {
    int top;
    char arr[SIZE];
};

void push(struct Stack *s, char a);
char pop(struct Stack *s);
int check(struct Stack *s);
void main()
{
    struct Stack s;
    s.top = 0;
    char st[SIZE];
    printf("Enter the String: ");
    gets(st);
    for (int i = 0; st[i] != '\0'; i++){
        push(&s, st[i]);
    }
    for (int i = 0; s.top > 0; i++)
    {
        st[i] = pop(&s);
    }
    printf("Reversed String is: %s", st);
}

/***
Adds elements to the top of the stack
***/
void push(struct Stack *s, char a)
{
    // Checks if the stack is full
    if (s->top < SIZE)
    {
        s->arr[s->top] = a;
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
char pop(struct Stack *s)
{
    //Checks if the stack is not empty
    if (s->top > 0)
    {
        s->top--;
        return s->arr[s->top];
    }
    else
    {
        printf("NO ELEMENTS IN STACK\n");
    }
}