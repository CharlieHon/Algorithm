#include<cstdio>
#include<cstring>
const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN]; //输入的字符串
int leftNumP[MAXN] = {0};
/**
 * @brief 输入一个字符串，只有PAT三种字母，计算其中包含多少个 PAT。
 * 对于一个确定位置的A来说，以它形成的 PAT 的个数等于它左边 P 的个数乘以它右边的 T 的个数。
 * @return int 
 */
int main()
{
    gets(str);  //字符串
    int len = strlen(str);  //字符拆长度
    for(int i=0; i<len; ++i){   //从左到右遍历字符串
        if(i > 0)   //如果不是0号位
            leftNumP[i] = leftNumP[i-1];    //继承上一位的结果
        if(str[i] == 'P')   //当前位是 P，令 leftNumP[i]加 1
            leftNumP[i]++;
    }
    int ans = 0, rightNumT = 0; //ans为答案，rightNumT记录右边T的个数
    for(int j=len-1; j>=0; --j){
        if(str[j] == 'T'){
            rightNumT++;
        }else if(str[j] == 'A'){
            ans = (ans + leftNumP[j] * rightNumT) % MOD;    //累积乘积
        }
    }
    printf("%d\n", ans);    //输出结果
    return 0;
}