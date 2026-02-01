//Q1 Insert an Element in an Array
#include<stdio.h>
int main(){
    int arr[10],n,v,p;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    scanf("%d",&v);
    scanf("%d",&p);
    for(int i=n;i>p;i--){
        arr[i]=arr[i-1];
    }
    arr[p]=v;
    for(int i=0;i<=n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}