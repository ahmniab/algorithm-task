// created by nabil & 3BS
// O(sz1+sz2)

#include <stdio.h>
#define sz(a) sizeof(a)/sizeof(a[0])

void merge(int * dest ,int arr1[] , int sz1 , int arr2[] , int sz2){
    int j = 0 , k = 0;
    for (int i = 0; i < sz1 + sz2; ++i) {
        if(arr1[j] <= arr2[k]) dest[i] = arr1[j++];
        else dest[i] = arr2[k++];
    }

}

int find_kth_el(int arr1[] , int sz1 , int arr2[] , int sz2 , int k){
    int dest[sz1+sz2];
    merge(dest,arr1,sz1,arr2,sz2);
    return dest[k-1];
}

int kthElementIterative(int arr1[], int arr2[], int m, int n, int k) {
    int low = 0, high = m;

    // Ensure k is within valid range (1 <= k <= m + n)
    if (k < 1 || k > m + n) {
        printf("Invalid k value\n");
        return -1;
    }

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1 - 1;
        if (mid1 > m - 1) {
            mid1 = m - 1;
        }
        if (mid2 < 0) {
            mid2 = 0;
        }

        if (arr1[mid1] <= arr2[mid2]) {
            if (mid1 + 1 == k) {
                return arr1[mid1];
            }
            low = mid1 + 1;
        } else {
            high = mid1 - 1;
        }
    }

    return -1; // Not found
}


int main() {
    int arr1[] =  { 100, 112 ,256 ,349 ,770};
    int arr2[] =  {72, 86 ,113 ,119 ,265 ,445 ,892};

    int k;

    printf("enter k = ");
    scanf("%d",&k);
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int kth_element_iterative = kthElementIterative(arr1, arr2, m, n, k);
    if (kth_element_iterative != -1) {
        printf("The kth (%dth) element is %d using iteration\n", k, kth_element_iterative);
    }
    
    printf("kth by merg = %d\n",\
    find_kth_el(arr1, sz(arr1),arr2, sz(arr2) , k)\
    );
    return 0;
}
