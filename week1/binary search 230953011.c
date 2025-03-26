//binary search algorithm

#include<stdio.h>

void main(){
    int arr[100], n, i, j, ele, low, high, mid,flag = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0;i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array is: ");
    for (i = 0;i < n; i++)
        printf("%d ", arr[i]);

// Sorting before searching
    for (i = 0; i <n - 1; i++){
        for (j = 0; j <n - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nArray after sorting is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nEnter element to be searched: ");
    scanf("%d", &ele);

// Searching operation
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == ele) {
            printf("Element found at index %d", mid);
            flag = 1;
            break;
        }
        else if (arr[mid]<ele)
            low = mid + 1;
        else
            high = mid-1;

    }

    if (flag == 0)
        printf("Element not found");
}
