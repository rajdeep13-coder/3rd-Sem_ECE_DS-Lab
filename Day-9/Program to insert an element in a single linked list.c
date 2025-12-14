#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head= NULL;

//Insert_at_beginning
void insb(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
    printf("\nElement added at beginning: %d", value);
    return;
}

//Insert_at_end
void inse(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){ //List is empty
        head=newnode;
        printf("\nElement added at end: %d", value);
        return;
    }
    struct node *temp=head;
    while(temp->next!= NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("\nElement added at end: %d", value);
}

//Insert_at_any_position
void insap(int value, int p){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(p==1){
        newnode->next=head;
        head=newnode;
        printf("\nElement added at beginning: %d", value);
        return;
    }
    
    struct node *temp=head;
    for(int i=1;i<p-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nPosition out of range");
        free(newnode);
        return;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Inserted %d at position %d.\n", value, p);
}

// ---- Display List ----
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insb(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                inse(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insap(value, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}