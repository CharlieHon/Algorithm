#include<cstdio>
/**
 * @brief 递归求解 n！
 */
int Fact(int n){
    if(n == 0)  //递归边界 0！=1
        return 1;
    return Fact(n-1) * n;   //递归式
}

/**
 * @brief 斐波那契数列的第n位
 */
int Fibonacci(int n){
    if(n == 1 || n == 2)    //递归边界，Fibonacci数列前两项为1
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2); //递归式 F(n) = F(n-1) + F(n-2)
}

/**
 * @brief  
 */
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
void Permutation(int index){
    
    if(index == n+1){
        for(int i=1; i<=n; ++i)
            printf("%d", P[i]);
        printf("\n");
        return;
    }
    for(int x=1; x<=n; ++x){    //枚举1~n，视情况将x填入P[index]
        if(hashTable[x] == false){  //如果x未出现在 P[1]~P[index-1]
            P[index] = x;
            hashTable[x] = true;
            Permutation(index+1);
            hashTable[x] = false;
        }
    }

}

int main()
{
    int n1, x;
    scanf("%d", &n1);
    x = Fact(n1);
    printf("n! = %d\n", x);

    int y = Fibonacci(n1);
    printf("Fibonacci(n) = %d\n", y);

    n = 3;  //进行1~3全排列
    Permutation(1);
    return 0;
}