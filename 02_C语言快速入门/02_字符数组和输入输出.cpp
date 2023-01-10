#include<cstdio>
int main()
{
    /*
     * %c 格式能够识别 空格 跟 换行 并将其输入
     * %s 通过 空格 或 换行 来识别一个字符串的结束
     */

    // char str[10];
    // scanf("%s", str);
    // printf("%s", str);
    
    // char str[5][5];
    // for(int i=0; i<3; ++i){
    //     for(int j=0; j<3; ++j){
    //         str[i][j] = getchar();
    //     }
    //     getchar();  //为了把输入中每行末尾的换行符吸收掉
    // }
    // for(int i=0; i<3; ++i){
    //     for(int j=0; j<3; ++j){
    //         putchar(str[i][j]);
    //     }
    //     putchar('\n');  //输出单个字符，所以用单引号''
    // }

    /**
     * gets 用来输入一行字符串，并将其存放于一维数组(或二维数组的一维)中
     * gets 识别 换行符\n 作为输入结束，因此scanf完一个整数后，如果要使用gets，需要先用getchar接收整数后的换行符
     * 
     * puts 用来输出一行字符串，即将一维数组(或二维数组的一维)在界面上输出，并紧跟一个换行
     */
    char str1[20];
    char str2[5][10];
    gets(str1);
    for(int i=0; i<3; ++i){
        gets(str2[i]);
    }
    puts(str1);
    for(int i=0; i<3; ++i){
        puts(str2[i]);
    }
    return 0;

}