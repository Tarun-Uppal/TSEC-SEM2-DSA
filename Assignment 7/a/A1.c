#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct ll_node
{
    int data;
    struct ll_node *next;
};

struct ll_node *push(struct ll_node *top1,int val);
struct ll_node *pop(struct ll_node *top1);
void display(struct ll_node *top1);

void main() {
    int val, choice;
    struct ll_node *top=NULL;
    do
    {
        printf("---------------MENU----------------\n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value to be pushed:");
            scanf("%d",&val);
            top=push(top,val);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            display(top);
            break;
            case 4:printf("......exiting the program\n");
            break;
            default: printf("INVALID CHOICE\n");
        }
    }while(choice!=4);
}

struct ll_node *push(struct ll_node *top1,int val) {
    struct ll_node *pnew=(struct ll_node *)malloc(sizeof(struct ll_node));
    pnew->next=NULL;
    pnew->data=val;
    pnew->next=top1;
    top1=pnew;
    return top1;
}

struct ll_node *pop(struct ll_node *top1) {
    struct ll_node *node2delete;
    if(top1==NULL)
    {
        printf("STACK UNDERFLOW\n");
        return top1;
    }
    node2delete=top1;
    top1=top1->next;
    free(node2delete);
    return top1;
}

void display(struct ll_node *top1) {
    struct ll_node *help_pointer=top1;
    if(top1==NULL) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    printf("Stack contains:\n");
    while(help_pointer!=NULL) {
        printf("%d\t",help_pointer->data);
        help_pointer=help_pointer->next;
    }
    printf("\n");
    return;
}
