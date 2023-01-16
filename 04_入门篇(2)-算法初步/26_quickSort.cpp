#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>

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

//randPartition 选择 [left, right] 范围内某个随机数 p ，令 A[p] 作为主元
int randPartition(int *A, int left, int right){
    //生成 [left, right] 内随机数 p
    int p = round(1.0*rand()/RAND_MAX*(right - left) + left);
    // swap(A[p], A[left]);    //交换 A[p] 和 A[left]
    int tmp1 = A[left];
    A[left] = A[p];
    A[p] = tmp1;
    //以下为原 Partition 函数的划分过程，不需要改变任何东西
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
        int pos = randPartition(A, left, right);    //采用随机选择主元的方式
        quickSort(A, left, pos-1);  //对左子区间递归进行快速排序
        quickSort(A, pos+1, right); //对右子区间递归进行快速排序
    }
}

//打印数组
void print_a(int  *a, const int n){
    for(int i=0; i<n; ++i){
        printf("%d", a[i]);
        if(i != n-1)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 5, 6, 32, 4, 8, 9, 2, 0};
    int n = sizeof(a) / sizeof(int);
    
    print_a(a, n);

    quickSort(a, 0, n-1);

    print_a(a, n);
    
    return 0;
}