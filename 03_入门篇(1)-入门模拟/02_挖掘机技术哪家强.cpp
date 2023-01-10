#include<cstdio>
const int N = 100010;
int a[N] = {0};
int main()
{
    int n, schID, score;
    scanf("%d", &n);    //挖掘机个数
    for(int i=0; i<n; ++i){
        scanf("%d %d", &schID, &score); //学校ID，分数
        a[schID] += score;  //学校schID的总分增加score
    }
    int k = 1, MAX = -1;    //最高分数和学校ID
    for(int j=1; j<=n; ++j){
        if(a[j] > MAX){
            MAX = a[j];
            k = j;
        }
    }
    printf("%d %d", k, MAX);    //输出最高总分的学校ID极其总分
    return 0;
}