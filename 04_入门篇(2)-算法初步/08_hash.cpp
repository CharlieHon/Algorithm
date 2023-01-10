#include<cstdio>

const int maxn = 100010;
bool hashTable[maxn] = {false};
/**
 * @brief 分别输入n，m个数，判断m个数中每个数分别是否出现在n个数中
 */
int main()
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i){
        scanf("%d", &x);
        hashTable[x] = true;
    }
    for(int j=0; j<m; ++j){
        scanf("%d", &x);
        if(hashTable[x])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}