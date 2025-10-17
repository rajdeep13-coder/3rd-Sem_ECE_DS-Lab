#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newNode, *temp;
    int n, i, count = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    for (i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node)); 
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // first node
            temp = head;
        } else {
            temp->next = newNode;  // link current node to previous
            temp = newNode;
        }
    }

    // Display the linked list
    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;  
    }
    printf("NULL\n");

    printf("Total number of nodes = %d\n", count);

    return 0;
}
