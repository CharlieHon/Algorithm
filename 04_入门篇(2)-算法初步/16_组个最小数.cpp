#include<cstdio>
int main()
{
    int n, a[11];
    for(int i=0; i<10; ++i){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<10; ++i){    //找到除0外的最小值，输出1个然后中断
        if(a[i] > 0){
            printf("%d", i);
            a[i] -= 1;
            break;
        }
    }
    for(int i=0; i<10; ++i){
        while(a[i] > 0){
            printf("%d", i);
            a[i] -= 1;
        }
    }
    return 0;
}