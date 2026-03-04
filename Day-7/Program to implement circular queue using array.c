#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((front == 0 && rear == SIZE-1) || (front == rear+1)) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {   // first element
        front = rear = 0;
    }
    else if (rear == SIZE-1) {
        rear = 0;   // circular move
    }
    else {
        rear++;
    }

    cq[rear] = value;
    printf("Inserted: %d\n", value);
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    if (front == rear) {   // only one element
        front = rear = -1;
    }
    else if (front == SIZE-1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    if (front <= rear) {
        for (int i = front; i <= rear; i++)
            printf("%d ", cq[i]);
    }
    else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", cq[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", cq[i]);
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
