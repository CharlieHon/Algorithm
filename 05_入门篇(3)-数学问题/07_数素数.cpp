#include<cstdio>
const int maxn = 1000001;
int prime[maxn], pNum;
bool p[maxn] = {0};

void Find_Prime(int n){
    for(int i=2; i<maxn; ++i){
        if(p[i] == false){
            prime[pNum++] = i;
            if(pNum >= n)   break;
            for(int j=i+i; j<maxn; j+=i){
                p[j] = true;
            }
        }
    }

}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    Find_Prime(n);
    int x = n - m + 1;  //要求输出的素数个数
    for(int i=1; i<=x; ++i){
        printf("%d", prime[m+i-2]);
        if(i % 10)
            printf("#");    //素数之间以空格表示，末尾不含空格(因为空格不可见，故用#代替之)
        else
            printf("\n");
    }
    return 0;
}