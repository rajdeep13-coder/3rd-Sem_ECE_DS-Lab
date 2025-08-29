//M-1
#include <stdio.h>
#include <string.h>
int main() {
    char s[100];    
    char st[100];   
    int t = -1;      
    int i, n;
    printf("Enter a string: ");
    scanf("%s", s);
    n = strlen(s);
    for (i = 0; i < n; i++) {
        t = t + 1;   
        st[t] = s[i];    
    }
    printf("Reversed string: ");
    for (i = 0; i < n; i++) {
        printf("%c", st[t]); 
        t = t - 1;           
    }
    return 0;
}



//M-2
#include <stdio.h>
#include <string.h>

#define MAX 100  

char stack[MAX];
int top = -1;    

// push function
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack is full!\n");
    } else {
        stack[++top] = c;
    }
}

// pop function
char pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s", str);  

    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
