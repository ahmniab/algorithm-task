// created by Mohamed Hassanin
#include <stdio.h>

int kth(int arr1[], int arr2[], int n, int m, int k)
{
    // array to store the merged sorted array
    int sorted1[m + n];
    int i = 0, j = 0, d = 0;
    while (i < n && j < m) {
        // If the element of arr1 is smaller, insert the
        // element to the sorted array
        if (arr1[i] < arr2[j])
            sorted1[d++] = arr1[i++];
        else
            // If the element of arr2 is smaller, insert the
            // element to the sorted array
            sorted1[d++] = arr2[j++];
    }
    while (i < n)
        sorted1[d++] = arr1[i++];
    while (j < m)
        sorted1[d++] = arr2[j++];
    // Return the element at kth position in the merged
    // sorted array
    return sorted1[k - 1];
}

int main()
{
    int arr1[5] = { 2, 3, 6, 7, 9 };
    int arr2[4] = { 1, 4, 8, 10 };
    int k = 2;
    printf( "%d",kth(arr1, arr2, 5, 4, k));
    return 0;
}
