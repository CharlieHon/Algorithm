#include<cstdio>
int main()
{
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int x = a + b;
    int z[40], num = 0; //z[40]数组用于存放d进制数的每位
    do{
        z[num++] = x % d;
        x = x / d;
    }while(x != 0);
    for(int i=num-1; i>=0; --i)
        printf("%d", z[i]);
    printf("\n");
    return 0;
}