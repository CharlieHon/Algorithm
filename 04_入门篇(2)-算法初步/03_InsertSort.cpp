#include<cstdio>
/**
 * @brief 插入排序
 * 
 * @param a 数组首地址
 * @param n 数组中元素的个数
 */
void insertSort(int *a, const int n){
    for(int i=1; i<n; ++i){ //从1开始，进行n-1轮
        int temp = a[i];
        int j = i;
        while(j > 0 && temp < a[j-1]){  //将temp插入到已排序的部分，使得插入后序列仍有序
            a[j] = a[j-1];
            --j;
        }
        a[j] = temp;
    }
}

void print_a(int *a, const int n){
    for(int i=0; i<n; ++i){
        printf("%d", a[i]);
        if(i != n-1)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int a[] = {5, 9, 1, 3, 2, 6, 4, 7, 0};
    int n = sizeof(a) / sizeof(int);
    print_a(a, n);
    insertSort(a, n);
    print_a(a, n);
    return 0;
}