# two pointers

## 什么是 two pointers

给定一个递增的整数序列和一个正整数 M ，求序列中的两个不同位置的数 a 和 b 使得它们的和恰好为 M ，输出所有满足条件的方案。例如给定序列 {1, 2, 3, 4, 5, 6} 和正整数 M = 8 ，就存在 2 + 6 = 8 与 3 + 5 = 8 成立。

最直观的想法是，使用二重循环枚举所有序列中的整数 a 和 b ，判断它们的和是否为 M ，如果是，输出方案；如果不是，则继续枚举。

```cpp
for(int i=0; i<n; ++i){
    for(int j=i+1; j<n; ++j){
        if(a[i] + a[j] == M)
            printf("%d %d\n", a[i], a[j]);
    }
}
```

这种做法的时间复杂度为 O(n^2) 。

i 和 j 的枚举是相互牵制的，因为是有序序列，可以使用 two pointers 降低复杂度。

令下标 i 的初值为 0 、下标 j 的初值为 n-1 ，即令

```cpp
int i = 0, j = n - 1;
while(i < j){
    if(a[i] + a[j] == m){
        printf("%d %d", i, j);
        ++i;
        --j;
    }
    else if(a[i] + a[j] < m){
        ++i;
    }else{
        --j;
    }
}
```

由于 i 的初值为 0 ，j的初值为 n-1 ，而程序中变量 i 只有递增操作、变量j只有递减操作，且循环当 i >= j 时停止，因此 i 和 j 的操作次数最多为 n 次，时间复杂度为 O(n) 。

**序列合并问题**。假设有两个递增序列 A 与 B ，要求将它们合并为一个递增序列 C。

同样的，可以设置两个下标 i 和 j ，初值均为 0 ，表示分别指向序列 A 的第一个元素和序列 B 的第一个元素，然后根据 A[i] 与 B[j] 的大小决定哪一个放入序列 C。

1. 若 A[i] < B[j] ，说明 A[i] 是当前序列 A 与序列 B 的剩余元素中最小的哪个，因此 A[i] 加入序列 C 中，并让 i 加 1(即让 i 右移一位)。
2. 若 A[i] > B[j] 同理
3. 若 A[i] == B[j] ，则任意选一个加入到序列 C 中，并让对应的下标加 1.

```cpp
int merge(int *A, int *B, int *C, int n, int m){
    int i = 0, j = 0, index = 0;    //i指向A[0] ，j指向B[0]
    while(i < n && j < m){
        if(A[i] <= B[j]){
            C[index++] = A[i++];    //如果 A[i] <= B[j] ，将 A[i] 加入到序列 C
        }else{
            C[index++] = B[j++]
        }
    }
    while(i < n)    C[index++] = A[i++];    //将序列A的剩余元素加入序列C
    while(j < m)    C[index++] = B[j++];    //将序列B的剩余元素加入序列C
}
```
