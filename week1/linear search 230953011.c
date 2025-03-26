//linear search algorithm

#include<stdio.h>

void main(){
    int arr[100],n,i,ele;
    printf("enter no. of elements:");
    scanf("%d",&n);

    printf("enter elements:\n");
    for (i=0; i<n; i++)
        scanf("%d",&arr[i]);

    printf("array is:");
    for (i=0; i<n; i++)
        printf("%d ",arr[i]);

    printf("\nenter ele to be searched:");
    scanf("%d",&ele);

//searching operation
    for (i=0; i<n; i++){
        if (arr[i]==ele){
            printf("\nelement found in index %d",i);
            exit(0);
        }

    }
    printf("element not found");

}
