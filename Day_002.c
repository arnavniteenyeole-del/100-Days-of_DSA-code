#include<stdio.h>
int main(){
    int n,p;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&p);
    if (p < 1 || p > n) {
        printf("Invalid position");
        return 0;
    }
    p=p-1;
    for(int i=p;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}