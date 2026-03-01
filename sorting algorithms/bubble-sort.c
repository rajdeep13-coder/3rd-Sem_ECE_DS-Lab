#include<stdio.h>
int main(){
    int ar[100];
    int n,t;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("\nEnter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d", &ar[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(ar[j]>ar[j+1]){
                t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    }
    printf("\nSorted array: ");
    for(int x=0;x<n;x++){
        printf("%d ", ar[x]);
    }
}