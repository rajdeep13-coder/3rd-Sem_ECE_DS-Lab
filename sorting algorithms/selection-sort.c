#include<stdio.h>
int main(){
    int i,j,t,min,n,d;
    int ar[100];
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("\nEnter array elements: ");
    for(int p=0;p<n;p++){
        scanf("%d", &ar[p]);
    }
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(ar[j]<ar[min])
                min=j;
        }
        if(min!=i){
            d=ar[min];
            ar[min]=ar[i];
            ar[i]=d;
        }
    }
    printf("\nSorted array: ");
    for(int x=0;x<n;x++){
        printf("%d ", ar[x]);
    }
    
}