#include <stdio.h>
#define SIZE 5   // define the size of the queue

struct CircularQueue {
    int arr[SIZE];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % SIZE == q->front);
}

// Check if queue is empty
int isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

// Enqueue
void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = value;
}

// Dequeue
int dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {  
        // Only one element was present
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return data;
}

// Display Queue
void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY\n");
        return;
    }
    int i = q->front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Example usage
int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 50);
    display(&q);

    return 0;
}
