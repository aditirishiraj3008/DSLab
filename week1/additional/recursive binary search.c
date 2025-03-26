#include <stdio.h>

int BinarySearch(int arr[],int low,int high,int ele) {
    if (low <= high) {
        int mid =low+(high-low)/2;
        if (arr[mid] == ele)
            return mid;
        if (arr[mid] > ele)
            return binarySearch(arr,low, mid-1,ele);
        else
            return binarySearch(arr,mid+1,high,ele);
    }
    return -1;//ele not found
}

int main() {
    int arr[100], n, ele, result;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements (in sorted form):\n");
    for (int i = 0; i< n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d",&ele);

    result = binarySearch(arr, 0, n - 1, ele);

    if (result!= -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
