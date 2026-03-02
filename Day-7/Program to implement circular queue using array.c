#include <stdio.h>

#define SIZE 5

struct Queue {
    int arr[SIZE];
    int front;
    int rear;
};
// Initialize queue
void init(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}
// Check empty
int isEmpty(struct Queue *q) {
    return (q->front == -1);
}
// Check full
int isFull(struct Queue *q) {
    return ((q->rear + 1) % SIZE == q->front);
}
// Insert element
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;

    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = value;
}
// Remove element
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear)  // only one element
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % SIZE;

    return value;
}
// Display queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    int i = q->front;
    printf("Queue: ");
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    printf("Deleted: %d\n", dequeue(&q));

    enqueue(&q, 50);
    display(&q);

    return 0;
}
