#include<cstdio>

typedef long long LL;

//求 a ^ b % m 的递归写法
LL binaryPow(LL a, LL b, LL m){
    if(b == 0)
        return 1;
    if(b & 1)   //b为奇数时，等价于 b % 2 == 1
        return a * binaryPow(a, b-1, m) % m;
    else{
        LL x = binaryPow(a, b/2, m);    //这样只需计算一次递归式
        return x * x % m;
    }
}

//求 a ^ b % m 迭代写法
LL binaryPow2(LL a, LL b, LL m){
    LL ans = 1;
    while(b > 0){
        if(b & 1)
            ans = ans * a % m;  //令 ans 累积上 a
        a = a * a % m;  //令 a 平方
        b >>= 1;    //将b的二进制右移 1 位，即 b = b >> 1 或 b = b / 2
    }
    return ans;
}


int main()
{
    LL a, b, m;
    scanf("%d%d%d", &a, &b, &m);
    LL res = binaryPow(a, b, m);
    printf("a ^ b %% m = %d\n", res);   //输出取余符号 %  需要使用 %%
    LL res2 = binaryPow2(a, b, m);
    printf("a ^ b %% m = %d\n", res2);
    return 0;
}