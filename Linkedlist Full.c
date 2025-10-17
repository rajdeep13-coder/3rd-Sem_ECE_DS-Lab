#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create linked list
void createList(int n) {
    struct node *newNode, *temp;
    int val, i;

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory not allocated.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &val);
    head->data = val;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    printf("List created with %d nodes.\n", n);
}

// Function to display list
void displayList() {
    struct node *temp = head;
    int count = 0;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total nodes: %d\n", count);
}

// Insert at first
void insertAtFirst(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at first.\n", val);
}

// Insert at last
void insertAtLast(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    printf("Inserted %d at last.\n", val);
}

// Insert at any position
void insertAtPos(int val, int pos) {
    struct node *newNode, *temp;
    int i;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", val, pos);
}

// Delete from first
void delFirst() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted %d from first.\n", temp->data);
    free(temp);
}

// Delete from last
void delLast() {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted %d from last.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted %d from last.\n", temp->data);
    free(temp);
}

// Delete from any position
void delPos(int pos) {
    struct node *temp, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (pos == 1) {
        head = head->next;
        printf("Deleted %d from position 1.\n", temp->data);
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

int main() {
    int ch, n, val, pos;

    while (1) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at First\n");
        printf("4. Insert at Last\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from First\n");
        printf("7. Delete from Last\n");
        printf("8. Delete from Position\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtFirst(val);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtLast(val);
                break;
            case 5:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAtPos(val, pos);
                break;
            case 6:
                delFirst();
                break;
            case 7:
                delLast();
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                delPos(pos);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}


/*SAMPLE OUTPUT (Write any one)


--- LINKED LIST MENU ---
1. Create List
2. Display List
3. Insert at First
4. Insert at Last
5. Insert at Position
6. Delete from First
7. Delete from Last
8. Delete from Position
9. Exit
Enter choice: 1
Enter number of nodes: 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
List created with 3 nodes.

--- LINKED LIST MENU ---
1. Create List
2. Display List
3. Insert at First
4. Insert at Last
5. Insert at Position
6. Delete from First
7. Delete from Last
8. Delete from Position
9. Exit
Enter choice: 2
Linked List: 10 -> 20 -> 30 -> NULL
Total nodes: 3

--- LINKED LIST MENU ---
Enter choice: 3
Enter value: 5
Inserted 5 at first.

--- LINKED LIST MENU ---
Enter choice: 4
Enter value: 40
Inserted 40 at last.

--- LINKED LIST MENU ---
Enter choice: 5
Enter value and position: 25 3
Inserted 25 at position 3.

--- LINKED LIST MENU ---
Enter choice: 2
Linked List: 5 -> 10 -> 25 -> 20 -> 30 -> 40 -> NULL
Total nodes: 6

--- LINKED LIST MENU ---
Enter choice: 6
Deleted 5 from first.

--- LINKED LIST MENU ---
Enter choice: 7
Deleted 40 from last.

--- LINKED LIST MENU ---
Enter choice: 8
Enter position: 3
Deleted 20 from position 3.

--- LINKED LIST MENU ---
Enter choice: 2
Linked List: 10 -> 25 -> 30 -> NULL
Total nodes: 3

--- LINKED LIST MENU ---
Enter choice: 9
Exiting...


*/