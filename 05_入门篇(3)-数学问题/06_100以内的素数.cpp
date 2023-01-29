#include<cstdio>
#include<cmath>

//判断素数
bool isPrime(int n){
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i=2; i<=sqr; ++i){
        if(n % i == 0)
            return false;
    }
    return true;
}


//获取素数表
const int maxn = 101;
int prime[maxn], pNum;  //素数表，以及素数个数
bool p[maxn] = {0}; //p[i] == true 表示 i 是素数
void Find_Prime(){
    for(int i=1; i<maxn; ++i){
        if(isPrime(i)){
            prime[pNum++] = i;
            p[i] = true;
        }
    }
}

//筛法求100以内素数
void Find_Prime2(){
    for(int i=2; i<maxn; ++i){
        if(p[i] == false){
            prime[pNum++] = i;
            for(int j=i+i; j<maxn; j+=i){
                p[j] = true;
            }
        }
    }

}

int main()
{
    Find_Prime();   //容易遗漏
    // Find_Prime2();   //筛法求素数
    for(int i=0; i<pNum; ++i)
        printf("%d ", prime[i]);
    return 0;
}
