#include<cstdio>

struct studentInfo{
    int id;
    char gender;    // 'F' or 'M'
    char name[20];
    char major[20];
}Alice, Bob, stu[1000]; //可以在此定义变量或数组，分号不能少

struct note{
    // note n;  //结构体里面能定义除了自己本身之外的任何数据类型
    note *next; //可以定义 note* 型指针变量
};

int main()
{
    return 0;
}