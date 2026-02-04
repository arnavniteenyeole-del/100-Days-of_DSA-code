#include<stdio.h>
#include<stdlib.h>
void Reverse(int arr[],int n){
    int mid,in;
    if(n%2==0){
        for(int i=0;i<n/2;i++){
            in=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=in;

        }
    }
    else if(n%2!=0){
        mid=(n-1)/2;
        for(int i=0;i<n/2;i++){
            if(i!=mid){
                in=arr[i];
                arr[i]=arr[n-1-i];
                arr[n-1-i]=in;
            }
        }
    }
    printf("Reversed Array:");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }

}
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *arr=(int*)calloc(n,sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Memory allocated successfully\n");
    for (int i=0;i<n;i++){
        arr[i]=i+1;
    }
    printf("Entered Array:");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    Reverse(arr,n);
    free(arr);
    arr=NULL;
}