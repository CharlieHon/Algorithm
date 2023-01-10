#include<cstdio>
const int maxn = 210;
int a[maxn];    //存放n个数
int main()
{
    int n, x;
    while(scanf("%d", &n) != EOF){
        for(int i=0; i<n; ++i){
            scanf("%d", &a[i]);
        }
        scanf("%d", &x);
        int k;  //下标
        for(k=0; k<n; ++k){
            if(a[k] == x){
                printf("%d\n", k);
                break;  //退出查找
            }
        }
        if(k == n)
            printf("%d\n", -1);   //如果没有找到，输出-1
    }
    return 0;
}