#include<cstdio>
#include<cstring>
const int maxn = 256;
//判断字符是否是回文串
bool judge(char str[]){
    int len = strlen(str);  //字符串长度
    for(int i=0; i<len/2; ++i){
        if(str[i] != str[len-1-i])
            return false;   //不是回文串
    }
    return true;    //通过判断则是回文串
}
int main()
{
    char str[maxn];
    while(gets(str)){   //输入字符串
        bool flag = judge(str);
        if(flag)    printf("YES\n");
        else        printf("NO\n");
    }
}