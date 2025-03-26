//insertion sort algorithm

#include<stdio.h>

void main(){
    int arr[100],n,i,j,t;
    printf("enter no. of elements:");
    scanf("%d",&n);

    printf("enter elements:\n");
    for (i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("array is:");

    for (i=0; i<n; i++)
        printf("%d ",arr[i]);

//sorting operation
     for (i =1; i<n; i++) {
        t =arr[i];
        j= i-1;
        //moving elements 1 pos ahead
        while (j>= 0 && arr[j] > t) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = t;
    }

    printf("\narray after sorting is:");
    for (i=0; i<n; i++)
        printf("%d ",arr[i]);
}
