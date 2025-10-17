#include <stdio.h>

struct Student {
    int roll;
    float marks;
    char name[30];
};

int main() {
    struct Student s;      // structure variable
    struct Student *ptr;   // structure pointer

    ptr = &s;  // pointer holds address of structure variable

    // Taking input using pointer
    printf("Enter Roll Number: ");
    scanf("%d", &ptr->roll);

    printf("Enter Name: ");
    scanf("%s", ptr->name);

    printf("Enter Marks: ");
    scanf("%f", &ptr->marks);

    // Displaying data using pointer
    printf("\n--- Student Details ---\n");
    printf("Roll No: %d\n", ptr->roll);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);

    return 0;
}
