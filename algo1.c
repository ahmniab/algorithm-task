// created by nabil & 3BS
// O(sz1+sz2)

#include <stdio.h>

// #define sz(a) sizeof(a)/sizeof(a[0])

int *max(int* a , int* b){
    if(*a > *b){
        return a ;
    }
    else return b;
}
// 1234
// 5678

int *return_k_rec(int *arr1_front , int *arr2_front , int arr1[] , int arr2[] , int i , int k){
    if ( i == k)
    {
        return max(arr1_front , arr2_front);
    }
    else {
        if (*arr1_front < *arr2_front)
        {
            arr2_front++;
        }else
        {
            arr1_front++;
        }

        return return_k_rec(arr1_front ,arr2_front , arr1 , arr2 , ++i , k);
    }
    
}

void merge(int * dest ,int arr1[] , int sz1 , int arr2[] , int sz2){
    int j = 0 , k = 0;
    for (int i = 0; i < sz1 + sz2; ++i) {
        if(arr1[j] <= arr2[k]) dest[i] = arr1[j++];
        else dest[i] = arr2[k++];
    }

}

int find_kth_el(int arr1[] , int sz1 , int arr2[] , int sz2 , int k){
    return return_k_rec(&arr1[0] , arr2[0] , arr1 , arr2 , 0 , k );
}

int main() {
    int arr1[] =  { 100, 112 ,256 ,349 ,770};
    int arr2[] =  {72, 86 ,113 ,119 ,265 ,445 ,892};

    int k;

    printf("enter k = ");
    scanf("%d",&k);

    printf("kth = %d\n",\
    find_kth_el(arr1, 5,arr2, 7 , k)\
    );
    return 0;
}
