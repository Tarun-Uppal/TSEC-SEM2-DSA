#include <stdio.h>
#include <stdlib.h>

struct ll_node {
    int data;
    struct ll_node *next;
};

struct ll_node* del(struct ll_node* head, int val);
struct ll_node* insert(struct ll_node *head, int val);
void display(struct ll_node *head);

void main() {

    struct ll_node *myList = NULL;
    int choice, value;

    do {
        printf("\n------ MENU ------\n");
        printf("1-Add Element\n");
        printf("2-Remove Element\n");
        printf("3-Show Linked List\n");
        printf("4-Quit\n");
        printf("Select option: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Input number to insert: ");
                scanf("%d", &value);
                myList = insert(myList, value);
                break;
            case 2:
                printf("Input number to remove: ");
                scanf("%d", &value);
                myList = del(myList, value);
                break;

            case 3:
                display(myList);
                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Wrong choice! Try again.\n");
        }

    } while(choice != 4);
}

struct ll_node* del(struct ll_node* head, int val) {
    struct ll_node *temp = head;
    if (temp != NULL){
        struct ll_node *prev = NULL;
        while (temp != NULL){
            if(temp->data == val){
                struct ll_node *rem = temp;
                if (prev == NULL){
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                free(rem);
                return head;
            }
            prev = temp;
            temp = temp->next;
        }
        printf("ELEMENT NOT FOUND");
        return head;
    }
    printf("LIST IS EMPTY");
    return head;
}

struct ll_node* insert(struct ll_node *head, int val) {

    struct ll_node *temp = head;

    struct ll_node *newNode = (struct ll_node*) malloc(sizeof(struct ll_node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL || head->data > val) {
        newNode->next = head;
        return newNode;
    }

    while (temp->next != NULL && temp->next->data < val) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void display(struct ll_node *head) {

    printf("\nLinked List Elements:\n");

    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next;
    }

    printf("\n");
}
