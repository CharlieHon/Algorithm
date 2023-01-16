#include<cstdio>
#include<algorithm>
using namespace std;

void bubbleSort(int *a, const int n){
    for(int i=1; i<n; ++i){
        for(int j=0; j<n-i; ++j){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectSort(int *a, const int n){
    for(int i=0; i<n-1; ++i){
        int min = i;
        for(int j=i+1; j<n; ++j){
            if(a[j] < a[min])
                min = j;
        }
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void insertSort(int *a, const int n){
    for(int i=1; i<n; ++i){
        int j = i, tmp = a[i];
        while(j > 0 && tmp < a[j-1]){
            a[j] = a[j-1];
            --j;
        }
        a[j] = tmp;
    }
}

void print_a(int  *a, const int n){
    for(int i=0; i<n; ++i){
        printf("%d", a[i]);
        if(i != n-1)
            printf(" ");
    }
    printf("\n");
}

const int maxn = 101;
//将数组 A 在区间 [L1, R1] 和 [L2, R2] 的两个有序子区间合并为连续的有序序列
void merge(int *A, int L1, int R1, int L2, int R2){
    int i = L1, j = L2;
    int tmp[maxn], index = 0;
    while(i <= R1 && j <= R2){
        if(A[i] <= A[j])
            tmp[index++] = A[i++];
        else
            tmp[index++] = A[j++];
    }
    while(i <= R1)  tmp[index++] = A[i++];
    while(j <= R2)  tmp[index++] = A[j++];
    for(int i=0; i<index; ++i)
        A[L1+i] = tmp[i];
}
//归并排序，[left, right] 为下标从0开始的区间
void mergeSort(int *A, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, mid+1, right);
    }
}

int Partition(int *A, int left, int right){
    int tmp = A[left];
    while(left < right){
        while(left < right && A[right] > tmp)  --right;
        A[left] = A[right];
        while(left < right && A[left] <= tmp)   ++left;
        A[right] = A[left];
    }
    A[left] = tmp;  //把 tmp 放到 left 与 right 相遇的地方
    return left;    //返回相遇的下标
}

//快速排序，递归实现
void quickSort(int *A, int left, int right){
    if(left < right){
        int pos = Partition(A, left, right);
        quickSort(A, left, pos-1);
        quickSort(A, pos+1, right);
    }
}

int main()
{
    int a[] = {1, 5, 6, 32, 4, 8, 9, 2, 0};
    int n = sizeof(a) / sizeof(int);
    print_a(a, n);
    // bubbleSort(a, n);
    // selectSort(a, n);
    // insertSort(a, n);
    // mergeSort(a, 0, n-1);
    quickSort(a, 0, n-1);
    // sort(a, a+n);   //sort(数组首元素地址，尾元素后一位地址，排序规则)
    print_a(a, n);
    return 0;
}