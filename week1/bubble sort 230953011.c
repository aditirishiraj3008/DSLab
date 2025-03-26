//bubble sort algorithm

#include<stdio.h>

void main(){
    int arr[100],n,i,j;
    printf("enter no. of elements:");
    scanf("%d",&n);

    printf("enter elements:\n");
    for (i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("array is:");

    for (i=0; i<n; i++)
        printf("%d ",arr[i]);

//sorting operation
    for (i=0; i<n-1; i++){
        for (j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("\narray after sorting is:");
    for (i=0; i<n; i++)
        printf("%d ",arr[i]);
}
