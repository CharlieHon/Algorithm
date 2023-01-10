#include<cstdio>

const int maxn = 100010;
int hashTable[maxn] = {0};
/**
 * @brief 分别输入n，m个数，输出m个数中每个分别在n个数中出现的次数
 */
int main()
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i){
        scanf("%d", &x);
        hashTable[x]++;
    }
    for(int j=0; j<m; ++j){
        scanf("%d", &x);
        printf("%d\n", hashTable[x]);
    }
    return 0;
}