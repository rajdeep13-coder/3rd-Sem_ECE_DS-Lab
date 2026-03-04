#include <stdio.h>

#define MAX 5

// Define Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Initialize Queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if empty
int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Check if full
int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

// Insert element
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1)   // first element
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;
}

// Remove element
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = q->arr[q->front];
    q->front++;

    return value;
}

// Display queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

// Main function
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);

    return 0;
}
