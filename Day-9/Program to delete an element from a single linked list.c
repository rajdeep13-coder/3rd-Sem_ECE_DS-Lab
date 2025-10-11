//a) from 1st position 
//b) from last position 
//c) from any position

#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *n;
};
struct node *h=NULL;

void ins(int x){
    struct node *t=malloc(sizeof(struct node));
    t->d=x; t->n=NULL;
    if(!h){
        h=t;return;
    }
    struct node *p=h;
    while(p->n)p=p->n;
    p->n=t;
}

void beg(){
    if(!h)return;
    struct node *t=h;
    h=h->n;
    free(t);
}

void end(){
    if(!h)return;
    if(!h->n){free(h);h=NULL;return;}
    struct node *p=h;
    while(p->n->n)p=p->n;
    free(p->n);
    p->n=NULL;
}

void pos(int k){
    if(k==1){beg();return;}
    struct node *p=h;
    for(int i=1;i<k-1 && p;i++)p=p->n;
    if(!p||!p->n){printf("Invalid\n");return;}
    struct node *t=p->n;
    p->n=t->n;
    free(t);
}

void dis(){
    struct node *p=h;
    while(p){printf("%d ",p->d);p=p->n;}
    printf("\n");
}

int main(){
    int c,x,k;
    while(1){
        printf("1.Add 2.DelBeg 3.DelEnd 4.DelPos 5.Show 6.Exit\n");
        scanf("%d",&c);
        if(c==6)break;
        if(c==1){printf("Data: ");scanf("%d",&x);ins(x);}
        else if(c==2)beg();
        else if(c==3)end();
        else if(c==4){printf("Pos: ");scanf("%d",&k);pos(k);}
        else if(c==5)dis();
    }
    return 0;
}
