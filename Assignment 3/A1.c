#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int start;
    int end;
} Queue;

void initialize(Queue* q) {
    q->start = 0;
    q->end = 0;
}

int isFull(Queue* q) {
    return (q->end + 1) % MAX_SIZE == q->start;
}

int isEmpty(Queue* q) {
    return q->start == q->end;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    q->data[q->end] = value;
    q->end = (q->end + 1) % MAX_SIZE;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->data[q->start];
    q->start = (q->start + 1) % MAX_SIZE;
    return value;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    int i = q->start;
    printf("Queue: ");
    while (i != q->end) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    int choice, val;

    while (1) {
        printf("\n1-Insert\n2-Remove\n3-Display\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;

            case 2:
                val = dequeue(&q);
                if (val != -1) {
                    printf("Removed value: %d\n", val);
                }
                break;

            case 3:
                display(&q);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
