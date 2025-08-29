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




