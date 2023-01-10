#include <stdio.h>  //头文件
int main()          //主函数
{
    int a, b;
    scanf("%d,%d", &a, &b);
    printf("%d\n", a+b);
    printf("%%");   //输出 '%'
    printf("\\");   //输出 '\'
    int c = printf("\n%3d\n", a);
    printf("c=%d", c);  //c=5
    return 0;
}