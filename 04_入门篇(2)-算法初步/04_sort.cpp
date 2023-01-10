#include<cstdio>
#include<algorithm>
using namespace std;
/**
 * @brief 冒泡排序
 * 从第1个元素开始与下一个相邻元素两两比较，交换位置，把序列中最大的元素冒泡至队尾，进行n-1次
 * @param a 数组首地址
 * @param n 数组中元素个数
 */
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
/**
 * @brief 选择排序
 * 选择序列中最小的数放在未排序的首位，依次类推，进行n-1次
 * @param a 数组首地址
 * @param n 数组中元素个数
 */
void selectSort(int *a, const int n){
    for(int i=0; i<n-1; ++i){
        int k = i;
        for(int j=i+1; j<n; ++j){
            if(a[j] < a[k]){
                k = j;
            }
        }
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}
/**
 * @brief 插入排序
 * 将待排序的temp，插入到已排好序的[1, i-1]中，使得插入后仍有序
 * @param a 数组首地址
 * @param n 数组中元素个数
 */
void insertSort(int *a, const int n){
    for(int i=1; i<=n; ++i){
        int temp = a[i];
        int j = i;
        while(j > 0 && temp < a[j-1]){
            a[j] = a[j-1];
            --j;
        }
        a[j] = temp;
    }
}
/**
 * @brief 打印数组
 * 
 * @param a 数组首地址
 * @param n 数组中元素个数
 */
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
    int a[99];
    int n = 0;
    while(scanf("%d", &a[n]) != EOF){
        ++n;    //数组中元素的个数
    }
    print_a(a, n);  //打印原始数组
    // bubbleSort(a, n);   //冒泡排序
    // selectSort(a, n);   //选择排序
    // insertSort(a, n);   //插入排序
    sort(a, a+n);   //使用sort函数
    print_a(a, n);  //打印排序后的结果
    return 0;
}