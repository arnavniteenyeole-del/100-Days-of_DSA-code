#include<stdio.h>
void maxmin(int arr[],int n){
    int max=arr[0],min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        else if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("Max: %d\n",max);
    printf("Min: %d",min);

}
int main(){
    int n;
    printf("Input number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Input array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Array:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    maxmin(arr,n);
    return 0;
}