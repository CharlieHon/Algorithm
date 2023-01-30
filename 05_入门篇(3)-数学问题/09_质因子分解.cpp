#include<cstdio>
#include<cmath>

const int maxn = 100010;
int prime[maxn], pNum;
bool p[maxn] = {0};

void Find_Prime(){
    for(int i=2; i<maxn; ++i){
        if(p[i] == false){
            prime[pNum++] = i;
            for(int j=i+i; j<maxn; j+=i){
                p[j] = true;
            }
        }
    }
}

struct factor{
    int x, cnt;
}fac[10];

int main()
{
    Find_Prime();   //制表，务必写上
    int n, num = 0; //num为n的不同质因子的个数
    scanf("%d", &n);
    if(n == 1){     //特判1的情况
        printf("1=1");
    }else{
        printf("%d=", n);
        int sqr = (int)sqrt(1.0 * n);   //n的根号
        //枚举根号n以内的质因子
        for(int i=0; i<pNum && prime[i]<=sqr; ++i){
            if(n % prime[i] == 0){  //如果prime[i]是n的因子
                fac[num].x = prime[i];  //记录该因子
                fac[num].cnt = 0;
                while(n % prime[i] == 0){   //计算出质因子prime[i]的个数
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;  //不同质因子个数加1
            }
            if(n == 1)  break;  //及时退出循环，节省点时间
        }
        if(n != 1){
            fac[num].x = n;
            fac[num].cnt = 1;
        }
    }

    //按格式输出
    for(int i=0; i<num; ++i){
        printf("%d", fac[i].x);
        if(fac[i].cnt > 1)
            printf("^%d", fac[i].cnt);
        if(i != num-1)
            printf("*");
    }
    return 0;
}