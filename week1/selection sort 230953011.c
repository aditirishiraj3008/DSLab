//selection sort algorithm

#include<stdio.h>
void main(){
    int arr[100],n,i,j,small,pos;
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
        small=arr[i];
        pos=i;
        //Find the smallest ele
        for (j = i + 1; j < n; j++) {
            if (arr[j] < small) {
                small = arr[j];
                pos =j;
            }
        }
        // Swap the smallest element with first ele
        if (pos != i) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
    printf("\narray after sorting is:");
    for (i=0; i<n; i++)
        printf("%d ",arr[i]);
}
