#include<cstdio>
int main()
{
    int num;
    char str[90][90];
    while(scanf("%s", str[num]) != EOF){
        num++;
    }
    for(int i=num-1; i>=0; --i){
        printf("%s", str[i]);
        if(i > 0)   printf(" ");    //单词之间的空格，最后一个单词后无空格
    }
    return 0;
}