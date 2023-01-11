#include<cstdio>
#include<cmath>
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
int P2[maxn], hashTable2[maxn] = {false};
/**
 * @brief n皇后问题，是全排列问题的变形，nxn棋盘上任意棋子不在同一行、同一列，也不在同一对角线上。
 * 即每列棋子的行数互不相同，再对是否在同一对角线上进行判断。
 */
int count1 = 0, count2 = 0;  //符合条件的个数
void Permutation(int index){
    if(index == n+1){
        bool flag = true;   //假设排列符合要求
        for(int i=1; i<n; ++i){ //判断排列是否有棋子在同一对角线上
            for(int j=i+1; j<=n; ++j){
                if(abs(j - i) == abs(P[j] - P[i])){
                    flag = false;
                    break;
                }
            }
            if(flag == false)   break;
        }
        if(flag){   //flag==true 排列符合条件，count计数加1
            ++count1;
            for(int i=1; i<=n; ++i)
                printf("%d", P[i]);
            printf("\n");
        }
        return;
    }
    for(int x=1; x<=n; ++x){    //思路与全排列一致，只需进行对角线判断
        if(hashTable[x] == false){
            P[index] = x;
            hashTable[x] = true;
            Permutation(index+1);
            hashTable[x] = false;
        }
    }
}

/**
 * @brief 回溯法求解n皇后问题
 * 
 * @param index 
 */
void Permutation2(int index){   //n皇后问题解法优化，在到达递归边界前的某层，由于一些事实不再需要任何一个子问题递归，就可以直接返回上一层——回溯法
    if(index == n+1){
        ++count2;    //前面做好判断，保证到达边界的都符合条件
        for(int i=1; i<=n; ++i)
            printf("%d", P2[i]);
        printf("\n");
        return;
    }
    for(int x=1; x<=n; ++x){
        bool flag = true;
        if(hashTable2[x] == false){
            for(int pre=1; pre<index; ++pre){
                if(abs(pre - index) == abs(P2[pre] - x)){   //在这里就进行判断
                    flag = false;
                    break;
                }
            }
            if(flag == false)   //不符合直接判断下一个x
                continue;
            P2[index] = x;
            hashTable2[x] = true;
            Permutation2(index+1);
            hashTable2[x] = false;
        }
    }
}

int main()
{
    n = 8;
    Permutation(1);
    printf("count = %d\n", count1);  // n=8时有92种排列方式
    printf("----------------------------\n");
    Permutation2(1);
    printf("count = %d\n", count2);  // 回溯法结果
    return 0;
}