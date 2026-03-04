#include <stdio.h>
#include <stdlib.h>

struct ll_node {
    int data;
    struct ll_node *next;
    struct ll_node *prev;
};

struct ll_node* insert(struct ll_node *head, int val);
struct ll_node* del(struct ll_node* head, int val);
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

    if (head == NULL) {
        printf("LIST IS EMPTY\n");
        return head;
    }

    struct ll_node *temp = head;

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("ELEMENT NOT FOUND\n");
        return head;
    }
    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

struct ll_node* insert(struct ll_node *head, int val) {

    struct ll_node *newNode = malloc(sizeof(struct ll_node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
        return newNode;
    if (val < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct ll_node *temp = head;
    while (temp->next != NULL && temp->next->data < val)
        temp = temp->next;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

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
