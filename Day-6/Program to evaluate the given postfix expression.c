#include <stdio.h>
#include <ctype.h>
int main() {
    char e[100];
    int st[100], t=-1, i;
    scanf("%s",e);
    for(i=0;e[i]!='\0';i++) {
        if(isdigit(e[i])) {
            st[++t]=e[i]-'0';
        }
        else {
            int b=st[t--];
            int a=st[t--];
            if(e[i]=='+') 
                st[++t]=a+b;
            else if(e[i]=='-') 
                st[++t]=a-b;
            else if(e[i]=='*') 
                st[++t]=a*b;
            else if(e[i]=='/') 
                st[++t]=a/b;
        }
    }
    printf("%d",st[t]);
    return 0;
}
