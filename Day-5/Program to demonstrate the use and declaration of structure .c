#include <stdio.h>
struct s {
    int id;
    char name[20];
    float marks;
};

int main() {
    struct s st;
    printf("Enter id, name, marks:\n");
    scanf("%d %s %f", &st.id, st.name, &st.marks);
    printf("Id: %d\n", st.id);
    printf("Name: %s\n", st.name);
    printf("Marks: %.2f\n", st.marks);

    return 0;
}

/* INPUT
Enter id, name, marks:
101 John 89.5
*/

/* OUTPUT
Id: 101
Name: John
Marks: 89.50
*/