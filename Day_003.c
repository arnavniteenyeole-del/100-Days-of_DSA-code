#include<stdio.h>
#include<stdlib.h>
void LinearSearch(int arr[],int n,int k){
    int c=0;
    for(int i=0;i<n;i++){
        c++;
        if(arr[i]==k){
            printf("Found at index %d\n",i);
            break;
        }

    }
    printf("Comparisons=%d",c);

}
int main(){
    int n,k;
    printf("Enter array size");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Input Array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter Key to Search:");
    scanf("%d",&k);
    LinearSearch(arr,n,k);
    free(arr);
    return 0;
}