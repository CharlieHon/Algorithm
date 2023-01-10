#include<cstdio>
/**
 * @brief 3n+1猜想
 * 对任何一个自然苏，如果它是偶数，那么把它砍掉一般；如果它是技术，那么把(3n+1)砍掉一般。
 * 一直反复下去，最后一定在某一步得到n=1
 * @return int 
 */
int main()
{
    int n, step = 0;
    scanf("%d", &n);
    while(n != 1){
        if(n % 2 == 0)
            n /= 2;
        else
            n = (3*n + 1) / 2;
        ++step;
    }
    printf("%d\n", step);
    return 0;
}