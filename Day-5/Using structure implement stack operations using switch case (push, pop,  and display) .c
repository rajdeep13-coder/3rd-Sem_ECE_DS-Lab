#include <stdio.h>

struct Stack {
    int data[10];
    int top;
};
int main() {
    struct Stack s;
    s.top = -1;
    int ch, val;

    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (s.top == 9)
                    printf("Full\n");
                else {
                    printf("Enter val: ");
                    scanf("%d", &val);
                    s.data[++s.top] = val;
                }
                break;

            case 2:
                if (s.top == -1)
                    printf("Empty\n");
                else
                    printf("Popped: %d\n", s.data[s.top--]);
                break;

            case 3:
                if (s.top == -1)
                    printf("Empty\n");
                else {
                    for (int i = s.top; i >= 0; i--)
                        printf("%d ", s.data[i]);
                    printf("\n");
                }
                break;

            case 4:
                return 0;
        }
    }
    return 0;
}