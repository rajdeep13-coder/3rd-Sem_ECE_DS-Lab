//a) at 1st position 
//b) at last position 
//c) at any position 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *n;
};
struct node *h = NULL;

void beg(int x){
    struct node *t = malloc(sizeof(struct node));
    t->d = x;
    t->n = h;
    h = t;
}

void end(int x){
    struct node *t = malloc(sizeof(struct node));
    t->d = x;
    t->n = NULL;
    if(h==NULL){
        h=t;return;
    }
    struct node *p=h;
    while(p->n) p=p->n;
    p->n=t;
}

void pos(int x,int p){
    if(p==1){
        beg(x);return;
    }
    struct node *t=malloc(sizeof(struct node)),*q=h;
    t->d=x;
    for(int i=1;i<p-1 && q;i++) q=q->n;
    if(q==NULL){
        printf("Invalid\n");
        free(t);
        return;
    }
    t->n=q->n;
    q->n=t;
}

void dis(){
    struct node *p=h;
    while(p){
        printf("%d ",p->d);
        p=p->n;
    }
    printf("\n");
}

int main(){
    int c,x,pn;
    while(1){
        printf("1.Beg 2.End 3.Pos 4.Display 5.Exit\n");
        scanf("%d",&c);
        if(c==5)
            break;
        if(c==4)
            {dis();continue;}
        printf("Enter data: ");
            scanf("%d",&x);
        if(c==1)
            beg(x);
        else if(c==2)
            end(x);
        else if(c==3)
            {printf("Enter pos: ");
            scanf("%d",&pn);pos(x,pn);}
    }
    return 0;
}
