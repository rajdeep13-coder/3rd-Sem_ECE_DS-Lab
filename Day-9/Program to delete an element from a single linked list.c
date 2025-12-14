#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// ---- Delete from 1st Position ----
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// ---- Delete from Last Position ----
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {  // only one node
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// ---- Delete from Any Position ----
void deleteFromPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// ---- Display List ----
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---- Main Function ----
int main() {
    int choice, pos;

    // Sample list creation
    for (int i = 1; i <= 5; i++) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = i * 10;
        newNode->next = head;
        head = newNode;
    }

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Any Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromBeginning();
                break;

            case 2:
                deleteFromEnd();
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
