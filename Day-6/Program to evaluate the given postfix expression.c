#include <stdio.h>
#include <ctype.h>

int main() {
    char e[100];
    int st[100], t=-1;

    printf("Enter postfix expression: ");
    scanf("%s", e);

    for(int i=0; e[i]!='\0'; i++) {

        if(isdigit(e[i])) {
            st[++t] = e[i] - '0';
        }
        else {
            int b = st[t--];
            int a = st[t--];

            switch(e[i]) {
                case '+': st[++t] = a+b; break;
                case '-': st[++t] = a-b; break;
                case '*': st[++t] = a*b; break;
                case '/': st[++t] = a/b; break;
            }
        }
    }

    printf("Result = %d", st[t]);
    return 0;
}
