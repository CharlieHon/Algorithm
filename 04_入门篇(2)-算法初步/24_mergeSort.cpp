#include<cstdio>

//将数组 A 的左子区间 [L1, R1] 与右子区间 [L2, R2] 合并
const int maxn = 101;
void merge(int *A, int L1, int R1, int L2, int R2){
    int i = L1, j = L2;
    int temp[maxn], index = 0;
    while(i <= R1 && j <= R2){
        if(A[i] <= A[j])
            temp[index++] = A[i++];
        else
            temp[index++] = A[j++];
    }
    while(i <= R1)   temp[index++] = A[i++];
    while(j <= R2)   temp[index++] = A[j++];
    for(int i=0; i<index; ++i)
        A[L1+i] = temp[i];
}

//将 数组当前区间 [left, right] 进行归并排序
void mergeSort(int *A, int left, int right){
    if(left < right){   //只要 left 小于 right
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, mid+1, right);
    }

}

//打印数组
void print_array(int *a, const int n){
    for(int i=0; i<n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{

    int a[] = {1, 5, 16, 7, 23, 6, 9, 7, 12, 25, 94, 0, 63, 37, 9};
    int n = sizeof(a) / sizeof(int);
    print_array(a, n);
    
    mergeSort(a, 0, n-1);

    print_array(a, n);
    
    return 0;
}