#include<cstdio>
const int maxn = 110;
char S[maxn][5], temp[5];
int hashTable[26 * 26 * 26 + 10];    //三位26进制数的大概取值范围
/**
 * @brief 将字符串转换为整数hash值
 * 
 * @param S 字符数组
 * @param len 字符数组长度
 * @return int hash值
 */
int hashFunc(char S[], int len){
    int id = 0;
    for(int i=0; i<len; ++i){
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}
int main()
{
    int n, m, id;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i){
        scanf("%s", S[i]);
        id = hashFunc(S[i], 3); //要求每个字符串长度为3
        hashTable[id]++;
    }
    for(int j=0; j<m; ++j){
        scanf("%s", temp);
        id = hashFunc(temp, 3);
        printf("%d\n", hashTable[id]);
    }
    return 0;
}