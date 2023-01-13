#include<cstdio>
#include<algorithm>
using namespace std;
/**
 * @brief 二分查找，查找指定元素在序列中的位置
 * 
 * @param a 严格递增序列的首地址
 * @param left 二分下界
 * @param right 二分上界
 * @param x 欲查询的数
 * @return int 返回 -1 表示没查到
 */
int binarySearch(int *a, int left, int right, int x){
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;  //没查到
}

/**
 * @brief 返回第一个 大于等于(>=) x 元素位置的索引
 * 因为要返回第一个大于等于x的元素的位置，所以不需要判断元素x本身是否存在
 * @param a 
 * @param left 0
 * @param right 欲查询元素有可能比序列中所有元素都要大，此时应当返回n(即假设它存在，它应该在的位置)。因此二分上界是元素个数 n
 * @param x 
 * @return int 
 */
int lower_bound(int *a, int left, int right, int x){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(a[mid] >= x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;    //返回第一个大于等于x位置的索引
}

/**
 * @brief 查询序列 a 中第一个 大于 x 元素的位置
 * 
 * @param a 
 * @param left 
 * @param right 
 * @param x 
 * @return int 
 */
int upper_bound(int *a, int left, int right, int x){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(a[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    int a[] = {1, 5, 6, 3, 8, 7, 4, 9, 2, 0, 3, 64, 78, 12, 54, 36, 99, 47, 24};
    int n = sizeof(a) / sizeof(int);    //序列长度
    sort(a, a+n);   //排序

    printf("index:");
    for(int i=0; i<n; ++i)
        printf("%2d ", i);
    printf("\n");
    printf("value:");
    for(auto i : a)
        printf("%2d ", i);   //输出排序后的序列
    printf("\n");
    
    int x;
    scanf("%d", &x);    //输入想要查询的数字
    
    //二分查找
    int res1 = binarySearch(a, 0, n-1, x);
    if(res1 == -1)
        printf("%d is not in the sequence\n", x);
    else
        printf("the index of x in the sequence is %d\n", res1);

    //查找第一个大于等于 x 的元素的位置
    int res2 = lower_bound(a, 0, n, x);
    printf("the index of the first value which is bigger  than or equal to x is %d\n", res2);

    //查找第一个大于 x 的元素的位置
    int res3 = upper_bound(a, 0, n, x);
    printf("the index of the first value which is bigger  than x is %d\n", res3);

    return 0;
}
