#include<cstdio>
/**
 * @brief 选择排序
 * [1, 2, 3, ..., i, i+1, ..., n]
 * [1, i-1]为已排序部分
 * 每次从待排序的[i, n]中选择最小的元素，放在a[i]位置，使得[1, i]部分有序
 * 即每次找到最小的元素放在最前面
 * @return int 
 */

void selectSort(int *a, const int n){
    for(int i=0; i<n; ++i){
        int k = i;
        for(int j=i+1; j<n; ++j){
            if(a[j] < a[k]){
                k = j;  //保存最小数字的索引位置
            }
        }
        int temp = a[i];    //交换a[i]和a[k]
        a[i] = a[k];
        a[k] = temp;
    }
}

int main()
{
    int a[] = {5, 6, 3, 4, 2, 1, 9, 8, 7, 0, 12};
    int n  = sizeof(a) / sizeof(int);

    // for(int i=0; i<n; ++i){
    //     for(int j=i+1; j<n; ++j){
    //         if(a[i] > a[j]){
    //             int temp = a[i];
    //             a[i] = a[j];
    //             a[j] = temp;
    //         }
    //     }
    // }

    selectSort(a, n);
    //打印排序后数组
    for(int i=0; i<n; ++i){
        printf("%d", a[i]);
        if(i != n-1)
            printf(" ");
    }
    return 0;
}