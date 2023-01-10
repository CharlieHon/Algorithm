#include<cstdio>
#include<cstring>
int main()
{
    char str[90];
    gets(str);
    int len = strlen(str), r = 0, c = 0;
    char res[90][90];
    for(int i=0; i<len; ++i){
        if(str[i] != ' '){
            res[r][c++] = str[i];
        }
        else{
            res[r][c] = '\0'; //末尾是换行符\0
            ++r;    //换至下一行
            c = 0;  //重新回到第1列
        }
    }
    for(int i=r; i>=0; --i){
        printf("%s", res[i]);
        if(i > 0)   printf(" ");
    }
    return 0;
}