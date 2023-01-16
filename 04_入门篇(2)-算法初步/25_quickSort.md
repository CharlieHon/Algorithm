# 快速排序

**快速排序**是排序算法中平均时间复杂度为 `O(nlogn)` 的一种算法，其实现需要先解决这样一个问题：对一个序列 A[1], A[2], ..., A[n] ，调整序列中元素的位置，使得 A[1] (原序列的A[1]，下同) 的左侧所有元素都不超过 A[1] ，右侧所有元素都大于 A[1] 。

例如对序列 {5, 3, 9, 6, 4, 1} 来说，可以调整序列中元素的位置，形成序列 {3, 1, 4, 5, 9, 6} ，这样就让 A[1] = 5 左侧的所有元素不超过它，右侧所有元素都大于它。

以下使用 **two pointers** 实现该想法：

1. 先将 A[1] 存至某个临时变量 tmp ，并令下标 left, right 分别指向序列首尾(如令 left=1, right=n)
2. 只要 right 指向的元素 A[right] 大于 tmp ，就将 right 不断左移；当某个时候 A[right] <= tmp 时，将元素 A[right] 挪到 left 指向的元素 A[left] 处
3. 只要 left 指向的元素 A[left] 不超过 tmp ，就不断将 left 不断右移；当某个时候 A[left] > tmp 时，将元素 A[left] 挪到 right 指向的元素 A[right] 处
4. 重复 2，3 步骤直到 left 与 right 相遇，把 tmp(也即原A[1]) 放到相遇的地方

```cpp
int Partition(int *A, int left, int right){
    int tmp = A[left];    //将 A[left] 存放至临时变量 tmp
    while(left < right){    //只要 left 与 right 不相遇
        while(left < right && A[right] > tmp)    --right;    //反复左移 right
        A[left] = A[right];
        while(left < right && A[left] <= tmp)    ++left;    //反复右移 left
        A[right] = A[left];
    }
    A[left] = tmp;    //把 tmp 放到 left 与 right 相遇的地方
    return left;    //返回相遇的下标
}
```

快速排序：

1. 调整序列中的元素，使当前序列最左端的元素在调整后满足左侧所有元素均不超过该元素、右侧所有元素均大于该元素。
2. 对该元素的左侧和右侧分别递归进行 步骤1 的调整，直到当前调整区间的长度不超过 1.

```cpp
//快速排序的递归实现
void quickSort(int *A, int left, right){
    if(left < right){    //当前区间长度超过1
        //将 [left, right] 按 A[left] 一分为二
        int pos = Partition(A, left, right);
        quickSort(A, left, pos-1);    //对左子区间递归进行快速排序
        quickSort(A, pos, right);    //对右子区间递归进行快速排序
    }
}
```

快速排序算法当序列中元素的排列比较随机时效率最高，但是当序列中元素接近有序时，会达到最坏时间复杂度 O(n^2) ，产生这种情况的主要原因在于**主元没有把当前区间划分为两个长度接近的子区间**。解决办法之一是**随机选择主元**，不总是用 A[left]作为主元，而是从 A[left\, A[left+1], ..., A[right] 中随机选择一个作为主元。这样虽然算法的最坏时间复杂度仍然是 O(n^2) (例如选择了A[left]作为主元)，但对于任意输入数据的期望时间复杂度都能达到 O(nlogn) 。

如下看看怎么**生成随机数**。C语言中有可以产生随机数据的函数，需要添加 stdlib.h 头文件与 time.h 头文件。首先在 main 函数开头加上 "srand((unsigned)time(NULL));" 这个语句将生成随机数的种子，`srand` 是初始化随机种子用的，在需要使用随机数的地方使用 `rand()` 函数。

输出结果是实时变化的。`rand()` 函数只能生成 [0, RAND_MAX] 范围内的整数。其中 `RAND_MAX` 是 `stdlib.h` 中的一个常数，在不同系统环境下，该常数的值有所不同。如果想要输出给定范围 [a, b] 内的随机数，需要使用 `rand() % (b-a+1) + a` 。

上种做法只对左右端点相差不超过 RAND_MAX 的区间的随机数有效，如果需要生成更大的数 (例如[a, b]，b大于 32767) 就不行了。可以随机选每一个数位的值 (0, 9) ，然后拼接成一个大整数；也可以采用另一种思路：先用 rand() 生成一个 [0, RAND_MAX] 范围内的随机数，然后用这个随机数除以 RAND_MAX ，这样会得到一个 [0, 1] 范围内的浮点数。然后只需要用这个浮点数乘以范围长度 (b-a+1) ，再加上 a 即可，即 `(int)((double)rand() / 32767 * (b-a+1) + a)` ，相当于这个浮点数就是 [a, b] 范围内的比例位置。其中32767为书中环境下 RAND_MAX 的值。

```cpp
#include<cstdio>
#include<cstdlib>
#include<ctime>
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0; i<10; ++i)
        printf("%d ", rand());
    printf("%d ", (int)(round(1.0*rand()/RAND_MAX*50000 + 10000)));    //生成 [10000, 60000]范围内随机数
    return 0;
}
```
