#include<cstdio>
#include<cstring>
int main()
{
    /**
     * @brief string.h头文件包含了许多用于 字符数组 的函数。使用以下函数时需要在程序开头添加string.h头文件
     * 1. strlen(字符数组)：得到字符数组中第一个\0之前的字符的个数
     * 2. strcmp(字符数组1, 字符数组2)：返回两个字符串大小的比较结果，比较原则是按字典序
     * 如果字符数组1＜字符数组2，则返回一个负整数；字符数组1 == 字符数组2，则返回 0；字符数组1＞字符数组2，则返回一个正整数
     * 3. strcpy(字符数组1, 字符数组2)：把一个字符串复制给另一个字符串
     * 把 字符数组2 复制给 字符数组1，这里的“复制”包括了结束符\0
     * 4. strcat(字符数组1, 字符数组2)：把一个字符串接到另一个字符串后面
     * 把 字符数组2 接到 字符数组1 后面
     * 5. sscanf 和 sprintf
     * sscanf(str, "%d", &n)：把字符数组str中的内容以"%d"的格式写到n中(从左到右)
     * sprintf(str, "%d", n)：把n以"%d"的格式写到str字符数组中(从右至左)
     */
    //1. strlen()
    char str[10];
    gets(str);
    int len = strlen(str);
    printf("len=%d\n", len);
    //2. strcmp()
    char str1[50], str2[50];
    gets(str1);
    gets(str2);
    int cmp = strcmp(str1, str2);
    printf("cmp=%d\n", cmp);
    if(cmp < 0)
        printf("str1 < str2\n");
    else if(cmp == 0)
        printf("str1 == str2\n");
    else
        printf("str1 > str2\n");
    //3. strcpy()
    strcpy(str1, str2);
    puts(str1);
    //4. strcat()
    strcat(str1, str2);
    printf("%s\n", str1);
    //5. sscanf()
    char str3[100] = "123";
    int n;
    sscanf(str3, "%d", &n);
    printf("%d\n", n);  // 123
    n +=100;
    char str4[100];
    sprintf(str4, "%d", n); //将n以"%d"格式写入到str4中
    printf("%s\n", str4);
    //sscanf和sprintf可以像使用scanf与printf那样进行复杂的格式输入和输出
    double db;
    char str5[]="2023:3.14,New_Year", str6[100];
    sscanf(str5, "%d:%lf,%s", &n, &db, str6);
    printf("n=%d, db=%.2f, str6=%s\n", n, db, str6);
    return 0;
}