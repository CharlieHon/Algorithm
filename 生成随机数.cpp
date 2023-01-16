#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0; i<10; ++i)
        printf("%d ", rand());  //输出结果是实时变化的
    
    printf("\n");
    
    for(int i=0; i<10; ++i)
        printf("%d ", rand() % 8 + 3);  //生成 [3, 10] 范围内的随机数
    
    printf("\n");
    
    int left = 12, right = 99;
    for(int i=0; i<10; ++i)
        printf("%d ", (int)round(1.0*rand()/RAND_MAX*(right - left) + left));  //生成 [left, right] 范围内的随机数
    
    return 0;
}