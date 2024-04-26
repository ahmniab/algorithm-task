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

int main() {
    int arr1[] =  { 100, 112 ,256 ,349 ,770};
    int arr2[] =  {72, 86 ,113 ,119 ,265 ,445 ,892};

    int k;

    printf("enter k = ");
    scanf("%d",&k);

    printf("kth = %d\n",\
    find_kth_el(arr1, sz(arr1),arr2, sz(arr2) , k)\
    );
    return 0;
}
