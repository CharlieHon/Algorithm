#include<cstdio>
/**
 * @brief 求最大公约数
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){   //测试数据有多组
        printf("gcd = %d\n", gcd(a, b));
        printf("lcm = %d\n", a / gcd(a, b) * b);
    }
    return 0;
}